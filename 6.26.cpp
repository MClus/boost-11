#include <thread>
#include <iostream>
#include <atomic>
#include <cassert>
#include <string>
using namespace std;

atomic<string*> ptr;
atomic<int> data;

void Producer() {
	string* p = new string("Hello");
	data.store(42, memory_order_relaxed);
	ptr.store(p, memory_order_release);
}

void Consumer() {
	string* p2;
	while (!(p2 = ptr.load(memory_order_consume)))
		;
	assert(*p2 == "Hello");
	cout << *p2 << endl;
	assert(data.load(memory_order_relaxed) == 42);
	cout << data << endl;
}

int main(int argc, char *argv[])
{
	thread t1(Producer);
	thread t2(Consumer);

	t1.join();
	t2.join();

	return 0;
}