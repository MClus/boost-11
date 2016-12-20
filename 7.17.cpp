#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int girls = 3, boys = 4;

	auto totalChild = [](int a, int b) ->decltype(a){ return a + b; };
	cout << totalChild(girls, boys) << endl;

	return 0;
}
