#include <iostream>
#include <string>

class Animal {
private:
	std::string name;
	int age;

public:
	Animal(std::string name, int age) : name(name), age(age) {}
	void setName(std::string name) { this->name = name; }
	void setAge(int age) { this->age = age; }
	std::string getName() { return name; }
	int getAge() { return age; }
	virtual void makeSound() { std::cout << "The animal makes a sound." << std::endl; }
};

class Dog : public Animal {
public:
	Dog(std::string name, int age) : Animal(name, age) {}
	void makeSound() { std::cout << "The dog barks." << std::endl; }
};

class Cat : public Animal {
public:
	Cat(std::string name, int age) : Animal(name, age) {}
	void makeSound() { std::cout << "The cat meows." << std::endl; }
};

int main() {
  	Animal* animal = new Animal("Unknown", 0);
  	animal->makeSound();
  	Dog *dog = new Dog("Rufus", 5);
  	dog->makeSound();
  	Cat *cat = new Cat("Luna", 3);
  	cat->makeSound();
	return 0;
}
