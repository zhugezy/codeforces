#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
int T, a, b, p, n;
char s[100008];

bool check(int x)
{
	int cur = 0;
	char curletter = 0;
	for (int i = x; i <= n - 1; ++i)
	{
		if (s[i] != curletter)
		{
			if (s[i] == 'A')
				cur += a;
			else
				cur += b;
			curletter = s[i];
		}
	}
	return cur <= p;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d %s", &a, &b, &p, s + 1);
		n = strlen(s + 1);
		int l = 1, r = n;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (check(mid))
				r = mid;
			else
				l = mid + 1;
		}
		printf("%d\n", l);
	}
}