#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n, m, a[300008][9];
int f[258];
bool check(int x)
{
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; ++i)
	{
		int mask = 0;
		for (int j = 1; j <= m; ++j)
		{
			if (a[i][j] >= x)
				mask += (1 << (j - 1));
		}
		f[mask] = i;
	}
	for (int i = 0; i < 256; ++i)
		for (int j = 0; j < 256; ++j)
			if (f[i] && f[j] && ((i | j) + 1 == (1 << m)))
				return true;
	return false;
}

void getans(int ans)
{
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; ++i)
	{
		int mask = 0;
		for (int j = 1; j <= m; ++j)
		{
			if (a[i][j] >= ans)
				mask += (1 << (j - 1));
		}
		f[mask] = i;
	}
	for (int i = 0; i < 256; ++i)
		for (int j = 0; j < 256; ++j)
			if (f[i] && f[j] && ((i | j) + 1 == (1 << m)))
			{
				cout << f[i] << " " << f[j] << endl;
				return;
			}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	int l = 0, r = 1000000007;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	getans(l - 1);
}