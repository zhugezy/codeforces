#include <bits/stdc++.h>
#define MAXN 100000
#define LL long long
#define pb push_back
using namespace std;
int prime[MAXN + 8];
bool notprime[MAXN + 8];
int ind = 0;
int n;
int b[1000];
int a[1000];
LL gcd(LL a, LL b)
{
    return b?gcd(b, a%b):a;
}

int e_gcd(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int ans = e_gcd(b, a%b, y, x);
    y -= x*(a/b);
    /*x = (x % a + a) % a;
    y = (y % b + b) % b;*/
    return ans;
}
bool n_equation(int a[], int x[], int c, int n){
    vector<int> d(n+3);
    d[1] = a[1];
    for(int i = 2; i < n; ++i)
    {
        d[i] = gcd(a[i-1],a[i]);
    }
    if(c%d[n-1] != 0)
        return false;
    int y,gcdd;
    for(int i = n-1; i >= 1; --i){
        gcdd = e_gcd(a[i+1],d[i],x[i+1],y);
        x[i+1] *= c/gcdd;
        y *= c/gcdd;
        c = d[i] * y;
    }
    x[1] = y;
    return true;
}

bool isprime(int x)
{
    if (x == 2)
        return true;
    for (int i = 2; i <= int(sqrt(x)) + 1; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void getprime()
{
    notprime[1] = true;
    for (int i = 2; i <= MAXN; ++i)
    {
        if (!notprime[i])
        {
            prime[++ind] = i;
        }
        for (int j = 1; j <= ind && prime[j] * i <= MAXN; ++j)
        {
            notprime[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}
bool cmp(int a, int b)
{
    return a > b;
}

int Len;
vector<int> vec;

int ans[12];
LL getans()
{
    LL tot = 0;
    for (int i = 1; i < Len; ++i)
    {
        tot += n / vec[i] * ans[i];
    }
    return tot;
}

void printans()
{
    int k = 0;
    for (int i = 0; i < Len; ++i)
    {
        if (ans[i])
            k++;
    }
    printf("%d\n", k);
    for (int i = 0; i < Len; ++i)
    {
        if (ans[i])
            printf("%d %d\n", ans[i], vec[i]);
    }
}



int main()
{
    getprime();
    scanf("%d", &n);
    int cpy = n;
    if (isprime(n))
    {
        printf("NO\n");
    }
    else
    {
        for (int i = 1; i <= ind && prime[i] <= n; ++i)
        {
            int p = prime[i];
            int cur = 1;
            while (n % p == 0)
            {
                cur *= p;
                n /= p;
            }
            vec.pb(p);
        }
        n = cpy;
        sort(vec.begin(), vec.end(), cmp);
        Len = vec.size();
        for (int i = 1; i <= Len; ++i)
        {
            b[i] = vec[i - 1];
        }
        LL g = gcd(vec[0], vec[1]);
        for (int i = 1; i < Len - 1; ++i)
        {
            g = gcd(g, vec[i + 1]);
        }
        if ((n - 1) % g == 0)
        {
            if (n_equation(b, a, n - 1, Len))
            {
                printf("YES\n%d\n", Len);
                for (int i = 1; i <= Len; ++i)
                {
                    printf("%d %d\n", a[i], n / b[i]);
                }
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            printf("NO\n");
        }
    }
}
