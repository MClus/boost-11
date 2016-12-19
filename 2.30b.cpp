#include "exterTemp.hpp"

using namespace std;

extern void tryA();
extern template int sum<int>(int, int);

int main(int argc, char *argv[])
{
	tryA();
	cout << sum(2, 6) << endl;

	return 0;
}
