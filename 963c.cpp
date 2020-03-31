#include <bits/stdc++.h>
#define LL long long
#define pii pair<long long,long long>
using namespace std;

LL gcd(LL a, LL b)
{
	return b?gcd(b,a%b):a;
}

int n;
LL a[200008], b[200008], c[200008];

bool check(vector<vector<pii>>& v)
{
	vector<LL> vc;
	for (int i = 0; i < v.size(); ++i)
	{
		LL g = 0;
		for (int j = 0; j < v[i].size(); ++j)
			g = gcd(g, v[i][j].second);
		vc.push_back(g);
	}
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i].size() != v[0].size())
			return false;
		for (int j = 0; j < v[i].size(); ++j)
		{
			if (v[0][j].first != v[i][j].first)
				return false;
		}
	}
	for (int j = 0; j < v[0].size(); ++j)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i][j].second / vc[i] != v[0][j].second / vc[0])
				return false;
		}
	}
	return true;
}

LL gao(unordered_map<LL, vector<pii>>& mp, LL g)
{
	vector<vector<pii>> v;
	for (auto x: mp)
	{
		sort(mp[x.first].begin(), mp[x.first].end());
		v.push_back(mp[x.first]);
	}
	if (!check(v))
		return 0;
	else
	{
		LL ans = 0;
		for (LL i = 1; i * i <= g; ++i)
		{
			if (g % i == 0)
				ans += 1 + (i * i < g);
		}
		return ans;
	}
}
int main()
{
	scanf("%d", &n);
	LL g = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%I64d %I64d %I64d", &a[i], &b[i], &c[i]);
		g = gcd(g, c[i]);
	}
	unordered_map<LL, vector<pii>> mp;
	for (int i = 1; i <= n; ++i)
		mp[a[i]].push_back(pii(b[i], c[i]));
	LL ans = gao(mp, g);
	mp.clear();
	for (int i = 1; i <= n; ++i)
		mp[b[i]].push_back(pii(a[i], c[i]));
	cout << max(ans, gao(mp, g)) << endl;
}