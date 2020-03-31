#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int MAXN = 200000;
LL n;
int M, a[108];
LL dp[108][MAXN + 8];

LL dfs(int m, LL n)
{
	if (n == 0)
		return dp[m][0] = 0;
	if (m <= 0)
		return n;
	if (n <= MAXN && dp[m][n] >= 0)
		return dp[m][n];
	LL ret = dfs(m - 1, n) - dfs(m - 1, n / a[m]);
	if (n <= MAXN)
		dp[m][n] = ret;
	return ret;
}

int main()
{
	cin >> n >> M;
	for (int i = 1; i <= M; ++i)
		cin >> a[i];
	sort(a + 1, a + M + 1);
	memset(dp, -1, sizeof(dp));
	cout << dfs(M, n) << endl;
}