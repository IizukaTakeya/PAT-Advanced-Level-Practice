#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
//1014 Waiting in Line simulation
using namespace std;
#pragma warning(disable : 4996)
int main()
{
	int n = 0, m = 0, k = 0, q = 0;
	scanf("%d %d %d %d", &n, &m, &k, &q);
	vector<int> customer(k, 0), queue_time(n, 8 * 60), service_time(k, 17 * 60);
	vector<queue<int>> line(n);
	for (int i = 0; i < customer.size(); i++)
	{
		scanf("%d", &customer[i]);
		if (i < n * m)
		{
			line[i % n].push(i);
		}
		else
		{
			int next_time = 24 * 60, next_queue = -1;
			for (int j = 0; j < line.size(); j++)
			{
				if (queue_time[j] < 17 * 60 && next_time > customer[line[j].front()] + queue_time[j])
				{
					next_time = customer[line[j].front()] + queue_time[j];
					next_queue = j;
				}
			}
			if (next_queue == -1)
			{
				continue;
			}
			line[next_queue].push(i);
			service_time[line[next_queue].front()] = min(service_time[line[next_queue].front()], queue_time[next_queue]);
			queue_time[next_queue] += customer[line[next_queue].front()];
			line[next_queue].pop();
		}
	}
	for (int i = 0; i < line.size(); i++)
	{
		while (!line[i].empty() && queue_time[i] < 17 * 60)
		{
			service_time[line[i].front()] = min(service_time[line[i].front()], queue_time[i]);
			queue_time[i] += customer[line[i].front()];
			line[i].pop();
		}
	}
	for (int i = 0; i < q; i++)
	{
		int temp = 0;
		scanf("%d", &temp);
		if (service_time[temp - 1] < 17 * 60)
		{
			printf("%02d:%02d\n", (service_time[temp - 1] + customer[temp - 1]) / 60, (service_time[temp - 1] + customer[temp - 1]) % 60);
		}
		else
		{
			printf("Sorry\n");
		}
	}
	return 0;
}