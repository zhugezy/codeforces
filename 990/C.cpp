#include <bits/stdc++.h>

using namespace std;

int lef[300004];
int righ[300004];
char str[300004];

long long res = 0;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		int lf = 1,rf = 1;
		int var = 0;
		int rvar = 0;
		scanf("%s",str);
		int len = strlen(str);
		for (int j = 0; j < len; ++j)
		{
			if (str[j] == '(')
			{
				var--;
			}
			else
			{
				if (var < 0) var++;
				else
				{
					lf = 0;
					rvar++;
				}
			} 
		}
		if (var < 0) rf = 0;  
		if (lf)
		{
			int v = abs(var);
			//printf("lef %d\n",v);
			lef[v]++;
		}
		if (rf)
		{
			//printf("righ %d\n",rvar);
			righ[rvar]++;
		}
	}
	for (int i = 0; i <= 300000; ++i)
	{
		//printf("lef[%d] = %d,righ[%d] = %d\n",i,lef[i],i,righ[i]);
		res += 1ll * lef[i] * righ[i];
	}
	printf("%I64d",res);
}
