/*************************
  Author: Defy logic guy
  10:55:56 - 18/07/2026
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
#define NAME "idk"

const int N = 32768;
int d[N + 1];
void solve()
{
    int n;
    cin >> n;
    fill(d, d + N + 1, LLONG_MAX);
    queue<int> q;
    d[N] = 0;
    q.push(N);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        if (x > 1 and d[x - 1] == LLONG_MAX)
        {
            d[x - 1] = d[x] + 1;
            q.push(x - 1);
        }
        if (x % 2 == 0)
        {
            int a = x / 2, b = (x + N) / 2;
            if (d[a] == LLONG_MAX)
            {
                d[a] = d[x] + 1;
                q.push(a);
            }
            if (b <= N and d[b] == LLONG_MAX)
            {
                d[b] = d[x] + 1;
                q.push(b);
            }
        }
    }
    while (n--)
    {
        int x;
        cin >> x;
        if (x == 0)
            x = N;
        cout << d[x] << ' ';
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
