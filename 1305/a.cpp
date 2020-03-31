#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
int T, n, a[108], b[108];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &b[i]);
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; ++i)
			printf("%d ", a[i]);
		cout << endl;
		for (int i = 1; i <= n; ++i)
			printf("%d ", b[i]);
		cout << endl;
	}
	return 0;
}