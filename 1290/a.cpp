#include <bits/stdc++.h>
#define LL long long
#define MAXN 1000000
using namespace std;

int n, m, k;
int arr[MAXN + 8];
LL ans = 0;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &arr[i]);
		}
		int ans = -1;
		k = min(m - 1, k);
		for (int a = 0; a <= k; ++a)
		{
			int b = k - a;
			int rem = max(0, m - 1 - k);
			int temp = 1000000007;
			for (int p = 0; p <= rem; ++p)
			{
				int aa = p + a, bb = rem - p + b;
				temp = min(temp, max(arr[aa + 1], arr[n - bb]));
			}
			ans = max(temp, ans);
		}
		printf("%d\n", ans);
	}
}