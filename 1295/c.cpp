#include <bits/stdc++.h>
#define LL long long
using namespace std;
char s[100008], t[100008];
vector<int> v[28];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i < 26; ++i)
			v[i].clear();
		scanf("%s %s", s + 1, t + 1);
		int slen = strlen(s + 1), tlen = strlen(t + 1);
		for (int i = 1; i <= slen; ++i)
		{
			v[s[i] - 'a'].push_back(i);
		}
		int ans = 0, id = slen + 2;
		for (int i = 1; i <= tlen; ++i)
		{
			if (!v[t[i] - 'a'].size())
			{
				ans = -1;
				break;
			}
			auto p = upper_bound(v[t[i] - 'a'].begin(), v[t[i] - 'a'].end(), id);
			if (p == v[t[i] - 'a'].end())
			{
				ans++, id = 0;
			}
			p = upper_bound(v[t[i] - 'a'].begin(), v[t[i] - 'a'].end(), id);
			id = *p;
		}
		printf("%d\n", ans);
	}
}