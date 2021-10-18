#include "ft_unlock_buyables.hpp"
#include "globals.hpp"
#include "offsets.hpp"

void ft_unlock_buyables::on_first_activation()
{
}

void ft_unlock_buyables::on_enable()
{
	Globals::g_pProcess->nop_bytes( Offsets::unlock_buyables_patch, 2 );
}

void ft_unlock_buyables::on_disable()
{
	Globals::g_pProcess->write< short >( Offsets::unlock_buyables_patch, 0x0A74  );
}

void ft_unlock_buyables::tick()
{
}
