#include <iostream>
#include <thread> // Include this for thread support(no need for -pthread in the build instruction)
#include <mutex>

std::mutex mutex; // Mutex must be in shared memory between both threads so both threads can access it(Can also be passed to the thread as a pointer)

void do_work(){
	mutex.lock(); // If mutex is unlocked, lock the mutex. If mutex is locked, wait for mutex to unlock, then lock the mutex
	std::this_thread::sleep_for(std::chrono::seconds(1)); // Sleeps on current thread for 1 second
	mutex.unlock();
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