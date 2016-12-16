#include <iostream>
using namespace std;

void Throw() { throw 1; }
void NoBlockThrow() {Throw();}
void BlockThrow() noexcept { Throw(); }

int main(int argc, char *argv[])
{
	try {
		Throw();
	}
	catch(...) {
		cout << "Found throw." << endl;
	}

	try {
		NoBlockThrow();
	}
	catch(...) {
		cout << "Throw is no blocked." << endl;
	}

	try {
		BlockThrow();
	}
	catch(...) {
		cout << "Found throw 1." << endl;
	}

	return 0;
}
