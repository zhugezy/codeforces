#include <bits/stdc++.h>

using namespace std;

long long n, m, a, b;
int main()
{
	scanf("%I64d %I64d %I64d %I64d",&n,&m,&a,&b);
	
	long long q = n / m;
	long long res1 = (n - q * m) * b;
	long long res2 = ((q + 1) * m - n) * a;
	printf("%I64d",min(res1,res2));
	return 0;
}
