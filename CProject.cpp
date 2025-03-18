#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string email;
	string comp="%20";
	string phrase = "%20*%20* FROM : student123456@atu.ie %20*%20";
	int i=0;
	int count = 0;
	int find;

	email = phrase.substr(16, 20);
	cout << "The message is from: " << email << endl;

	for (i = 0; i < phrase.length(); i++)
	{
		find = phrase.find(comp, i);
		if (find == i)
		{
			count++;
		}
	}
	cout << "The substring %20 occurs " << count << " times";

	return 0;
}