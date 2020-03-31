#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> vec[26];
struct Node
{
	char c;
	int id;
	int col;
	Node(){}
	Node(char _c, int _id, int _col)
	{
		c = _c; id = _id; col = _col;
	}
};
char str[208];
Node arr[208];
int color[208];
bool mp[208][208];

bool gao()
{
	for (int i = 1; i <= n; ++i)
	{
		if (!color[i])
		{
			color[i] = 1;
			queue<int> que;
			que.push(i);
			while (!que.empty())
			{
				int x = que.front();
				que.pop();
				for (int j = 1; j <= n; ++j)
				{
					if (mp[x][j])
					{
						if (color[j])
						{
							if (color[j] == color[x])
								return false;
						}
						else
						{
							color[j] = (color[x] == 1?2:1);
							que.push(j);
						}
					}
				}
			}
		}
	}
	return true;
}

int main()
{
	scanf("%d %s", &n, str + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i - 1; j >= 1; --j)
		{
			if (str[j] > str[i])
				mp[i][j] = mp[j][i] = true;
		}
	}
	if (gao())
	{
		printf("YES\n");
		for (int i = 1; i <= n; ++i)
			printf("%d", color[i] - 1);
	}
	else
		printf("NO\n");
}