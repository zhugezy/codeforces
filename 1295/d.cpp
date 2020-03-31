#include <bits/stdc++.h>
#define LL long long
using namespace std;
#define MAXN 1000000

LL gcd(LL a, LL b)
{
	return b?gcd(b,a%b):a;
}

LL a, m;

LL f(LL x, LL mm)
{
	vector<LL> v;
	for (LL i = 2; i * i <= mm; ++i)
	{
		if (mm % i == 0)
		{
			v.push_back(i);
			while (mm % i == 0)
				mm /= i;
		}
	}
	if (mm > 1)
		v.push_back(mm);
	LL ret = 0;
	int Len = v.size();
	for (int msk = 1; msk < (1 << Len); ++msk)
	{
		LL cur = 1;
		int cnt = 0;
		for (int i = 0; i < Len; ++i)
		{
			if (msk & (1 << i))
			{
				cnt++;
				cur *= v[i];
			}
		}
		if (cnt & 1)
			ret += x / cur;
		else
			ret -= x / cur;
	}
	return x - ret;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> a >> m;
		LL g = gcd(a, m);
		cout << f((a + m - 1) / g, m / g) - f((a - 1) / g, m / g) << endl;
	}
}