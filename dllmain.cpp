// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

extern "C" __declspec (dllexport) void __cdecl HelloWorld()
{
	//Show a message box with the text "Hello World"
	MessageBox(NULL, TEXT("Hello World"), TEXT("In a DLL"), MB_OK);
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	//Different behaviors depending on the reason why DllMain is called
	switch (ul_reason_for_call) {
		case DLL_PROCESS_ATTACH:
			HelloWorld();
			break;
		case DLL_PROCESS_DETACH:
			HelloWorld();
			break;
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
	}

	return TRUE;
}
