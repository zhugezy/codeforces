#include <bits/stdc++.h>
#define LL long long
#define pb push_back
using namespace std;
int n;
char s[100008];
LL cnt[100008][28];
vector<int> loc[28];
LL ans = 0;
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
	{
		loc[s[i] - 'a'].pb(i);
		for (int c = 0; c < 26; ++c)
		{
			cnt[i][c] = cnt[i - 1][c] + (s[i] - 'a' == c);
		}
	}
	for (int c = 0; c < 26; ++c)
		ans = max(ans, cnt[n][c]);
	for (int c = 0; c < 26; ++c)
	{
		for (int d = 0; d < 26; ++d)
		{
			LL temp = 0;
			for (auto x: loc[c])
			{
				temp += cnt[n][d] - cnt[x][d];
			}
			ans = max(ans, temp);
		}
	}
	cout << ans << endl;
}