#include <iostream>

int main(){
	
	// Static cast simply changes the binary data to preserve the value
	// int a = 45;
	// float b = static_cast<float>(a);
	// std::cout << b << std::endl;

	// Reinterpret cast does not change the binary data and will not preserve the value
	// unsigned int a = 7;
	// int* b = reinterpret_cast<int*>(&a); // Mostly used to change pointers(and reinterpret data that way)

	return 0;
}