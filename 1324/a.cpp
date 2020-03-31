#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;
int T, n, a[108];

bool gao()
{
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] % 2 != a[1] % 2)
			return false;
	}
	return true;
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		cout << (gao()? "YES":"NO") << endl;
	}
}