#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;
int T, n, a[5008], b[5008];

bool gao()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			if (b[a[j]])
				return true;
		}
		b[a[i]] = 1;
	}
	return false;
}

int main()
{
	cin >> T;
	while (T--)
	{
		memset(b, 0, sizeof(b));
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		cout << (gao()? "YES":"NO") << endl;
	}
}