#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
//1012 The Best Rank sort
using namespace std;
#pragma warning(disable : 4996)
struct stu
{
	int id;
	vector<int> grade;
	stu(int id, vector<int> grade) :id(id), grade(grade) {};
};
int compare_para = 0;
char subject[] = { 'A','C','M','E' };
bool cmp(stu stu1, stu stu2)
{
	return stu1.grade[compare_para] > stu2.grade[compare_para];
}
int main()
{
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	vector<stu> student;
	unordered_map<int, pair<int, char>> best;
	for (int i = 0; i < n; i++)
	{
		int temp_id = 0;
		scanf("%d", &temp_id);
		vector<int> temp_grade(4, 0);
		for (int j = 1; j < temp_grade.size(); j++)
		{
			scanf("%d", &temp_grade[j]);
			temp_grade[0] += temp_grade[j];
		}
		student.push_back(stu(temp_id, temp_grade));
	}
	for (int i = 0; i < 4; i++)
	{
		compare_para = i;
		sort(student.begin(), student.end(), cmp);
		int curr_rank = 1;
		for (int j = 0; j < student.size(); j++)
		{
			if (j == 0)
			{
				curr_rank = 1;
			}
			else if (student[j].grade[i] != student[j - 1].grade[i])
			{
				/*
				* test point 2:
				* rank goes like: 1 2 3 3 5 instead of 1 2 3 3 4
				*/
				curr_rank = j + 1;
			}
			if (best[student[j].id].first == 0 || best[student[j].id].first > curr_rank)
			{
				best[student[j].id].first = curr_rank;
				best[student[j].id].second = subject[i];
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		int temp = 0;
		scanf("%d", &temp);
		if (best[temp].first == 0)
		{
			printf("N/A\n");
		}
		else
		{
			printf("%d %c\n", best[temp].first, best[temp].second);
		}
	}
	return 0;
}