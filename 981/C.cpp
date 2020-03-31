#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	vector<int> nxt;
};

Node arr[100008];
int cnt[100008];
queue<int> que;
int main()
{
	int flag = 0;
	int n;
	scanf("%d",&n);
	int a,b;
	for (int i = 0; i < n - 1; ++i)
	{
		scanf("%d %d",&a,&b);
		arr[a].nxt.push_back(b);
		arr[b].nxt.push_back(a);
		cnt[a]++,cnt[b]++;
	}
	for (int i = 1; i <= 100000; ++i)
	{
		if (cnt[i] >= 3) flag++;
	}
	if (flag >= 2)
	{
		printf("No");
	}
	else
	{
		printf("Yes\n");
		int i;
		for (i = 1; i <= 100000; ++i)
		{
			if (cnt[i] >= 3)
			{
				int res = 0;
				for (int j = 0; j < cnt[i]; ++j)
				{
					int end;
					int pre = i;
					int cur = arr[i].nxt[j];
					while (1)
					{
						//printf("pre = %d cur = %d\n",pre,cur);
						if (cnt[cur] == 1)
						{
							end = cur;
							break;
						}
						if (arr[cur].nxt[0] != pre)
						{
							pre = cur;
							cur = arr[cur].nxt[0];
						}
						else
						{
							pre = cur;
							cur = arr[cur].nxt[1];
						}
					}
					que.push(i);
					que.push(end);
				}
				printf("%d\n",cnt[i]);
				while (cnt[i]--)
				{
					printf("%d",que.front());
					que.pop();
					printf(" %d\n",que.front());
					que.pop();
				}
				break;
			}
		}
		if (i == 100001)
		{
			i = 0;
			for (i = 1; i <= 100000; ++i)
			{
				if (cnt[i])
				{
					for (int j = 0; j < cnt[i]; ++j)
					{
						int end;
						int pre = i;
						int cur = arr[i].nxt[j];
						while (1)
						{
							//printf("pre = %d cur = %d\n",pre,cur);
							if (cnt[cur] == 1)
							{
								end = cur;
								break;
							}
							if (arr[cur].nxt[0] != pre)
							{
								pre = cur;
								cur = arr[cur].nxt[0];
							}
							else
							{
								pre = cur;
								cur = arr[cur].nxt[1];
							}
						}
						que.push(i);
						que.push(end);
					}
					printf("%d\n",cnt[i]);
					while (cnt[i]--)
					{
						printf("%d",que.front());
						que.pop();
						printf(" %d\n",que.front());
						que.pop();
					}
					break;
				}
			}
		}
	}
}
