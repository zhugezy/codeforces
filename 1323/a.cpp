#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;

int T, n, a[108];

int main()
{
	cin >> T;
	while (T--)
	{
		vector<int> v;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; ++i)
		{
			if (a[i] % 2 == 0)
			{
				v.clear();
				v.pb(i);
			}
			else
			{
				v.pb(i);
			}
		}
		if (a[v[0]] % 2 == 0)
			cout << 1 << endl << v[0] << endl;
		else
		{
			if (v.size() <= 1)
				cout << -1 << endl;
			else
				cout << 2 << endl << v[0] << " " << v[1] << endl;
		}
	}
}