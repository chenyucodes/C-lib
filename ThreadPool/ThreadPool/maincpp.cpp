#include <iostream>
#include "threadpool.h"
#include <future>
#include <thread>
#include <chrono>

using UL = unsigned long long ;

UL sun(UL begin, UL end) {
	int sum = 0;
	for (int i = begin; i <= end; i++) {
		sum += i;
	}
	return sum;
}

int main() {
	
	ThreadPool pool;
	pool.setMode(PoolMode::MODE_FIXED);
	pool.start(4);

	std::future<UL> res1 = pool.submitTask(sun, 1, 1000);
	std::future<UL> res2 = pool.submitTask(sun, 1000, 2000);
	std::future<UL> res3 = pool.submitTask(sun, 2000, 3000);
	std::future<UL> res4 = pool.submitTask(sun, 3000, 4000);
	
	UL r1 = res1.get();
	UL r2 = res2.get();
	UL r3 = res3.get();
	UL r4 = res4.get();
	UL sum = r1 + r2 + r3 + r4;

	std::this_thread::sleep_for(std::chrono::seconds(2));

	std::cout << r1 << " + " << r2 << " + " << r3 << " + " << r4 << std::endl;
	std::cout << "result: " << sum << std::endl;

	getchar();

	return 0;
}
