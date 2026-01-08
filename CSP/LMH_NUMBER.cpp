/*************************
  Author: Defy logic guy
  23:02:02 - 17/11/2025
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
#define NAME "LMH_NUMBER"

void solve()
{
    string a, b;
    cin >> a >> b;
    vector<vector<pair<int, char>>> dp(a.size() + 1, vector<pair<int, char>>(b.size() + 1, {0, '0'}));
    for (int i = a.size() - 1; i >= 0; i--)
        for (int j = b.size() - 1; j >= 0; j--)
            if (a[i] == b[j])
                dp[i][j] = make_pair(dp[i + 1][j + 1].first + 1, a[i]);
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
    pair<int, int> res = make_pair(0, '0');
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            if (dp[i][j].second != '0' && dp[i][j].first > res.first)
                res = dp[i][j];
    if (res.first == 0)
    {
        cout << 0;
        return;
    }
    int i = 0, j = 0;
    char c = res.second;
    while (true)
    {
        cout << c;
        while (a[i] != c)
            i++;
        i++;
        while (b[j] != c)
            j++;
        j++;
        if (dp[i][j].first == 0)
            break;
        c = dp[i][j].second;
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
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
