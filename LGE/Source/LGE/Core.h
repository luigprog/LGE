#pragma once

#ifdef LGE_PLATFORM_WINDOWS
	#ifdef LGE_BUILD_DLL
		#define LGE_API __declspec(dllexport) 
	#else
		#define LGE_API __declspec(dllimport)
	#endif
#else
	#error LGE only supports Windows!	
#endif
