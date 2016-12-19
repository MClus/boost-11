#include <iostream>
#include <type_traits>
using namespace std;

struct Copyable {
	Copyable() {}
	Copyable(const Copyable &o) {
		cout << "Copied" << endl;
	}
};

Copyable ReturnRvalue() 
{
	return Copyable();
}

void AcceptVal(Copyable) {}
void AcceptRef(Copyable && a) {
	cout << is_rvalue_reference
}

int main(int argc, char *argv[])
{
	cout << "Pass by value: " << endl;
	AcceptVal(ReturnRvalue());
	cout << "Pass by reference: " << endl;
	AcceptRef(ReturnRvalue());

	return 0;
}
