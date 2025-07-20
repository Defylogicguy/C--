/*************************
  Author: Defy logic guy
  11:46:58 - 20/07/2025
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
#define NAME "2111E"

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<set<int>>> ops(3, vector<set<int>>(3));
    for (int u = 0; u < 3; u++)
        for (int v = 0; v < 3; v++)
            ops[u][v].clear();

    vector<pair<int, int>> op(q);
    for (int i = 0; i < q; i++)
    {
        char cx, cy;
        cin >> cx >> cy;
        int x = cx - 'a';
        int y = cy - 'a';
        op[i] = {x, y};
        ops[x][y].insert(i);
    }

    string ans = s;
    for (int i = 0; i < n; i++)
    {
        int x = s[i] - 'a';
        bool c = false;

        for (int y = 0; y < x; y++)
        {
            int bl = 4;
            int bi = q + 1;
            vector<tuple<int, int, int>> bc;

            if (!ops[x][y].empty())
            {
                int j = *ops[x][y].begin();
                bl = 1;
                bi = j;
                bc = {make_tuple(x, y, j)};
            }

            if (bl > 1)
            {
                int j2mn = q + 1;
                int x1 = -1, x2 = -1, i1 = -1, i2 = -1;
                for (int m = 0; m < 3; m++)
                {
                    if (m == x || m == y)
                        continue;
                    if (ops[x][m].empty())
                        continue;
                    int j1 = *ops[x][m].begin();
                    auto it = ops[m][y].upper_bound(j1);
                    if (it == ops[m][y].end())
                        continue;
                    int j2 = *it;
                    if (j2 < j2mn)
                    {
                        j2mn = j2;
                        x1 = x;
                        x2 = m;
                        i1 = j1;
                        i2 = j2;
                    }
                }
                if (j2mn < q + 1)
                {
                    bl = 2;
                    bi = j2mn;
                    bc.clear();
                    bc.push_back(make_tuple(x1, x2, i1));
                    bc.push_back(make_tuple(x2, y, i2));
                }
            }

            if (bl > 2)
            {
                int j3mn = q + 1;
                int r1 = -1, r2 = -1, r3 = -1, id1 = -1, id2 = -1, id3 = -1;
                for (int m1 = 0; m1 < 3; m1++)
                {
                    if (m1 == x)
                        continue;
                    if (ops[x][m1].empty())
                        continue;
                    int j1 = *ops[x][m1].begin();
                    for (int m2 = 0; m2 < 3; m2++)
                    {
                        if (m2 == m1 || m2 == y)
                            continue;
                        auto it2 = ops[m1][m2].upper_bound(j1);
                        if (it2 == ops[m1][m2].end())
                            continue;
                        int j2 = *it2;
                        auto it3 = ops[m2][y].upper_bound(j2);
                        if (it3 == ops[m2][y].end())
                            continue;
                        int j3 = *it3;
                        if (j3 < j3mn)
                        {
                            j3mn = j3;
                            r1 = x;
                            r2 = m1;
                            r3 = m2;
                            id1 = j1;
                            id2 = j2;
                            id3 = j3;
                        }
                    }
                }
                if (j3mn < q + 1)
                {
                    bl = 3;
                    bi = j3mn;
                    bc.clear();
                    bc.push_back(make_tuple(r1, r2, id1));
                    bc.push_back(make_tuple(r2, r3, id2));
                    bc.push_back(make_tuple(r3, y, id3));
                }
            }

            if (bl < 4)
            {
                for (auto &e : bc)
                {
                    int x, y, idx;
                    tie(x, y, idx) = e;
                    ops[x][y].erase(idx);
                }
                ans[i] = char('a' + y);
                c = true;
                break;
            }
        }

        if (!c)
            ans[i] = s[i];
    }

    cout << ans << '\n';
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
