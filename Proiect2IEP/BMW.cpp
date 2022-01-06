#include<iostream>
#include "Car.cpp"


class BMW : public Car
{

private:
	int fuel_level;
	
public:
	BMW(const std::string& es) : Car(es), fuel_level(0)
	{
		std::cout << "S-a apelat constructorul clasei BMW" << std::endl;
	}
	
	~BMW()
	{
		std::cout << "S-a apelat destructorul clasei BMW" << std::endl;
	}
	
	BMW(const BMW &bmw) : Car(bmw)
	{
		std::cout<< "S-a apelat Copy-Constructorul clasei BMW" << std::endl;
		fuel_level = bmw.fuel_level;
	}

	BMW& operator=(const BMW& bmw)
	{
		if(this == &bmw)
		{
			std::cout<< "E acelasi obiect" << std::endl;
			return *this; 
		}
		
		Car::operator=(bmw);
		
		std::cout<< "Copy assigment operator BMW" << std::endl;
		fuel_level = bmw.fuel_level;
		return *this;
	}


	int get_fuel_level()
	{
		return this->fuel_level;
	}
	
	void set_fuel_level(int fuel_level)
	{
		this->fuel_level = fuel_level;
	}

};
