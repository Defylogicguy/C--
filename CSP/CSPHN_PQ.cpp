/*************************
  Author: Defy logic guy
  14:17:33 - 08/02/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "CSPHN_PQ"
void solve()
{
    int n;
    cin >> n;
    heap<char> pq;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "-")
        {
            if (pq.size())
            {
                char c = pq.top();
                while (pq.size() and pq.top() == c)
                    pq.pop();
            }
        }
        else
            pq.push(s[1]);
    }

    vector<char> ans;
    while (pq.size())
    {
        char c = pq.top();
        while (pq.size() and pq.top() == c)
            pq.pop();
        ans.pb(c);
    }
    cout << ans.size() << endl;
    for (char c : ans)
        cout << c << ' ';
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
