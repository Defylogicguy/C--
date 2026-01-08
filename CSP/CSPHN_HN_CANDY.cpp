/*************************
  Author: Defy logic guy
  14:31:33 - 16/08/2025
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
#define NAME "CSPHN_HN_CANDY"

set<tuple<int, int, int, int>> memo;
void f(int idx, array<int, 3> res, const vector<int> &a, int &ans, int r)
{
    if (idx == a.size())
    {
        ans = min(ans, res[2] - res[0]);
        return;
    }
    if (max(0LL, res[2] - (res[0] + r)) >= ans)
        return;

    tuple<int, int, int, int> st = {idx, res[0], res[1], res[2]};
    if (memo.find(st) != memo.end())
        return;
    memo.insert(st);

    for (int i = 0; i < 3; i++)
    {
        if (i > 0 && res[i] == res[i - 1])
            continue;
        array<int, 3> nw = res;
        nw[i] += a[idx];
        if (nw[0] > nw[1])
            swap(nw[0], nw[1]);
        if (nw[1] > nw[2])
            swap(nw[1], nw[2]);
        if (nw[0] > nw[1])
            swap(nw[0], nw[1]);
        f(idx + 1, nw, a, ans, r - a[idx]);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        r += a[i];
    }
    sort(rall(a));
    int ans = LLONG_MAX;
    array<int, 3> res = {0, 0, 0};
    f(0, res, a, ans, r);
    cout << ans << '\n';
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
