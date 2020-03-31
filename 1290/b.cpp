#include <bits/stdc++.h>
#define LL long long
#define MAXN 200000
using namespace std;

char s[MAXN + 8];
int cnt[MAXN + 8][26];
int n;
int test[26];
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int c = 0; c < 26; ++c)
		{
			cnt[i][c] = cnt[i - 1][c] + (s[i] - 'a' == c);
		}
	}
	int Q;
	scanf("%d", &Q);
	while (Q--)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		int typ = 0;
		for (int c = 0; c < 26; ++c)
		{
			test[c] = cnt[r][c] - cnt[l - 1][c];
			if (test[c])
				typ++;
		}
		if (typ == 1)
		{
			if (l == r)
				printf("Yes\n");
			else
				printf("No\n");
		}
		else if (typ == 2)
		{
			if (s[l] != s[r])
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
			printf("Yes\n");
	}
	return 0;
}