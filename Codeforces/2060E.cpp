/*************************
  Author: Defy logic guy
  22:36:31 - 19/01/2025
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
#define NAME "2060E"

const int maxn = 2e5 + 5;

vector<bool> check1(maxn, false), check2(maxn, false);
int cnt = 0, cnt2 = 0, n, m1, m2;
vector<vector<int>> connect1(maxn), connect2(maxn);
vector<int> idk(maxn);
map<pair<int, int>, int> mp;

void find1(int i)
{
    check1[i] = true;
    for (int it : connect1[i])
        if (!check1[it] && mp[{i, it}] != 1)
            find1(it);
}

void find2(int i)
{
    idk[i] = cnt;
    check2[i] = true;
    for (int it : connect2[i])
        if (!check2[it])
            find2(it);
}

void solve()
{
    int m1, m2;
    cin >> n >> m1 >> m2;
    cnt = 0, cnt2 = 0;

    mp.clear();
    connect1.assign(n, vector<int>()), connect2.assign(n, vector<int>());
    check1.assign(n, false), check2.assign(n, false), idk.assign(n, 0);

    for (int i = 0; i < m1; i++)
    {
        int u, v;
        cin >> u >> v;
        connect1[u - 1].pb(v - 1);
        connect1[v - 1].pb(u - 1);
    }

    for (int i = 0; i < m2; i++)
    {
        int u, v;
        cin >> u >> v;
        connect2[u - 1].pb(v - 1);
        connect2[v - 1].pb(u - 1);
    }

    for (int i = 0; i < n; i++)
        if (!check2[i])
        {
            cnt++;
            find2(i);
        }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int v : connect1[i])
            if (idk[i] != idk[v])
            {
                ans++;
                mp[{i, v}] = true;
            }

    for (int i = 0; i < n; i++)
        if (!check1[i])
        {
            cnt2++;
            find1(i);
        }

    cout << ans / 2 + (cnt2 - cnt) << endl;
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
