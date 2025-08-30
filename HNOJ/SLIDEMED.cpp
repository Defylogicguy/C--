/*************************
  Author: Defy logic guy
  22:35:23 - 03/09/2025
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
#define NAME "SLIDEMED"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    multiset<int> l, r;
    auto f = [&]()
    {
        while (l.size() > (k + 1) / 2)
        {
            auto it = prev(l.end());
            r.insert(*it);
            l.erase(it);
        }
        while (r.size() > k / 2)
        {
            auto it = r.begin();
            l.insert(*it);
            r.erase(it);
        }
    };
    for (int i = 0; i < k; i++)
        l.insert(a[i]);
    f();
    cout << *prev(l.end()) << ' ';
    for (int i = k; i < n; i++)
    {
        int rm = a[i - k];
        if (l.find(rm) != l.end())
            l.erase(l.find(rm));
        else
            r.erase(r.find(rm));
        if (l.size() and a[i] <= *prev(l.end()) )
            l.insert(a[i]);
        else
            r.insert(a[i]);
        f();
        cout << *prev(l.end()) << ' ';
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
