/*************************
  Author: Defy logic guy
  14:06:28 - 31/01/2026
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
#define NAME "LUYENDE2025_CONTEST2_B1"

const int maxn = 1e6 + 5;
bool p[maxn];
vector<int> prime;
void sieve()
{
    fill(p, p + maxn, true);
    p[0] = p[1] = false;
    for (int i = 2; i * i <= maxn; i++)
        if (p[i])
            for (int j = i * i; j < maxn; j += i)
                p[j] = false;
    for (int i = 0; i < maxn; i++)
        if (p[i])
            prime.pb(i);
}

void solve()
{
    int l, r;
    cin >> l >> r;
    int a = ceil(sqrt(l)), b = floor(sqrt(r));

    if (a > b)
    {
        cout << 0 << '\n';
        return;
    }

    cout << upper_bound(all(prime), b) - lower_bound(all(prime), a) << '\n';
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
    cin >> tt;

    sieve();

    while (tt--)
        solve();

    return 0;
}
