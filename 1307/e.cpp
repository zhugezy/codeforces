#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const LL mod = 1000000007;
const LL inv2 = 500000004;
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

int n, m, a[5008];
int mat[5008][5008];
int cnt[5008][5008];
pii cow[5008];
bool used[5008], usedtype[5008];
vector<int> loc[5008];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		loc[a[i]].pb(i);
		for (int j = 1; j <= n; ++j)
		{
			cnt[i][j] = cnt[i - 1][j] + (a[i] == j);
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d", &cow[i].x, &cow[i].y);
		mat[cow[i].x][cow[i].y] = i;
	}
	int mx = 0;
	LL ans1 = 0, ans2 = 0;
	for (int i = 1; i <= m; ++i)
	{
		if (loc[cow[i].x].size() >= cow[i].y)
		{
			//l -> r
			memset(used, false, sizeof(used));
			memset(usedtype, false, sizeof(usedtype));
			used[i] = true;
			usedtype[cow[i].x] = true;
			int cmax = 1;
			LL cans = 1;
			int d = loc[cow[i].x][cow[i].y - 1];
			for (int j = d - 1; j >= 1; --j)
			{
				int id = mat[a[j]][ cnt[j][ a[j] ] ];
				if (id == i)
					continue;
				if (id && !used[id] && !usedtype[a[j]])
				{
					cmax++;
					used[id] = true;
					usedtype[a[j]] = true;
				}
			}
			memset(usedtype, false, sizeof(usedtype));
			bool _flag = 1;
			for (int j = d + 1; j <= n; ++j)
			{
				int id = mat[a[j]][ cnt[n][ a[j] ] - cnt[j - 1][ a[j] ] ];
				if (id == i)
					continue;
				if (id && !usedtype[a[j]])
				{
					if (!used[id])
					{
						cmax++;
						usedtype[a[j]] = true;
						_flag = 0;
					}
					else
					{
						cout << j << "  *2" << endl;
						cans = cans * 2 % mod;
					}
				}
			}
			if (cmax > mx)
			{
				mx = cmax;
				ans2 = cans - _flag;
				ans1 = _flag;
			}
			else if (cmax == mx)
			{
				ans2 = (ans2 + cans - _flag) % mod;
				ans1 = (ans1 + _flag) % mod;
			}
			cout << ans1 << " ww " << ans2 << endl;
			//r -> l
			memset(used, false, sizeof(used));
			memset(usedtype, false, sizeof(usedtype));
			used[i] = true;
			usedtype[cow[i].x] = true;
			cmax = 1;
			cans = 1;
			d = loc[cow[i].x][loc[cow[i].x].size() - cow[i].y];
			for (int j = d + 1; j <= n; ++j)
			{
				int id = mat[a[j]][ cnt[n][ a[j] ] - cnt[j - 1][ a[j] ] ];
				if (id == i)
					continue;
				if (id && !used[id] && !usedtype[a[j]])
				{
					cmax++;
					used[id] = true;
					usedtype[a[j]] = true;
				}
			}
			memset(usedtype, false, sizeof(usedtype));
			_flag = 1;
			for (int j = d - 1; j >= 1; --j)
			{
				int id = mat[a[j]][ cnt[j][ a[j] ] ];
				if (id == i)
					continue;
				if (id && !usedtype[a[j]])
				{
					if (!used[id])
					{
						_flag = 0;
						usedtype[a[j]] = true;
						cmax++;
					}
					else
					{
						cout << j << "  *2" << endl;
						cans = cans * 2 % mod;
					}
				}
			}
			if (cmax > mx)
			{
				mx = cmax;
				ans2 = cans - _flag;
				ans1 = _flag;
			}
			else if (cmax == mx)
			{
				ans2 = (ans2 + cans - _flag) % mod;
				ans1 = (ans1 + _flag) % mod;
			}
			cout << ans1 << " ww " << ans2 << endl;
		}
	}
	LL endans = (ans2 * inv2 % mod + ans1) % mod;
	if (mx == 0)
		endans = 1;
	cout << mx << " " << endans << endl;
}