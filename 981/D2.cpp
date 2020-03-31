#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int n,k;


long long arr[52];
long long suffix[52];
vector<long long> dp[52][52];

int in(int i, int j, long long tmp, int llen)
{
	for (int k = 0; k < llen; ++k)
	{
		if (tmp == dp[i][j][k]) return 1;
	}
	return 0;
}

int main()
{
	long long res = 0;
	scanf("%d %d",&n,&k);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%I64d",&arr[i]);
		if (i == 1) suffix[1] = arr[1];
		else suffix[i] = suffix[i - 1] + arr[i];
		dp[i][1].push_back(suffix[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i && j <= k; ++j)
		{
			for (int k = 1; k < i; ++k)
			{
				int len = dp[k][j - 1].size();
				for (int t = 0; t < len; ++t)
				{
					int llen = 0;
					long long tmp = dp[k][j - 1][t] & (suffix[i] - suffix[k]);
					if (!in(i,j,tmp,llen))
					{
						dp[i][j].push_back(tmp);
						llen++;
					}
				}
			}
		}
	}
	int len = dp[n][k].size();
	for (int i = 0; i < len; ++i)
	{
		res = max(res,dp[n][k][i]);
	}
	printf("%I64d",res);
}
