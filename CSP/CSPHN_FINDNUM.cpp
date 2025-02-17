/*************************
  Author: Defy logic guy
  14:48:26 - 15/02/2025
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
#define NAME "CSPHN_FINDNUM"

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(all(a)), sort(all(b));
    heap<trio, vector<trio>, comp> pq;
    for (int i = 0; i < n; i++)
        pq.push({a[i] + b[0], i, 0});

    while (k-- && !pq.empty())
    {
        trio tp = pq.top();
        pq.pop();
        cout << tp.one << ' ';
        int i = tp.two, j = tp.tri;
        if (j + 1 < m)
            pq.push({a[i] + b[j + 1], i, j + 1});
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
