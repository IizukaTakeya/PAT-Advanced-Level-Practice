#include <iostream>
//1008 Elevator simulation
using namespace std;
#pragma warning(disable : 4996)
int main()
{
	int n = 0, total_time = 0, curr_floor = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		total_time += 5;
		int next_floor = 0;
		scanf("%d", &next_floor);
		next_floor > curr_floor ? total_time += 6 * (next_floor - curr_floor) : total_time += 4 * (curr_floor - next_floor);
		curr_floor = next_floor;
	}
	printf("%d", total_time);
	return 0;
}