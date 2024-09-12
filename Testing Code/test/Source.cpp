#include <iostream>
#include <string>
#include <cctype>


using namespace std;

int main() {
	string userString;

	getline(cin, userString);

	if (tolower(userString.at(0)) == tolower(userString.at(1)))
		cout << "Valid string" << endl;
	else
		cout << "Invalid string" << endl;

	return 0;
}