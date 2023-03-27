#include <algorithm>
#include <iostream>
#include <vector>
//1011 World Cup Betting simulation
using namespace std;
#pragma warning(disable : 4996)
int main()
{
	char result[] = { 'W', 'T', 'L' };
	double win = 0, tie = 0, lose = 0, gain = 0.65;
	for (int i = 0; i < 3; i++)
	{
		vector<double> rate(3);
		scanf("%lf %lf %lf", &rate[0], &rate[1], &rate[2]);
		for (int j = 0; j < rate.size(); j++)
		{
			if (rate[j] == *max_element(rate.begin(), rate.end()))
			{
				printf("%c ", result[j]);
				break;
			}
		}
		gain *= *max_element(rate.begin(), rate.end());
	}
	printf("%.2lf", (gain - 1) * 2);
	return 0;
}