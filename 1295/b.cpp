#include <bits/stdc++.h>
#define LL long long
using namespace std;

int v[100008];
char str[100008];
int n, x;
bool flag = false;

int Mod(int x, int m)
{
	return (x % m + m) % m;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		flag = false;
		scanf("%d %d %s", &n, &x, str + 1);
		if (v[0] == x)
			flag = true;
		for (int i = 1; i <= n; ++i)
		{
			if (str[i] == '0')
				v[i] = v[i - 1] + 1;
			else
				v[i] = v[i - 1] - 1;
			if (v[i] == x)
				flag = true;
		}
		int m = v[n];
		if (m == 0)
		{
			if (flag)
				printf("-1\n");
			else
				printf("0\n");
			continue;
		}
		int ans = (x == 0);
		if (m < 0)
		{
			m = -m;
			for (int i = 1; i <= n; ++i)
			{
				if (v[i] >= x && Mod(v[i], m) == Mod(x, m))
					ans++;
			}
		}
		else
		{
			for (int i = 1; i <= n; ++i)
			{
				if (v[i] <= x && Mod(v[i], m) == Mod(x, m))
					ans++;
			}
		}
		printf("%d\n", ans);
	}
}