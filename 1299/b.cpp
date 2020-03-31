#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
int n;
pii arr[100008];

pii gao(pii u, pii v)
{
	return make_pair(u.x - v.x, u.y - v.y);
}

bool judge()
{
	for (int i = 0; i * 2 < n; ++i)
	{
		int ii = (i + 1) % n;
		int j = (i + n / 2) % n;
		int jj = (j + 1) % n;
		pii u = gao(arr[ii], arr[i]), v = gao(arr[jj], arr[j]);
		if ((u.x != v.x || u.y != v.y) && ((u.x != -v.x || u.y != -v.y)))
			return false;
	}
	return true;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &arr[i].x, &arr[i].y);
	if (n % 2)
	{
		cout << "No" << endl;
	}
	else
	{
		if (judge())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}