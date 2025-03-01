/*************************
  Author: Defy logic guy
  21:27:52 - 25/02/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "F43BK"

struct trio
{
    int one, two, tri;
};

class comp
{
public:
    bool operator() (trio a, trio b)
    {
        if (a.one != b.one)
            return a.one > b.one;
        else
            return a.two == b.two ? a.tri > b.tri : a.two > b.two;
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(all(a));
    sort(all(b));

    heap<trio, vector<trio>, comp> pq;
    for (int i = 0; i < n; i++)
        pq.push({a[i] + b[0], i, 0});

    vector<int> res;
    while (k-- and pq.size())
    {
        auto [sum, i, j] = pq.top();
        pq.pop();
        res.pb(sum);
        if (j + 1 < n)
            pq.push({a[i] + b[j + 1], i, j + 1});
    }
    for (int i : res)
        cout << i << ' ';
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
