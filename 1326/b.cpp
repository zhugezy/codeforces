#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;
int n;
LL b[200008], a[200008], x[200008];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &b[i]);
	for (int i = 1; i <= n; ++i)
	{
		a[i] = b[i] + x[i];
		x[i + 1] = max(x[i], a[i]);
	}
	for (int i = 1; i <= n; ++i)
		printf("%lld ", a[i]);
	cout << endl;
}