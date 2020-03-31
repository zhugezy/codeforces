#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
string a[12];
int n, m;
int main()
{
	cin >> n >> m;
	if (n == 1)
	{
		if (m == 0)
			cout << 1 << endl;
		else
			cout << -1 << endl;
	}
	else if (n == 2)
	{
		if (m == 0)
			printf("1 2\n");
		else
			cout << -1 << endl;
	}
	else if (n == 3)
	{
		if (m == 0)
			printf("1 2 4\n");
		else if (m == 1)
			printf("1 2 3\n");
		else
			cout << -1 << endl;
	}
	else if (n == 4)
	{
		if (m == 0)
			printf("1 2 4 8\n");
		else if (m == 1)
			printf("1 2 3 8\n");
		else if (m == 2)
			printf("1 2 3 5\n");
		else
			cout << -1 << endl;
	}
	else if (n == 5)
	{
		if (m == 0)
			printf("1 2 4 8 16\n");
		else if (m == 1)
			printf("1 2 3 16 32\n");
		else if (m == 2)
			printf("1 2 3 5 10000\n");
		else if (m == 3)
			printf("1 2 3 5 8\n");
		else if (m == 4)
			printf("1 2 3 4 5\n");
		else
			printf("-1\n");
	}
	else if (n == 6)
	{
		if (m == 0)
			printf("1 2 4 8 16 32\n");
		else if (m == 1)
			printf("1 2 3 16 32 64\n");
		else if (m == 2)
			printf("1 2 3 5 32 64\n");
		else if (m == 3)
			printf("1 2 3 5 8 64\n");
		else if (m == 4)
			printf("1 2 3 4 5 64\n");
		else if (m == 5)
			printf("1 2 3 4 5 8\n");
		else if (m == 6)
			printf("1 2 3 4 5 6\n");
		else
			printf("-1\n");
	}
	else
	{
		
	}
	return 0;
}