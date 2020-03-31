#include <bits/stdc++.h>
#define LL long long
using namespace std;
int T, n, d, a[108];
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		int ans = a[1];
		for (int i = 2; i <= n; ++i)
		{
			while (a[i])
			{
				if (d >= i - 1)
				{
					ans++;
					a[i]--;
					d -= i - 1;
				}
				else
					break;
			}
		}
		cout << ans << endl;
	}
}