#include <iostream>
#include <thread> // Include this for thread support(no need for -pthread in the build instruction)

void do_work(){
	std::this_thread::sleep_for(std::chrono::seconds(1)); // Sleeps on current thread for 1 second
}

int main(){
	auto start = std::chrono::high_resolution_clock::now();
	std::thread worker(do_work); // Automatically starts the first thread
	std::thread worker2(do_work); // Automatically starts the second thread

	worker.join(); // Waits for first thread to finish
	worker2.join(); // Waits for second thread to finish
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> time = end - start; // Measures the time it took
	std::cout << "It took " << time.count() << " seconds" << std::endl; // Prints the time it took to run both threads

	return 0;
}