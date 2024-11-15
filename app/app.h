#pragma once
#include <string>
#include <memory>
#include <iostream>

namespace vsite::oop::v4 
{
	class animal {
	public:
		virtual ~animal()=default;
		virtual std::string species() const=0;
		virtual unsigned legs() const=0;
	};

	class insect : public animal {};
	class spider : public animal {};
	class bird : public animal {};

	class cockroach : public insect {
	public:
		std::string species() const override;
		unsigned legs() const override;
	};

	class tarantula : public spider {
	public:
		std::string species() const override;
		unsigned legs() const override;
	};

	class sparrow : public bird {
	public:
		std::string species() const override;
		unsigned legs() const override;
	};

	class leg_counter {
	public:
		std::string add_animal(const animal* a); //dodao zbog testa
		std::string add_animal(std::unique_ptr<animal> a);
		unsigned legs() const;
		
	private:
		unsigned counter=0;
	};

	std::unique_ptr<animal> animal_factory(const unsigned type);

}