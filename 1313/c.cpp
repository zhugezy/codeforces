#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define MAXN 500004
using namespace std;
int n;
LL m[500008];
LL ans = 0, ansi = 0;
LL _[500008];
int l[500008], r[500008], suml[500008], sumr[500008];
int tre[MAXN << 2], lazy[500008];

void pushup(int rt)
{
	tre[rt] = tre[rt << 1] + tre[rt << 1 | 1];
}
void pushdown(int rt, int l, int r)
{
	if (!lazy[rt])
		return;
	int mid = (l + r) >> 1;
	tre[rt << 1] = lazy[rt] * (mid - l + 1);
	tre[rt << 1 | 1] = lazy[rt] * (r - mid);
	lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
	lazy[rt] = 0;
}
void build(int rt, int l, int r)
{
	if (l == r)
		{tre[rt] = _[l];return;}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int l, int r, int L, int R, LL V)
{
	if (L <= l && r <= R)
	{
		tre[rt] = (r - l + 1) * V;
		lazy[rt] = V;
		return;
	}
	pushdown(rt, l, r);
	int mid = (l + r) >> 1;
	if (L <= mid)
		update(rt << 1, l, mid, L, R, V);
	if (mid + 1 <= R)
		update(rt << 1 | 1, mid + 1, r, L, R, V);
	pushup(rt);
}

LL query(int rt, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
		return tre[rt];
	pushdown(rt, l, r);
	int mid = (l + r) >> 1;
	LL ret = 0;
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
		scanf("%lld", &m[i]);
	LL res = m[1], cur = m[1];
	_[1] = m[1];
	for (int i = 2; i <= n; ++i)
	{
		cur = min(cur, m[i]);
		_[i] = cur;
		res += cur;
	}
	build(1, 1, n);
	ansi = 1, ans = res;
	stack<int> sta;
	sta.push(n + 1);
	for (int i = n; i >= 0; --i)
	{
		if (m[sta.top()] <= m[i])
			sta.push(i);
		else
		{
			while (m[sta.top()] > m[i])
			{
				l[sta.top()] = i;
				sta.pop();
			}
			sta.push(i);
		}
	}
	while (!sta.empty())
		sta.pop();
	sta.push(0);
	for (int i = 1; i <= n + 1; ++i)
	{
		if (m[sta.top()] <= m[i])
			sta.push(i);
		else
		{
			while (m[sta.top()] > m[i])
			{
				r[sta.top()] = i;
				sta.pop();
			}
			sta.push(i);
		}
	}
	suml[1] = m[1];
	for (int i = 2; i <= n; ++i)
	{
		suml[i] = suml[l[i]] + (i - l[i]) * m[i];
	}
	sumr[n] = m[n];
	for (int i = n; i >= 1; --i)
	{
		sumr[i] = sumr[r[i]] + (r[i] - i) * m[i];
	}
	for (int i = 2; i <= n; ++i)
	{
		if (m[i - 1] == m[i])
			continue;
		else if (m[i - 1] < m[i])
		{
			update(1, 1, n, i, r[i] - 1, m[i]);
			cout << i << "  " << r[i] - 1 << "     " << m[i] << endl;
			res = query(1, 1, n, 1, r[i] - 1);
			if (ans < res)
			{
				ansi = i;
				ans = res;
			}
		}
		else
		{
			update(1, 1, n, l[i] + 1, i, m[i]);
			cout << l[i] + 1 << "  " << i << "     " << m[i] << endl;
			res = query(1, 1, n, 1, n);
			if (ans < res)
			{
				ansi = i;
				ans = res;
			}
		}
		cout << res << endl;
	}
	cout << ansi << endl;
}