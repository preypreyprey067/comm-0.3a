#ifndef __os__
#define __os__

#include <string>

class os {
public:
	explicit os() = default;
	
	std::string name() {
#ifdef _WIN32 || _WIN64
		return "Windows";
#elif __unix || __unix__
		return "Unix";
#elif __APPLE__ || __MACH__
		return "Mac OSX";
#elif __linux__
		return "Linux";
#elif __FreeBSD__
		return "FreeBSD";
#else
		return "Other";
#endif
	}

	unsigned bits() {
		return sizeof(void*) * 8;
	}
};


#endif