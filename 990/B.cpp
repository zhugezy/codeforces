#include <bits/stdc++.h>

using namespace std;

int n,k;
int arr[200008];
int main()
{
	scanf("%d %d",&n,&k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	int res = n;
	int cnt = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		if (arr[i + 1] == arr[i])
		{
			cnt++;
		}
		else if (arr[i + 1] - arr[i] <= k)
		{
			res -= (cnt + 1);
			cnt = 0;
		}
		else
		{
			cnt = 0;
		}
	}
	printf("%d",res);
	return 0;
}
