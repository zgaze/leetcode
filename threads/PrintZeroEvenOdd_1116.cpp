/* ***********************************************************************

  > File Name: PrintZeroEvenOdd_1116.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 10 Aug 2019 02:06:50 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <gtest/gtest.h>

using std::vector;
using std::string;
using std::function;

class ZeroEvenOdd {
private:
    int n;
    std::mutex mu;
    std::condition_variable cv1;
    bool volatile is_zero = true;
	int counter = 0;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
	void zero(function<void(int)> printNumber) {
		for(int i = 0; i < n; ++i) {
			std::unique_lock<std::mutex> locker(mu);
			cv1.wait(locker, [this](){return this->is_zero || counter >= n;});
			counter ++;
			printNumber(0);
			is_zero = false;
			cv1.notify_all();
		}
	}

	void even(function<void(int)> printNumber) {
		for(int i = 0; i < n/2; ++i) {
			std::unique_lock<std::mutex> locker(mu);
			cv1.wait(locker, [this](){return !this->is_zero && this->counter % 2 == 0;}); 
			printNumber(counter);
			is_zero = true;
			cv1.notify_all(); 
		}
	}

	void odd(function<void(int)> printNumber) {
		for(int i = 0; i < (n + 1)/2; ++i) {
			std::unique_lock<std::mutex> locker(mu);
			cv1.wait(locker, [this](){return !this->is_zero && this->counter % 2 == 1;});  
			printNumber(counter);
			is_zero = true;
			cv1.notify_all();
		}
	}
};

void printNumber(int n) 
{
	printf("%d \n", n);
}

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
	ZeroEvenOdd zeo(10);
	std::thread t1(&ZeroEvenOdd::zero, &zeo, printNumber);
	std::thread t2(&ZeroEvenOdd::even, &zeo, printNumber);
	std::thread t3(&ZeroEvenOdd::odd, &zeo, printNumber);
	t1.join();
	t2.join();
	t3.join();
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

