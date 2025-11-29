/*************************
  Author: Defy logic guy
  16:13:58 - 29/11/2025
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
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "TOUR"

struct node
{
    int l, r;
    float dr, t;
};

void solve()
{
    int n, m, k, x, y;
    cin >> n >> k >> m >> x >> y;
    vector<node> a;
    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        float dr = (float)r + (float)(r - l) * (float)y / (float)x;
        float t = (float)(r - l) / (float)x + (float)(n - r) / (float)y;
        a.pb({l, r, dr, t});
    }
    vector<pair<int, int>> qry;
    vector<int> s(m);
    for (int i = 0; i < m; i++)
    {
        cin >> s[i];
        qry.emplace_back(s[i], i);
    }
    sort(all(a), [](const node &a, const node &b)
         { return a.l < b.l; });
    sort(all(qry));
    vector<float> ans(m);
    auto cmp = [](const pair<float, float> &a, const pair<float, float> &b)
    { return a.first > b.first; };
    heap<pair<float, float>, vector<pair<float, float>>, decltype(cmp)> pq(cmp);
    int idx = 0;
    for (auto &it : qry)
    {
        while (idx < a.size() and a[idx].l <= it.first)
        {
            pq.emplace(a[idx].t, a[idx].dr);
            idx++;
        }
        while (pq.size() and pq.top().second < (float)it.first)
            pq.pop();
        float mn = (float)(n - it.first) / (float)y;
        if (pq.size())
            mn = min(mn, pq.top().first);
        ans[it.second] = mn;
    }
    for (float i : ans)
        cout << i << '\n';
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