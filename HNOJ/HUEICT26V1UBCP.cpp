/*************************
  Author: Defy logic guy
  18:48:17 - 27/03/2026
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
#define NAME "HUEICT26V1UBCP"

const int N = 1e6 + 5;
int sq[N];

void sieve()
{
    for (int i = 0; i < N; i++)
        sq[i] = i;
    for (int i = 2; i * i < N; i++)
        if (sq[i] == i)
            for (int j = i * i; j < N; j += i * i)
                while (sq[j] % (i * i) == 0)
                    sq[j] /= (i * i);
}

void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ans += mp[sq[x]];
        mp[sq[x]]++;
    }
    cout << ans;
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

    sieve();

    while (tt--)
        solve();

    return 0;
}
