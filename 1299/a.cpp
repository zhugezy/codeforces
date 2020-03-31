#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n, a[100008];
int cnt[48];
int main()
{
	scanf("%d", &n);
	int m = 0, mval = -1;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		int x = a[i];
		int id = 0;
		while (x)
		{
			cnt[id++] += x & 1;
			x >>= 1;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		int x = a[i];
		int id = 0;
		while (x)
		{
			cnt[id++] -= x & 1;
			x >>= 1;
		}
		int val = 0;
		for (int cid = 0; cid <= 30; ++cid)
		{
			if (cnt[cid])
				val += (1 << cid);
		}
		if (a[i] - (a[i] & val) >= mval)
		{
			mval = a[i] - (a[i] & val);
			m = i;
		}
		x = a[i];
		id = 0;
		while (x)
		{
			cnt[id++] += x & 1;
			x >>= 1;
		}
	}
	swap(a[1], a[m]);
	for (int i = 1; i <= n; ++i)
		printf("%d%c", a[i], " \n"[i==n]);
}