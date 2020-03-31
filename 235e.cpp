#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
using namespace std;
const int mod = 1 << 30;
int prime[2008], mu[2008];
bool notprime[2008];
int ind = 0;
int _gcd[2008][2008];
int gcd(int a, int b)
{
	return b?gcd(b,a%b):a;
}
int gcd(int a, int b, int c)
{
	return gcd(gcd(a, b), c);
}

void getprime()
{
	mu[1] = 1;
	notprime[1] = true;
	for (int i = 2; i <= 2000; ++i)
	{
		if (!notprime[i])
		{
			prime[++ind] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= ind && i * prime[j] <= 2000; ++j)
		{
			notprime[i * prime[j]] = true;
			if (i % prime[j] == 0)
			{
				mu[i * prime[j]] = 0;
				break;
			}
			mu[i * prime[j]] = -mu[i];
		}
	}
	for (int i = 2; i <= 2000; ++i)
	{
		mu[i] = (mu[i] + mod) % mod;
	}
}

LL f(int n, int d, int k)
{
	LL ret = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (_gcd[i*d][k] == 1)
			ret = (ret + n / i) % mod;
	}
	return ret;
}

int a, b, c;
int main()
{
	getprime();
	for (int i = 1; i <= 2000; ++i)
		for (int j = 1; j <= 2000; ++j)
			_gcd[i][j] = gcd(i, j);
	cin >> a >> b >> c;
	if (a > b)
		swap(a, b);
	if (b > c)
		swap(b, c);
	if (a > b)
		swap(a, b);
	LL ans = 0;
	for (int k = 1; k <= c; ++k)
	{
		for (int d = 1; d <= a; ++d)
		{
			ans = (ans + 1LL * mu[d] * (c / k) % mod * f(a / d, d, k) % mod * f(b / d, d, k) % mod) % mod;
		}
	}
	cout << ans << endl;
	
}