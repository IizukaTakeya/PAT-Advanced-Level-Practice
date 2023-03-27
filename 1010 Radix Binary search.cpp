#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <climits>
//1010 Radix Binary search
using namespace std;
#pragma warning(disable : 4996)
long long getValue(string s, string idx)
{
	long long ans = 0, count = 1, index = 0;
	if (isdigit(idx[0]))
	{
		index = stoll(idx);
	}
	else
	{
		index = idx[0] - 'a' + 10;
	}
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (isdigit(s[i]))
		{
			ans += (s[i] - '0') * count;
		}
		if (islower(s[i]))
		{
			ans += (s[i] - 'a' + 10) * count;
		}
		count *= index;
	}
	return ans;
}
int main()
{
	string n1, n2, radix;
	long long tag = 0, ans = LLONG_MAX;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 2)
	{
		swap(n1, n2);
	}
	char left_char = *max_element(n2.begin(), n2.end());
	long long left = (isdigit(left_char) ? left_char - '0' : left_char - 'a' + 10) + 1;
	long long right = max(left, getValue(n1, radix)) + 1;
	long long next = 0;
	while (left < right)
	{
		next = (left + right) / 2;
		if (getValue(n1, radix) == getValue(n2, to_string(next)))
		{
			ans = min(ans, next);
			right = next;
		}
		else if (getValue(n2, to_string(next)) > 0 && getValue(n1, radix) > getValue(n2, to_string(next)))
		{
			left = next + 1;
		}
		else
		{
			right = next;
		}
	}
	next = (left + right) / 2;
	if (getValue(n1, radix) == getValue(n2, to_string(next)))
	{
		ans = min(ans, next);
	}
	if (ans != LLONG_MAX)
	{
		printf("%d", ans);
	}
	else
	{
		printf("Impossible");
	}
	return 0;
}