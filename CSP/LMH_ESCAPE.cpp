/*************************
  Author: Defy logic guy
  20:54:30 - 17/01/2026
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
#define NAME "LMH_ESCAPE"

void solve()
{
    int n, h;
    cin >> n >> h;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int c = accumulate(all(a), 0ll) - h;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.emplace_back(a[i], c + b[i]);
    sort(all(v), [](const pair<int, int> &a, const pair<int, int> &b)
         { return (a.second == b.second ? a.first < b.first : a.second < b.second); });
    heap<int> pq;
    int cur = 0;
    for (auto it : v)
        if (cur + it.first <= it.second)
            cur += it.first, pq.push(it.first);
        else
        {
            if (pq.empty())
                continue;
            if (pq.top() > it.first)
            {
                cur -= pq.top();
                pq.pop();
                pq.push(it.first);
                cur += it.first;
            }
        }
    cout << pq.size() << '\n';
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
