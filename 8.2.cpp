#include <iostream>
using namespace std;

struct alignas(32) ColorVector {
	double r;
	double g;
	double b;
	double e;
};
typedef struct alignas(8){
	int a;
	char b;
} data;
int main(int argc, char *argv[])
{
	cout << sizeof(ColorVector) << endl;

	cout << alignof(ColorVector) << endl;
	//cout << offsetof(ColorVector, g) << endl;

	data* x = new data[100];

	cout << sizeof(int) << endl;
	cout << sizeof(data) << endl;
	cout << alignof(data) << endl;
	cout << hex << &x[0] << endl;
	cout << hex << &x[1] << endl;
	delete [] x;
	return 0;
}
