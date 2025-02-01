/*************************
  Author: Defy logic guy
  23:25:38 - 23/01/2025
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
#define NAME "BALLOONS"

void solve()
{
    int n;
    cin >> n;
    stack<pair<float, float>> st;

    cout << fixed << setprecision(3);
    for (int i = 0; i < n; i++)
    {
        float x, r;
        cin >> x >> r;
        while (st.size())
        {
            float x1, r1;
            tie(x1, r1) = st.top();
            r = min(r, (x1 - x) * (x1 - x) / (4 * r1));
            if (r >= r1)
                st.pop();
            else
                break;
        }

        st.push({x, r});
        cout << r << '\n';
    }
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
