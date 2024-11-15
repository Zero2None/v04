#include "app.h"

using namespace vsite::oop::v4;

// read animal id's (until 0) and display species name
// display total leg count
int main()
{
	unsigned uID;
	leg_counter countLegs = leg_counter();

	do  {
		std::cout << "Unesi broj zivotinje: " << std::endl;
		std::cin >> uID;

		std::unique_ptr<animal> some_animal = animal_factory(uID);
		std::cout << countLegs.add_animal(std::move(some_animal)) << std::endl;

	} while (uID != 0);

	std::cout << "Ukupan broj nogu: " << countLegs.legs() << std::endl;
}
