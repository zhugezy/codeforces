#include <bits/stdc++.h>
using namespace std;
int T;
int main()
{
	cin >> T;
	while (T--)
	{
		int n;
		int sum = 0;
		cin >> n;
		int x;
		int od = 0, ev = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> x;
			sum += x;
			od += (x % 2 == 1);
			ev += (x % 2 == 0);
		}
		if (sum % 2 || (od && ev))
			printf("YES\n");
		else
			printf("NO\n");
	}
	
}