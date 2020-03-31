#include <bits/stdc++.h>

using namespace std;

bool honest[40];

int main()
{
    memset(honest,false,sizeof(honest));
    int m, n;
    scanf("%d %d", &m, &n);
    int cnt = 0;
    for (cnt = 1; cnt <= n; ++cnt)
    {
        int reci;
        cout << m<< endl;
        fflush(stdout);
        cin >> reci;
        if (reci == -1) honest[cnt] = true;
        else if (reci == 1)honest[cnt] = false;
        else if (reci == -2 || reci == 0) return 0;
    }
    int l = 1, r = m;
    int mid = (l + r) >> 1;
    cnt = 0;
    while (true)
    {
        int x;
        cnt++;
        if (cnt == n + 1) cnt = 1;
        mid = (l + r) >> 1;
        cout << mid << endl;
        fflush(stdout);
        cin >> x;
        if (x == 0)
            return 0;
        else
        {
            if (honest[cnt] == false) x = -x;
            if (x == -1)
            {
                r = mid;
            }
            else if (x == 1)
            {
                l = mid + 1;
            }
            else if (x == -2)
            {
                return 0;
            }
        }
    }
    return 0;
}
