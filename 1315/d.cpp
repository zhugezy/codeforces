#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
using namespace std;
int n;
LL a[200008];
LL t[200008];
map<LL, vector<LL> > mp;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", &t[i]);
		mp[a[i]].push_back(t[i]);
	}
	mp[2000000007].push_back(0);
	multiset<LL> s;
	LL ans = 0, sum = 0;
	LL pre = 0;
	for (auto pr: mp)
	{
		if (pre)
		{
			for (int i = 1; i <= pr.first - pre; ++i)
			{
				if (s.empty())
					break;
				sum -= *(--s.end());
				s.erase(--s.end());
				ans += sum;
			}
		}
		sort(pr.second.begin(), pr.second.end());
		for (LL x: pr.second)
		{
			s.insert(x);
			sum += x;
		}
		pre = pr.first;
	}
	printf("%lld\n", ans);
}