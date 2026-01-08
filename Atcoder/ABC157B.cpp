/*************************
  Author: Defy logic guy
  22:14:30 - 12/05/2025
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
#define endl '\n'
#define NAME "ABC157B"

void solve()
{
    vector<vector<int>> a(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    vector<vector<bool>> vis(3, vector<bool>(3, false));
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (a[i][j] == x)
                    vis[i][j] = true;
    }
    for (int i = 0; i < 3; i++)
        if ((vis[i][0] && vis[i][1] && vis[i][2]) or (vis[0][i] && vis[1][i] && vis[2][i]))
        {
            cout << "Yes\n";
            return;
        }
    cout << ((vis[0][0] and vis[1][1] and vis[2][2]) or (vis[0][2] and vis[1][1] and vis[2][0]) ? "Yes\n" : "No\n");
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
