#include<iostream>
#include "BMW.cpp"




int main()
{

	Car car("Sunet--1");
	BMW X3("Sunet--2");
	BMW M5("Sunet--3");
	
	car = X3 = M5;
	
	
 	std::cout << std::endl;
 	std::cout << "Sunet CAR: " << car.get_engine_sound() << std::endl;
 	
 	car = car;
 	X3 = X3;
 	
 	X3.set_engine_sound("SUNETNOU");
 	
 	M5 = X3;
 	
 	std::cout << "Sunet BMW M5: " << M5.get_engine_sound() << std::endl;
 	
	return 0;

}

























