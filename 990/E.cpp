#include <bits/stdc++.h>

using namespace std;
int n,m,k;

int s[1000004];
int c[1000004];
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	int minlen = 0;
	for (int i = 0; i < k; ++i)
	{
		int b;
		scanf("%d",&b);
		s[b]++;
	}
	for (int i = 1; i <= k; ++i)
	{
		int b;
		scanf("%d",&b);
		c[i] = b;
	}
	if (s[0] == 1)
	{
		printf("-1");
		return 0;
	}
	int len = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i]) len++;
		else
		{
			minlen = max(len, minlen);
			len = 0;
		}
	}
	minlen++;
	if (k < minlen)
	{
		printf("-1");
		return 0;
	}
	
	return 0;
}
