#include <bits/stdc++.h>
#define LL long long
using namespace std;

int n;
LL a, b, k, h[200008];
LL arr[200008];
int main()
{
	scanf("%d %lld %lld %lld", &n, &a, &b, &k);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", &h[i]);
		LL r = h[i] % (a + b);
		if (r == 0)
			r += a + b;
		arr[i] = ceil(r * 1.0 / a) - 1;
	}
	sort(arr + 1, arr + n + 1);
	int sum = 0;
	arr[n + 1] = k + 10000;
	for (int i = 1; i <= n + 1; ++i)
	{
		sum += arr[i];
		if (sum > k)
		{
			printf("%d\n", i - 1);
			break;
		}
	}
}