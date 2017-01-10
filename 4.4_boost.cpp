#include <iostream>
#include <complex>
#include <boost/utility.hpp>
using namespace std;
using namespace boost;

class base {
	public:
		base(complex<int> c) {
			cout << "base actor:\t" << c << endl;
		}
};

class derived:
	private base_from_member<complex<int>>, public base{
		typedef base_from_member<complex<int>> pbase_type;
	public:
		derived(int a, int b): pbase_type(a, b), base(member) {
			cout << "derived actor:\t" << member << endl;
		}
};

int main(int argc, char *argv[])
{
	derived(10, 20);

	return 0;
}
