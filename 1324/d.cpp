#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;
int n, a[200008], b[200008], tre[(200004 << 2)];
LL ans = 0;
map<int, int> mp;

void pushup(int rt)
{
	tre[rt] = tre[rt << 1] + tre[rt << 1 | 1];
}

void update(int rt, int l, int r, int loc)
{
	if (l == r)
		{tre[rt]++;return;}
	int mid = (l + r) >> 1;
	if (loc <= mid)
		update(rt << 1, l, mid, loc);
	else
		update(rt << 1 | 1, mid + 1, r, loc);
	pushup(rt);
}

int query(int rt, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
		return tre[rt];
	int mid = (l + r) >> 1;
	int ret = 0;
	if (L <= mid)
		ret += query(rt << 1, l, mid, L, R);
	if (mid + 1 <= R)
		ret += query(rt << 1 | 1, mid + 1, r, L, R);
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		a[i] -= x;
	}
	for (int i = 1; i <= n; ++i)
	{
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	int c = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (!mp[b[i]])
		{
			mp[b[i]] = ++c;
 		}
	}
	for (int i = 1; i <= n; ++i)
	{
		int* v = upper_bound(b + 1, b + n + 1, -a[i]);
		if (v <= b + n)
		{
			ans += query(1, 1, n, mp[*v], n);
		}
		update(1, 1, n, mp[a[i]]);
	}
	cout << ans << endl;
}