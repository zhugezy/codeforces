#include <bits/stdc++.h>
#define LL long long
#define MAXN 100000
using namespace std;
const LL mod = 1000000007;
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

LL sum[6][MAXN + 8];
LL tre[6][(MAXN << 2) + 8];
LL lazy[(MAXN << 2) + 8];
int n, Q;
LL a[MAXN + 8];

void pushup(int rt)
{
	for (int i = 0; i <= 5; ++i)
		tre[i][rt] = (tre[i][rt << 1] + tre[i][rt << 1 | 1]) % mod;
}

void build(int rt, int l, int r)
{
	lazy[rt] = -0x3f3f3f3f;
	if (l > r)
		return;
	if (l == r)
	{
		for (int i = 0; i <= 5; ++i)
			tre[i][rt] = qp(l, i) * a[l] % mod;
		return;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
	return;
}

void pushdown(int rt, int l, int r)
{
	if (lazy[rt] >= 0)
	{
		int mid = (l + r) >> 1;
		for (int i = 0; i <= 5; ++i)
		{
			tre[i][rt << 1] = lazy[rt] * (sum[i][mid] - sum[i][l - 1] + mod) % mod;
			tre[i][rt << 1 | 1] = lazy[rt] * (sum[i][r] - sum[i][mid] + mod) % mod;
		}
		lazy[rt << 1] = lazy[rt];
		lazy[rt << 1 | 1] = lazy[rt];
		lazy[rt] = -0x3f3f3f3f;
	}
}

void update(int rt, int l, int r, int L, int R, LL v)
{
	if (L <= l && r <= R)
	{
		lazy[rt] = v;
		for (int i = 0; i <= 5; ++i)
		{
			tre[i][rt] = v * (sum[i][r] - sum[i][l - 1] + mod) % mod;
		}
		return;
	}
	pushdown(rt, l, r);
	int mid = (l + r) >> 1;
	if (mid >= L)
		update(rt << 1, l, mid, L, R, v);
	if (mid + 1 <= R)
		update(rt << 1 | 1, mid + 1, r, L, R, v);
	pushup(rt);
	return;
}

LL query(int rt, int l, int r, int L, int R, int k)
{
	if (L <= l && r <= R)
		return tre[k][rt];
	pushdown(rt, l, r);
	int mid = (l + r) >> 1;
	LL ret = 0;
	if (mid >= L)
		ret = (ret + query(rt << 1, l, mid, L, R, k)) % mod;
	if (mid + 1 <= R)
		ret = (ret + query(rt << 1 | 1, mid + 1, r, L, R, k)) % mod;
	return ret;
}
LL C(LL n, LL m)
{
	int fac[] = {1, 1, 2, 6, 24, 120, 720};
	return fac[n] / fac[m] / fac[n - m];
}
int main()
{
	scanf("%d %d", &n, &Q);
	for (int k = 0; k <= 5; ++k)
		for (int i = 1; i <= 100000; ++i)
			sum[k][i] = (sum[k][i - 1] + qp(i, k)) % mod;
	for (int i = 1; i <= n; ++i)
		scanf("%I64d", &a[i]);
	build(1, 1, n);
	while (Q--)
	{
		char s[2];
		scanf("%s", s);
		if (s[0] == '?')
		{
			int l, r, k;
			scanf("%d %d %d", &l, &r, &k);
			LL ret = 0;
			for (int i = 0; i <= k; ++i)
			{
				ret = (ret + C(k, i) * qp(mod + 1 - l, i) % mod * query(1, 1, n, l, r, k - i) % mod) % mod;
			}
			printf("%I64d\n", ret);
		}
		else
		{
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			update(1, 1, n, l, r, x);
		}
	}
}