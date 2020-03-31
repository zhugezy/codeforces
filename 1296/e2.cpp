#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;
int n;
char str[MAXN + 4];
int tre[(MAXN + 4) << 2];

void pushup(int rt)
{
	tre[rt] = max(tre[rt << 1], tre[rt << 1 | 1]);
}

void update(int rt, int l, int r, int X, int V)
{
	if (l == r)
	{
		tre[rt] = V;
		return;
	}
	int mid = (l + r) >> 1;
	if (X <= mid)
		update(rt << 1, l, mid, X, V);
	else
		update(rt << 1 | 1, mid + 1, r, X, V);
	pushup(rt);
}

int query(int rt, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
		return tre[rt];
	int ret = -1;
	int mid = (l + r) >> 1;
	if (L <= mid)
		ret = max(ret, query(rt << 1, l, mid, L, R));
	if (mid + 1 <= R)
		ret = max(ret, query(rt << 1 | 1, mid + 1, r, L, R));
	return ret;
}
int ans[MAXN + 4];
int main()
{
	scanf("%d %s", &n, str + 1);
	for (char ch = 'a'; ch <= 'z'; ++ch)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (str[i] == ch)
			{
				int q = query(1, 1, n, i, n);
				update(1, 1, n, i, q + 1);
			}
		}
	}
	int mx = -1;
	for (int i = 1; i <= n; ++i)
	{
		ans[i] = query(1, 1, n, i, i);
		mx = max(mx, ans[i]);
	}
	printf("%d\n", mx);
	for (int i = 1; i <= n; ++i)
		printf("%d%c", ans[i], " \n"[i==n]);
}