#include <map>
#include <iostream>
#include <vector>
//1004 Counting Leaves DFS
using namespace std;
#pragma warning(disable : 4996)
int max_depth = 0;
void dfs(int curr_node, int curr_depth, vector<vector<int>> tree, vector<int>& ans)
{
	max_depth = max(max_depth, curr_depth);
	if (tree[curr_node].empty())
	{
		ans[curr_depth]++;
		return;
	}
	for (int i = 0; i < tree[curr_node].size(); i++)
	{
		dfs(tree[curr_node][i], curr_depth + 1, tree, ans);
	}
}
int main()
{
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	vector<vector<int>> tree(100);
	for (int i = 0; i < m; i++)
	{
		int temp1 = 0, temp2 = 0;
		scanf("%d %d", &temp1, &temp2);
		for (int j = 0; j < temp2; j++)
		{
			int temp3 = 0;
			scanf("%d", &temp3);
			tree[temp1].push_back(temp3);
		}
	}
	vector<int> ans(100, 0);
	dfs(1, 0, tree, ans);
	for (int i = 0; i <= max_depth; i++)
	{
		if (i > 0)
		{
			printf(" ");
		}
		printf("%d", ans[i]);
	}
	return 0;
}