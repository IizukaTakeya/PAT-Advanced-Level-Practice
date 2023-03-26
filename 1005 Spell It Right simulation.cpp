#include <string>
#include <iostream>
#include <vector>
//1005 Spell It Right simulation
using namespace std;
#pragma warning(disable : 4996)
string spell[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void func(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (i > 0)
		{
			printf(" ");
		}
		printf("%s", spell[s[i] - '0'].c_str());
	}
}
int main()
{
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		ans += s[i] - '0';
	}
	func(to_string(ans));
	return 0;
}