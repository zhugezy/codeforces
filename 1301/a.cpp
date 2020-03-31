#include <bits/stdc++.h>
#define LL long long
using namespace std;
int T, n;
char a[1008], b[1008], c[1008];

bool gao()
{
	for (int i = 0; i < n; ++i)
	{
		if (!(b[i] == c[i] || a[i] == c[i]))
			return false;
	}
	return true;
}
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> a >> b >> c;
		n = strlen(a);
		cout << (gao()? "YES":"NO") << endl;
	}
}