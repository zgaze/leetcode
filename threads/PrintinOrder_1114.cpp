/* ***********************************************************************

  > File Name: PrintinOrder_1114.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 08 Aug 2019 06:45:53 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <thread>
#include <gtest/gtest.h>

using std::vector;
using std::string;
using std::function;

class Foo {
public:
	std::mutex mu;
	int counter = 1;
	std::condition_variable cv1;
    Foo() {
        
    }

    void first() {
		while(1) {
        std::unique_lock<std::mutex> locker(mu);
        // printFirst() outputs "first". Do not change or remove this line.
        //printFirst();
		cv1.wait(locker, [this](){return this->counter == 1;});
		printf("11111 \n");
		counter = 2;
        cv1.notify_all();
		}
    }

    //void second(function<void()> printSecond) {
    void second() {
		while (1) {
        std::unique_lock<std::mutex> locker(mu);
        cv1.wait(locker, [this]{return this->counter == 2;});
        // printSecond() outputs "second". Do not change or remove this line.
        //printSecond();
		printf("222222 \n");
		counter = 3;
        cv1.notify_all();
		}
    }

    void third() {
		while (1) {
        std::unique_lock<std::mutex> locker(mu);
        cv1.wait(locker, [this]{return this->counter == 3;});
        // printThird() outputs "third". Do not change or remove this line.
        //printThird();
		printf("3333333 \n");
		counter = 1;
		cv1.notify_all();
		}
    }
};


TEST(testCase,test0) {

}

void print1() {
	printf("111 \n");
}
void print2() {
	printf("222 \n");
}

void print3() {
	printf("333 \n");
}


int main(int argc, char* argv[]) {
	Foo f;
	//std::function<void()> f1 = print1;
	//std::function<void()> f2 = print2;
	//std::function<void()> f3 = print3;
	std::thread h1(&Foo::first, std::ref(f));
	std::thread h2(&Foo::second, std::ref(f));
	std::thread h3(&Foo::third, std::ref(f));
	h1.join();
	h2.join();
	h3.join();
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

