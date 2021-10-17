#include "farcry_cheat.hpp"
#include "globals.hpp"
#include "offsets.hpp"
#include "ft_infinite_ammo.hpp"
#include "ft_infinite_throwables.hpp"
#include "ft_free_vendor.hpp"
#include "utils.hpp"

bool farcry_cheat::setup_features()
{
	auto infinite_ammo = std::make_unique< ft_infinite_ammo >();
	infinite_ammo->set_name( L"Infinite Ammo" );
	infinite_ammo->set_virtual_key_code( VK_NUMPAD1 );
	infinite_ammo->set_activation_delay( 500 );
	infinite_ammo->set_print_status( true );
	this->m_features.push_back( std::move( infinite_ammo ) );

	auto infinite_throwables = std::make_unique< ft_infinite_throwables >();
	infinite_throwables->set_name(L"Infinite Throwables");
	infinite_throwables->set_virtual_key_code(VK_NUMPAD2);
	infinite_throwables->set_activation_delay(500);
	infinite_throwables->set_print_status(true);
	this->m_features.push_back( std::move( infinite_throwables ) );

	auto free_vendor = std::make_unique< ft_free_vendor >();
	free_vendor->set_name(L"Free Vendor");
	free_vendor->set_virtual_key_code(VK_NUMPAD3);
	free_vendor->set_activation_delay(500);
	free_vendor->set_print_status(true);
	this->m_features.push_back( std::move( free_vendor ) );
	
    return true;
}

bool farcry_cheat::setup_offsets()
{
	// check if image is already in map
    if( !Globals::g_pProcess->does_image_exist_in_map( L"FC64.dll" ) )
        return false;

	// retrieve here the ptr to the image
    const auto image = Globals::g_pProcess->get_image_ptr_by_name( L"FC64.dll" );

	// search now for the different signatures
	
    const auto infinite_ammo = image->find_pattern( L"89 8A 04 01 00 00", false );
    
	if( !infinite_ammo )
        return false;

	Offsets::infinite_ammo_patch = infinite_ammo;

	
    const auto infinite_throwables = image->find_pattern( L"89 51 78 4C 8B 40 70", false );

	if( !infinite_throwables )
		return false;

	Offsets::infinite_throwables_patch = infinite_throwables;

	// mysterious pattern: 2B FA 48 8B 8E E0 00 00 00
	// 0F 48 E8 89 AE 28 01 00 00 45
	const auto vendor_patch = image->find_pattern( L"2B C3 48 8B 5C 24 30 0F", false );

	if( !vendor_patch )
		return false;

	Offsets::free_vendor_patch = vendor_patch;
	
    return true;
}

void farcry_cheat::run()
{
	for (const auto& feature : this->m_features)
	{
		// before tick'ing the feature, check first if the state will eventually change
		if (utils::is_key_pressed(feature->get_virtual_key_code()))
			feature->toggle();

		// let the feature tick() when active
		if (feature->is_active())
			feature->tick();
	}
}

void farcry_cheat::shutdown()
{
	// disable every feature here
	for (const auto& feature : this->m_features)
		if (feature->is_active())
			feature->disable();

	// clear image map here
	if (Globals::g_pProcess)
		Globals::g_pProcess->clear_image_map();
}

void farcry_cheat::print_features()
{
	printf("\n");

	printf("Feature-Name -> Feature-Hotkey\n");

	for (const auto& feature : this->m_features)
		printf("[>] %-25ws -> %s\n", feature->get_name().c_str(), utils::virtual_key_as_string(feature->get_virtual_key_code()).c_str());

	printf("\n");
}

void farcry_cheat::print_offsets()
{
	printf("\n");

	const auto msg = [](const std::wstring& name, const std::uintptr_t value)
	{
		printf("[>] %-35ws -> 0x%llX\n", name.c_str(), value);
	};

	msg(L"Infinite Ammo Patch", Offsets::infinite_ammo_patch);
	msg(L"Infinite Throwables Patch", Offsets::infinite_throwables_patch);
	msg(L"Free Vendor Patch", Offsets::free_vendor_patch);

	printf("\n");
}