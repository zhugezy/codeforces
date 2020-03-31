#include <bits/stdc++.h>
using namespace std;
int n, Q;
bool a[3][100008];

bool check(int l, int r)
{
	return (a[l][r] && (a[l^1][r] || a[l^1][r - 1] || a[l^1][r + 1]));
}
int c1 = 0, c2 = 0, c3 = 0;
int main()
{
	scanf("%d %d", &n, &Q);
	while (Q--)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		l--;
		a[l][r] ^= 1;
		if (!a[l][r])
		{
			if (l == 0)
			{
				if (a[1][r - 1])
					c1--;
				if (a[1][r])
					c2--;
				if (a[1][r + 1])
					c3--;
			}
			else
			{
				if (a[0][r - 1])
					c3--;
				if (a[0][r])
					c2--;
				if (a[0][r + 1])
					c1--;
			}
		}
		else
		{
			if (l == 0)
			{
				if (a[1][r - 1])
					c1++;
				if (a[1][r])
					c2++;
				if (a[1][r + 1])
					c3++;
			}
			else
			{
				if (a[0][r - 1])
					c3++;
				if (a[0][r])
					c2++;
				if (a[0][r + 1])
					c1++;
			}
		}
		printf((c1==0&&c2==0&&c3==0)?"Yes\n":"No\n");
	}
}