#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define MAXN 500004
using namespace std;
int n;
LL m[500008];
LL ans = 0, ansi = 0;
int l[500008], r[500008];
LL suml[500008], sumr[500008];
LL arr[500008];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &m[i]);
	stack<int> sta;
	sta.push(n + 1);
	for (int i = n; i >= 0; --i)
	{
		if (m[sta.top()] <= m[i])
			sta.push(i);
		else
		{
			while (m[sta.top()] > m[i])
			{
				l[sta.top()] = i;
				sta.pop();
			}
			sta.push(i);
		}
	}
	while (!sta.empty())
		sta.pop();
	sta.push(0);
	for (int i = 1; i <= n + 1; ++i)
	{
		if (m[sta.top()] <= m[i])
			sta.push(i);
		else
		{
			while (m[sta.top()] > m[i])
			{
				r[sta.top()] = i;
				sta.pop();
			}
			sta.push(i);
		}
	}
	suml[1] = m[1];
	for (int i = 2; i <= n; ++i)
	{
		suml[i] = suml[l[i]] + (i - l[i]) * m[i];
	}
	sumr[n] = m[n];
	for (int i = n; i >= 1; --i)
	{
		sumr[i] = sumr[r[i]] + (r[i] - i) * m[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		LL res = suml[l[i]] + sumr[r[i]] + (r[i] - l[i] - 1) * m[i];
		if (res > ans)
		{
			ans = res;
			ansi = i;
		}
	}
	arr[ansi] = m[ansi];
	for (int i = ansi - 1; i >= 1; --i)
	{
		arr[i] = min(arr[i + 1], m[i]);
	}
	for (int i = ansi + 1; i <= n; ++i)
	{
		arr[i] = min(arr[i - 1], m[i]);
	}
	for (int i = 1; i <= n; ++i)
		printf("%lld%c", arr[i], " \n"[i==n]);
}