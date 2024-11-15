#include "app.h"
#include <algorithm>


namespace vsite::oop::v4
{
	std::string cockroach::species() const { return "cockroach"; }
	unsigned cockroach::legs() const { return 6; }

	std::string tarantula::species() const { return "tarantula"; }
	unsigned tarantula::legs() const { return 8; }

	std::string sparrow::species() const { return "sparrow"; }
	unsigned sparrow::legs() const { return 2; }

	std::string leg_counter::add_animal(const animal* a) {
		if (a != nullptr) {

			counter += a->legs();
			return a->species();
		}
		else {
			std::cout << "error " << std::endl;
			return "";
		}
		
	};

	std::string leg_counter::add_animal(std::unique_ptr<animal> a) {
		if (a != nullptr) {

			counter += a->legs();
			return a->species();
		}
		else {
			std::cout << "error " << std::endl;
			return "";
		}
	};

	unsigned leg_counter::legs() const {
		return counter;
	}

	std::unique_ptr<animal> animal_factory(const unsigned type) {
		switch (type) {
		case 1: return std::make_unique<cockroach>();
		case 2: return std::make_unique<sparrow>();
		case 3: return std::make_unique<tarantula>();
		default: return nullptr;
		}
	}
}