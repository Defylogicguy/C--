/*************************
  Author: Defy logic guy
  15:46:44 - 05/07/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "LMH_LM"

void solve()
{
    int k;
    string s;
    cin >> k >> s;
    if (k == 0)
    {
        cout << 0;
        return;
    }
    sort(all(s));
    queue<pair<int, string>> q;
    vector<bool> vis(1e6 + 5, false);
    for (char c : s)
    {
        if (c == '0')
            continue;
        int r = (c - '0') % k;
        if (!vis[r])
        {
            vis[r] = true;
            q.push({r, string(1, c)});
        }
    }
    while (q.size())
    {
        int u = q.front().first;
        string v = q.front().second;
        q.pop();
        if (u == 0)
        {
            cout << v;
            return;
        }
        for (char c : s)
            if (!vis[(u * 10 + (c - '0')) % k])
            {
                vis[(u * 10 + (c - '0')) % k] = true;
                q.push({(u * 10 + (c - '0')) % k, v + c});
            }
    }
    cout << 0;
}

signed main()
{
    if (fopen(NAME ".INP", "r"))
    {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();
    return 0;
}
