#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;
int n, h, l, r, dp[2008][2008], a[2008];

int gao(int x)
{
	return l <= x && x <= r;
}

int main()
{
	scanf("%d %d %d %d", &n, &h, &l, &r);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < h; ++j)
		{
			if (dp[i][j] < 0) continue;
			//printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
			dp[i + 1][(j + a[i] - 1) % h] = max(dp[i + 1][(j + a[i] - 1) % h], dp[i][j] + gao((j + a[i] - 1) % h));
			dp[i + 1][(j + a[i]) % h] = max(dp[i + 1][(j + a[i]) % h], dp[i][j] + gao((j + a[i]) % h));
		}
	}
	int ans = 0;
	for (int j = 0; j < h; ++j)
		ans = max(ans, dp[n][j]);
	cout << ans << endl;
}