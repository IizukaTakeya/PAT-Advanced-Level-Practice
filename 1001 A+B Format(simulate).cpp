#include <iostream>
#include <string>
//1001 A+B Format simulate
#pragma warning(disable : 4996)
using namespace std;
string func(int a, int b)
{
	string ans = to_string(a + b);
	if (ans.size() >= 7 && ans[ans.size() - 7] != '-')
	{
		ans.insert(ans.size() - 6, ",");
	}
	if (ans.size() >= 4 && ans[ans.size() - 4] != '-')
	{
		ans.insert(ans.size() - 3, ",");
	}
	return ans;
}
int main()
{
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	printf("%s", func(a, b).c_str());
	return 0;
}