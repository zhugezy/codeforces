#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define MAXN 1000000
#define LL long long
using namespace std;

int prime[MAXN + 8];
bool notprime[MAXN + 8];
int ind = 0;
void getprime()
{
	notprime[1] = true;
	for (int i = 2; i <= MAXN; ++i)
	{
		if (!notprime[i])
		{
			prime[++ind] = i;
		}
		for (int j = 1; j <= ind && i * prime[j] <= MAXN; ++j)
		{
			notprime[i * prime[j]] = true;
			if (i % prime[j] == 0)
				break;
		}
	}
}

//unordered_map<LL, LL> _check;
LL check(LL x)   //check if x == p^e+1.
{
	LL rem = x;
	x--;
	for (int j = 1; j <= ind && prime[j] * prime[j] <= x; ++j)
	{
		if (x % prime[j] == 0)
		{
			while (x % prime[j] == 0)
				x /= prime[j];
			if (x == 1)
				return prime[j];
			else
				return 0;
		}
	}
	if (x > 1)
		return x;
	else
		return 0;
}

LL A;
map<LL, vector<LL>> vec;
unordered_map<LL, LL> mp[2];
int main()
{
	getprime();
	cin >> A;
	for (LL i = 1; i * i <= A; ++i)
	{
		if (A % i == 0)
		{
			LL ci = check(i);
			if (ci)
			{
				vec[ci].push_back(i);
			}
			LL j = A / i;
			LL cj = check(j);
			if (j != i && cj)
				vec[cj].push_back(j);
		}
	}
	mp[0][1] = 1;
	int c = 1;
	for (auto p: vec)
	{
		mp[c].clear();
		for (auto x: mp[c^1])
		{
			mp[c][x.first] += x.second;
			for (auto v: p.second)
			{
				if (A % (x.first) == 0 && (A / (x.first)) % v == 0)
				{
					mp[c][(x.first)*v] += x.second;
				}
			}
		}
		c ^= 1;
	}
	cout << mp[c^1][A] << endl;
}