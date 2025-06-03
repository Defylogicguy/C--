/*************************
  Author: Defy logic guy
  08:06:37 - 03/06/2025
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
#define endl '\n'
#define NAME "DNA"

int n, t;
vector<int> one, two;
void do1(int i, int cur, const vector<int> &a)
{
    if (i == n / 2)
    {
        one.pb(cur);
        return;
    }

    do1(i + 1, cur, a);
    do1(i + 1, cur + a[i], a);
}

void do2(int i, int cur, const vector<int> &a)
{
    if (i == n)
    {
        two.pb(cur);
        return;
    }

    do2(i + 1, cur, a);
    do2(i + 1, cur + a[i], a);
}

void solve()
{
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    do1(0, 0, a);
    do2(n / 2, 0, a);
    sort(all(two));
    int ans = 0;
    for (int i = 0; i < one.size(); i++)
    {
        auto it = upper_bound(all(two), t - one[i]);
        // cout << ">>>" << *it << endl;
        ans = max(ans, one[i] + *prev(it));
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
