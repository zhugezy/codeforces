#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL T, n, x, a[100008], mx = -1;
LL ans = 0;

LL gao()
{
	for (int i = 1; i <= n; ++i)
		if (a[i] == x)
			return 1;
	if (mx * 2 >= x)
		return 2;
	else
	{
		LL ans = x / mx + 1;
		if (x % mx == 0)
			ans--;
		return ans;
	}
}

int main()
{
	scanf("%lld", &T);
	while (T--)
	{
		mx = -1;
		scanf("%lld %lld", &n, &x);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%lld", &a[i]);
			mx = max(mx, a[i]);
		}
		cout << gao() << endl;
	}
}