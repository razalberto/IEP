#include <iostream>

class Car
{

private:
	int wheels = 4;
	std::string engine_sound = "Vruum";
	bool isLocked = false;


public:
	Car()
	{
		std::cout << "S-a apelat constructorul fara parmetrii" << std::endl;
	}
	
	Car(const std::string& es) : engine_sound(es)
	{
		std::cout << "S-a apelat constructorul cu parametrii" << std::endl;	
	}
	
	virtual ~Car() 
	{
		std::cout<< "S-a apelat destructorul" << std::endl;
	}
	
	Car(const Car &car)
	{
		std::cout<< "S-a apelat Copy-Constructorul" << std::endl;
		this->wheels = car.wheels;
		this->engine_sound = car.engine_sound; 
		this->isLocked = car.isLocked;
	}
	
	Car& operator=(const Car &car)
	{	
		if(this == &car)
		{
			std::cout<< "E acelasi obiect" << std::endl;
			return *this; 
		}
		
		std::cout << "Copy assigment operator" << std::endl;
		this->wheels = car.wheels;
		this->engine_sound = car.engine_sound;
		this->isLocked = car.isLocked;
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
	
	bool get_isLocked()
	{
		return this->isLocked;
	}
	
	void set_isLocked(bool isLocked)
	{
		this->isLocked = isLocked;
	}
	
	void statusCar()
	{
		if(this->isLocked)
		{
			std::cout << "Masina este blocata " << std::endl;
		}
		else
		{
			std::cout << "Masina este deblocata, o puteti folosi " << std::endl;
		}
	}
		
};



