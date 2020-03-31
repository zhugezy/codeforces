#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> nxt[200008];
int c[200008];
int d[200008];
int fa[200008];
int dd[200008];
void dfs(int cur, int pre)
{
	fa[cur] = pre;
	d[cur] = d[pre] + 1;
	for (auto x: nxt[cur])
	{
		if (x == pre)
			continue;
		dfs(x, cur);
	}
}

bool dfs2(int cur, int pre)
{
	dd[cur] = dd[pre] + 1;
	for (auto x: nxt[cur])
	{
		if (x == pre)
			continue;
		dfs2(x, cur);
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		nxt[u].push_back(v);
		nxt[v].push_back(u);
	}
	if (m == 1)
	{
		scanf("%d", &c[1]);
		printf("YES\n1\n");
		return 0;
	}
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &c[i]);
	}
	d[0] = -1;
	dfs(c[1], 0);
	int a, mx = -1;
	for (int i = 1; i <= m; ++i)
	{
		if (d[c[i]] > mx)
		{
			mx = d[c[i]];
			a = c[i];
		}
	}
	d[0] = -1;
	dfs(a, 0);
	int b;
	mx = -1;
	int len;
	for (int i = 1; i <= m; ++i)
	{
		if (d[c[i]] > mx)
		{
			mx = d[c[i]];
			len = d[c[i]] - 1;
			b = c[i];
		}
	}
	int cnt = 0;
	int cur = b;
	while (cur)
	{
		if (cnt == len / 2 || cnt == len / 2 - 1 || cnt == len / 2 + 1)
		{
			dfs2(cur, 0);
			int i;
			for (i = 2; i <= m; ++i)
			{
				if (dd[c[i]] != dd[c[1]])
					break;
			}
			if (i > m)
			{
				printf("YES\n%d\n", cur);
				return 0;
			}
		}
		cnt++;
		cur = fa[cur];
	}
	printf("NO\n");
	return 0;
}