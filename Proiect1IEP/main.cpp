#include<iostream>


class Uncopyable
{

protected:
	Uncopyable()
	{
		std::cout << "S-a apelat constructorul clasei Uncopyable"<< std::endl;
	}
	~Uncopyable() {}
	
private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);

};


class Car : private Uncopyable 
{

private:
	int wheels;
	std::string engine_sound;

protected:
	Car(const std::string& es) : Uncopyable(), engine_sound(es), wheels(4)
	{
		std::cout << "S-a apelat constructorul clasei Car" << std::endl;	
	}
	
public:
	virtual ~Car() 
	{
		std::cout<< "S-a apelat destructorul clasei Car" << std::endl;
	}
	
	int get_wheels() 
	{
		return this->wheels;
	}
	
	std::string get_engine_sound()
	{
		return this->engine_sound;
	}
		
};


class Tesla : public Car 
{

private:
	int battery_life;
	
public:
	Tesla(const std::string& es) : Car(es), battery_life(0) 
	{
		std::cout << "S-a apelat constructorul clasei Tesla" << std::endl;
	}
	
	~Tesla()
	{
		std::cout << "S-a apelat destructorul clasei Tesla" << std::endl;
	}

	int get_battery_life()
	{
		return this->battery_life;
	}
	
	void set_battery_life(int battery_life)
	{
		this->battery_life = battery_life;
	}

};


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

	int get_fuel_level()
	{
		return this->fuel_level;
	}
	
	void set_fuel_level(int fuel_level)
	{
		this->fuel_level = fuel_level;
	}

};


int main()
{

	Tesla modelS("Viuumm");
	BMW X3("Vruuum");
	// Tesla cyber = modelS;  eroare de compilare nu se poate copia
	/* Tesla cyber;
 	cyber = modelS; eroare de compilare nu se poate copia*/ 
 	
 	std::cout << std::endl;
 	std::cout << "Nr roti Tesla : " << modelS.get_wheels() << std::endl;
 	std::cout << "Sunet motor Tesla : " << modelS.get_engine_sound() << std::endl;         
	std::cout << "Baterie Tesla " << modelS.get_battery_life() << "%" << std::endl;
	modelS.set_battery_life(90);
	std::cout << "Baterie Tesla dupa incarcare : " << modelS.get_battery_life() << "%" << std::endl;
	std::cout << std::endl;
	std::cout << "Nr roti BMW : " << X3.get_wheels() << std::endl;
	std::cout << "Sunet motor BMW : " << X3.get_engine_sound() << std::endl;
	std::cout << "Nivel rezervor BMW : " << X3.get_fuel_level() << "l" << std::endl;
	X3.set_fuel_level(26);
	std::cout << "Nivel rezervor BMW dupa alimentare: " << X3.get_fuel_level() << "l" << std::endl;
	std::cout << std::endl;
	return 0;

}

























