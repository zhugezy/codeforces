#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define MAXN 1000008
using namespace std;

const int mod = 1000000007;

LL gcd(LL a, LL b){return b == 0 ? a : gcd(b, a % b);}
LL qp(LL a, LL b){LL ret = 1;while (b){if (b & 1) ret = ret * a;a = a * a;b >>= 1;}return ret;}

int cnt[108];
int res[108];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    if (m < n) cout << 0 << endl;
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            double maxx = -1;
            int ind = -1;
            for (int typ = 1; typ <= 100; ++typ)
            {

                if (cnt[typ] && cnt[typ] / (res[typ] + 1.0) > maxx)
                {
                    //cout << typ << endl;
                    maxx = cnt[typ] / (res[typ] + 1.0);
                    ind = typ;
                }
            }
            res[ind]++;
        }
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= 100; ++i)
        {
            if (cnt[i] && res[i])
                ans = min(ans, cnt[i] / res[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
