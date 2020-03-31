#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL mod = 1000000007;
LL dp[1008][1008][2][2][2];
LL f[1008], g[1008];
LL fac[1008], invfac[1008];

LL qp(LL a, LL b)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

void init()
{
	fac[0] = invfac[0] = 1;
	for (int i = 1; i <= 1000; ++i)
	{
		fac[i] = fac[i - 1] * i % mod;
		invfac[i] = invfac[i - 1] * qp(i, mod - 2) % mod;
	}
}

LL C(LL n, LL m)
{
	return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

int n, k;
int main()
{
	init();
	cin >> n >> k;
	if (n <= 1)
		dp[0][0][1][0][1] = 1;
	else
		dp[0][0][1][0][0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int f0 = 0; f0 <= 1; ++f0)
				for (int f1 = 0; f1 <= 1; ++f1)
					for (int f2 = 0; f2 <= 1; ++f2)
					{
						dp[i+1][j][f1][f2][(i + 3 > n)] = (dp[i+1][j][f1][f2][(i + 3 > n)] + dp[i][j][f0][f1][f2]) % mod;
						if (f0 == 0)
							dp[i+1][j+1][f1][f2][(i + 3 > n)] = (dp[i+1][j+1][f1][f2][(i + 3 > n)] + dp[i][j][f0][f1][f2]) % mod;
						if (f2 == 0)
							dp[i+1][j+1][f1][1][(i + 3 > n)] = (dp[i+1][j+1][f1][1][(i + 3 > n)] + dp[i][j][f0][f1][f2]) % mod;
					}
		}
	}
	for (int j = 0; j <= n; ++j)
		for (int f0 = 0; f0 <= 1; ++f0)
			for (int f1 = 0; f1 <= 1; ++f1)
				for (int f2 = 0; f2 <= 1; ++f2)
					f[j] = (f[j] + dp[n][j][f0][f1][f2]) % mod;
	for (int i = n; i >= 0; --i)
	{
		g[i] = f[i] * fac[n - i] % mod;
		for (int j = i + 1; j <= n; ++j)
		{
			g[i] = (g[i] - C(j, i) * g[j] % mod + mod) % mod;
		}
	}
	cout << g[k] << endl;
}