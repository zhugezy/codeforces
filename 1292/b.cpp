#include <bits/stdc++.h>
#define LL long long
#define pii pair<long long, long long>
#define x first
#define y second
using namespace std;
vector<pii> nodes;
pii st;
LL ax, ay, bx, by, t;
int res = 0;

LL dis(pii p, pii q)
{
	return abs(p.x - q.x) + abs(p.y - q.y);
}
int main()
{
	nodes.emplace_back();
	cin >> nodes[0].x >> nodes[0].y >> ax >> ay >> bx >> by >> st.x >> st.y >> t;
	for (int i = 1; ; ++i)
	{
		if (1.0 * nodes[i - 1].x * ax + bx > 1e18 || 1.0 * nodes[i - 1].y * ay + by > 1e18)
			break;
		nodes.emplace_back(nodes[i - 1].x * ax + bx, nodes[i - 1].y * ay + by);
	}
	for (int i = 0; i < nodes.size(); ++i)
	{
		LL _t1 = t, _t2 = t;
		int ans1 = 0, ans2 = 0;
		pii cur = st;
		for (int j = i; j >= 0; --j)
		{
			if (dis(cur, nodes[j]) <= _t1)
				ans1++;
			_t1 -= dis(cur, nodes[j]);
			cur = nodes[j];
		}
		for (int j = i + 1; j < nodes.size(); ++j)
		{
			if (dis(cur, nodes[j]) <= _t1)
				ans1++;
			_t1 -= dis(cur, nodes[j]);
			cur = nodes[j];
		}
		cur = st;
		for (int j = i; j < nodes.size(); ++j)
		{
			if (dis(cur, nodes[j]) <= _t2)
				ans2++;
			_t2 -= dis(cur, nodes[j]);
			cur = nodes[j];
		}
		for (int j = i - 1; j >= 0; --j)
		{
			if (dis(cur, nodes[j]) <= _t2)
				ans2++;
			_t2 -= dis(cur, nodes[j]);
			cur = nodes[j];
		}
		res = max(res, max(ans1, ans2));
	}
	cout << res << endl;
}