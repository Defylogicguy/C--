/*************************
  Author: Defy logic guy
  15:46:06 - 01/11/2025
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
#define NAME "LMH_PUNCH"

int rotate(int x)
{
    int ans = 0;
    for (int i = 0; i < 16; i++)
        if ((x >> i) & 1)
            ans |= (1 << ((i % 4) * 4 + 3 - i / 4));
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<pair<int, int>> v(all(mp));
    vector<vector<int>> r(v.size(), vector<int>(4));
    for (int i = 0; i < v.size(); i++)
    {
        r[i][0] = v[i].first;
        for (int _ = 1; _ < 4; _++)
            r[i][_] = rotate(r[i][_ - 1]);
    }
    int ans = 0;
    for (int i = 0; i < 16; i++)
        for (int j = i + 1; j < 16; j++)
        {
            int cnt = 0;
            for (int k = 0; k < v.size(); k++)
            {
                int t = 0;
                for (int _ = 0; _ < 4; _++)
                {
                    int idk = ((r[k][_] >> i) & 1) + ((r[k][_] >> j) & 1);
                    t = max(t, idk);
                    if (t == 2)
                        break;
                }
                cnt += t * v[k].second;
            }
            ans = max(ans, cnt);
        }
    cout << 2 * n - ans;
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
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
