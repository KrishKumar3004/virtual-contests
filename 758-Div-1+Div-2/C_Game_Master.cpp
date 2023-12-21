#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n), b(n);

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[i] = {x, i};
    }
    for (ll j = 0; j < n; j++)
    {
        ll x;
        cin >> x;
        b[j] = {x, j};
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> adj[n];

    for (ll i = 0; i < n - 1; i++)
    {
        adj[a[i].second].push_back(a[i + 1].second);
        adj[b[i].second].push_back(b[i + 1].second);
    }

    vector<int> vis(n);

    vis[a.back().second] = 1;
    vis[b.back().second] = 1;

    queue<ll> q;
    q.push(a.back().second);
    q.push(b.back().second);

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        // cout << node << " ";
        for (auto child : adj[node])
        {
            if (vis[child] != 1)
            {
                q.push(child);
                vis[child] = 1;
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << ": ";
    //     for (auto it : adj[i])
    //     {
    //         cout << it << " ";
    //     }

    //     cout << endl;
    // }

    string ans(n, '0');

    for (ll i = 0; i < n; i++)
    {
        if (vis[i] == 1)
        {
            ans[i] = '1';
        }
    }

    cout << ans << endl;
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
