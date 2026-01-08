/*************************
  Author: Defy logic guy
  15:30:12 - 16/08/2025
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
#define NAME "CSPHN_HSG2017_SUBSEQ"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int s = accumulate(all(a), 0ll);
    int mx = -1;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int m = a[i];
        int cur = m;
        vector<int> b{i};

        vector<pair<int, int>> c;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            if (a[j] >= m)
                c.pb({a[j], j});
        }

        sort(all(c), [](auto &p1, auto &p2)
             { return p1.first > p2.first; });

        for (auto &j : c)
        {
            int one = j.first, two = j.second;
            if (2 * (cur + one) <= s + 2 * m)
            {
                cur += one;
                b.pb(two);
            }
        }

        if (cur > mx)
        {
            mx = cur;
            ans = b;
        }
    }

    sort(all(ans));
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i + 1 << ' ';
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
