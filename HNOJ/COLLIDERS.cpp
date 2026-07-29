/*************************
  Author: Defy logic guy
  19:09:00 - 19/06/2026
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
#define NAME "COLLIDERS"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> spf(n + 1);
    for (int i = 2; i <= n; i++)
        if (spf[i] == 0)
            for (int j = i; j <= n; j += i)
                if (spf[j] == 0)
                    spf[j] = i;
    vector<char> on(n + 1, 0);
    vector<vector<int>> vis(n + 1);
    while (m--)
    {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+')
        {
            if (on[x])
            {
                cout << "Already on\n";
                continue;
            }
            int t = x, ans = 0;
            while (t > 1)
            {
                int p = spf[t];
                while (t % p == 0)
                    t /= p;
                auto &v = vis[p];
                while (v.size() and !on[v.back()])
                    v.pop_back();
                if (v.size())
                {
                    ans = v.back();
                    break;
                }
            }
            if (ans)
                cout << "Conflict with " << ans << '\n';
            else
            {
                cout << "Success\n";
                on[x] = 1;
                t = x;
                while (t > 1)
                {
                    int p = spf[t];
                    while (t % p == 0)
                        t /= p;
                    vis[p].pb(x);
                }
            }
        }
        else
        {
            if (!on[x])
                cout << "Already off\n";
            else
            {
                cout << "Success\n";
                on[x] = 0;
            }
        }
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

    while (tt--)
        solve();

    return 0;
}
