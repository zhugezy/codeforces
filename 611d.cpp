#include <bits/stdc++.h>
#define LL long long
using namespace std;
int cnt[50008];
vector<int> vec;
const int mod = 19260817;
int Len;
LL dp[50008];

LL qp(LL a, LL b)
{
    int ret = 1;
    while (b)
    {
        if (b & 1)ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
void showdp()
{
    for (int i = 0; i <= 8; ++i)
    {
        printf("dp[%d] = %d\n",i, dp[i]);
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        int a;
        scanf("%d", &a);
        cnt[a]++;
    }
    for (int i = 1; i <= m; ++i)
    {
        if (cnt[i]) vec.push_back(i);
    }
    Len = vec.size();
    int v = vec[0];
    int cur = 1;
    /*for (int i = 0; i <= m; i += v)
    {
        dp[i] = cur;
        cur = cur * cnt[v] % mod;
    }*/
    dp[0] = 1;
    for (int i = 0; i < Len; ++i)
    {
        v = vec[i];
        for (int j = m; j >= v; --j)
        {
            for (int k = 1; j - k * v >= 0; ++k)
            {
                dp[j] += dp[j - k * v] * qp(cnt[v], )
            }
        }
    }
    LL res = 0;
    for (int i = 1; i <= m; ++i)
    {
        res = (res + dp[i]) % mod;
    }
    cout << res << endl;
}
