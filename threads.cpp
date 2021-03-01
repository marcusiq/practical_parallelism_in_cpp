// This program prints from multiple threads using c++11
// by marcus with help by coffeebeforearch

#include <iostream>
#include <thread>
#include <mutex>

std::mutex my_mutex;
void print_func(int id) {
	std::lock_guard<std::mutex> g(my_mutex);
	std::cout << "Printing from threads" << id << '\n';
}

void add_one(int id){
	std::cout << "Print the id +1" << id +1 << '\n';
}

int main() {
	// Create 4 threads that all call print function
	std::thread t0(print_func, 0);
	std::thread t1(print_func, 1);
	std::thread t2(print_func, 2);
	std::thread t3(print_func, 3);


	// wait for the threads to finish
	t0.join();
	t1.join();
	t2.join();
	t3.join();

	// Create 4 threads that all call print function
	std::thread t4(add_one, 0);
	std::thread t5(add_one, 1);
	std::thread t6(add_one, 2);
	std::thread t7(add_one, 3);
	// wait for the threads to finish
	t4.join();
	t5.join();
	t6.join();
	t7.join();

}