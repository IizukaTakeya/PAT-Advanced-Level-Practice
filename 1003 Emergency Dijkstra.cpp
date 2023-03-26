#include <map>
#include <iostream>
#include <vector>
//1003 Emergency Dijkstra
#pragma warning(disable : 4996)
using namespace std;
const int inf = 99999999;
int main()
{
	int n = 0, m = 0, c1 = 0, c2 = 0;
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	vector<int> team(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &team[i]);
	}
	vector<vector<int>> road(n, vector<int>(n, inf));
	for (int i = 0; i < m; i++)
	{
		int temp1 = 0, temp2 = 0, temp3 = 0;
		scanf("%d %d %d", &temp1, &temp2, &temp3);
		road[temp1][temp2] = temp3;
		road[temp2][temp1] = temp3;
	}
	vector<int> visit(n, -1), distance(n, inf), road_count(n, 0), team_count(n, 0);
	team_count[c1] = team[c1];
	int curr_city = c1;
	distance[curr_city] = 0;
	road_count[curr_city] = 1;
	for (int i = 1; i < visit.size(); i++)
	{
		int temp_distance = inf;
		visit[curr_city] = 1;
		for (int j = 0; j < road[0].size(); j++)
		{
			if (distance[curr_city] + road[curr_city][j] < distance[j])
			{
				distance[j] = distance[curr_city] + road[curr_city][j];
				road_count[j] = road_count[curr_city];
				team_count[j] = team_count[curr_city] + team[j];
			}
			else if (distance[j] == distance[curr_city] + road[curr_city][j])
			{
				road_count[j] += road_count[curr_city];
				team_count[j] = max(team_count[j], team_count[curr_city] + team[j]);
			}
		}
		for (int j = 0; j < road[0].size(); j++)
		{
			if (visit[j] == -1 && distance[j] < temp_distance)
			{
				temp_distance = distance[j];
				curr_city = j;
			}
		}
	}

	printf("%d %d", road_count[c2], team_count[c2]);

	return 0;
}