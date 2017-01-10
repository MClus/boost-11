#include <iostream>
#include <typeinfo>
#include <cassert>
#include <type_traits>
#include <utility>
#include <boost/type_traits.hpp>
#include <boost/compressed_pair.hpp>
using namespace boost;

class empty {
};

template<typename T1, typename T2>
compressed_pair<T1, T2> make_compressed_pair(T1 t1, T2 t2) {
	return compressed_pair<T1, T2>(t1, t2);
}

int main(int argc, char *argv[])
{
	//static_assert(sizeof(empty) == 2, "this cper is not a char for empty");
//	if (is_class<empty>::value && is_empty<empty>::value) {
//		std::cout << "Empty class!" << std::endl;
//	}
//
//	stif (id::cout << sizeof(compressed_pair<int, empty>) << std::endl;
//	stif (id::cout << sizeof(std::pair<int, empty>) << std::endl;
//	stif (id::cout << sizeof(std::pair<empty, empty>) << std::endl;
//	stif (id::cout << sizeof(std::pair<empty, empty>) << std::endl;

	auto cp1 = make_compressed_pair(10, "char*");
	auto cp2 = std::move(make_compressed_pair(3.14, nullptr));

	std::cout << typeid(cp1).hash_code() << std::endl;
	std::cout << typeid(cp2).hash_code() << std::endl;
	return 0;
}
