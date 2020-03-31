#include <bits/stdc++.h>
#define LL long long
using namespace std;
int T, n;
char s[18];

bool all9()
{
	for (int i = 0; i < strlen(s); ++i)
	{
		if (s[i] != '9')
			return false;
	}
	return true;
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> s;
		cout << 1LL * n * (strlen(s) - (all9() == false)) << endl;
	}
}