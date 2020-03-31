#include <bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;

int n, m;
char mat[1008][1008];
char ansmat[1008][1008];
pii coordinate[28];

bool check(int l, int r)
{
	bool f1 = false, f2 = false;
	for (int i = 1; i < 26; ++i)
	{
		if (coordinate[i].x == coordinate[0].x && coordinate[i].y >= l && coordinate[i].y <= r)
			return false;
		if (1 <= coordinate[i].y && coordinate[i].y < l)
			f1 = true;
		if (coordinate[i].y > r && coordinate[i].y <= m)
			f2 = true;
	}
	return (l == 1 || f1) && (f2 || r == m);
}



void tian(int l, int r, int u, int d, char c)
{
	for (int x = u; x <= d; ++x)
	{
		for (int y = l; y <= r; ++y)
		{
			ansmat[x][y] = c;
		}
	}
}

void gao(int l, int r, int u, int d)
{
	int prex = u - 1;
	for (int x = u; x <= d; ++x)
	{
		int prey = l - 1;
		bool flag = false;
		for (int y = l; y <= r; ++y)
		{
			if (mat[x][y] != '.')
			{
				flag = true;
				tian(prey + 1, y, prex + 1, x, mat[x][y] - 'A' + 'a');
				prey = y;
			}
		}
		if (flag)
		{
			tian(prey + 1, r, prex + 1, x, ansmat[x][prey]);
			prex = x;
		}
	}
	for (int y = l; y <= r; ++y)
	{
		tian(y, y, prex + 1, d, ansmat[prex][y]);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%s", mat[i] + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (mat[i][j] != '.')
				coordinate[mat[i][j] - 'A'] = pii(i, j);
		}
	}
	int ansl, ansr, ansu, ansd, anss = -1;
	for (int l = coordinate[0].y; l >= 1; --l)
	{
		for (int r = coordinate[0].y; r <= m; ++r)
		{
			if (!check(l, r))
				continue;
			int u = 1, d = n;
			for (int i = 1; i < 26; ++i)
			{
				if (coordinate[i].y >= l && coordinate[i].y <= r && coordinate[i].x < coordinate[0].x)
				{
					u = max(u, coordinate[i].x + 1);
				}
				if (coordinate[i].y >= l && coordinate[i].y <= r && coordinate[i].x > coordinate[0].x)
				{
					d = min(d, coordinate[i].x - 1);
				}
			}
			if ((r - l + 1) * (d - u + 1) >= anss)
			{
				anss = (r - l + 1) * (d - u + 1);
				ansl = l, ansr = r, ansu = u, ansd = d;
			}
		}
	}
	tian(ansl, ansr, ansu, ansd, 'a');
	gao(1, ansl - 1, 1, n);
	gao(ansr + 1, m, 1, n);
	gao(ansl, ansr, 1, ansu - 1);
	gao(ansl, ansr, ansd + 1, n);
	for (int i = 0; i < 26; ++i)
	{
		if (coordinate[i].x)
		{
			ansmat[coordinate[i].x][coordinate[i].y] = i + 'A';
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			printf("%c", ansmat[i][j]);
		printf("\n");
	}
}