#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define MAXN 1000000
using namespace std;

int T, n;
int a[MAXN + 8];

bool ok1()
{
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] != a[1])
			return false;
	}
	return true;
}

bool ok2()
{
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] == a[i - 1])
			return true;
	}
	return a[n] == a[1];
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		if (ok1())
		{
			printf("1\n");
			for (int i = 1; i <= n; ++i)
				printf("1 ");
			printf("\n");
		}
		else if (n % 2 == 0)
		{
			printf("2\n");
			for (int i = 1; i <= n; ++i)
			{
				printf("%d ", i % 2 + 1);
			}
			printf("\n");
		}
		else if (ok2())
		{
			printf("2\n");
			bool flag = false;
			int c = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (!flag && a[i] == a[i - 1])
				{
					flag = true;
				}
				else
					c ^= 1;
				printf("%d ", c + 1);
			}
			printf("\n");
		}
		else
		{
			printf("3\n");
			for (int i = 1; i <= n; ++i)
			{
				if (i == n)
					printf("3 ");
				else
					printf("%d ", i % 2 + 1);
			}
			printf("\n");
		}
	}
}