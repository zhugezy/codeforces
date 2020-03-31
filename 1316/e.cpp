#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pll pair<LL,LL>
using namespace std;

int n, p, k;
LL dp[2][180][12];
LL a[100008];
LL s[100008][9];
pll arr[100008];
int pos[100008];
int main()
{
	scanf("%d %d %d", &n, &p, &k);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", &a[i]);
		arr[i] = pll(a[i], i);
	}
	sort(arr + 1, arr + n + 1);
	reverse(arr + 1, arr + n + 1);
	for (int i = 1; i <= n; ++i)
	{
		pos[arr[i].second] = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < p; ++j)
		{
			scanf("%lld", &s[i][j]);
		}
	}
	int _c = 0;
	for (int ii = 1; ii <= n; ++ii)
	{
		int i = arr[ii].second;  //pos[i] == ii
		for (int msk = 0; msk < (1 << p); ++msk)
		{
			int jmax = 0;
			for (int t = 0; t < p; ++t)
			{
				if (msk & (1 << t))
				{
					jmax++;
				}
			}
			for (int j = 0; j <= jmax; ++j)
			{
				if ( !(dp[_c][msk][j] || (ii == 1 && msk == 0 && j == 0)) )
					continue;
				//printf("dp[%d][%d][%d] = %I64d\n", ii - 1, msk, j, dp[_c][msk][j]);
				if (pos[i] <= k + j)
				{
					for (int pi = 0; pi < p; ++pi)
					{
						if (!(msk & (1 << pi)))
						{
							dp[_c^1][(msk | (1 << pi))][j + 1] = max(dp[_c^1][(msk | (1 << pi))][j + 1], dp[_c][msk][j] + s[i][pi]);
						}
					}
					dp[_c^1][msk][j] = max(dp[_c^1][msk][j], dp[_c][msk][j] + a[i]);
				}
				else
				{
					for (int pi = 0; pi < p; ++pi)
					{
						if (!(msk & (1 << pi)))
						{
							dp[_c^1][(msk | (1 << pi))][j] = max(dp[_c^1][(msk | (1 << pi))][j], dp[_c][msk][j] + s[i][pi]);
						}
					}
					dp[_c^1][msk][j] = max(dp[_c^1][msk][j], dp[_c][msk][j]);
				}
			}
		}
		_c ^= 1;
	}
	/*for (int msk = 0; msk < (1 << p); ++msk)
	{
		int jmax = 0;
		for (int t = 0; t < p; ++t)
		{
			if (msk & (1 << t))
			{
				jmax++;
			}
		}
		for (int j = 0; j <= jmax; ++j)
		{
			printf("dp[%d][%d][%d] = %I64d\n", n, msk, j, dp[_c][msk][j]);
		}
	}*/
	LL ans = 0;
	for (int j = 0; j <= p; ++j)
	{
		ans = max(ans, dp[_c][(1<<p)-1][j]);
	}
	cout << ans << endl;
}