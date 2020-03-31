#include <bits/stdc++.h>

using namespace std;
int n;
int mat[1008][1008];
void solve(int flag, int a, int b)
{
	if (a == 1 && b == 1)
	{
		if (n == 3 || n == 2)
		{
			printf("NO");
			return;
		}
	}
	printf("YES\n");
	for (int i = 1; i <= n - a; ++i)
	{
		mat[i][i + 1] = 1;
		mat[i + 1][i] = 1;
	}
	/*for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				printf("%d",mat[i][j]);
			}
			printf("\n");
		}*/
	if (!flag)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				printf("%d",mat[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (i != j)
				{
					if (mat[i][j] == 0) mat[i][j] = 1;
					else mat[i][j] = 0;
				}
				printf("%d",mat[i][j]);
			}
			printf("\n");
		}
	}
}

int main()
{
	int a, b;
	scanf("%d %d %d",&n,&a,&b);
	if (a > 1)
	{
		if (b != 1)
		{
			printf("NO");
			return 0;
		}
		else
		{
			solve(0,a,b);
		}
	}
	else
	{
		solve(1,b,a);
	}
	return 0;
}
