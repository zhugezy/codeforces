#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define MAXN 1000000
using namespace std;

int T, n, m;
LL a, b;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		cout << (b - (a % b)) % b << endl;
	}
}