#include <atomic>
#include <thread>
#include <iostream>
using namespace std;
typedef struct {
	int a[10];
}intVec;

atomic_llong total {0};
void func(int) {
	for (long long i = 0; i < 100000000LL; ++i) {
		total += i;
	}
}

int main(int argc, char *argv[])
{
	intVec x;
	
	thread t1(func, 0);
	thread t2(func, 0);

	t1.join();
	t2.join();
	cout << total << endl;

	return 0;
}
	
