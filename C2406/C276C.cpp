/*************************
  Author: Defy logic guy
  22:32:10 - 18/02/2025
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
#define NAME "C276C"

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> diff(n + 1, 0);
    vector<pair<int, int>> query(q);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        diff[l]++;
        if (r + 1 < n)
            diff[r + 1]--;
        query[i] = {l, r};
    }

    vector<pair<int, int>> freq(n);
    freq[0] = {diff[0], 0};
    for (int i = 1; i < n; i++)
    {
        freq[i].first = freq[i - 1].first + diff[i];
        freq[i].second = i;
    }

    sort(rall(freq));
    sort(rall(a));

    vector<int> newa(n);
    for (int i = 0; i < n; i++)
        newa[freq[i].second] = a[i];

    vector<int> pf(n + 1, 0);
    partial_sum(all(newa), pf.begin() + 1);

    int ans = 0;
    for (int i = 0; i < q; i++)
    {
        int l = query[i].first, r = query[i].second;
        int cur = pf[r + 1] - pf[l];
        ans += cur;
    }
    cout << ans << endl;
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
