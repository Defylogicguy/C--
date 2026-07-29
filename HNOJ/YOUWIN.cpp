/*************************
  Author: Defy logic guy
  18:55:01 - 10/07/2026
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "YOUWIN"

bool solve(string s)
{
    if (s == "0")
        return true;
    int n = s.size();
    int M = 1 << n;
    vector<vector<int>> pos(M, vector<int>(n));
    for (int m = 0; m < M; m++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            pos[m][i] = cnt;
            if (m & (1 << i))
                cnt++;
        }
    }
    vector<vector<int>> dp(M, vector<int>(n + 1, LLONG_MAX));
    dp[0][n] = 0;
    for (int m = 0; m < M; m++)
    {
        for (int i = 0; i <= n; i++)
        {
            if (dp[m][i] == LLONG_MAX)
                continue;
            int curr;
            char cur;
            if (i == n)
                curr = 0, cur = 'A';
            else
                curr = pos[(m ^ (1 << i))][i] + 1, cur = s[i];
            for (int j = 0; j < n; j++)
            {
                if (m & (1 << j))
                    continue;
                int d = abs(cur - s[j]);
                int cost = dp[m][i] + abs(curr - pos[m][j]) + min(d, 26 - d) + 1;
                dp[m | (1 << j)][j] = min(dp[m | (1 << j)][j], cost);
            }
        }
    }
    cout << minall(dp[M - 1]) << '\n';
    return false;
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

    string s;

    while (cin >> s)
        if (solve(s))
            break;

    return 0;
}
