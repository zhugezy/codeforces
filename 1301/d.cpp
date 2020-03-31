#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
using namespace std;
vector<pair<int,string>> ans;
vector<pair<int,string>> cans;
void process(int n, int m)
{
	if (n == 1 && m == 1)
	{

	}
	else if (n == 1)
	{
		ans.eb(m - 1, "R");
		ans.eb(m - 1, "L");
	}
	else if (m == 1)
	{
		ans.eb(n - 1, "D");
		ans.eb(n - 1, "U");
	}
	else if (n == 2 && m == 2)
	{
		ans.eb(1, "DRUL");
		ans.eb(1, "RDLU");
	}
	else if (n == 2)
	{
		ans.eb(m - 1, "R");
		ans.eb(1, "D");
		ans.eb(m - 1, "LUD");
		ans.eb(m - 1, "R");
		ans.eb(1, "U");
		ans.eb(m - 1, "L");
	}
	else if (m == 2)
	{
		ans.eb(n - 1, "D");
		ans.eb(1, "R");
		ans.eb(n - 1, "ULR");
		ans.eb(n - 1, "D");
		ans.eb(1, "L");
		ans.eb(n - 1, "U");
	}
	else //n >= 3, m >= 3
	{
		if (n >= 4)
		{
			ans.eb(1, "D");
			ans.eb(n - 3, "DRL");
			ans.eb(1, "D");
		}
		else
		{
			ans.eb(2, "D");
		}
		ans.eb(m - 2, "RUD");
		ans.eb(1, "R");
		ans.eb(n - 2, "ULR");
		ans.eb(1, "U");
		ans.eb(m - 2, "LDU");
		ans.eb(1, "L");
		ans.eb(m - 1, "R");
		ans.eb(n - 1, "D");
		ans.eb(m - 1, "L");
		ans.eb(n - 2, "U");
		ans.eb(1, "R");
	}
}

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
	int N, M, k;
	cin >> N >> M >> k;
	for (int R = 0; R * 2 < N && R * 2 < M; ++R)
	{
		process(N - 2 * R, M - 2 * R);
	}
	if (N >= 3 && M >= 3)
		ans.eb(min((N - 1) / 2, (M - 1) / 2), "LU");
	if (gao(k))
	{
		cout << "YES" << endl << cans.size() << endl;
		for (auto pr: cans)
			cout << pr.first << " " << pr.second << endl;
	}
	else
		cout << "NO" << endl;
}