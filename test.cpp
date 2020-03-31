#include <bits/stdc++.h>
#define LL long long
#define MAXN 1000008
using namespace std;
int n, a, b, arr[108], dp[108][54][2];  //previous i elements, using j odd elements, on location i there's an even/odd element.
int main()
{
	memset(dp, 0x3f, sizeof(dp));
	cin >> n;
	b = n / 2, a = n / 2 + n % 2;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		if (arr[i])
		{
			if (arr[i] % 2)
				a--;
			else
				b--;
		}
	}
	dp[0][0][0] = dp[0][0][1] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int x = 0; x <= a; ++x)
		{
			for (int f = 0; f <= 1; ++f)
			{
				//printf("dp[%d][%d][%d] = %d\n", i, x, f, dp[i][x][f]);
				if (arr[i + 1] == 0)
				{
					if (x < a)
						dp[i + 1][x + 1][1] = min(dp[i + 1][x + 1][1], dp[i][x][f] + (f != 1));
					dp[i + 1][x][0] = min(dp[i + 1][x][0], dp[i][x][f] + (f != 0));
				}
				else
				{
					dp[i + 1][x][arr[i+1] % 2] = min(dp[i + 1][x][arr[i+1] % 2], dp[i][x][f] + (f != arr[i+1] % 2));
				}
			}
		}
	}
	cout << min(dp[n][a][0], dp[n][a][1]) << endl;
    return 0;
}