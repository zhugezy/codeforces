#include <bits/stdc++.h>
#define LL long long
using namespace std;
int T, n, m;
char s[408], t[408];
int dp[408][408];

bool gao()
{
	n = strlen(s + 1); 
	m = strlen(t + 1);
	for (int l = 1; l <= m; ++l)
	{
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j <= m - l; ++j)
			{
				if (s[i] == t[l + j])
				{
					if (dp[i - 1][j - 1] >= 0)
						dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
				}
				if (dp[i - 1][j] >= 0)
					dp[i][j] = max(dp[i][j], dp[i - 1][j] + (s[i] == t[dp[i - 1][j] + 1]));
				printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
			}
		}
		if (dp[n][m - l] >= l)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s %s", s + 1, t + 1);
		cout << (gao()?"YES":"NO") << endl;
	}
}