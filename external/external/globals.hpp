#pragma once
#include "osmium/Memory/Process/process.hpp"
#include "farcry_cheat.hpp"

namespace Globals
{
	inline std::unique_ptr< process > g_pProcess = std::make_unique< process >();

	inline std::unique_ptr< farcry_cheat > g_pCheat = std::make_unique< farcry_cheat >();
}
