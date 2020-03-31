#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
int T, n, a, b;
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> a >> b;
		int s = a + b;
		int la = max(1, s + 1 - n);
		int lb = min(n, s + 1 - la);
	}
}