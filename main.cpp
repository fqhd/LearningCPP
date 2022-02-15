#include <iostream>

struct Vector {
	float x, y;
};

std::ostream& operator<<(std::ostream& a, const Vector& b){
	a << b.x << ", " << b.y;
	return a;
}

int main(){

	Vector a = {2, 6};

	std::cout << a << std::endl;;

	return 0;
}