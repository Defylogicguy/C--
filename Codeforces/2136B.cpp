/*************************
  Author: Defy logic guy
  21:48:43 - 28/08/2025
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
#define NAME "2136B"

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnt = 0;
    for (int i = 0; i < k and i < n; i++)
        cnt += (s[i] == '1');
    bool ok = false;
    if (k <= n and cnt == k)
        ok = true;
    for (int i = k; i < n and !ok; i++)
    {
        cnt += (s[i] == '1');
        cnt -= (s[i - k] == '1');
        if (cnt == k)
            ok = true;
    }
    if (ok)
    {
        cout << "NO\n";
        return;
    }
    vector<int> p(n);
    int l = 1, r = n;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            p[i] = r--;
        else
            p[i] = l++;
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << p[i] << ' ';
    cout << '\n';
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
    cin >> tt;

    while (tt--)
        solve();

    return 0;
}
