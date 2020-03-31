#include <bits/stdc++.h>
#define LL long long
using namespace std;

int T, n;
char s[208];
bool mp[28][28];
int deg[28];
char ans[28];
int loc[28];

bool gao()
{
	int cur = 0, i;
	for (i = 1; i <= 26; ++i)
	{
		int a;
		for (a = 0; a < 26; ++a)
		{
			if (!cur)
			{
				if (!loc[a] && deg[a] == 1)
				{
					ans[i] = a;
					loc[a] = i;
					cur = 1;
					break;
				}
			}
			else
			{
				if (!loc[a] && mp[a][ans[i - 1]])
				{
					ans[i] = a;
					loc[a] = i;
					if (deg[a] == 1)
						cur = 0;
					break;
				}
			}
		}
		if (a >= 26)
			break;
	}
	for (; i <= 26; ++i)
	{
		for (int a = 0; a < 26; ++a)
		{
			if (!loc[a])
			{
				ans[i] = a;
				loc[a] = i;
				break;
			}
		}
	}
	for (i = 1; i < n; ++i)
	{
		if (abs(loc[s[i] - 'a'] - loc[s[i + 1] - 'a']) > 1)
			return false;
	}
	return true;
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> s + 1;
		n = strlen(s + 1);
		memset(mp, false, sizeof(mp));
		memset(deg, 0, sizeof(deg));
		for (int i = 1; i < n; ++i)
			mp[s[i] - 'a'][s[i + 1] - 'a'] = mp[s[i + 1] - 'a'][s[i] - 'a'] = true;
		for (int a = 0; a < 26; ++a)
		{
			for (int b = a + 1; b < 26; ++b)
			{
				if (mp[a][b])
				{
					deg[a]++; 
					deg[b]++;
				}
			}
		}
		memset(loc, 0, sizeof(loc));
		if (!gao())
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
			for (int i = 1; i <= 26; ++i)
				printf("%c", ans[i] + 'a');
			printf("\n");
		}
	}
}