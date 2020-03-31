#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int n,k;


long long arr[52];
long long suffix[52];
long long dp[52][52];


long long rnk(long long x)
{
	long long res = 0;
	while (x > 0)
	{
		if (x % 2 == 1) res++;
		x /= 2;
	}
	return res;
}

long long rrrmax(long long a, long long b)
{
	if (rnk(a) > rnk(b)) return a;
	else if (rnk(a) == rnk(b) && a > b) return a;
	else return b;
}


int main()
{
	scanf("%d %d",&n,&k);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%I64d",&arr[i]);
		if (i == 1) suffix[1] = arr[1];
		else suffix[i] = suffix[i - 1] + arr[i];
		dp[i][1] = suffix[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 2; j <= i && j <= k; ++j)
		{
			for (int k = 1; k < i; ++k)
			{
				dp[i][j] = rrrmax(dp[i][j], dp[k][j - 1] & (suffix[i] - suffix[k]));
				//printf("dp[%d][%d] = %d\n",i,j,dp[i][j]);
			}
			//printf("dp[%d][%d] = %d\n",i,j,dp[i][j]);
		}
	}
	printf("%I64d",dp[n][k]);
}
