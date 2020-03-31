#include <bits/stdc++.h>
#define LL long long
using namespace std;

int n;
LL a[100008];
int T;
LL sum = 0, xo = 0;
LL ans[4];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		sum = 0, xo = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%lld", &a[i]);
			sum += a[i], xo = xo ^ a[i];
		}
		ans[0] = xo;
		sum = sum + xo, xo = xo ^ xo;
		ans[1] = sum;
		xo = xo ^ sum, sum = sum + sum;
		cout << 2 << endl;
		cout << ans[0] << " " << ans[1] << endl;
	}
}