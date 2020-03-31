#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL mod = 998244353;
int n, Q;
LL p[200008];
LL mul[200008], sum[200008];
set<int> st;
LL f[200008];
LL qp(LL a, LL b)
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

LL inv(LL a)
{
	return qp(a, mod - 2);
}
LL ans = 0;
void renew(int c, int cc)
{
	ans = (ans - f[c] + mod) % mod;
	f[c] = ((sum[cc - 2] - sum[c - 1] + mod) % mod * inv(mul[c - 1]) % mod + 1) % mod * inv(mul[cc - 1]) % mod * mul[c - 1] % mod;
	ans = (ans + f[c]) % mod;
}

int main()
{
	scanf("%d %d", &n, &Q);
	mul[0] = sum[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%I64d", &p[i]);
		p[i] = p[i] * inv(100) % mod;
		mul[i] = mul[i - 1] * p[i] % mod;
		sum[i] = (sum[i - 1] + mul[i]) % mod;
	}
	renew(1, n + 1);
	st.insert(1);
	st.insert(n + 1);
	while (Q--)
	{
		int x;
		scanf("%d", &x);
		if (st.find(x) != st.end())
		{
			st.erase(x);
			ans = (ans - f[x] + mod) % mod;
			f[x] = 0;
			renew(*(--(st.lower_bound(x))), *(st.upper_bound(x)));
		}
		else
		{
			st.insert(x);
			renew(*(--(st.lower_bound(x))), x);
			renew(x, *(st.upper_bound(x)));
		}
		printf("%I64d\n", ans);
	}
}