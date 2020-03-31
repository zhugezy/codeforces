#include <bits/stdc++.h>
#define LL long long
using namespace std;
int T;
LL n;
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		LL ans = 0;
		while (n >= 10)
		{
			LL x = n / 10;
			ans += 10 * x;
			n -= 10 * x;
			n += x;
		}
		cout << ans + n << endl;
	}
}