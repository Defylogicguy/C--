/*************************
  Author: Defy logic guy
  11:43:18 - 20/07/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "2118D1"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<vector<int>> rev(n * 2 * k);
    vector<char> v(n * 2 * k, 0);
    auto f = [k](int a, int b, int c)
    {
        return (a * 2 + b) * k + c;
    };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            for (int u = 0; u < k; u++)
            {
                int cur = f(i, j, u);
                int d = (j == 1 ? 1 : -1);
                int nr = u;
                if (u == b[i])
                    d = -d;
                int nxt = i + d;
                if (nxt < 0 || nxt >= n)
                    v[cur] = 1;
                else
                {
                    int ds = abs(a[nxt] - a[i]);
                    int nr2 = (nr + ds) % k;
                    int nd = (d == 1 ? 1 : 0);
                    int nid = f(nxt, nd, nr2);
                    rev[nid].push_back(cur);
                }
            }
    vector<char> gud(n * 2 * k, 0);
    deque<int> dq;
    for (int id = 0; id < n * 2 * k; id++)
        if (v[id])
        {
            gud[id] = 1;
            dq.push_back(id);
        }
    while (dq.size())
    {
        int u = dq.front();
        dq.pop_front();
        for (int v : rev[u])
            if (!gud[v])
            {
                gud[v] = 1;
                dq.push_back(v);
            }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a1;
        cin >> a1;
        int idx = lower_bound(a.begin(), a.end(), a1) - a.begin();
        int id0;
        if (idx < n && a[idx] == a1)
        {
            int j = idx;
            int d = 1;
            if (b[j] == 0)
                d = -1;
            if (d == -1)
            {
                if (j == 0)
                {
                    cout << "YES\n";
                    continue;
                }
            }
            else
            {
                if (j == n - 1)
                {
                    cout << "YES\n";
                    continue;
                }
            }
            int nxt = j + d;
            int ds = abs(a[nxt] - a1);
            int r0 = ds % k;
            int di = (d == 1 ? 1 : 0);
            id0 = f(nxt, di, r0);
        }
        else
        {
            int j = idx;
            if (j >= n)
            {
                cout << "YES\n";
                continue;
            }
            int ds = a[j] - a1;
            int r0 = ds % k;
            int di = 1;
            id0 = f(j, di, r0);
        }
        cout << (gud[id0] ? "YES\n" : "NO\n");
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
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
