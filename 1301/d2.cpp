#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
using namespace std;
vector<pair<int,string>> ans;
vector<pair<int,string>> cans;

bool gao(int k)
{
	int tot = 0;
	for (auto pr: ans)
	{
		tot += pr.first * pr.second.length();
		if (tot < k)
			cans.pb(pr);
		else
		{
			int pre = tot - pr.first * pr.second.length();
			int need = k - pre;
			if (need / pr.second.length() >= 1)
				cans.eb(need / pr.second.length(), pr.second);
			need = need % pr.second.length();
			string temp;
			for (int i = 0; i < need; ++i)
				temp += pr.second[i];
			if (need >= 1)
				cans.eb(1, temp);
			return true;
		}
	}
	return false;
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	if (n == 1 && m == 1)
	{

	}
	else if (m == 1)
	{
		ans.eb(n - 1, "D");
		ans.eb(n - 1, "U");
	}
	else
	{
		ans.eb(m - 1, "R");
		ans.eb(m - 1, "L");
		ans.eb(1, "D");
	}
	for (int R = 2; R <= n; ++R)
	{
		ans.eb(m - 1, "RUD");
		ans.eb(m - 1, "L");
		ans.eb(1, "D");
	}
	ans.eb(n - 1, "U");
	if (gao(k))
	{
		cout << "YES" << endl << cans.size() << endl;
		for (auto pr: cans)
			cout << pr.first << " " << pr.second << endl;
	}
	else
		cout << "NO" << endl;
}