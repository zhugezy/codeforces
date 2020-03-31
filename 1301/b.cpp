#include <bits/stdc++.h>
#define LL long long
using namespace std;

int T, n;
int a[100008];

int check(int m)
{
	int l = 0, r = 1000000000;
	for (int i = 1; i < n; ++i)
	{
		if (a[i] >= 0 && a[i + 1] >= 0)
		{
			if (abs(a[i] - a[i + 1]) > m)
				return -1;
		}
		else if (a[i] >= 0)
		{
			l = max(l, a[i] - m);
			r = min(r, a[i] + m);
		}
		else if (a[i + 1] >= 0)
		{
			l = max(l, a[i + 1] - m);
			r = min(r, a[i + 1] + m);
		}
		else
		{
			//pass;
		}
	}
	if (l <= r)
		return l;
	else
		return -1;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		int l = 0, r = 1000000000;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (check(mid) >= 0)
				r = mid;
			else
				l = mid + 1;
		}
		printf("%d %d\n", l, check(l));
	}
}