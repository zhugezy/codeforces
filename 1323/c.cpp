#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;

int n;
char s[1000008];
bool flag = false;
int l = -1;
int cur = 0;
int ans = 0;
int main()
{
	scanf("%d %s", &n, s + 1);
	for (int i = 1; i <= n; ++i)
	{
		if (s[i] == '(')
			cur++;
		else
			cur--;
		if (cur < 0 && !flag)
		{
			l = i;
			flag = true;
		}
		if (cur >= 0 && flag)
		{
			//process
			ans += i - l + 1;
			flag = false;
		}
	}
	if (cur != 0)
		cout << -1 << endl;
	else
		cout << ans << endl;
}