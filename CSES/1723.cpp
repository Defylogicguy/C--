/*************************
  Author: Defy logic guy
  16:20:12 - 17/06/2026
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
#define NAME "1723"

struct Mat
{
    int a[100][100] = {0};
    int n, m, mm;
    Mat(int n = 0, int m = 0, int mod = MOD) : n(n), m(m), mm(mod) {}
    Mat operator*(const Mat &o) const
    {
        if (m != o.n)
        {
            cerr << "Invalid dimensions\n";
            exit(0);
        }
        Mat ans(n, o.m, mm);
        for (int i = 0; i < n; i++)
            for (int k = 0; k < m; k++)
                if (a[i][k])
                    for (int j = 0; j < o.m; j++)
                        (ans.a[i][j] += (a[i][k] * o.a[k][j])) %= mm;
        return ans;
    }
    Mat &operator*=(const Mat &o)
    {
        *this = *this * o;
        return *this;
    }
    Mat identity(int n)
    {
        Mat ans(n, n, mm);
        for (int i = 0; i < n; i++)
            ans.a[i][i] = 1;
        return ans;
    }
    Mat pow(int p)
    {
        Mat ans = identity(n);
        Mat base = *this;
        while (p)
        {
            if (p & 1)
                ans *= base;
            base *= base;
            p >>= 1;
        }
        return ans;
    }
    bool iszero() const
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j])
                    return false;
        return true;
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    Mat one(n, n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        (one.a[v - 1][u - 1] += 1) %= MOD;
    }
    one = one.pow(k);
    cout << one.a[n - 1][0];
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
