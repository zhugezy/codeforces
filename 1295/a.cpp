#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> a;
		while (n >= 2)
		{
			a.push_back(1);
			n -= 2;
		}
		if (n)
			a[0] = 7;
		for (auto x: a)
			cout << x;
		cout << endl;
	}
}