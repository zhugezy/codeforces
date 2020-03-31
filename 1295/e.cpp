#include <bits/stdc++.h>
#define LL long long
#define MAXN 200000
using namespace std;

LL tre[(MAXN << 2) + 8], lazy[(MAXN << 2) + 8];
int n, p[MAXN + 8], loc[MAXN + 8];
LL a[MAXN + 8], suma[MAXN + 8];

void pushup(int rt)
{
	tre[rt] = min(tre[rt << 1], tre[rt << 1 | 1]);
}

void build(int rt, int l, int r)
{
	if (l > r)
		return;
	if (l == r)
	{
		tre[rt] = suma[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

LL query(int rt, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
		return tre[rt];
	int mid = (l + r) >> 1;
	LL ret = 0x3f3f3f3f3f3f3f3fLL;
	if (mid >= L)
		ret = min(ret, query(rt << 1, l, mid, L, R));
	if (mid + 1 <= R)
		ret = min(ret, query(rt << 1 | 1, mid + 1, r, L, R));
	return ret;
}

void pushdown(int rt)
{
	if (!lazy[rt])
		return;
	tre[rt << 1] += lazy[rt];
	tre[rt << 1 | 1] += lazy[rt];
	lazy[rt << 1] += lazy[rt];
	lazy[rt << 1 | 1] += lazy[rt];
	lazy[rt] = 0;
	return;
}

void update(int rt, int l, int r, int L, int R, LL v)
{
	if (L <= l && r <= R)
	{
		tre[rt] += v;
		lazy[rt] += v;
		return;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (L <= mid)
		update(rt << 1, l, mid, L, R, v);
	if (mid + 1 <= R)
		update(rt << 1 | 1, mid + 1, r, L, R, v);
	pushup(rt);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		{scanf("%d", &p[i]); loc[p[i]] = i;}
	for (int i = 1; i <= n; ++i)
		{scanf("%lld", &a[i]); suma[i] = suma[i - 1] + a[i];}
	build(1, 1, n);
	LL ans = query(1, 1, n, 1, n - 1);
	for (int val = 1; val <= n; ++val)
	{
		int k = loc[val];
		if (k <= n - 1)
			update(1, 1, n, k, n - 1, -a[k]);
		if (k - 1 >= 1)
			update(1, 1, n, 1, k - 1, a[k]);
		ans = min(ans, query(1, 1, n, 1, n - 1));
	}
	printf("%lld\n", ans);
}