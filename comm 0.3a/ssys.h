#ifndef __csys__
#define __csys__

#include "cart.h"
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include "os.h"

#if _WIN32 || _WIN64
#include <Windows.h>
#elif __unix__ || __unix
#endif

class ssys {
public:
	explicit ssys(std::string title = "Comm 0.3a") {
#if _WIN32 || _WIN64
		::SetConsoleTitleA(title.c_str());
#elif __unix__ || __unix
#endif
	}

	~ssys() { construct(); };


	void add(const product& p, std::string code) {
		mdict[code] = p;
	}

private:
	void construct() {
		for (;;) {
			std::vector<std::pair<product, float>> prds;
			std::string code;
			cart cr;
			float kgoramt;


			std::cout << std::fixed << std::setprecision(2);

			for (;;) {
				std::cout << "Code: ";
				std::cin >> code;
				std::transform(code.begin(), code.end(), code.begin(), tolower);
				if (code == "stotal") {
					std::system("@cls||clear");
					for (auto a : prds)
						std::cout << a.first << " " << a.second << std::endl;
					std::cout << "===================================" << std::endl;
					std::cout << "Subtotal: " << cr.total() << std::endl;
					break;
				}
				else if (code == "exit")
					exit(0);
				else if (code == "jmp") {
					std::system("@cls||clear");
					continue;
				}
				else if (code == "clear") {
					std::system("@cls||clear");
					continue;
				}
				else if (code == "reset") {
					std::system("@cls||clear");
					cr.reset();
					prds.clear();
					continue;
				}
				std::cout << "Info: ";
				std::cout << mdict[code] << std::endl;
				std::cout << "Amount: ";
				std::cin >> kgoramt;
				cr.add(mdict[code], kgoramt);
				prds.push_back(std::make_pair(mdict[code], kgoramt));
				std::system("@cls||clear");

			}

			std::cin.get();
			std::cin.get();
			std::system("@cls||clear");
		}
	}
	std::map<std::string, product> mdict;
};

#endif