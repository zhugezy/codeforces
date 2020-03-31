#include <bits/stdc++.h>
#define LL long long
using namespace std;
int T, n, d;

bool check(int x)
{
	return x + ceil(1.0 * d / (x + 1)) <= n;
}
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> d;
		int x = sqrt(d);
		if (check(x - 1) || check(x) || check(x + 1))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}