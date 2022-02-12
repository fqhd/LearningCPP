#include <iostream>

struct E {
	E(){
		std::cout << "Created E struct" << std::endl;
	}
	~E(){
		std::cout << "Destroyed E struct" << std::endl;
	}
};

struct Vector2 {
	Vector2(){ // Initializing a without initializer list(calls E::constructor twice)
		a = E();
	}
	Vector2(int r) : a() {} // Initializing with initializer list(calls E::constructor once)
	E a;
};

int main(){
	
	// Vector2 a;
	Vector2 b(2);

	return 0;
}