#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;

int T, n;
int main()
{
	cin >> T;
	while (T--)
	{
		scanf("%d", &n);
		if (n == 1)
			printf("-1\n");
		else if (n == 2)
			printf("57\n");
		else
		{
			for (int k = 0; k <= n; ++k)
			{
				int s = 2 * k + 3 * (n - k);
				if (s % 3)
				{
					for (int i = 1; i <= k; ++i)
						printf("2");
					for (int i = k + 1; i <= n; ++i)
						printf("3");
					printf("\n");
					break;
				}
			}
		}
	}
}