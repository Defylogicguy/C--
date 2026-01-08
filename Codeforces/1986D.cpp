/*************************
  Author: Defy logic guy
  23:30:51 - 16/09/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> decltype(c.begin(), c.end(), os)
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
#define NAME "1986D"

int calc(vector<int> a, int n)
{
    sort(all(a));
    if (a[0] == 0)
        return 0;
    else if (a == vector<int>(n, 1))
        return 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            continue;
        ans += a[i];
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = LLONG_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        vector<int> cur;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
            {
                if (s[j] == '0')
                    cur.pb(s[j + 1] - '0');
                else
                    cur.pb((s[j] - '0') * 10 + s[j + 1] - '0');
                j++;
            }
            else
                cur.pb(s[j] - '0');
        }
        ans = min(ans, calc(cur, n - 1));
    }
    cout << ans << '\n';
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

    while (tt--)
        solve();

    return 0;
}
