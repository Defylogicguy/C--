/*************************
  Author: Defy logic guy
  10:56:30 - 23/11/2025
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
    for (auto it = c.begin(); it != c.end(); ++it)
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
#define NAME "2413"

template <int mod>
struct ModInt
{
    using mint = long long;
    int val;

    ModInt(mint v = 0) : val(v % mod)
    {
        if (val < 0)
            val += mod;
    };

    ModInt operator+() const { return ModInt(val); }
    ModInt operator-() const { return ModInt(mod - val); }
    ModInt inv() const { return this->pow(mod - 2); }

    ModInt operator+(const ModInt &x) const { return ModInt(*this) += x; }
    ModInt operator-(const ModInt &x) const { return ModInt(*this) -= x; }
    ModInt operator*(const ModInt &x) const { return ModInt(*this) *= x; }
    ModInt operator/(const ModInt &x) const { return ModInt(*this) /= x; }
    ModInt pow(mint n) const
    {
        auto x = ModInt(1);
        auto b = *this;
        while (n > 0)
        {
            if (n & 1)
                x *= b;
            n >>= 1;
            b *= b;
        }
        return x;
    }

    ModInt &operator+=(const ModInt &x)
    {
        if ((val += x.val) >= mod)
            val -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &x)
    {
        if ((val -= x.val) < 0)
            val += mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &x)
    {
        val = mint(val) * x.val % mod;
        return *this;
    }
    ModInt &operator/=(const ModInt &x) { return *this *= x.inv(); }

    bool operator==(const ModInt &b) const { return val == b.val; }
    bool operator!=(const ModInt &b) const { return val != b.val; }

    friend std::istream &operator>>(std::istream &is, ModInt &x) noexcept { return is >> x.val; }
    friend std::ostream &operator<<(std::ostream &os, const ModInt &x) noexcept { return os << x.val; }
};
using mint = ModInt<MOD>;

const int maxn = 1e6 + 5;
mint dp[maxn][2];

void pre()
{
    dp[1][0] = dp[1][1] = mint(1);
    for (int i = 2; i < maxn; i++)
    {
        dp[i][0] = mint(4) * dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + mint(2) * dp[i - 1][1];
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << dp[n][0] + dp[n][1] << '\n';
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
    
    pre();

    while (tt--)
        solve();

    return 0;
}
