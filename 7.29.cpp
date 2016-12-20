#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums;
vector<int> largeNums;

const int ubound = 10;

inline void LargeNumsFunc(int i) {
	if (i > ubound)
		largeNums.push_back(i);
}

void Above() {
	for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
		if (*itr > ubound)
			largeNums.push_back(*itr);
	}
	
	for_each(nums.begin(), nums.end(), LargeNumsFunc);

	for_each(nums.begin(), nums.end(), [=](int i) {
			if (i > ubound)
			largeNums.push_back(i);
			});
}
