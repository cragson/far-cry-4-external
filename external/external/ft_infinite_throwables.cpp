#include "ft_infinite_throwables.hpp"
#include "globals.hpp"
#include "offsets.hpp"

void ft_infinite_throwables::on_first_activation()
{
}

void ft_infinite_throwables::on_enable()
{
	Globals::g_pProcess->nop_bytes( Offsets::infinite_throwables_patch, 3 );
}

void ft_infinite_throwables::on_disable()
{
	Globals::g_pProcess->write< short >( Offsets::infinite_throwables_patch, 0x5189 );
	Globals::g_pProcess->write< char >( Offsets::infinite_throwables_patch + 2, 0x78 );
}

void ft_infinite_throwables::tick()
{
}
