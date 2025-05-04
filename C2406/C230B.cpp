/*************************
  Author: Defy logic guy
  22:11:21 - 04/05/2025
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
#define NAME "C230B"

vector<bool> p(1e6 + 1, true);

void sieve()
{
    p[0] = p[1] = false;
    for (int i = 2; i * i <= 1e6; ++i)
        if (p[i])
            for (int j = i * i; j <= 1e6; j += i)
                p[j] = false;
}

void solve()
{
    int n;
    cin >> n;
    int s = sqrt(n);
    cout << (s * s == n && p[s] ? "YES\n" : "NO\n");
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
    
    sieve();
    while (tt--)
        solve();
    return 0;
}
