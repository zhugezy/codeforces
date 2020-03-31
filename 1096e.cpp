#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL mod = 998244353;

LL fac[100008], inv[100008], invfac[100008];

void init()
{
	fac[0] = invfac[0] = fac[1] = invfac[1] = inv[1] = 1;
	for (int i = 2; i <= 100000; ++i)
	{
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		fac[i] = fac[i - 1] * i % mod;
		invfac[i] = invfac[i - 1] * inv[i] % mod;
	}
}

LL C(LL n, LL m)
{
	//printf("C(%I64d,%I64d)\n", n, m);
	return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

LL f(LL n, LL p)
{
	//printf("f(%I64d,%I64d) = %I64d\n", n, p, C(n + p - 1, p - 1));
	return C(n + p - 1, p - 1);
}

LL g(LL n, LL m, LL p)
{
	if (p == 0)
		return n == 0;
	LL pow_1 = 1;
	LL ret = 0;
	for (int i = 0; i <= p && i * (m + 1) <= n; ++i)
	{
		ret = (ret + pow_1 * C(p, i) % mod * f(n - i * (m + 1), p) % mod) % mod;
		pow_1 = pow_1 * (mod - 1) % mod;
	}
	//printf("g(%I64d,%I64d,%I64d) = %I64d\n", n, m, p, ret);
	return ret;
}

LL qp(LL a, LL b){LL ret = 1;while (b){if (b & 1)ret = ret * a % mod;a = a * a % mod;b >>= 1;}return ret;}

LL getinv(LL n){return qp(n, mod - 2);}
LL p, r, s;
int main()
{
	init();
	cin >> p >> s >> r;
	LL ans = 0;
	for (int a1 = r; a1 <= s; ++a1)
	{
		if (a1 == 0)
		{
			if (s == 0)
				ans = (ans + inv[p]) % mod;
			continue;
		}
		for (int q = 1; q <= p && s-q*a1 >= 0; ++q)
		{
			ans = (ans + C(p - 1, q - 1) * g(s - q*a1, a1 - 1, p - q) % mod * inv[q] % mod) % mod;
		}
		//printf("a1 = %d   ans = %I64d\n", a1, ans);
	}
	ans = ans * getinv(f(s - r, p)) % mod;
	cout << ans << endl;
}