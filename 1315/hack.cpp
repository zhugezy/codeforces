#include <bits/stdc++.h>
using namespace std;
int a,b,p;
string s;
int main()
{
	cin >> a >> b >> p >> s;
	bool found = false;
	int ans = 0;
	s[s.length() - 1] = 'c';
	for (int i = s.size() - 2; i >= 0; --i)
	{
		if (s[i] == s[i + 1])
			continue;
		if (s[i] == 'A') p -= a;
		else p -= b;
		if (p < 0)
		{
			ans = i + 2;
			found = true;
			break;
		}
	}
	if (found)
		cout << ans << endl;
	else
		cout << 1 << endl;
}