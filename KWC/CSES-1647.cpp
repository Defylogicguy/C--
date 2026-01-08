/*************************
  Author: Defy logic guy
  23:57:13 - 05/08/2025
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
#define NAME "CSES-1647"

const int N = 2e5 + 5;
int a[N];
int f[N][21];
int lg[N];
int n, q;
int get(int l, int r)
{
    if (l > r)
        return 0;
    int t = lg[r - l + 1];
    return min(f[l][t], f[r - (1 << t) + 1][t]);
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        lg[i] = log2(i);
        f[i][0] = a[i];
    }

    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << (j - 1)) <= n; i++)
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int x = get(l, r);
        cout << x << '\n';
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
