#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define MAXN 100008
using namespace std;

const int mod = 1000000007;

LL gcd(LL a, LL b){return b == 0 ? a : gcd(b, a % b);}
LL qp(LL a, LL b){LL ret = 1;while (b){if (b & 1) ret = ret * a;a = a * a;b >>= 1;}return ret;}
LL n, k;
LL prime[MAXN];
bool isprime[MAXN];
LL arr[MAXN];
int flag[MAXN];
int ans[MAXN];
int ind = 0;
/*
void getprime()
{
    memset(isprime,true,sizeof(isprime));
    isprime[1] = false;
    for (int i = 2; i <= 100000; ++i)
    {
        if (isprime[i])
        {
            for (LL j = i; i * j <= 100000; ++j)
            {
                isprime[j * i] = false;
            }
            prime[++ind] = i;
        }
    }
}
*/

void print(int f)
{
    if (f == 1)
    {
        printf("%I64d\n", n);
        for (int i = 0; i < n; ++i)
        {
            printf("%d ", i);
        }
    }
}
int main()
{
    //getprime();

    scanf("%I64d %I64d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%I64d", &arr[i]);
        arr[i] %= k;
        flag[gcd(k, arr[i])] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            LL g = gcd(arr[i], arr[j]) % k;
            if (g == 1 || gcd(k, g) == 1)
            {
                print(1);
                return 0;
            }
            flag[g] = 1;
        }
    }
    for (int i = 1; i < k; ++i)
    {
        if (flag[i])
        {
            for (LL j = 0; j * i < k; ++j)
            {
                ans[i * j] = 1;
            }
        }
    }
    if (flag[0]) ans[0] = 1;
    int cnt = 0;
    for (int i = 0; i < k; ++i)
    {
        if (ans[i]) cnt++;
    }
    printf("%d\n",cnt);
    for (int i = 0; i < k; ++i)
    {
        if (ans[i]) printf("%d ",i);
    }
}
