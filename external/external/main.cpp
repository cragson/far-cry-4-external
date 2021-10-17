#include <iostream>

#include "globals.hpp"
#include "utils.hpp"

int main()
{
	SetConsoleTitleA( "Far Cry 4 external" );

	printf( "[>] Waiting for the game process.." );

	while( !Globals::g_pProcess->setup_process( L"FarCry®4" ) )
	{
		printf( "." );

		Sleep( 750 );
	}

	printf( "done!\n" );

	printf("[+] Dumped %.2lf MBs of images!\n", Globals::g_pProcess->get_map_size_in_mbytes());

	printf("[+] Scanning for signatures..");

	while (!Globals::g_pCheat->setup_offsets())
	{
		printf(".");

		Sleep(1420);
	}
	printf("done!\n");

	Globals::g_pCheat->print_offsets();

	Globals::g_pCheat->setup_features();

	Globals::g_pCheat->print_features();

	while (true)
	{
		Globals::g_pCheat->run();

		if (utils::is_key_pressed(VK_END))
			break;

		Sleep(3);
	}

	Globals::g_pCheat->shutdown();
	
	return EXIT_SUCCESS;
}
