#include <iostream>
#include <vector>
#include <string>
//1015 Reversible Primes simulation
using namespace std;
#pragma warning(disable : 4996)
bool isPrime(int n)
{
	if (n <= 1)
	{
		return false;
	}
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	while (true)
	{
		int n = 0;
		scanf("%d", &n);
		if (n < 0)
		{
			return 0;
		}
		int d = 0;
		scanf("%d", &d);
		if (isPrime(n))
		{
			string temps;
			while (n > 0)
			{
				temps += to_string(n % d);
				n /= d;
			}
			if (isPrime(stoi(temps, 0, d)))
			{
				printf("Yes\n");
				continue;
			}
		}
		printf("No\n");
	}
	return 0;
}