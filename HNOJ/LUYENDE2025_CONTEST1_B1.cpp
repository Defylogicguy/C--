/*************************
  Author: Defy logic guy
  14:17:04 - 24/01/2026
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
#define NAME "LUYENDE2025_CONTEST1_B1"

const int N = 1e6 + 5;
int lpf[N];

void sieve()
{
    for (int i = 2; i < N; i++)
        if (lpf[i] == 0)
            for (int j = i; j < N; j += i)
                lpf[j] = i;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1, 0);

    for (int i = 2; i <= n; i++)
        a[lpf[i]]++;

    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];

    while (q--)
    {
        int k;
        cin >> k;
        cout << a[k] << '\n';
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

    int tt = 1;
    // cin >> tt;

    sieve();

    while (tt--)
        solve();

    return 0;
}
