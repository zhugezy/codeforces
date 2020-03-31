#include <bits/stdc++.h>
using namespace std;
const int H = 60;
double dp[500008][68];
vector<int> son[500008];
int fa[500008];


int main()
{
	int Q;
	scanf("%d", &Q);
	int cid = 1;
	fa[1] = 0;
	for (int i = 1; i <= Q; ++i)
	{
		for (int h = 0; h <= H; ++h)
		{
			dp[i][h] = 1;
		}
	}
	while (Q--)
	{
		int op, v;
		scanf("%d %d", &op, &v);
		if (op == 1)
		{
			cid++;
			fa[cid] = v;
			son[v].push_back(cid);
			int cur = fa[cid], pre = cid, h = 0;
			double preval;
			while (cur && h <= H)
			{
				double tt = dp[cur][h];
				if (h == 0)
					dp[cur][h] *= 0.5;
				else
				{
					dp[cur][h] *= (1 + dp[pre][h - 1]) / (1 + preval);
				}
				preval = tt;
				pre = cur;
				cur = fa[cur];
				h++;
			}
		}
		else
		{
			double ans = 0;
			for (int h = 0; h < H; ++h)
			{
				ans += (h + 1) * (dp[v][h + 1] - dp[v][h]);
			}
			printf("%.10f\n", ans);
		}
	}
}