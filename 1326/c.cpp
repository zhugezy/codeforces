#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;
const LL mod = 998244353;
int k, n, p[200008];
vector<int> v;
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &p[i]);
	}
	LL maxans = 0;
	for (int i = 0; i < k; ++i)
		maxans += n - i;
	printf("%lld ", maxans);
	for (int i = 1; i <= n; ++i)
	{
		if (p[i] >= n - k + 1)
			v.pb(i);
	}
	LL ans = 1;
	for (int i = 0; i + 1 < v.size(); ++i)
	{
		ans = ans * (v[i + 1] - v[i]) % mod;
	}
	printf("%lld\n", ans);
}