#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;

    ll mx1 = (n - 1) / 2, mx2 = (n - 2) / 2;

    if (a + b > mx1 + mx2 || abs(a - b) > 1 || max(a, b) > mx1)
    {
        cout << -1 << endl;
        return;
    }
    ll low = 1, high = n;

    bool flag = false;
    if (a >= b)
        flag = true;

    for (ll j = 1; j <= a + b + 1; j++)
    {
        if (flag)
        {
            cout << low << " ";
            low++;
            flag = false;
        }
        else
        {
            cout << high << " ";
            high--;
            flag = true;
        }
    }
    if (flag)
    {
        while (high >= low)
        {
            cout << high << " ";
            high--;
        }
    }
    else
    {
        while (low <= high)
        {
            cout << low << " ";
            low++;
        }
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
