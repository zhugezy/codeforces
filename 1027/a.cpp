#include <bits/stdc++.h>
#define LL long long
#define MAXN 700
using namespace std;
int n;
char s[100008];

int getans(int sta, int c)
{
    if (sta == 1)
    {
        reverse(s + 1, s + c + 1);
        reverse(s + c + 2, s + n + 1);
    }
    int ans = 0;
    int cur = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (s[i] != s[i - 1])
        {
            cur++;
        }
        else
        {
            ans = max(ans, cur);
            cur = 1;
        }
    }
    if (sta == 1)
    {
        reverse(s + 1, s + c + 1);
        reverse(s + c + 2, s + n + 1);
    }
    return ans;
}

int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    if (s[1] == s[n])
    {
        cout << getans(0, 0) << endl;
        return 0;
    }
    else
    {
        int cc;
        if (s[1] == 'b' && s[n] == 'w')
            cc = 1;
        else
            cc = 2;
        int res = getans(0, 0);
        for (int i = 1; i < n; ++i)
        {
            if (cc == 1)
            {
                if (s[i] == 'w' && s[i + 1] == 'b')
                {
                    res = max(getans(1, i), res);
                }
                else if (s[i] == 'b' && s[i + 1] == 'w')
                {
                    res = max(getans(1, i), res);
                }
            }
        }
        cout << res << endl;
    }
}
