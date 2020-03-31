#include <bits/stdc++.h>
#define LL long long
using namespace std;

int n, k, _;
int a, b = -1, arr[508];
bool flag[508];
vector<int> query;
struct Node
{
	int id;
	int v;
	Node(){}
	Node(int _i, int _v)
	{
		id = _i; v = _v;
	}
	bool operator<(const Node& oth) const
	{
		return v > oth.v;
	}
};

void printquery()
{
	printf("?");
	for (int i = 0; i < k; ++i)
		printf(" %d", query[i]);
	printf("\n");
	fflush(stdout);
}
int main()
{
	memset(arr, -1, sizeof(arr));
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; ++i)
		query.push_back(i);
	printquery();
	scanf("%d %d", &a, &_);
	arr[a] = _;
	int cur = a;
	vector<Node> F;
	F.push_back(Node(a, arr[a]));
	for (int add = k + 1; add <= n; ++add)
	{
		Node rem;
		for (int i = 0; i < k; ++i)
		{
			if (query[i] == cur)
			{
				rem = Node(i, cur);
				query[i] = add;
			}
		}
		printquery();
		int x;
		scanf("%d %d", &x, &_);
		arr[x] = _;
		F.push_back(Node(x, arr[x]));
		sort(F.begin(), F.end());
		if (x == add)
		{
			query.clear();
			for (int i = 1; i <= k; ++i)
			{
				if (i != F[0].id)
					query.push_back(i);
			}
			if (add != F[0].id)
				query.push_back(add);
			break;
		}
		else
		{
			cur = F[0].id;
		}
		query[rem.id] = rem.v;
	}
	int cnt = 0;
	for (int i = 0; i < k; ++i)
	{
		if (arr[i] == -1)
		{
			int temp = query[i];
			query[i] = F[0].id;
			printquery();
			int t;
			scanf("%d %d", &t, &_);
			if (t != F.back().id)
			{
				cnt++;
			}
			query[i] = temp;
		}
	}
	printf("! %d\n", cnt + 1);
}