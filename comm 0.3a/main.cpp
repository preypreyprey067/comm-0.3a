#include "ssys.h"
#include "os.h"
#include <cstdio>

int main() {
	ssys system;
	system.add(product("Demo A", 28.50), "0000");
	system.add(product("Demo B", 32.50), "0001");
	system.add(product("Demo C", 19.50), "0002");
	system.add(product("Demo D", 16.50), "0003");
	return 0;
}