#include <iostream>
using namespace std;

struct A {
	A(int i) { cout << "int" << endl; }
	A(double d, int i) {cout << "doubel_int" << endl; }
	A(float f, int i, const char* c) { cout << "float_int_const" << endl;}
};

struct B : public A {
	using A::A;
	B(int i, float f):A(i), d(f) {cout << "B_INT_F" << endl;}
	float d{0.0};
};

int main(int argc, char *argv[])
{
	B b(356);

	return 0;
}
