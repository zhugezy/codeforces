#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define MAXN 1000008
using namespace std;

const int mod = 1000000007;

LL gcd(LL a, LL b){return b == 0 ? a : gcd(b, a % b);}
LL qp(LL a, LL b){LL ret = 1;while (b){if (b & 1) ret = ret * a;a = a * a;b >>= 1;}return ret;}

double a[2008];

int main()
{
    double n, m;
    cin >> n >> m;
    int flag = 0;
    double res = m;
    for (int i = 1; i <= 2 * n; ++i)
    {
        cin >> a[i];
        if (a[i] == 1) flag = 1;
    }
    if (flag)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 1; i <= 2 * n; ++i)
        {
            res /= (1 - (1 / a[i]));
        }
        res -= m;
        printf("%.6f", res);
    }
    return 0;
}
