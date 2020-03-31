#include <bits/stdc++.h>
#define MAXN 600000
using namespace std;

int tre[(MAXN << 2) + 4], lazy[(MAXN << 2) + 4];

void pushup(int rt)
{
	tre[rt] = tre[rt << 1] + tre[rt << 1 | 1];
}

void pushdown(int rt, int l, int r)
{
	if (!lazy[rt])
		return;
	int mid = (l + r) >> 1;
	tre[rt << 1] += lazy[rt] * (mid - l + 1);
	tre[rt << 1 | 1] += lazy[rt] * (r - mid);
	lazy[rt << 1] += lazy[rt];
	lazy[rt << 1 | 1] += lazy[rt];
	lazy[rt] = 0;
}

void update(int rt, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
	{
		tre[rt] += r - l + 1;
		lazy[rt]++;
		return;
	}
	int mid = (l + r) >> 1;
	if (L <= mid)
		update(rt << 1, l, mid, L, R);
	if (mid + 1 <= R)
		update(rt << 1 | 1, mid + 1, r, L, R);
	pushup(rt);
}

int query(int rt, int l, int r, int D)
{
	if (l == r)
		return tre[rt];
	int mid = (l + r) >> 1;
	int ret = 0;
	pushdown(rt, l, r);
	if (D <= mid)
		return query(rt << 1, l, mid, D);
	else
		return query(rt << 1 | 1, mid + 1, r, D);
}

vector<int> vec[MAXN + 4];
int arr[300008], a[600008];
int mn[300008], mx[300008];
int pre[300008];
int n, m;
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &arr[i]);
		vec[arr[i]].push_back(i);
	}
	int _ = 0;
	for (int i = n; i >= 1; --i)
	{
		if (!vec[i].size())
		{
			mn[i] = i;
		}
		else
		{
			_++;
			mn[i] = 1;
		}
	}
	for (int i = 1; i <= n; ++i)
		a[i] = n - i + 1;
	for (int i = n + 1; i <= n + m; ++i)
		a[i] = arr[i - n];
	for (int i = 1; i <= n + m; ++i)
	{
		update(1, 1, n + m, pre[a[i]] + 1, i);
		if (i > n)
			mx[a[i]] = max(mx[a[i]], query(1, 1, n + m, pre[a[i]] + 1));
		pre[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i)
		mx[i] = max(mx[i], query(1, 1, n + m, pre[i]));
	for (int i = 1; i <= n; ++i)
		printf("%d %d\n", mn[i], mx[i]);
		
}
