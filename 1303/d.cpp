#include <bits/stdc++.h>
#define LL long long
using namespace std;
int T, m;
LL n;
int a[68], need[68];
int gao()
{
	int ans = 0;
	for (int i = 0; i <= 64; ++i)
	{
		if (!need[i])
			a[i + 1] += a[i] / 2;
		else
		{
			if (a[i])
			{
				need[i]--;
				a[i]--;
				a[i + 1] += a[i] / 2;
			}
			else
			{
				for (int j = i + 1; j <= 64; ++j)
				{
					if (a[j])
					{
						for (int k = j - 1; k >= i; --k)
						{
							a[k] += 2;
							a[k + 1] -= 1;
							ans++;
						}
						break;
					}
				}
				if (a[i])
				{
					need[i]--;
					a[i]--;
				}
				else
					return -1;
			}
		}
	}
	for (int i = 0; i <= 64; ++i)
		if (need[i])
			return -1;
	return ans;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(a, 0, sizeof(a));
		memset(need, 0, sizeof(need));
		scanf("%lld %d", &n, &m);
		for (int i = 1; i <= m; ++i)
		{
			int p;
			scanf("%d", &p);
			int ind = 0;
			while (p > 1)
			{
				p >>= 1;
				ind++;
			}
			a[ind]++;
		}
		int ind = 0;
		while (n)
		{
			if (n & 1)
				need[ind]++;
			n >>= 1;
			ind++;
		}
		cout << gao() << endl;
	}
}