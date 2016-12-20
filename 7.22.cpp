#include <iostream>
#include <type_traits>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

class AirportPrice {
	private:
		float _dutyfreerate;
	public:
		AirportPrice() = default;
		AirportPrice(float rate): _dutyfreerate(rate) {}

		float operator()(float price) {
			return price * (1 - _dutyfreerate/100);
		}
};

int main(int argc, char *argv[])
{
	float tax_rate = 5.5f;
	AirportPrice Changi(tax_rate);

	auto changi2 = [tax_rate](float price) ->float{
		return price * (1 - tax_rate/100);
	};

	cout << is_pod<AirportPrice>::value << endl;
	float purchased = Changi(3699);
	cout << purchased << endl;
	float purchased2 = changi2(2899);
	cout << purchased2 << endl;

	vector<int> data;
	for (int i = 1; i < 10; ++i)
		data.push_back(i);

	auto forSor = [](int t1, int t2) ->bool {
		return t1 > t2;
	};

	sort(data.begin(), data.end(), forSor);

	for (auto a : data)
		cout << a << endl;
	return 0;
}
