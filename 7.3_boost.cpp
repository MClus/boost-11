#include <iostream>
#include <typeinfo>
#include <boost/utility.hpp>
#include <boost/functional/factory.hpp>
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
	mem_fn(&demo_class::print)(d);

	demo_class *p = &d;
	mem_fn(&demo_class::hello)(p, "Hello");

	auto q = factory<demo_class*>()();
	std::cout << typeid(q).name() << std::endl;
	q->print();
	mem_fn(&demo_class::hello)(q, "hellp world!");
	//checked_delete(p);
	checked_delete(q);
	return 0;
}
