#include <bits/stdc++.h>
#define LL long long
using namespace std;

int T;
LL n, g, b;

bool check(LL x)
{
	LL totg = x / (g + b) * g + min(g, x % (g + b));
	return (totg * 2 >= n && x >= n);
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld %lld %lld", &n, &g, &b);
		LL l = 1, r = 8000000000000000000LL;
		while (l < r)
		{
			LL mid = (l + r) >> 1;
			if (check(mid))
				r = mid;
			else
				l = mid + 1;
		}
		cout << l << endl;
	}
}