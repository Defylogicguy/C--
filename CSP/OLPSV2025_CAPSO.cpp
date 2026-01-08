/*************************
  Author: Defy logic guy
  14:41:49 - 13/12/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &os, const string &s)
{
    os.write(s.data(), s.size());
    return os;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> typename enable_if<!is_same<T, string>::value, decltype(c.begin(), c.end(), os)>::type
{
    for (auto it = c.begin(); it != c.end(); it++)
        os << (it == c.begin() ? "{" : ", ") << *it;
    return os << "}";
}
#define dbg(x) cerr << #x << " = " << (x) << '\n';
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "OLPSV2025_CAPSO"

const int maxn = 1e6 + 5;
int spf[maxn];

void sieve()
{
    iota(spf, spf + maxn, 0);
    for (int i = 2; i * i <= maxn; i++)
        if (spf[i] == i)
            for (int j = i * i; j <= maxn; j += i)
                if (spf[j] == j)
                    spf[j] = i;
}

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int t = 1;
        while (x > 1)
        {   
            int p = spf[x], cnt = 0;
            while (x % p == 0)
                x /= p, cnt++;
            t *= (cnt & 1 ? p : 1);
        }
        mp[t]++;
    }
    int ans = 0;
    for (auto it : mp)
        ans += it.second * (it.second - 1) / 2;
    cout << ans;
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

    int tt = 1;
    // cin >> tt;

    sieve();

    while (tt--)
        solve();

    return 0;
}
