/*************************
  Author: Defy logic guy
  18:49:56 - 24/04/2026
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
#define NAME "SONGUYENTO"

const int N = 4e4;
bool p[N];
vector<int> v;
void pre()
{
    fill(p, p + N, true);
    p[0] = p[1] = false;
    for (int i = 2; i * i <= N; i++)
        if (p[i])
            for (int j = i * i; j < N; j += i)
                p[j] = false;
    for (int i = 0; i < N; i++)
        if (p[i])
            v.pb(i);
}

void solve()
{
    int l, r;
    cin >> l >> r;
    vector<int> a(r - l + 1, 0), cnt(r - l + 1, 0);
    iota(all(a), l);
    for (int p : v)
    {
        if (p * p > r)
            break;
        for (int j = (l + p - 1) / p * p; j <= r; j += p)
        {
            int idx = j - l;
            while (a[idx] % p == 0)
                a[idx] /= p, cnt[idx]++;
        }
    }
    for (int i = 0; i < r - l + 1; i++)
        if (a[i] > 1)
            cnt[i]++;
    int ans = 0;
    for (int i = 0; i < r - l + 1; i++)
        ans += (cnt[i] <= 1);
    cout << ans - (l == 1) << '\n';
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

    pre();

    while (tt--)
        solve();

    return 0;
}
