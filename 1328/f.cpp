#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define MAXN 1000000
using namespace std;

int n, k;
int a[MAXN + 8];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	if (k < n / 2)
	{
		LL ans = 0, temp = 0;
		for (int i = 1; i <= k; ++i)
		{
			ans += a[k] - a[i];
		}
		for (int i = n - k + 1; i <= n; ++i)
		{
			temp += a[n] - a[i];
		}
		ans = min(ans, temp);
		cout << ans << endl;
		return 0;
	}
	if (n % 2)
	{
		int v = a[n / 2 + 1];
		for (int x = v - 100; x <= v + 100; ++x)
		{

		}
	}
	else
	{
		int v1 = a[n / 2], v2 = a[n / 2 + 1];
		for (int x = v1 - 100; x <= v1 + 100; ++x)
		{

		}
		for (int x = v2 - 100; x <= v2 + 100; ++x)
		{

		}
	}
}