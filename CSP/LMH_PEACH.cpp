/*************************
  Author: Defy logic guy
  14:57:40 - 11/10/2025
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
#define NAME "LMH_PEACH"

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int t, k;
        cin >> t >> k;
        v.emplace_back(t, k);
    }
    sort(all(v));
    heap<int> pq;
    int idx = 0, ans = 0, i = a;
    while (i < b)
    {
        while (idx < n and v[idx].first <= i)
        {
            pq.push(v[idx].second);
            idx++;
        }
        if (pq.size())
        {
            ans += pq.top();
            pq.pop();
            i++;
        }
        else
        {
            if (idx >= n)
                break;
            i = max(i, v[idx].first);
        }
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
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
