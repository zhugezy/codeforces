#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, vector<int>> mp;
char s[200008];
int n;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		mp.clear();
		scanf("%d %s", &n, s + 1);
		int x = 0, y = 0;
		mp[make_pair(x, y)].push_back(0);
		int i;
		for (i = 1; i <= n; ++i)
		{
			if (s[i] == 'L')
				y--;
			else if (s[i] == 'R')
				y++;
			else if (s[i] == 'U')
				x--;
			else
				x++;
			mp[make_pair(x, y)].push_back(i);
		}
		int a1 = -1, a2 = -1, mn = 300008;
		for (auto x: mp)
		{
			for (int i = 0; i + 1 < x.second.size(); ++i)
			{
				if (x.second[i + 1] - x.second[i] <= mn)
				{
					mn = x.second[i + 1] - x.second[i];
					a1 = x.second[i], a2 = x.second[i + 1];
				}
			}
		}
		if (a1 < 0)
			printf("-1\n");
		else
			printf("%d %d\n", a1 + 1, a2);
	}
}