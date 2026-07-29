/*************************
  Author: Defy logic guy
  19:00:59 - 15/05/2026
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
#define NAME "PPRIME"

const int maxn = 1e7 + 7;
bool p[maxn];
int pf[maxn + 1];
void pre()
{
    vector<int> v;
    fill(p, p + maxn, true);
    p[0] = p[1] = false;
    for (int i = 2; i * i < maxn; i++)
        if (p[i])
            for (int j = i * i; j < maxn; j += i)
                p[j] = false;
    for (int i = 2; i < maxn; i++)
        if (p[i])
            v.pb(i);
    vector<int> ten(7, 1);
    for (int i = 1; i <= 6; i++)
        ten[i] = ten[i - 1] * 10;
    for (int x : v)
    {
        int t = x, len = 0;
        while (t)
            t /= 10, len++;
        for (int i = 1; i <= len - 1; i++)
        {
            int r = x % ten[i], l = x / ten[i];
            if (l < maxn and r < maxn and p[l] and p[r])
            {
                pf[x] = 1;
                break;
            }
        }
    }
    for (int i = 1; i < maxn; i++)
        pf[i] += pf[i - 1];
}

void solve()
{
    int l, r;
    cin >> l >> r;
    cout << pf[r] - pf[l - 1] << '\n';
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
