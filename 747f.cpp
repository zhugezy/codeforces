#include <bits/stdc++.h>
#define LL long long
using namespace std;

int ans[12];
LL k, t;
LL fac[12] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800};
int cnt[18];
LL C(LL n, LL m)
{
	return fac[n] / fac[m] / fac[n - m];
}
LL dfs(int L, int curi, bool flag)
{
	if (L == 0)
		return 1;
	if (curi > 15)
		return 0;
	LL ans = 0;
	if (flag && curi == 0)
	{
		for (int i = 0; i + cnt[curi] <= t && i < L; ++i)
		{
			ans = (ans + C(L - 1, i) * dfs(L - i, curi + 1, false));
		}
	}
	else
	{
		for (int i = 0; i + cnt[curi] <= t && i <= L; ++i)
		{
			ans = (ans + C(L, i) * dfs(L - i, curi + 1, false));
		}
	}
	//printf("dfs(%d, %d) = %I64d\n", L, curi, ans);
	return ans;
}
int main()
{
	cin >> k >> t;
	/*if (k <= 10)
	{
		printf("%d\n", k);
		return 0;
	}
	else if (k <= 15)
	{
		printf("%c\n", k - 10 + 'a');
		return 0;
	}*/
	int ansL = 0;
	for (int l = 1; l <= 10; ++l)
	{
		//printf("dfs(2, 0) = %I64d\n", dfs(2, 0));
		LL temp = dfs(l, 0, true);
		if (temp >= k)
		{
			ansL = l;
			break;
		}
		k -= temp;
	}
	for (int i = 1; i <= ansL; ++i)
	{
		int v;
		LL curtot = 0;
		for (v = 0; v <= 15; ++v)
		{
			if (v == 0 && i == 1 || cnt[v] >= t)
				continue;
			cnt[v]++;
			LL curval = dfs(ansL - i, 0, false);
			//printf("ans[%d] = %d    , curval = %I64d\n", i, v, curval);
			if (curval + curtot >= k)
			{
				ans[i] = v;
				k -= curtot;
				break;
			}
			curtot += curval;
			cnt[v]--;
		}
		if (v > 15)
		{
			ans[i] = 15;
			cnt[15]++;
			k -= curtot;
		}
	}
	for (int i = 1; i <= ansL; ++i)
	{
		if (ans[i] < 10)
			printf("%d", ans[i]);
		else
			printf("%c", ans[i] - 10 + 'a');
	}
	printf("\n");
}