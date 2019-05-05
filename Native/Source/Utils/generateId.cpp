#include "generateId.h"
#include <sstream>
#include <random>

namespace
{
	unsigned char random_char() {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distro(0, 255);
		return static_cast<unsigned char>(distro(gen));
	}
}

namespace Utils
{
	std::string generateId()
	{
		std::stringstream ss;

		for (auto i = 0; i < 10; i++) {
			auto rc = random_char();
			std::stringstream hexstream;
			hexstream << std::hex << int(rc);
			auto hex = hexstream.str();
			ss << (hex.length() < 2 ? '0' + hex : hex);
		}

		return ss.str();
	}
}