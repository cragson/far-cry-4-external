#include "ft_free_vendor.hpp"
#include "globals.hpp"
#include "offsets.hpp"

void ft_free_vendor::on_first_activation()
{
	
}

void ft_free_vendor::on_enable()
{
	Globals::g_pProcess->write< short >( Offsets::free_vendor_patch, 0x9090 );
}

void ft_free_vendor::on_disable()
{
	Globals::g_pProcess->write< short >( Offsets::free_vendor_patch,  0xC32B );
}

void ft_free_vendor::tick()
{
	
}
