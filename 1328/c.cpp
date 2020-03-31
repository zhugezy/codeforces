#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define MAXN 1000000
using namespace std;

int T, n;
char x[50004];
vector<char> a, b;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		a.clear();
		b.clear();
		scanf("%s", x + 1);
		if (x[1] == '2')
		{
			a.pb('1');
			b.pb('1');
		}
		bool flag = false;
		for (int i = 2; i <= n; ++i)
		{
			if (!flag)
			{
				if (x[i] == '2')
				{
					a.pb('1');
					b.pb('1');
				}
				else if (x[i] == '0')
				{
					a.pb('0');
					b.pb('0');
				}
				else
				{
					flag = true;
					a.pb('1');
					b.pb('0');
				}
			}
			else
			{
				if (x[i] == '2')
				{
					a.pb('0');
					b.pb('2');
				}
				else if (x[i] == '0')
				{
					a.pb('0');
					b.pb('0');
				}
				else
				{
					flag = true;
					a.pb('0');
					b.pb('1');
				}
			}
		}
		for (auto p: a)
			cout << p;
		cout << endl;
		for (auto p: b)
			cout << p;
		cout << endl;
	}
}