#include <bits/stdc++.h>
#define LL long long
using namespace std;

int T;
LL n, m;
LL g(LL x)
{
	return x * (x + 1) / 2;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld %lld", &n, &m);
		LL x = n - m;
		LL u = x / (m + 1);
		LL r = x % (m + 1);
		printf("%lld\n", g(n) - (r * g(u + 1) + (m - r + 1) * g(u)));
	}
}