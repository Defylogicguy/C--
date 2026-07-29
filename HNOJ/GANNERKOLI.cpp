/*************************
  Author: Defy logic guy
  14:48:56 - 16/07/2026
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
#define NAME "GANNERKOLI"

const int N = (1 << 22);
bool dp[N][26];
void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    fill(&dp[0][0], &dp[0][0] + N * 26, true);
    int M = (1 << n);
    for (int m = 1; m < M; m++)
        for (int i = 0; i < 26; i++)
            for (int k = 0; k < n; k++)
            {
                if ((m >> k & 1) or ((s[k][0] - 'a') != i))
                    continue;
                for (char c : s[k])
                    dp[(m | (1 << k))][c - 'a'] &= !dp[m][i];
            }
    for (int i = 0; i < M; i++)
        for (int j = 0; j < 26; j++)
            cout << dp[i][j] << " \n"[j == 25];
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

    while (tt--)
        solve();

    return 0;
}
