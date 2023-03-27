#include <algorithm>
#include <iostream>
#include <vector>
//1013 Battle Over Cities graph(dfs)
using namespace std;
#pragma warning(disable : 4996)
//pass by reference to avoid Memory Limit Exceeded
void func(vector<vector<int>> &g, vector<int>& visit, int curr_city, int invalid_city)
{
	visit[curr_city] = 1;
	for (int i = 0; i < g[curr_city].size(); i++)
	{
		if (g[curr_city][i] != invalid_city && visit[g[curr_city][i]] != 1)
		{
			func(g, visit, g[curr_city][i], invalid_city);
		}
	}
	return;
}
int main()
{
	int n = 0, m = 0, k = 0;
	scanf("%d %d %d", &n, &m, &k);
	vector<vector<int>> road(n);
	for (int i = 0; i < m; i++)
	{
		int temp1 = 0, temp2 = 0;
		scanf("%d %d", &temp1, &temp2);
		//simply change city count from 1~N to 0~N-1
		road[temp1 - 1].push_back(temp2 - 1);
		road[temp2 - 1].push_back(temp1 - 1);
	}
	for (int i = 0; i < k; i++)
	{
		vector<int> visit(n, -1);
		int city = 0, ans = 0;
		scanf("%d", &city);
		for (int j = 0; j < visit.size(); j++)
		{
			if (j != city - 1 && visit[j] == -1)
			{
				func(road, visit, j, city - 1);
				ans++;
			}
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}