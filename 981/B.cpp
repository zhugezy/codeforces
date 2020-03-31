#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int n;
	int v;
	int vis;
}No;

bool cmp(Node a, Node b)
{
	return a.n < b.n;
}

vector<Node>vec;
int n,m;

int bs(int len, int key)
{
	int left = 0;
	int right = len - 1;
	int mid;
	
	while (left <= right) 
	{
		mid = (left + right) / 2;
		if (key < vec[mid].n) 
		{
			right = mid - 1;
		} 
		else if (vec[mid].n < key) 
		{
			left = mid + 1;
		} 
		else 
		{
			return mid;
		}
	}
	return -1;
}
int main()
{
	int a,x;
	long long res = 0;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d",&a,&x);
		No.n = a,No.v = x,No.vis = 0;
		vec.push_back(No);
	}
	sort(vec.begin(),vec.end(),cmp);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d %d",&a,&x);
		int in = bs(n,a);
		if (in == -1)
		{
			res += x;
		}
		else
		{
			res += max(x,vec[in].v);
			vec[in].vis = 1;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if(!vec[i].vis)
		{
			res += vec[i].v;
		}
	}
	printf("%I64d",res);
}
