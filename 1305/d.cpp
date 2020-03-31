#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
int n;
int d[1008];
bool mp[1008][1008];
bool ans[1008];
int main()
{
	cin >> n;
	for (int i = 1; i <= n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		mp[a][b] = mp[b][a] = 1;
		d[a]++, d[b]++;
	}
	for (int i = 1; i <= n / 2; ++i)
	{
		int a = 0, b = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (d[j] == 1)
			{
				if (!a)
					a = j;
				else
				{
					b = j;
					break;
				}
			}
		}
		cout << "? " << a << " " << b << endl;
		ans[a] = ans[b] = 1;
		cout.flush();
		int x;
		cin >> x;
		if (x == a || x == b)
		{
			cout << "! " << x << endl;
			cout.flush();
			return 0;
		}
		else
		{
			d[a]--; d[b]--;
			for (int j = 1; j <= n; ++j)
			{
				if (mp[a][j])
				{
					d[j]--;
					mp[a][j] = mp[j][a] = 0;
				}
				if (mp[b][j])
				{
					d[j]--;
					mp[b][j] = mp[j][b] = 0;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!ans[i])
		{
			cout << "! " << i << endl;
			cout.flush();
			return 0;
		}
	}
	return 0;
}