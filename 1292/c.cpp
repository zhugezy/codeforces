#include <bits/stdc++.h>
using namespace std;
int n;

int siz[3008];

struct Edge
{
	int u, v, val;
	Edge(){}
	Edge(int _u, int _v, int _val)
	{
		u = _u; v = _v; val = _val;
	}
};
vector<Edge> mp[3008];
struct Node
{
	int id, val;
	Node(){}
	Node(int _i, int _v)
	{
		id = _i; val = _v;
	}
	bool operator<(const Node& oth) const
	{
		if (val != oth.val)
			return val > oth.val;
		return id < oth.id;
	}
};
Node arr[3008];
int dfs(int pre, int cur)
{
	int tot = 1;
	for (auto e: mp[cur])
	{
		if (e.v != pre)
			tot += dfs(cur, e.v);
	}
	return siz[cur] = tot;
}

int ans[3008];
Edge edges[3008];
void dfs2(int pre, int cur)
{
	for (int i = 0; i < mp[cur].size(); ++i)
	{
		if (mp[cur][i].v != pre)
		{
			mp[cur][i].val = ans[mp[cur][i].v];
			//cout << mp[cur][i].u << "  " << mp[cur][i].v << "  " << mp[cur][i].val << endl;
			edges[mp[cur][i].val] = Edge(mp[cur][i].u, mp[cur][i].v, mp[cur][i].val);
			dfs2(cur, mp[cur][i].v);
		}
	}
}

long long res = 0;
int dfs3(int pre, int cur, int M)
{
	int tot = 1;
	for (auto e: mp[cur])
	{
		if (e.v != pre && e.val >= M)
			tot += dfs3(cur, e.v, M);
	}
	return tot;
}

int dfs4(int pre, int cur, int uu, int vv)
{
	int tot = 1;
	for (auto e: mp[cur])
	{
		if (e.v != pre && (min(e.v, cur) != min(uu, vv) || max(e.v, cur) != max(uu, vv)))
			tot += dfs4(cur, e.v, uu, vv);
	}
	return tot;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		mp[x].push_back(Edge(x, y, 0));
		mp[y].push_back(Edge(y, x, 0));
	}
	dfs(0, 1);
	for (int i = 2; i <= n; ++i)
	{
		arr[i] = Node(i, siz[i] * (n - siz[i]));
	}
	sort(arr + 2, arr + n + 1);
	for (int i = 2; i <= n; ++i)
		ans[arr[i].id] = i - 2;
	dfs2(0, 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int u = edges[i].u, v = edges[i].v;
		res += dfs4(0, u, u, v) * dfs4(0, v, u, v) - dfs3(0, u, i + 1) * dfs3(0, v, i + 1);
		cout << dfs4(0, u, u, v) * dfs4(0, v, u, v) << "  " << dfs3(0, u, i + 1) * dfs3(0, v, i + 1) << endl;
	}
	cout << res << endl;
}