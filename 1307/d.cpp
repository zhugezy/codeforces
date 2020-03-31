#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define a first
#define b second
using namespace std;

bool cmp(const pii& x, const pii& y)
{
	return x.a - x.b < y.a - y.b;
}


int n, m, k;
int p[200008];
pii t[200008];
pii tt[200008];
vector<int> mp[200008];
int mx[200008];
void bfs1()
{
	queue<int> que;
	que.push(1);
	while (!que.empty())
	{
		int c = que.front();
		que.pop();
		for (auto nxt: mp[c])
		{
			if (nxt != 1 && !t[nxt].a)
			{
				que.push(nxt);
				t[nxt].a = t[c].a + 1;
			}
		}
	}
}

void bfs2()
{
	queue<int> que;
	que.push(n);
	while (!que.empty())
	{
		int c = que.front();
		que.pop();
		for (auto nxt: mp[c])
		{
			if (nxt != n && !t[nxt].b)
			{
				que.push(nxt);
				t[nxt].b = t[c].b + 1;
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; ++i)
		scanf("%d", &p[i]);
	for (int i = 1; i <= m; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	bfs1();
	bfs2();
	int id = 0, mxa = -1, mxb = -1;
	for (int i = 1; i <= k; ++i)
	{
		tt[i] = make_pair(t[p[i]].a, t[p[i]].b);
	}
	sort(tt + 1, tt + k + 1, cmp);
	for (int i = k; i >= 1; --i)
	{
		mx[i] = max(mx[i + 1], tt[i].b);
	}
	int ans = 0;
	for (int i = 1; i < k; ++i)
	{
		ans = max(ans, tt[i].a + mx[i + 1] + 1);
	}
	cout << min(ans, t[n].a) << endl;
}