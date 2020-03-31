#include <bits/stdc++.h>
#define LL long long
using namespace std;

int n, m;
int a = -1, b = -1;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		a = -1, b = -1;
		int _;
		cin >> _ >> n >> m;
		for (int i = 1; i <= n; ++i)
		{
			int __;
			cin >> __;
			a = max(a, __);
		} 
		for (int i = 1; i <= m; ++i)
		{
			int __;
			cin >> __;
			b = max(b, __);
		} 
		cout << (a>b?"YES":"NO") << endl;
	}
}