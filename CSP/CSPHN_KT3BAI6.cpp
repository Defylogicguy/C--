/*************************
  Author: Defy logic guy
  13:17:55 - 09/08/2025
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
#define NAME "CSPHN_KT3BAI6"


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto f = [](const vector<int> &a, const vector<int> &b) -> vector<int>
    {
        vector<int> res(a.size());
        for (int i = 0; i < a.size(); i++)
            res[i] = b[a[i]];
        return res;
    };
    auto mu = [f](vector<int> b, int e) -> vector<int>
    {
        vector<int> ans(b.size());
        iota(ans.begin(), ans.end(), 0);
        while (e)
        {
            if (e & 1)
                ans = f(ans, b);
            b = f(b, b);
            e >>= 1;
        }
        return ans;
    };
    vector<int> ans = mu(a, m);
    for (int i : ans)
        cout << i << ' ';
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
