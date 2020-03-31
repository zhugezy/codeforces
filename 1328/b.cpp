#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define MAXN 1000000
using namespace std;

LL T, n, k;
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		k = n * (n - 1) / 2 - k + 1;
		LL sum = 0, i;
		for (i = 1; i <= n; ++i)
		{
			sum += n - i;
			if (sum >= k)
			{
				break;
			}
		}
		sum -= n - i;
		int j = i + k - sum;
		//cout << i << "  " << j << endl;
		for (int p = 1; p <= n; ++p)
		{
			printf("%c", (p==i||p==j)?'b':'a');
		}
		printf("\n");
	}
}