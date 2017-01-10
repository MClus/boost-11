#include <unordered_set>
#include <iostream>
#include <string>
#include <boost/functional/hash.hpp>
using namespace boost;

class person final {
	private:
		int id;
		std::string name;
		unsigned int age;
	public:
		person(int a, const char* b, unsigned int c):
			id(a), name(b), age(c){};
		size_t hash_value() const {
			size_t seed = 2017;
			hash_combine(seed, id);
			hash_combine(seed, name);
			hash_combine(seed, age);
			return seed;
		}

		friend bool operator==(person const& l, person const& r) {
			return l.id == r.id;
		}
};

size_t hash_value(person const& p) {
	return p.hash_value();
}

int main(int argc, char *argv[])
{
	std::cout << hash<int>()(8) << std::endl;
	std::cout << hash<double>()(2.563) << std::endl;
	std::cout << hash<const char*>()("string") << std::endl;
	std::cout << hash<const char*>()("String") << std::endl;

	person p1(1, "adam", 20);
	person p2(2, "eva", 20);
	std::cout << hash<person>()(p1) << std::endl;
	std::cout << hash<person>()(p2) << std::endl;

//	std::unordered_set<person> us;
//	us.insert(p1);
//	us.insert(p2);
//	std::cout << us.size() << std::endl;
	return 0;
}
