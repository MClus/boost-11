#include <iostream>
#include <boost/utility.hpp>
using namespace boost;
class dome;
void del_dome(dome* p) { checked_deleter<dome>()(p);	}

class dome {
	public:
		~dome () { std::cout << "delete dome!" << std::endl;	};
};

int main(int argc, char *argv[])
{
//	int* p = new int(10);
//
//	auto parr = new int[10];
//
//	//checked_delete(p);
//	//checked_delete(p);
//	delete p;
//	delete p;
//	checked_array_delete(parr);

	auto p = new dome;
	del_dome(p);
	return 0;
}
