/*************************
  Author: Defy logic guy
  10:23:58 - 12/06/2025
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
#define NAME "THE MAGICIAN"

void solve()
{
    int n;
    cin >> n;
    auto query = [](int x, int y) -> int
    {
        cout << "? " << x << ' ' << y << endl;
        cout.flush();
        int ans;
        cin >> ans;
        return ans;
    };

    int mx = 0;
    vector<int> a(n);
    for (int i = 1; i < n; i++)
    {
        int b = query(i + 1, mx + 1);
        int a1 = query(mx + 1, i + 1);
        if (a1 > b)
        {
            a[mx] = a1;
            mx = i;
        }
        else
            a[i] = b;
    }
    a[mx] = n;
    cout << "! ";
    for (int i : a)
        cout << i << ' ';
    cout << endl;
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
