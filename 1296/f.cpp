#include <bits/stdc++.h>
using namespace std;

struct Query
{
	int a, b;
	Query(){}
	Query(int _a, int _b)
	{
		a = _a; b = _b;
	}
};

int n, m;
vector<int> vec[5008];
Query _[5008];
int fa[5008], lca[5008][5008];
vector<Query> query[1000008];
int ans[5008][5008];
vector<int> dfs(int cur, int pre)
{
	vector<int> ret;
	ret.push_back(cur);
	vector<vector<int>> vv;
	for (auto nxt: vec[cur])
	{
		if (nxt == pre)
			continue;
		fa[nxt] = cur;
		vector<int> tmp = dfs(nxt, cur);
		for (auto x: tmp)
			ret.push_back(x);
		vv.push_back(tmp);
	}
	for (int i = 0; i < vv.size(); ++i)
		for (int j = i + 1; j < vv.size(); ++j)
			for (auto x: vv[i])
				for (auto y: vv[j])
					lca[x][y] = lca[y][x] = cur;
	for (auto x: ret)
		lca[x][cur] = lca[cur][x] = cur;
	return ret;
}

bool gao()
{
	for (int val = 1000000; val >= 1; --val)
	{
		for (auto q: query[val])
		{
			int l = lca[q.a][q.b];
			int cur = q.a;
			while (cur != l)
			{
				if (!ans[cur][fa[cur]])
				{
					//cout << cur << " tt " << fa[cur] << endl;
					ans[cur][fa[cur]] = ans[fa[cur]][cur] = val;
				}
				cur = fa[cur];
			}
			cur = q.b;
			while (cur != l)
			{
				if (!ans[cur][fa[cur]])
				{
					//cout << cur << " tt " << fa[cur] << endl;
					ans[cur][fa[cur]] = ans[fa[cur]][cur] = val;
				}
				cur = fa[cur];
			}
		}
	}
	for (int val = 1000000; val >= 1; --val)
	{
		for (auto q: query[val])
		{
			int mn = 1000000007;
			//cout << q.a << "  " << q.b << "  " << val << endl;
			int l = lca[q.a][q.b];
			//cout << "lca = " << l << endl;
			int cur = q.a;
			while (cur != l)
			{
				if (ans[cur][fa[cur]] == 0)
					ans[cur][fa[cur]] = 1000000;
				mn = min(mn, ans[cur][fa[cur]]);
				cur = fa[cur];
			}
			cur = q.b;
			while (cur != l)
			{
				if (ans[cur][fa[cur]] == 0)
					ans[cur][fa[cur]] = 1000000;
				mn = min(mn, ans[cur][fa[cur]]);
				cur = fa[cur];
			}
			if (mn != val)
				return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
		_[i] = Query(a, b);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
	{
		int a, b, v;
		scanf("%d %d %d", &a, &b, &v);
		query[v].push_back(Query(a, b));
	}
	dfs(1, 0);
	if (!gao())
		printf("-1\n");
	else
	{
		for (int i = 1; i < n; ++i)
		{
			if (!ans[_[i].a][_[i].b])
				ans[_[i].a][_[i].b] = 1000000;
			printf("%d%c", ans[_[i].a][_[i].b], " \n"[i == n - 1]);
		}
	}
}