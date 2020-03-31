#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;
int n, p[300008], tre[300008 << 2], lazy[300008 << 2], loc[300008];
void pushup(int rt)
{
	tre[rt] = max(tre[rt << 1], tre[rt << 1 | 1]);
}

void pushdown(int rt)
{
	if (!lazy[rt])
		return;
	lazy[rt << 1] += lazy[rt];
	lazy[rt << 1 | 1] += lazy[rt];
	tre[rt << 1] += lazy[rt];
	tre[rt << 1 | 1] += lazy[rt];
	lazy[rt] = 0;
}

void update(int rt, int l, int r, int L, int R, int V)
{
	if (L <= l && r <= R)
	{
		tre[rt] += V;
		lazy[rt] += V;
		return;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (L <= mid)
		update(rt << 1, l, mid, L, R, V);
	if (mid + 1 <= R)
		update(rt << 1 | 1, mid + 1, r, L, R, V);
	pushup(rt);
}


int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &p[i]);
		loc[p[i]] = i;
	}
	printf("%d ", n);
	int cur = n + 1;
	for (int i = 1; i < n; ++i)
	{
		int q;
		scanf("%d", &q);
		update(1, 1, n, 1, q, -1);
		//print();
		if (tre[1] <= 0)
		{
			while (tre[1] <= 0)
			{
				cur--;
				update(1, 1, n, 1, loc[cur], 1);
				//print();
			}
			update(1, 1, n, 1, loc[cur], -1);
			//print();
			cur++;
		}
		printf("%d ", cur - 1);
	}
	printf("\n");
}