#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
int T;
LL a, b, x, y;
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> a >> b >> x >> y;
		cout << max(max(a * y, b * x), max(a * (b - y - 1), b * (a - x - 1))) << endl;
	}
}