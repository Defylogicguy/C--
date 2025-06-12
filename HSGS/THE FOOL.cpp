/*************************
  Author: Defy logic guy
  09:59:27 - 12/06/2025
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
#define NAME "The Fool"

void solve()
{
    auto query = [](int x, int y) -> int
    {
        int ans = 0, z = 0;
        cout << "and " << x << " " << y << endl;
        cout.flush();
        cin >> ans;
        cout << "or " << x << " " << y << endl;
        cout.flush();
        cin >> z;
        return ans + z;
    };

    int n, k;
    cin >> n >> k;
    int a01 = query(1, 2), a02 = query(1, 3), a12 = query(2, 3);
    vector<int> a(3);
    a[0] = (a01 + a02 - a12) / 2;
    a[1] = a01 - a[0];
    a[2] = a02 - a[0];
    for (int i = 4; i <= n; i++)
        a.pb(query(1, i) - a[0]);
    sort(all(a));
    cout << "finish " << a[k - 1] << endl;
    cout.flush();
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
