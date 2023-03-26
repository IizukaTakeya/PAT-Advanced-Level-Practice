#include <map>
#include <iostream>
#include <vector>
//1002 A+B for Polynomials simulate
using namespace std;
int main()
{
	map<int, double> polynomial;
	int k1 = 0;
	scanf("%d", &k1);
	for (int i = 0; i < k1; i++)
	{
		int n = 0;
		double a = 0;
		scanf("%d %lf", &n, &a);
		polynomial[n] += a;
	}
	int k2 = 0;
	scanf("%d", &k2);
	for (int i = 0; i < k2; i++)
	{
		int n = 0;
		double a = 0;
		scanf("%d %lf", &n, &a);
		polynomial[n] += a;
	}
	/*
	* test point: 3 4 5 6 
	* input:
	* 1 1 0
	* 0
	* output:
	* 0
	*/
	int ZeroCount = 0;
	for (auto it = polynomial.rbegin(); it != polynomial.rend(); it++)
	{
		if (it->second == 0)
		{
			ZeroCount++;
		}
	}
	printf("%d", polynomial.size() - ZeroCount);
	for (auto it = polynomial.rbegin(); it != polynomial.rend(); it++)
	{
		if (it->second != 0)
		{
			printf(" %d %.1lf", it->first, it->second);
		}
	}
	printf("\n");
	return 0;
}