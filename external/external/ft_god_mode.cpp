#include "ft_god_mode.hpp"
#include "globals.hpp"
#include "offsets.hpp"

void ft_god_mode::on_first_activation()
{
}

void ft_god_mode::on_enable()
{
	Globals::g_pProcess->write< short >( Offsets::god_mode_patch, 0x03EB );
}

void ft_god_mode::on_disable()
{
	Globals::g_pProcess->write< short >( Offsets::god_mode_patch, 0x0372 );
}

void ft_god_mode::tick()
{
}
