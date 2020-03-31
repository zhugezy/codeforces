#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL Mod(LL b, LL mod){return b < mod?b:b%mod+mod;}
int Q;
LL k, l, r, p;

LL qp(LL a, LL b, LL mod)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

LL inv(LL a, LL p)
{
	return qp(a, p - 2, p);
}

int main()
{
	scanf("%d", &Q);
	while (Q--)
	{
		scanf("%I64d %I64d %I64d %I64d", &k, &l, &r, &p);
		LL cur = 0;
		if (k == 1)
		{
			cur = qp(2, r - l + 1, p);
		}
		else
		{
			if (k % p == 0)
				cur = 1;
			else
			{
				LL fm = qp(k, Mod(qp(2, l, p - 1), p - 1), p) - 1 + p;
				if (fm % p == 0)
				{
					cur = qp(2, (r - l + 1), p);
				}
				else
				{
					cur = (qp(k, Mod(qp(2, r + 1, p - 1), p - 1), p) - 1 + p) % p;
					cur = cur * inv(fm, p) % p;
				}
				
			}
		}
		if (k % 2)
		{
			if (p == 2)
				cur = 0;
			cur = cur * inv(qp(2, r - l, p), p) % p;
		}	
		printf("%I64d\n", cur);
	}
}