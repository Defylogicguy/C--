/*************************
 Author: Defy logic guy
09:52:15 - 13/06/2025
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
#define NAME "GOLD"

vector<int> up;
void makedj(int n)
{
    up.resize(n + 1);
    iota(all(up), 0);
}
int find(int x) { return x == up[x] ? x : up[x] = find(up[x]); }
void uni(int x, int y) { up[find(x)] = find(y); }
bool same(int x, int y) { return find(x) == find(y); }

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> edge(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[i] = {x, y};
    }

    vector<vector<int>> query;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        query.pb({x, y});
    }

    vector<int> l(q, 0), r(q, m + 1);

    while (true)
    {
        bool flag = false;
        vector<vector<int>> c(m + 2);

        for (int i = 0; i < q; i++)
            if (l[i] < r[i])
            {
                int mid = (l[i] + r[i]) / 2;
                c[mid].pb(i);
                flag = true;
            }

        if (!flag)
            break;

        makedj(n);

        for (int i = 0; i <= m; i++)
        {
            if (i > 0)
                uni(edge[i - 1][0], edge[i - 1][1]);
            for (int j : c[i])
                same(query[j][0], query[j][1]) ? r[j] = i : l[j] = i + 1;
        }
    }

    for (int i = 0; i < q; i++)
        cout << (l[i] <= m ? l[i] : -1) << '\n';
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
