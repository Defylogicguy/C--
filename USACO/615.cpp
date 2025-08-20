/*************************
  Author: Defy logic guy
  14:48:38 - 20/08/2025
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
#define NAME "pails"

int ans = 0, x, y, m;
set<int> st;
void f(int cur)
{
    if (st.find(cur) != st.end())
        return;
    ans = max(ans, cur);
    st.insert(cur);
    if (cur + y <= m)
        f(cur + y);
    if (cur + x <= m)
        f(cur + x);
}

void solve()
{
    cin >> x >> y >> m;
    f(0);
    cout << ans;
}

signed main()
{
    if (fopen(NAME ".in", "r"))
    {
        freopen(NAME ".in", "r", stdin);
        freopen(NAME ".out", "w", stdout);
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
