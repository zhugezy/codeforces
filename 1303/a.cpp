#include <bits/stdc++.h>
#define LL long long
using namespace std;
int T;
char s[108];
int n;
bool all0()
{
	for (int i = 1; i <= n; ++i)
		if (s[i] == '1')
			return false;
	return true;
}
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> s + 1;
		n = strlen(s + 1);
		if (all0())
			cout << 0 << endl;
		else
		{
			int cnt = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (s[i] == '0')
					cnt++;
				else
					break;
			}
			for (int i = n; i >= 1; --i)
			{
				if (s[i] == '0')
					cnt++;
				else
					break;
			}
			int cnt1 = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (s[i] == '1')
					cnt1++;
			}
			cout << n - cnt1 - cnt << endl;
		}
	}
}