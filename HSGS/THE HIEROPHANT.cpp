/*************************
 Author: Defy logic guy
20:39:11 - 12/06/2025
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
#define NAME "THE HIEROPHANT"

void solve()
{
    int n;
    cin >> n;
    vector<int> f(n - 1);
    auto q = [](string s, int i, int j) -> int
    {
        i++, j++;
        cout << s << ' ' << i << ' ' << j << endl;
        cout.flush();
        int a;
        cin >> a;
        return a;
    };

    int a0 = LLONG_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        f[i] = q("XOR", 0, i + 1);
        if (f[i] == 0)
            a0 = q("AND", 0, i + 1);
    }
    if (a0 != LLONG_MAX)
    {
        cout << "! " << a0 << ' ';
        for (int i = 0; i < n - 1; i++)
            cout << (f[i] ^ a0) << ' ';
        cout << endl;
        cout.flush();
        return;
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n - 1; i++)
        mp[f[i]].pb(i);
    for (auto &[x, y] : mp)
        if (y.size() >= 2)
        {
            int a = q("AND", y[0] + 1, y[1] + 1);
            a0 = f[y[0]] ^ a;
            cout << "! " << a0 << ' ';
            for (int i = 0; i < n - 1; i++)
                cout << (f[i] ^ a0) << ' ';
            cout << endl;
            cout.flush();
            return;
        }
    int a12 = q("AND", 0, 1), a13 = q("AND", 0, 2);
    a0 = ((f[0] + 2 * a12) + (f[1] + 2 * a13) - (f[0] ^ f[1])) / 2;
    cout << "! " << a0 << ' ';
    for (int i = 0; i < n - 1; i++)
        cout << (f[i] ^ a0) << ' ';
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
