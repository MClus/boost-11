#include <iostream>
#include <boost/mem_fn.hpp>
using namespace boost;

class demo_class
{
	public:
		int x;
		demo_class(int a = 0): x(a) {}
		void print() {
			std::cout << x << std::endl;
		}
		void hello(const char* str) {
			std::cout << str << std::endl;
		}
};

int main(int argc, char *argv[])
{
	demo_class d;
	mem_fn(&demo_class::print)(d, 10);

	demo_class *p = &d;
	mem_fn(&demo_class::hello)(p, "Hello");


	return 0;
}
