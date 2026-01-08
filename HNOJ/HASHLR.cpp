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
#define NAME "HASHLR"

int power(int a, int b, int mod)
{
    int res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> hash(n + 1);
    hash[0] = 0;
    for (int i = 1; i <= n; i++)
        hash[i] = (hash[i - 1] * 31 + (s[i - 1] - 'a')) % MOD;

    while (q--)
    {
        int x, y, l, r;
        cin >> x >> y >> l >> r;

        int len = y - x + 1;
        int p = power(31, len, MOD);

        int one = (hash[y] - (hash[x - 1] * p) % MOD + MOD) % MOD;
        int two = (hash[r] - (hash[l - 1] * p) % MOD + MOD) % MOD;
        cout << (one == two) << endl;
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
