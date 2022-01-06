#include <iostream>

class Car
{

private:
	int wheels;
	std::string engine_sound;


	
	
public:
	Car(const std::string& es) : engine_sound(es), wheels(4)
	{
		std::cout << "S-a apelat constructorul clasei Car" << std::endl;	
	}
	
	virtual ~Car() 
	{
		std::cout<< "S-a apelat destructorul clasei Car" << std::endl;
	}
	
	Car(const Car &car)
	{
		std::cout<< "S-a apelat Copy-Constructorul clasei Car" << std::endl;
		this->wheels = car.wheels;
		this->engine_sound = car.engine_sound; 
	}
	
	Car& operator=(const Car &car)
	{
		if(this == &car)
		{
			std::cout<< "E acelasi obiect" << std::endl;
			return *this; 
		}
		
		std::cout << "Copy assigment operator Car" << std::endl;
		wheels = car.wheels;
		engine_sound = car.engine_sound;
		return *this;
	}
	
	int get_wheels() 
	{
		return this->wheels;
	}
	
	void set_wheels(int wheels) 
	{
		 this->wheels = wheels;
	}
	
	std::string get_engine_sound()
	{
		return this->engine_sound;
	}
	
	void set_engine_sound(std::string engine_sound)
	{
		this->engine_sound = engine_sound;
	}
		
};

