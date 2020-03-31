#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
int T, _a[3];
int main()
{
	cin >> T;
	while (T--)
	{
		int ans = 0;
		cin >> _a[0] >> _a[1] >> _a[2];
		sort(_a, _a + 3);
		reverse(_a, _a + 3);
		int a = _a[0], b = _a[1], c = _a[2];
		if (c){ans++; c--;}
		if (b){ans++; b--;}
		if (a){ans++; a--;}
		if (a&&b){ans++;a--;b--;}
		if (a&&c){ans++;a--;c--;}
		if (b&&c){ans++;b--;c--;}
		if(a&&b&&c){ans++;a--;b--;c--;}
		cout << ans << endl;
	}
}