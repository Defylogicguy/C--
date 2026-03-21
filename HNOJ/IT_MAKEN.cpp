/*************************
  Author: Defy logic guy
  19:42:43 - 13/03/2026
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
#define NAME "IT_MAKEN"

const int maxn = 1e6 + 5, lim = 1000000000000000000ll;
bool p[maxn];
int b[maxn];
vector<int> prime;
void pre()
{
    fill(p, p + maxn, true);
    p[0] = p[1] = false;
    for (int i = 2; i * i <= maxn; i++)
        if (p[i])
            for (int j = i * i; j < maxn; j += i)
                p[j] = false;
    for (int i = 2; i < maxn; i++)
        if (p[i])
            prime.pb(i);
}

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int ans = 1;
    for (int i = 0; i < (int)prime.size(); i++)
    {
        int x = prime[i], cnt = 1;
        while (x <= 1000000)
            x *= prime[i], cnt++;
        b[prime[i]] = cnt;
    }
    for (int i = 0; i < (int)prime.size(); i++)
    {
        if ((ans * prime[i]) > 1000000)
            break;
        cout << "ucln " << binpow(prime[i], b[prime[i]]) << endl;
        int x;
        cin >> x;
        ans *= x;
    }
    cout << "traloi " << ans << endl;
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

    pre();

    while (tt--)
        solve();

    return 0;
}
