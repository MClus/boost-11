#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	cout << "Standard Clib: " << __STDC_HOSTED__ << endl;

	cout << "Standard C: " << __STDC__  << endl;

	//cout << "ISO/IEC: " << __STD_ISO_10646__ << endl;

	return 0;
}
