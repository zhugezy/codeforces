#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
int T, n, b[108], a[208];
bool flag[208];

bool gao()
{
	for (int i = 1; i <= n; ++i)
	{
		a[2*i-1] = b[i];
		int j;
		for (j = b[i] + 1; j <= 2 * n; ++j)
		{
			if (!flag[j])
			{
				flag[j] = true;
				a[2*i] = j;
				break;
			}
		}
		if (j > 2*n)
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
		memset(flag, false, sizeof(flag));
		for (int i = 1; i <= n; ++i)
		{
			cin >> b[i];
			flag[b[i]] = true;
		}
		if (!gao())
			cout << -1 << endl;
		else
		{
			for (int i = 1; i <= 2 * n; ++i)
				cout << a[i] << " ";
			cout << endl;
		}
	}
}