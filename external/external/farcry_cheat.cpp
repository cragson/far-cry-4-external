#include "farcry_cheat.hpp"
#include "globals.hpp"
#include "offsets.hpp"
#include "ft_infinite_ammo.hpp"
#include "ft_infinite_throwables.hpp"
#include "ft_free_vendor.hpp"
#include "utils.hpp"
#include "ft_infinite_stimpacks.hpp"
#include "ft_god_mode.hpp"
#include "ft_unlock_buyables.hpp"
#include "ft_infinite_backpack.hpp"
#include "ft_norecoil.hpp"
#include "ft_cali_mode.hpp"

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
	free_vendor->set_name( L"Free Vendor" );
	free_vendor->set_virtual_key_code( VK_NUMPAD3 );
	free_vendor->set_activation_delay( 500 );
	free_vendor->set_print_status( true );
	this->m_features.push_back( std::move( free_vendor ) );

	auto infinite_stimpacks = std::make_unique< ft_infinite_stimpacks >();
	infinite_stimpacks->set_name( L"Infinite Stimpacks" );
	infinite_stimpacks->set_virtual_key_code( VK_NUMPAD4 );
	infinite_stimpacks->set_activation_delay( 500 );
	infinite_stimpacks->set_print_status( true );
	this->m_features.push_back( std::move( infinite_stimpacks ) );

	auto god_mode = std::make_unique< ft_god_mode >();
	god_mode->set_name( L"God Mode" );
	god_mode->set_virtual_key_code( VK_NUMPAD5 );
	god_mode->set_activation_delay( 500 );
	god_mode->set_print_status( true );
	this->m_features.push_back( std::move( god_mode ) );

	auto unlock_buyables = std::make_unique< ft_unlock_buyables >();
	unlock_buyables->set_name( L"Unlock Buyables" );
	unlock_buyables->set_virtual_key_code( VK_NUMPAD6 );
	unlock_buyables->set_activation_delay( 500 );
	unlock_buyables->set_print_status( true );
	this->m_features.push_back( std::move( unlock_buyables ) );

	auto infinite_backpack = std::make_unique< ft_infinite_backpack >();
	infinite_backpack->set_name( L"Infinite Backpack" );
	infinite_backpack->set_virtual_key_code( VK_NUMPAD7 );
	infinite_backpack->set_activation_delay( 500 );
	infinite_backpack->set_print_status( true );
	this->m_features.push_back( std::move( infinite_backpack ) );

	auto norecoil = std::make_unique< ft_norecoil >();
	norecoil->set_name( L"Norecoil" );
	norecoil->set_virtual_key_code( VK_NUMPAD8 );
	norecoil->set_activation_delay( 500 );
	norecoil->set_print_status( true );
	this->m_features.push_back( std::move( norecoil ) );

	auto cali_mode = std::make_unique< ft_cali_mode >();
	cali_mode->set_name( L"Cali Mode" );
	cali_mode->set_virtual_key_code( VK_NUMPAD9 );
	cali_mode->set_activation_delay( 500 );
	cali_mode->set_print_status( true );
	this->m_features.push_back( std::move( cali_mode ) );
	
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


	const auto infinite_arrows = image->find_pattern( L"2B C1 89 03 48 8B 5C 24 30", false );

	if( !infinite_arrows )
		return false;

	Offsets::infinite_arrows_patch = infinite_arrows;


	const auto infinite_stimpacks = image->find_pattern( L"FF C8 48 89 5C 24 38 89", false );

	if( !infinite_stimpacks )
		return false;

	Offsets::infinite_stimpacks_patch = infinite_stimpacks;


	const auto god_mode = image->find_pattern( L"72 03 B0 01 C3 32 C0 C3 CC 48", false );

	if( !god_mode )
		return false;

	Offsets::god_mode_patch = god_mode;


	// credits for this feature to gir489
	// Thank you! :)
	const auto unlock_buyables = image->find_pattern( L"4C 8B FA 74 0A", false );

	if( !unlock_buyables )
		return false;

	Offsets::unlock_buyables_patch = unlock_buyables + 3;


	const auto infinite_backpack = image->find_pattern( L"8B 4B 04 E8 08 FB 21 00", false );

	if( !infinite_backpack )
		return false;

	Offsets::infinite_backpack_patch = infinite_backpack;


	const auto player_recoil_y = image->find_pattern( L"F3 0F 59 35 ? ? ? ? 48 85 DB", false );

	if( !player_recoil_y )
		return false;

	Offsets::player_viewvelocity_y = static_cast< uint32_t >( image->deref_address< std::uintptr_t >( player_recoil_y + 4 ) + player_recoil_y + 8 - image->get_image_base() ) + image->get_image_base();


	const auto cali = image->find_pattern( L"0F 2E 3D ? ? ? ? 75 0A", false );

	if( !cali )
		return false;

	Offsets::cali_mode = static_cast< uint32_t >( image->deref_address< std::uintptr_t >( cali + 3 ) + cali + 7 - image->get_image_base() ) + image->get_image_base();

	// A small gift for the interested reader
	// F2 0F 11 0D ? ? ? ? EB 25 + 4 in FC64.dll as float
	// play with it a little and have fun ;)

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
	printf( "\n" );

	const auto msg = []( const std::wstring& name, const std::uintptr_t value )
	{
		printf( "[>] %-35ws -> 0x%llX\n", name.c_str(), value );
	};

	msg( L"Infinite Ammo Patch", Offsets::infinite_ammo_patch );
	msg( L"Infinite Throwables Patch", Offsets::infinite_throwables_patch );
	msg( L"Free Vendor Patch", Offsets::free_vendor_patch );
	msg( L"Infinite Bow Arrows Patch", Offsets::infinite_arrows_patch );
	msg( L"Infinite Stimpacks Patch", Offsets::infinite_stimpacks_patch );
	msg( L"God Mode Patch", Offsets::god_mode_patch );
	msg( L"Unlock Buyables Patch", Offsets::unlock_buyables_patch );
	msg( L"Infinite Backpack Patch", Offsets::infinite_backpack_patch );
	msg( L"Player Viewvelocity Y", Offsets::player_viewvelocity_y );
	msg( L"Cali Mode", Offsets::cali_mode );

	printf( "\n" );
}