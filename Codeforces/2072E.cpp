/*************************
  Author: Defy logic guy
  Modified: 25/02/2025
*************************/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int lim = 1e5 + 5;
const ll INF = LLONG_MAX;
const string FILE_NAME = "2072E";

vector<ll> mn(lim + 1, INF);
vector<ll> prt(lim + 1, -1);
vector<ll> sel(lim + 1, -1);

void pre()
{
    mn[0] = 0;

    vector<int> tri(501, 0);
    for (int j = 2; j <= 500; j++)
        tri[j] = j * (j - 1) / 2;

    for (int i = 0; i <= lim; i++)
        if (mn[i] != INF)
            for (int j = 2; j <= 500; j++)
            {
                if (i + tri[j] > lim)
                    break;

                if (mn[i] + j < mn[i + tri[j]])
                {
                    mn[i + tri[j]] = mn[i] + j;
                    prt[i + tri[j]] = i;
                    sel[i + tri[j]] = j;
                }
            }
}

void solve()
{
    int k;
    cin >> k;

    if (k == 0)
    {
        cout << "1\n1 1\n";
        return;
    }

    if (mn[k] > 500)
    {
        cout << "0\n";
        return;
    }

    vector<int> sq;
    int cur = k;
    while (cur > 0)
    {
        sq.push_back(sel[cur]);
        cur = prt[cur];
    }
    reverse(sq.begin(), sq.end());

    vector<pair<int, int>> res;
    int idx = 0;
    for (int j = 0; j < sq.size(); j++)
        for (int i = 0; i < sq[j]; i++, idx++)
            res.push_back({idx, j});

    cout << res.size() << '\n';
    for (const auto &[x, y] : res)
        cout << x << ' ' << y << '\n';
}

int main()
{
    if (fopen((FILE_NAME + ".INP").c_str(), "r"))
    {
        freopen((FILE_NAME + ".INP").c_str(), "r", stdin);
        freopen((FILE_NAME + ".OUT").c_str(), "w", stdout);
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    cin >> testCases;

    pre();
    while (testCases--)
    solve();

    return 0;
}
