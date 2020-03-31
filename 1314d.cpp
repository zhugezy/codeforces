#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
using namespace std;
int n, k;
int mp[84][84];
vector<pii> mn[84][84];
int c[12];
int ans = 0x3f3f3f3f;

bool in(int x)
{
	for (int i = 2; i <= k - 1; i += 2)
	{
		if (x == c[i])
			return true;
	}
	return false;
}

int find(int j)
{
	for (auto p: mn[c[j - 2]][c[j]])
	{
		if (!in(p.second))
			return p.first;
	}
	return 200020000;
}
void dfs(int cur)
{
	if (cur >= k)
	{
		/*for (int j = 0; j <= k; ++j)
		{
			cout << c[j] << "  ";
		}
		cout << endl;*/
		int temp = 0;
		for (int j = 2; j <= k; j += 2)
		{
			temp += find(j);
		}
		//cout << temp << endl;
		ans = min(ans, temp);
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			c[cur] = i;
			dfs(cur + 2);
		}
	}
	
	
}


int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> mp[i][j];
	}
	for (int a = 0; a < n; ++a)
	{
		for (int b = 0; b < n; ++b)
		{
			for (int c = 0; c < n; ++c)
			{
				if (c == a || c == b)
					continue;
				mn[a][b].eb(mp[a][c] + mp[c][b], c);	
			}
			sort(mn[a][b].begin(), mn[a][b].end());
		}
	}
	dfs(2);
	cout << ans << endl;
}
