#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
using namespace std;

int T, n;

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		LL m;
		scanf("%d %lld", &n, &m);
		LL s = 0;
		for (int i = 1; i <= n; ++i)
		{
			LL x;
			scanf("%lld", &x);
			s += x;
		}
		printf("%lld\n", min(m, s));
	}
}