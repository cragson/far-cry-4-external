#include "ft_infinite_ammo.hpp"

#include "globals.hpp"
#include "offsets.hpp"

void ft_infinite_ammo::on_first_activation()
{
	// save original bytes from function
	for( size_t i = 0; i < 6; i++ )
		this->m_vecOriginalBytes.push_back( Globals::g_pProcess->read< char >( Offsets::infinite_ammo_patch + i ) );
}

void ft_infinite_ammo::on_enable()
{
	Globals::g_pProcess->nop_bytes( Offsets::infinite_ammo_patch, 6 );
}

void ft_infinite_ammo::on_disable()
{
	for( size_t i = 0; i < this->m_vecOriginalBytes.size(); i++ )
		Globals::g_pProcess->write< char >( Offsets::infinite_ammo_patch + i, this->m_vecOriginalBytes.at( i ) );
}

void ft_infinite_ammo::tick()
{
}
