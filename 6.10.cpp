#include <iostream>

template<typename... Elements> class tuple {
	tuple() { std::cout << "a" << std::endl; }
};

template<typename Head, typename...Tail>
class tuple<Head, Tail...> : private tuple<Tail...> {
	tuple(Head head) { std::cout << head << "\t"; }
};

template<> class tuple<> {};

int main(int argc, char *argv[])
{
	tuple<int, char, float> a;

	return 0;
}
