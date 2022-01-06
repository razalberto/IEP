#include<iostream>
#include<memory>
#include "Car.cpp"


Car* createCarInstance()
{
	return (new Car);
}

void lock(Car &car)
{
	std::cout << "Locking car " << std::endl;
	car.set_isLocked(true);
}


void unlock(Car &car)
{
	std::cout << "Unlocking car" << std::endl;
	car.set_isLocked(false);
}

class LockCar
{

private:
	Car &lockPtr;
	

public:
	LockCar(Car &ptr):
	lockPtr(ptr)
	{
		lock(lockPtr);
	}
	
	~LockCar()
	{
		unlock(lockPtr);
	}

};


int main()
{
	std::cout << "--auto--" << std::endl;
	{
		std::auto_ptr<Car> tesla(createCarInstance());
		std::cout << "Nr roti " << tesla->get_wheels() << std::endl;
		std::auto_ptr<Car> tesla2(tesla);
		
		std::cout << "Nr roti " << tesla2->get_wheels() << std::endl;
		//std::cout << "Nr roti " << tesla->get_wheels() << std::endl; 
		
	}
	
	std::cout << "--unique--" << std::endl;
	{
		std::unique_ptr<Car> bmw(createCarInstance());
		std::cout << "Nr roti " << bmw->get_wheels() << std::endl;
	
		std::unique_ptr<Car> bmw2 = move(bmw); 
	}
	
	std::cout << "--shared--" << std::endl;
	{
		std::shared_ptr<Car> audi(createCarInstance());
		std::cout << "Nr roti " << audi->get_wheels() << std::endl;
		std::cout << "audi count = " << audi.use_count() << std::endl;
		
		std::shared_ptr<Car> audi2(audi);
		std::cout << "audi count = " << audi.use_count() << std::endl;
		std::cout << "Sunte motor " << audi2->get_engine_sound() << std::endl;
		audi2->set_engine_sound("Viumm");
		std::cout << "Sunte motor " << audi->get_engine_sound() << std::endl;
		
		
		std::shared_ptr<Car> audi3 = move(audi); // transfer de ownership, nu copiere
		std::cout << "audi count = " << audi.use_count() << std::endl;
		std::cout << "audi3 count = " << audi3.use_count() << std::endl;
		audi3->set_engine_sound("Vrrrrrr");
		
		std::cout << "Sunte motor " << audi3->get_engine_sound() << std::endl;
		std::cout << "Sunte motor " << audi2->get_engine_sound() << std::endl;
		
	}
	
	Car renault("Vrrrium");
	LockCar *lockedCar = new LockCar(renault);
	renault.statusCar();
	delete lockedCar;
	renault.statusCar();	
	
	return 0;

}






