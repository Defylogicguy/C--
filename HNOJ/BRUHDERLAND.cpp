/*************************
  Author: Defy logic guy
  19:24:02 - 22/08/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "BRUHDERLAND"

struct node
{
    int a, b, c;
    node(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}
};

const int maxn = 2507;
queue<node> q[maxn];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 1e9;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int d[n][m][k + 1];
    fill(&d[0][0][0], &d[0][0][0] + sizeof(d) / sizeof(int), INF);
    d[0][0][0] = 0;
    q[0].push({0, 0, 0});
    for (int i = 0; i <= 2500; i++)
        while (q[i].size())
        {
            auto t = q[i].front();
            q[i].pop();
            if (d[t.a][t.b][t.c] != i)
                continue;
            if (t.a == n - 1 and t.b == m - 1)
            {
                cout << i;
                return;
            }
            for (int j = 0; j < 4; j++)
            {
                int nx = t.a + dx[j];
                int ny = t.b + dy[j];
                if (nx < 0 or ny < 0 or nx >= n or ny >= m)
                    continue;
                if (a[nx][ny] == '*')
                {
                    if (t.c == k)
                        continue;
                    if (i < d[nx][ny][t.c + 1])
                    {
                        d[nx][ny][t.c + 1] = i;
                        q[i].push({nx, ny, t.c + 1});
                    }
                }
                else
                {
                    int w = (a[nx][ny] == '.' ? 0 : (a[nx][ny] == 'A' ? 1 : 2));
                    if (i + w < d[nx][ny][t.c])
                    {
                        d[nx][ny][t.c] = i + w;
                        q[i + w].push({nx, ny, t.c});
                    }
                }
            }
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
