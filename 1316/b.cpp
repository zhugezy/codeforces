#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
using namespace std;

int T, n;
string s;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		cin >> s;
		int ans = 1;
		string anss = s;
		for (int k = n; k >= 1; --k)
		{
			string cur;
			for (int i = k - 1; i < n; ++i)
				cur += s[i];
			if ((n - k + 1) % 2 == 0)
			{
				for (int i = 0; i < k - 1; ++i)
					cur += s[i];
			}
			else
			{
				for (int i = k - 2; i >= 0; --i)
					cur += s[i];
			}
			if (cur < anss)
			{
				anss = cur;
				ans = k;
			}
			else if (cur == anss)
			{
				ans = min(ans, k);
			}
		}
		cout << anss << endl << ans << endl;
	}
}