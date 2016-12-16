#include <cstring>
using namespace std;

template <typename T, typename U>
	int bit_copy(T& a, U& b) {
		static_assert(sizeof(a) == sizeof(b),
				"the parameters of bit_copy must have same width.");
		memcpy(&a, &b, sizeof(b));
	}

int main(int argc, char *argv[])
{
	int a = 0x2468;
	int b;
	bit_copy(a, b);

	return 0;
}
