#include <bits/stdc++.h>
#define MAXN 100000
#define pii pair<int,int>
#define mp make_pair
#define PII_INIT pair<int,int>(1, 0)
using namespace std;
const int mod = 10007;
int n, tre[(MAXN << 2) + 8][4];
pii lazy[(MAXN << 2) + 8];

void pushup(int rt)
{
	for (int i = 1; i <= 3; ++i)
		tre[rt][i] = (tre[rt << 1][i] + tre[rt << 1 | 1][i]) % mod;
}

void modify(int index, int l, int r, pii V)
{
	int a = V.first, b = V.second;
	tre[index][3] = (tre[index][3] * a % mod * a % mod * a % mod +
				   3 * a % mod * a % mod * b % mod * tre[index][2] % mod+
				   3 * a % mod * b % mod * b % mod * tre[index][1] % mod+
				   (r - l + 1) * b % mod * b % mod * b % mod) % mod;
	tre[index][2] = (tre[index][2] * a % mod * a % mod + 
				   2 * a % mod * b % mod * tre[index][1] % mod + 
				   b * b % mod * (r - l + 1) % mod) % mod;
	tre[index][1] = (tre[index][1] * a % mod + (r - l + 1) * b % mod) % mod;
}

void modify_lazy(int index, pii V)
{
	int a = V.first, b = V.second;
	lazy[index] = mp(a * lazy[index].first % mod, (a * lazy[index].second % mod + b) % mod);
}

void pushdown(int rt, int l, int r)
{
	if (lazy[rt] == PII_INIT)
		return;
	int mid = (l + r) >> 1;
	modify(rt << 1, l, mid, lazy[rt]);
	modify(rt << 1 | 1, mid + 1, r, lazy[rt]);
	modify_lazy(rt << 1, lazy[rt]);
	modify_lazy(rt << 1 | 1, lazy[rt]);
	lazy[rt] = PII_INIT;
	return;
}

void build(int rt, int l, int r)
{
	lazy[rt] = PII_INIT;
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}
void update(int rt, int l, int r, int L, int R, pii V)
{
	if (L <= l && r <= R)
	{
		modify(rt, l, r, V);
		modify_lazy(rt, V);
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

int query(int rt, int l, int r, int L, int R, int p)
{
	if (L <= l && r <= R)
		return tre[rt][p];
	pushdown(rt, l, r);
	int mid = (l + r) >> 1;
	int ret = 0;
	if (L <= mid)
		ret += query(rt << 1, l, mid, L, R, p);
	if (mid + 1 <= R)
		ret += query(rt << 1 | 1, mid + 1, r, L, R, p);
	return ret % mod;
}

void print(int rt, int l, int r)
{
	if (l > r)
		return;
	printf("[%d,%d]    lazy = %d,%d", l, r, lazy[rt].first,lazy[rt].second);
	for (int i = 1; i <= 3; ++i)
		printf("    tre[%d] = %d", i, tre[rt][i]);
	printf("\n");
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	print(rt << 1, l, mid);
	print(rt << 1 | 1, mid + 1, r);
}

int main()
{
	int Q;
	while (scanf("%d %d", &n, &Q) && (n != 0 && Q != 0))
	{
		memset(tre, 0, sizeof(tre));
		build(1, 1, n);
		while (Q--)
		{
			int op, x, y, c;
			scanf("%d %d %d %d", &op, &x, &y, &c);
			if (op == 1)
				update(1, 1, n, x, y, mp(1, c));
			else if (op == 2)
				update(1, 1, n, x, y, mp(c, 0));
			else if (op == 3)
				update(1, 1, n, x, y, mp(0, c));
			else
				printf("%d\n", query(1, 1, n, x, y, c));
			//print(1, 1, n);
		}
	}
}