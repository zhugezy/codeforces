#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
using namespace std;
const int mod = 1000000007;
LL qp(LL a, LL b)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1)
			 ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

int n, m, k;
vector<pii> vec;
int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		if (v == u + 1)
			continue;
		else if (v == u + k + 1)
		{
			vec.push_back(pii(u, v));
			if (u >= vec[0].second)
			{
				cout << 0 << endl;
				return 0;
			}
		}
		else
		{
			cout << 0 << endl;
			return 0;
		}
	}
	LL ans = 0;
	if (vec.size())
	{
		int cnt = 0;
		for (int i = vec[0].first + 1; i < vec[0].second && i + k + 1 <= n; ++i)
		{
			cnt++;
		}
		//cout << "c = " << cnt << endl;
		ans = qp(2, cnt - vec.size() + 1);
		for (int i = 1; i < vec[0].first && i + k + 1 <= n; ++i)
		{
			if (i + k + 1 > vec.back().first)
			{
				//cout << "i = " << i << "	cnt = " << n - i - k - 1 << endl;
				ans = (ans + qp(2, min(k, n - i - k - 1) - vec.size())) % mod;
			}
		}
	}
	else
	{
		for (int i = 1; i + k + 1 <= n; ++i)
		{
			ans = (ans + qp(2, min(k, n - i - k - 1))) % mod;
		}
		ans = (ans + 1) % mod;
	}
	cout << ans << endl;
}