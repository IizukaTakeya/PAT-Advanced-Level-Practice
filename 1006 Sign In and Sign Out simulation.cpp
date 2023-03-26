#include <string>
#include <iostream>
#include <vector>
//1006 Sign In and Sign Out simulation
using namespace std;
#pragma warning(disable : 4996)
int main()
{
	int m = 0;
	scanf("%d", &m);
	string open_time, close_time, open_id, close_id;
	for (int i = 0; i < m; i++)
	{
		string temp1, temp2, temp3;
		cin >> temp1 >> temp2 >> temp3;
		if (open_time.empty() || temp2 < open_time)
		{
			open_id = temp1;
			open_time = temp2;
		}
		if (close_time.empty() || temp3 > close_time)
		{
			close_id = temp1;
			close_time = temp3;
		}
	}
	printf("%s %s", open_id.c_str(), close_id.c_str());
	return 0;
}