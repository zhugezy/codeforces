#include <bits/stdc++.h>
#define LL long long
using namespace std;

int T;
int n, a[200008], mx[200008], mn[200008];

void fuck()
{
	scanf("%d", &n);
	mx[0] = mx[n + 1] = -2000000000, mn[0] = mn[n + 1] = 2000000000;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		a[i] += i;
	}
	for (int i = n; i >= 1; --i)
	{
		mx[i] = max(mx[i + 1], a[i]);
		mn[i] = min(mn[i + 1], a[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		//printf("a[%d] = %d\n", i, a[i]);
		if (a[i] > mn[i])
		{
			printf("YES\n");
			for (int j = i + 1; j <= n; ++j)
			{
				if (a[j] == mn[i])
				{
					printf("%d %d\n", i, j);
					return;
				}
			}
			return;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		a[i] -= 2 * i;
	}
	for (int i = n; i >= 1; --i)
	{
		mx[i] = max(mx[i + 1], a[i]);
		mn[i] = min(mn[i + 1], a[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		//printf("a[%d] = %d %d\n", i, a[i], mx[i]);
		if (a[i] < mx[i])
		{
			printf("YES\n");
			for (int j = i + 1; j <= n; ++j)
			{
				if (a[j] == mx[i])
				{
					printf("%d %d\n", i, j);
					return;
				}

			}
			
		}
	}
	printf("NO\n");
	return;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		fuck();
	}
}