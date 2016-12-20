#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T1, typename T2>
auto sum(T1& t1, T2& t2)->decltype(t1 + t2) {
	return t1 + t2;
}

int main(int argc, char *argv[])
{
	int a = 3;
	long b = 5;
	float c = 1.0f, d = 2.3f;

	auto e = sum(a, b);
	cout << e << "\t" << typeid(e).name() << endl;	
	auto f = sum(c, d);
	cout << f << "\t" << typeid(f).name() << endl;
	
	cout << (typeid(e).hash_code() == typeid(f).hash_code()) << endl;

	return 0;
}
