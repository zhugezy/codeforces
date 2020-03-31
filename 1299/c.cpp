#include <bits/stdc++.h>
#define LL long long
#define MAXN 1000000
#define pid pair<int,double>
using namespace std;

int n;
int arr[MAXN + 4];
LL sumarr[MAXN + 4];
double tre[(MAXN << 2) + 4], lazy[(MAXN << 2) + 4];

void pushup(int rt)
{
	tre[rt] = tre[rt << 1] + tre[rt << 1 | 1];
}

void pushdown(int rt, int l, int r)
{
	if (lazy[rt] <= 1e-6)
		return;
	int mid = (l + r) >> 1;
	tre[rt << 1] = lazy[rt] * (mid - l + 1);
	tre[rt << 1 | 1] = lazy[rt] * (r - mid);
	lazy[rt << 1] = lazy[rt];
	lazy[rt << 1 | 1] = lazy[rt];
	lazy[rt] = 0;
	return;
}

void build(int rt, int l, int r)
{
	if (l == r)
	{
		tre[rt] = arr[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt, int l, int r, int L, int R, double V)
{
	if (L <= l && r <= R)
	{
		tre[rt] = V * (r - l + 1);
		lazy[rt] = V;
		return;
	}
	int mid = (l + r) >> 1;
	if (L <= mid)
		update(rt << 1, l, mid, L, R, V);
	if (mid + 1 <= R)
		update(rt << 1 | 1, mid + 1, r, L, R, V);
	pushup(rt);
}

double querysum(int rt, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
		return tre[rt];
	pushdown(rt, l, r);
	int mid = (l + r) >> 1;
	double s1 = 0, s2 = 0;
	if (L <= mid)
		s1 = querysum(rt << 1, l, mid, L, R);
	if (mid + 1 <= R)
		s2 = querysum(rt << 1 | 1, mid + 1, r, L, R);
	return s1 + s2;
}

pid query(int rt, int l, int r, int L)
{
	//cout << l << "  " << r << endl;
	int mid = (l + r) >> 1;
	if (l == r)
		return make_pair(l, tre[rt]);
	if (L <= mid)
	{
		pid p1 = query(rt << 1, l, mid, L), p2 = query(rt << 1 | 1, mid + 1, r, L);
		double sp = querysum(rt << 1, l, mid, max(l, L), mid);
		//cout << a1 << " aa " << a2 << endl;
		//cout << s1 << " ss " << s2 << endl;
		if (p1.second / (p1.first - L + 1) <= (sp + p2.second) / (p2.first - L + 1))
			return make_pair(p1.first, p1.second);
		else
			return make_pair(p2.first, sp + p2.second);
	}
	else
		return query(rt << 1 | 1, mid + 1, r, L);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		{scanf("%d", &arr[i]); sumarr[i] = sumarr[i - 1] + arr[i];}
	build(1, 1, n);
	for (int i = 1; i <= n; ++i)
	{
		//cout << "i  =  " << i << endl;
		int a = query(1, 1, n, i).first;
		//cout << "a = " << a << endl;
		double s = querysum(1, 1, n, i, a);
		update(1, 1, n, i, a, s / (a - i + 1));
	}
	for (int i = 1; i <= n; ++i)
		printf("%.10f\n", querysum(1, 1, n, i, i));
}