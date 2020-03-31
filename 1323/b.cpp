#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;

int n, m, k;
int a[40008], b[40008];
LL cnta[40008], cntb[40008];
LL suma[40008], sumb[40008];
int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &b[i]);
	LL c = 0;
	for (int i = 1; i <= n + 1; ++i)
	{
		if (a[i])
			c++;
		else
		{
			if (c)
			{
				cnta[c]++;
			}
			c = 0;
		}
	}
	c = 0;
	for (int i = 1; i <= m + 1; ++i)
	{
		if (b[i])
			c++;
		else
		{
			if (c)
			{
				cntb[c]++;
			}
			c = 0;
		}
	}
	LL cur = 0;
	for (int i = n; i >= 1; --i)
	{
		cur += cnta[i];
		suma[i] = suma[i + 1] + cur;
	}
	cur = 0;
	for (int i = m; i >= 1; --i)
	{
		cur += cntb[i];
		sumb[i] = sumb[i + 1] + cur;
	}
	LL ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (k % i || k / i > m)
			continue;
		ans += suma[i] * sumb[k / i];
	}
	cout << ans << endl;
}