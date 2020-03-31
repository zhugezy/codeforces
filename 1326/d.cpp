#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
using namespace std;
int T, n;
char s[1000008];

bool ispa(int l, int r)
{
	int c = l, d = r;
	while (c <= d)
	{
		if (s[c] != s[d])
			return false;
		c++;d--;
	}
	return true;
}
char ss[4000008];
int ll[4000008];
pii gao(int x, int y)
{
	int ans = 0;
	int l = 0;
	ss[l++] = '$';
	ss[l++] = '#';
	for (int i = x; i <= y; ++i)
	{
		ss[l++] = s[i];
		ss[l++] = '#';
	}
	ss[l] = 0;
	int mx = 0, id = 0;
	for (int i = 0; i < l; ++i)
	{
		ll[i] = mx>i?min(ll[2*id-i], mx-i):1;
		while (ss[i+ll[i]]==ss[i-ll[i]])
			ll[i]++;
		if (i + ll[i] > mx)
		{
			mx = i + ll[i];
			id = i;
		}
	}
	int amx = 0, aid = 0;
	for (int i = 0; i < l; ++i)
	{
		if (i - ll[i] + 1 <= 2 && i + ll[i] > amx)
		{
			amx = i + ll[i];
			aid = i;
		}
	}
	//cout << ss << "   " << aid << endl;
	for (int i = 0; i < ll[aid]; ++i)
	{
		if (ss[aid - i] >= 'a' && ss[aid - i] <= 'z')
			ans++;
		if (i != 0 && ss[aid + i] >= 'a' && ss[aid + i] <= 'z')
			ans++;
	}
	for (int i = 0; i < l; ++i)
		{ss[i] = 0; ll[i] = 0;}
	l = 0;
	ss[l++] = '$';
	ss[l++] = '#';
	for (int i = y; i >= x; --i)
	{
		ss[l++] = s[i];
		ss[l++] = '#';
	}
	ss[l] = 0;
	mx = 0, id = 0;
	for (int i = 0; i < l; ++i)
	{
		ll[i] = mx>i?min(ll[2*id-i], mx-i):1;
		while (ss[i+ll[i]]==ss[i-ll[i]])
			ll[i]++;
		if (i + ll[i] > mx)
		{
			mx = i + ll[i];
			id = i;
		}
	}
	amx = 0, aid = 0;
	for (int i = 0; i < l; ++i)
	{
		if (i - ll[i] + 1 <= 2 && i + ll[i] > amx)
		{
			amx = i + ll[i];
			aid = i;
		}
	}
	//cout << ss << "   " << aid << endl;
	int temp = 0;
	for (int i = 0; i < ll[aid]; ++i)
	{
		if (ss[aid - i] >= 'a' && ss[aid - i] <= 'z')
			temp++;
		if (i != 0 && ss[aid + i] >= 'a' && ss[aid + i] <= 'z')
			temp++;
	}
	//cout << "ans = " << ans << "  temp = " << temp << endl;
	if (ans <= temp)
		return pii(y - temp + 1, y);
	else
		return pii(x, x + ans - 1);
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int l = 1, r = n;
		while (l <= r)
		{
			if (s[l] == s[r])
			{
				l++;
				r--;
			}
			else
				break;
		}
		//cout << l << "   " << r << endl;
		if (l > r)
		{
			printf("%s\n", s + 1);
		}
		else
		{
			pii cur = gao(l, r);
			for (int i = 1; i < l; ++i)
				printf("%c", s[i]);
			for (int i = cur.first; i <= cur.second; ++i)
				printf("%c", s[i]);
			for (int i = r + 1; i <= n; ++i)
				printf("%c", s[i]);
			printf("\n");
		}

	}
}