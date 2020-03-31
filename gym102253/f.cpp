#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n, m;
int a[100008], b[100008];
bool dis[100008];
int cnta[100008], cntb[100008];
const int mod = 1000000007;

LL qp(LL a, LL b)
{
    LL ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

int main()
{
    int cas = 0;
    while (~scanf("%d %d", &n, &m))
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        for (int i = 0; i < m; ++i)
            scanf("%d", &b[i]);
        memset(dis, 0, sizeof(dis));
        for (int i = 0; i < n; ++i)
        {
            if (dis[i])
                continue;
            int cur = a[i];
            dis[a[i]] = true;
            int cnt = 1;
            while (cur != i)
            {
                cur = a[cur];
                dis[cur] = true;
                cnt++;
            }
            cnta[cnt]++;
        }
        memset(dis, 0, sizeof(dis));
        for (int i = 0; i < m; ++i)
        {
            if (dis[i])
                continue;
            int cur = b[i];
            dis[b[i]] = true;
            int cnt = 1;
            while (cur != i)
            {
                cur = b[cur];
                dis[cur] = true;
                cnt++;
            }
            cntb[cnt]++;
        }
        /*for (int i = 1; i <= n; ++i)
            printf("cnta[%d] = %d\n", i, cnta[i]);
        for (int j = 1; j <= m; ++j)
            printf("cntb[%d] = %d\n", j, cntb[j]);*/
        LL ans = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (cnta[i])
            {
                //printf("cntb[%d] = %d\n", i, cntb[i]);
                LL t = 0;
                for (LL j = 1; j <= i; ++j)
                {
                    if (i % j == 0)
                    {
                        t = (t + j * cntb[j] % mod) % mod;
                    }
                }
                ans = ans * qp(t, cnta[i]) % mod;
            }
        }
        memset(cnta, 0, sizeof(cnta));
        memset(cntb, 0, sizeof(cntb));
        printf("Case #%d: %I64d\n", ++cas, ans);
    }
    return 0;
}
