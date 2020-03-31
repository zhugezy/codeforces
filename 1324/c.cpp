#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;
int T;
char s[200008];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		int c = 0, ans = 0;
		for (int i = 1; i <= n + 1; ++i)
		{
			if (s[i] == 'L')
			{
				c++;
			}
			else
			{
				ans = max(ans, c);
				c = 0;
			}
		}
		cout << ans + 1 << endl;
	}
}