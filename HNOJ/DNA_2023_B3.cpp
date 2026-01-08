/*************************
  Author: Defy logic guy
  18:45:08 - 19/12/2025
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
#define NAME "DNA_2023_B3"

int modmul(int a, int b, int mod)
{
    return (int)((__int128)a * b % mod);
}

int modpow(int a, int e, int mod)
{
    __int128 res = 1;
    __int128 base = a % mod;
    while (e > 0)
    {
        if (e & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        e >>= 1;
    }
    return (int)res;
}

bool miller_rabin(int n)
{
    if (n < 2)
        return false;
    int smallPrimes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (int p : smallPrimes)
    {
        if (n == p)
            return true;
        if (n % p == 0)
            return false;
    }
    int d = n - 1;
    int s = 0;
    while ((d & 1) == 0)
    {
        d >>= 1;
        s++;
    }
    int bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (int a : bases)
    {
        if (a % n == 0)
            continue;
        int x = modpow((int)(a % n), d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool composite = true;
        for (int r = 1; r < s; ++r)
        {
            x = modmul((int)x, (int)x, n);
            if (x == n - 1)
            {
                composite = false;
                break;
            }
        }
        if (composite)
            return false;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    auto f = [](int n) -> int
    {
        int ans = n;
        n /= 10;
        while (n)
            ans = ans * 10 + n % 10, n /= 10;
        return ans;
    };
    int ans = (n > 1);
    for (int i = 1;; i++)
    {
        int p = f(i);
        if (p >= n)
            break;
        if (p > 11 and miller_rabin(p))
            ans++;
    }
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

    while (tt--)
        solve();

    return 0;
}
