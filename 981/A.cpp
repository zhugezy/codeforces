#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char str[104];

bool ispa(int i,int j)
{
	int mid = (i + j) / 2;
	for (int pi = i; pi <= mid; ++pi)
	{
		if (str[pi] != str[i + j - pi]) return false;
	}
	return true;
}

int main()
{
	int res = 0;
	scanf("%s",str);
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		for (int j = i; j < len; ++j)
		{
			if(!ispa(i,j)) res = max(res, j - i + 1);
		}
	}
	printf("%d",res);
}
