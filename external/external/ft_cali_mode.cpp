#include "ft_cali_mode.hpp"
#include "globals.hpp"
#include "offsets.hpp"

void ft_cali_mode::on_first_activation()
{
}

void ft_cali_mode::on_enable()
{
	Globals::g_pProcess->write_to_protected_memory< float >( Offsets::cali_mode, 0.5f );
	Globals::g_pProcess->write_to_protected_memory< float >( Offsets::cali_mode + sizeof( float ), -0.15f );
}

void ft_cali_mode::on_disable()
{
	Globals::g_pProcess->write_to_protected_memory< uint64_t >( Offsets::cali_mode, 0  );
}

void ft_cali_mode::tick()
{
}
