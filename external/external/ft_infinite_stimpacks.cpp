#include "ft_infinite_stimpacks.hpp"
#include "globals.hpp"
#include "offsets.hpp"

void ft_infinite_stimpacks::on_first_activation()
{
}

void ft_infinite_stimpacks::on_enable()
{
	Globals::g_pProcess->nop_bytes( Offsets::infinite_stimpacks_patch, 2 );
}

void ft_infinite_stimpacks::on_disable()
{
	Globals::g_pProcess->write< short >( Offsets::infinite_stimpacks_patch, 0xC8FF );
}

void ft_infinite_stimpacks::tick()
{
}
