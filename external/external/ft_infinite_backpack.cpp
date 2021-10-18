#include "ft_infinite_backpack.hpp"
#include "globals.hpp"
#include "offsets.hpp"

void ft_infinite_backpack::on_first_activation()
{
}

void ft_infinite_backpack::on_enable()
{
	Globals::g_pProcess->nop_bytes( Offsets::infinite_backpack_patch, 3 );
}

void ft_infinite_backpack::on_disable()
{
	Globals::g_pProcess->write< short >( Offsets::infinite_backpack_patch, 0x4B8B );
	Globals::g_pProcess->write< char >( Offsets::infinite_backpack_patch + 2, 0x04 );
}

void ft_infinite_backpack::tick()
{
}
