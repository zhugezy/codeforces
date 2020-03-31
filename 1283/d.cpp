#include <bits/stdc++.h>
using namespace std;

int x[200008];

struct Node
{
	int l, r, d;
	Node(){}
	Node(int _l, int _r, int _d)
	{
		l = _l; r = _r; d = _d;
	}
	bool operator<(const Node& oth) const
	{
		return d < oth.d;
	}
}arr[200008];

vector<int> vec;
long long ans = 0;
int n, m;
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &x[i]);
	sort(x + 1, x + n + 1);
	for (int i = 1; i < n; ++i)
	{
		arr[i].d = x[i + 1] - x[i] - 1;
		arr[i].l = x[i] + 1, arr[i].r = x[i + 1] - 1;
	}
	sort(arr + 1, arr + n);
	int start = n;
	for (int i = 1; i < n; ++i)
	{
		if (arr[i].d)
		{
			start = i;
			break;
		}
	}
	for (int v = 1; m > 0; ++v)
	{
		if (m >= 2)
		{
			vec.push_back(x[1] - v);
			vec.push_back(x[n] + v);
			ans += 2 * v, m -= 2;
		}
		else if (m == 1)
		{
			vec.push_back(x[1] - v);
			ans += v, m--;
		}
		for (int i = start; i < n && m > 0; ++i)
		{
			if (m >= 2 && arr[i].d >= 2)
			{
				ans += 2 * v, arr[i].d -= 2, m -= 2;
				vec.push_back(arr[i].l++);
				vec.push_back(arr[i].r--);
			}
			else if (arr[i].d >= 1)
			{
				ans += v, arr[i].d -= 1, start = i + 1, m--;
				vec.push_back(arr[i].l++);
			}
			else
			{
				start = i + 1;
			}
		}
	}
	cout << ans << endl;
	for (auto t: vec)
		printf("%d ", t);
	printf("\n");
}