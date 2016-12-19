#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

enum Gender {boy, girl};
class People {
	public:
		People(initializer_list<pair<string, Gender>> l) {
			for (auto it = l.begin(); it != l.end(); ++it) {
				data.push_back(*it);
			}
		}

		void Print() {
			for (auto it = data.begin(); it != data.end(); ++it) {
				cout << it->first << ":\t\t" << it->second << endl;
			}
		}
	private:
		vector<pair<string, Gender>> data;
};

class MyPeople : public People {
	public:
		MyPeople(initializer_list<pair<string, Gender>> l): People(l) {}
		void Print() {
			cout << "This is a test." << endl;
		}
};

int main(int argc, char *argv[])
{
	People* p;
	MyPeople ship{{"Garfield", boy}, {"HelloKitty", girl}};
	p = &ship;
	p->Print();

	return 0;
}
			
			
