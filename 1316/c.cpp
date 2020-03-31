#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
using namespace std;

int n, m, p, a[1000008], b[1000008];

int gao()
{
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] == 0 && b[i] == 0)
			continue;
		else if (a[i] != 0 && b[i] != 0)
		{
			return i + i - 2;
		}
		else if (a[i] != 0)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				if (b[j] != 0)
					return i + j - 2;
			}
		}
		else
		{
			for (int j = i + 1; j <= n; ++j)
			{
				if (a[j] != 0)
					return i + j - 2;
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 1; i <= n; ++i)
		{scanf("%d", &a[i]); a[i] %= p;}
	for (int i = 1; i <= m; ++i)
		{scanf("%d", &b[i]); b[i] %= p;}
	n = max(n, m);
	m = max(n, m);
	cout << gao() << endl;
}