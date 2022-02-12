#include <iostream>

struct Vector2 {
	float x, y;

	Vector2(float x, float y){
		this->x = x;
		this->y = y;
		std::cout << "hi" << std::endl;
	}
	Vector2 operator+(const Vector2& other) const { // Use const in member functions that don't change the data of the class
		return Vector2(this->x + other.x, this->y + other.y);
	}
	Vector2 operator*(const Vector2& other) const {
		return Vector2(this->x * other.x, this->y * other.y);
	}
	Vector2 operator*(const float scalar) const {
		return Vector2(this->x * scalar, this->y * scalar);
	}
};


int main(){
	// Creates two vectors
	Vector2 a(5, 5);
	Vector2 b(6, 8);

	// Uses the member operator functions to initialize a new vector
	Vector2 c = a + b * a * 2.0f;
	
	return 0;
}