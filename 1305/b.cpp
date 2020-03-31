#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
char s[1008];
int n;
vector<int> v1, v2;
int main()
{
	cin >> s + 1;
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
	{
		if (s[i] == '(')
			v1.pb(i);
		else
			v2.pb(i);
	}
	reverse(v2.begin(), v2.end());
	int ans = 0;
	int c = 0;
	vector<int> vec;
	for (int i = 0; i < v1.size() && i < v2.size(); ++i)
	{
		if (v1[i] < v2[i])
		{
			c++;
			vec.pb(v1[i]);
			vec.pb(v2[i]);
		}
		else
		{
			if (c)
				ans++;
			c = 0;
		}
	}
	sort(vec.begin(), vec.end());
	if (c)
		ans++;
	cout << ans << endl;
	if (ans)
	{
		cout << vec.size() << endl;
		for (auto x: vec)
			cout << x << " ";
		cout << endl;
	}
	
	return 0;
}