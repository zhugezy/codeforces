#include <bits/stdc++.h>
using namespace std;
int n;
int nxt[200008];
bool in[200008];
bool vis[200008];
int last = -1;
vector<int> v;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &nxt[i]);
		in[nxt[i]]++;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (nxt[i] && !in[i])
		{
			int cur = i;
			while (!vis[cur])
			{
				vis[cur] = true;
				if (!nxt[cur])
				{
					nxt[cur] = i;
					last = cur;
					in[i]++;
					break;
				}
				else
					cur = nxt[cur];
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!nxt[i])
			v.push_back(i);
	}
	if (v.size() == 1)
	{
		int temp = nxt[last];
		nxt[last] = v[0];
		nxt[v[0]] = temp;
	}
	else
	{
		for (int i = 0; i < v.size(); ++i)
		{
			nxt[v[i]] = v[(i + 1) % v.size()];
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", nxt[i], " \n"[i==n]);
}