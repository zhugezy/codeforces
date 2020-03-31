#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
int n;
int m, a[200008];
int cnt[1008];
vector<int> val[1008];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	if (m == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
	{
		a[i] %= m;
		cnt[a[i]]++;
	}
	for (int i = 0; i < m; ++i)
	{
		if (cnt[a[i]] >= 2)
		{
			cout << 0 << endl;
			return 0;
		}
	}  // n <= m
	LL ans = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
			ans = ans * (a[i] - a[j] + m) % m;
	}
	cout << ans << endl;
	return 0;
}