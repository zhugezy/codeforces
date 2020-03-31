#include <bits/stdc++.h>
using namespace std;
int n, x[200008], cnt[200008], final[200008];
int temp[200008];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &x[i]);
		cnt[x[i]]++;
		temp[x[i]]++;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (cnt[i] && !final[i - 1])
		{
			cnt[i]--, final[i - 1]++;
		}
		if (cnt[i] && !final[i])
		{
			cnt[i]--, final[i]++;
		}
		if (cnt[i] && !final[i + 1])
		{
			cnt[i]--, final[i + 1]++;
		}
	}
	int ansmax = 0;
	for (int i = 0; i <= n + 1; ++i)
	{
		ansmax += final[i] >= 1;
	}
	memset(cnt, 0, sizeof(cnt));
	memset(final, 0, sizeof(final));
	for (int i = 1; i <= n; ++i)
		cnt[i] = temp[i];
	for (int i = 1; i <= n; ++i)
	{
		if (cnt[i])
		{
			if (final[i - 1])
			{
				final[i - 1] += cnt[i];
				cnt[i] = 0;
			}
			else if (final[i])
			{
				final[i] += cnt[i];
				cnt[i] = 0;
			}
			else
			{
				final[i + 1] += cnt[i];
				cnt[i] = 0;
			}
		}
	}
	int ansmin = 0;
	for (int i = 0; i <= n + 1; ++i)
		ansmin += final[i] >= 1;
	cout << ansmin << " " << ansmax << endl;
}