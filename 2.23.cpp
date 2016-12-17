#if __cplusplus < 201103L
	#error "should use c++11 implementation"
#endif

#include <iostream>
using namespace std;

class MathObject {
	public:
		virtual double Arith() = 0;
		virtual void Print() = 0;
};

class Printable : public MathObject {
	public:
		double Arith() = 0;
		void Print() final {
			cout << "Output is: " << Arith() << endl;
		}
};

class Add2 : public Printable {
	public:
		Add2(double a, double b) : x(a), y(b) {}
		double Arith() { return x + y;}
	private:
		double x, y;
};

class Mul3 : public Printable {
	public:
		Mul3(double a, double b, double c) : x(a), y(b), z(c) {}
		double Arith() { return x*y*z;}
	private:
		double x, y, z;
};

int main(int argc, char *argv[])
{
	Add2 b(2.0, 5.0);
	b.Print();

	Mul3 c(2.0,3.0, 5.5);
	c.Print();

	return 0;
}
