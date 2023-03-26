#include <iostream>
#include <map>
//1009 Product of Polynomials simulation
using namespace std;
#pragma warning(disable : 4996)
map<int, double> a, ans;
int main()
{
	int k1 = 0;
	scanf("%d", &k1);
	for (int i = 0; i < k1; i++)
	{
		int n = 0;
		double d = 0.0;
		scanf("%d %lf", &n, &d);
		a[n] += d;
	}
	int k2 = 0;
	scanf("%d", &k2);
	for (int i = 0; i < k2; i++)
	{
		int n = 0;
		double d = 0.0;
		scanf("%d %lf", &n, &d);
		for (auto it = a.begin(); it != a.end(); it++)
		{
			ans[it->first + n] += it->second * d;
		}
	}
	int zero_count = 0;
	for (auto it = ans.rbegin(); it != ans.rend(); it++)
	{
		if (it->second == 0.0)
		{
			zero_count++;
		}
	}
	printf("%d", ans.size() - zero_count);
	for (auto it = ans.rbegin(); it != ans.rend(); it++)
	{
		if (it->second != 0.0)
		{
			printf(" %d %.1lf", it->first, it->second);
		}
	}
	return 0;
}