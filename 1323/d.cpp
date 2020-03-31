#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;

int n, a[400008], cnt[20000008], v[400008];
int ans[32];
int fans = 0;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 25; ++i)
	{
		//cout << "i = " << i << endl;
		for (int j = 1; j <= n; ++j)
		{
			v[j] += (a[j] & (1 << i));
		}
		memset(cnt, 0, sizeof(cnt));
		for (int j = 1; j <= n; ++j)
		{
			cnt[v[j]]++;
		}
		for (int val = 1; val <= 20000000; ++val)
		{
			cnt[val] += cnt[val - 1];
		}
		for (int j = 1; j <= n; ++j)
		{
			//cout << "j = " << j << endl;
			int l = ((1 << i) - v[j]), r = ((1 << (i + 1)) - 1 - v[j]);
			int l2 = (1 << (i + 1)) + (1 << i) - v[j];
			//cout << l << "  " << r << endl;
			if (l - 1 >= 0)
				ans[i] += cnt[min(r, 20000000)] - cnt[l - 1] - (v[j] >= l && v[j] <= r);
			else
				ans[i] += cnt[min(r, 20000000)] - (v[j] >= l && v[j] <= r);
			/*if (l - 1 >= 0)
				cout << cnt[min(r, 20000000)] - cnt[l - 1] - (v[j] >= l && v[j] <= r) << endl;
			else
				cout << cnt[min(r, 20000000)] - (v[j] >= l && v[j] <= r) << endl;*/
			if (l2 >= r + 1)
				ans[i] += n - cnt[min(r + (1 << i), 20000000)] - (v[j] >= l2);
		}
		ans[i] /= 2;
		//cout << ans[i] << endl;
		if (ans[i] % 2)
			fans += (1 << i);
	}
	cout << fans << endl;
}