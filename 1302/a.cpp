#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1008][1008];
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	}

	for (int i = 1; i <= n; ++i)
	{
		int mx = -1;
		vector<int> mxid;
		for (int j = 1; j <= m; ++j)
		{
			if (a[i][j] > mx)
			{
				mx = a[i][j];
				mxid.clear();
				mxid.push_back(j);
			}
			else if (a[i][j] == mx)
				mxid.push_back(j);
		}
		if (mxid.size() == 1)
		{
			int x = i, y = mxid[0];
			int xx = 1;
			for (xx = 1; xx <= n; ++xx)
			{
				if (a[xx][y] < a[x][y])
					break;
			}
			if (xx > n)
			{
				printf("%d %d\n", x, y);
				return 0;
			}
		}
	}
	printf("0 0\n");
}