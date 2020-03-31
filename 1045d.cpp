#include <bits/stdc++.h>
using namespace std;

double p[100008];
double f[100008];
vector<int> vec[100008];
int fa[100008];
double ans = 0;
void dfs(int i, int pre)
{
	fa[i] = pre;
	for (auto s: vec[i])
	{
		if (s == pre)
			continue;
		dfs(s, i);
		f[i] += p[s];
	}
	ans += p[i] - p[i] * f[i];
}
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf", &p[i]);
		p[i] = 1 - p[i];
	}
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	dfs(0, -1);
	int Q;
	scanf("%d", &Q);
	while (Q--)
	{
		int x;
		scanf("%d", &x);
		double np;
		scanf("%lf", &np);
		np = 1 - np;
		ans = ans - p[x] + np;
		ans = ans + p[x] * f[x];
		if (x)
		{
			ans = ans + p[fa[x]] * f[fa[x]];
			f[fa[x]] -= p[x];
			f[fa[x]] += np;
			ans = ans - p[fa[x]] * f[fa[x]];
		}
		p[x] = np;
		ans = ans - p[x] * f[x];
		printf("%.10f\n", ans);
		
	}
}