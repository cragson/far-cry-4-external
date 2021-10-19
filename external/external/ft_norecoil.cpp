#include "ft_norecoil.hpp"
#include "globals.hpp"
#include "offsets.hpp"

void ft_norecoil::on_first_activation()
{
	this->m_flOldVelocity = Globals::g_pProcess->read< float >( Offsets::player_viewvelocity_y );
}

void ft_norecoil::on_enable()
{
	Globals::g_pProcess->write_to_protected_memory< float >( Offsets::player_viewvelocity_y, 0.010f );
}

void ft_norecoil::on_disable()
{
	Globals::g_pProcess->write_to_protected_memory< float >( Offsets::player_viewvelocity_y, this->m_flOldVelocity  );
}

void ft_norecoil::tick()
{
}
