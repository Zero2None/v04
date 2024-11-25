#include "app.h"
#include <algorithm>


namespace vsite::oop::v4
{
	unsigned int insect::legs() const {return 6; }
	unsigned int spider::legs() const { return 8; }
	unsigned int bird::legs() const { return 2; }

	std::string cockroach::species() const { return "cockroach"; }
	std::string tarantula::species() const { return "tarantula"; }
	std::string sparrow::species() const { return "sparrow"; }

	std::string leg_counter::add_animal(const animal* a) {
		if (a) {

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