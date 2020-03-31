#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL dp[12][1008][1008], sum[12][1008][1008];
const LL mod = 1000000007;
int n, m;
int main()
{
	cin >> n >> m;
	for (int x = 1; x <= n; ++x)
		for (int y = x; y <= n; ++y)
			dp[1][x][y] = 1;
	for (int x = 1; x <= n; ++x)
	{
		for (int y = n; y >= 1; --y)
		{
			sum[1][x][y] = (sum[1][x - 1][y] + sum[1][x][y + 1] - sum[1][x - 1][y + 1] + dp[1][x][y] + mod) % mod;
		}
	}
	for (int i = 2; i <= m; ++i)
	{
		for (int x = 1; x <= n; ++x)
		{
			for (int y = x; y <= n; ++y)
			{
				dp[i][x][y] = sum[i - 1][x][y];
			}
		}
		for (int x = 1; x <= n; ++x)
		{
			for (int y = n; y >= 1; --y)
			{
				sum[i][x][y] = (sum[i][x - 1][y] + sum[i][x][y + 1] - sum[i][x - 1][y + 1] + dp[i][x][y] + mod) % mod;
			}
		}
	}
	LL ans = 0;
	for (int x = 1; x <= n; ++x)
	{
		for (int y = x; y <= n; ++y)
			ans = (ans + dp[m][x][y]) % mod;
	}
	cout << ans << endl;
}