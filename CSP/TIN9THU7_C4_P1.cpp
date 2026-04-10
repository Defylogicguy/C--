/*************************
  Author: Defy logic guy
  14:10:04 - 28/03/2026
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
#define NAME "idk1"

const int N = 1005;
int prime[N];
void pre()
{
    fill(prime, prime + N, true);
    prime[1] = prime[0] = false;
    for (int i = 2; i * i < N; i++)
        if (prime[i])
            for (int j = i * i; j < N; j += i)
                prime[j] = false;
}

void solve()
{
    int x;
    cin >> x;
    x++;
    for (;; x++)
    {
        auto f = [&](int n) -> bool
        {
            int t = 0;
            while (n)
                t += (n % 10) * (n % 10), n /= 10;
            return prime[t];
        };
        if (!f(x))
            continue;
        cout << x << '\n';
        break;
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
    cin >> tt;

    pre();

    while (tt--)
        solve();

    return 0;
}
