/*************************
  Author: Defy logic guy
  09:36:34 - 05/06/2025
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
#define NAME "ABC336F"

int h, w;
map<string, int> one, two;

vector<vector<int>> rotate(const vector<vector<int>> &a)
{
    vector<vector<int>> ans(h, vector<int>(w));
    for (int i = 0; i < h - 1; i++)
        for (int j = 0; j < w - 1; j++)
            ans[h - 2 - i][w - 2 - j] = a[i][j];
    return ans;
}

void do1(vector<vector<int>> &a, int x, int y, int idx)
{
    string hash = "";
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            hash += to_string(a[i][j]) + "#";
    if (one.find(hash) != one.end())
        one[hash] = min(one[hash], idx);
    else
        one[hash] = idx;
    if (idx == 10)
        return;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            if (i == x and j == y)
                continue;
            vector<vector<int>> b = a;
            vector<vector<int>> tmp(h - 1, vector<int>(w - 1));
            for (int k = i; k < h - 1 + i; k++)
                for (int l = j; l < w - 1 + j; l++)
                    tmp[k - i][l - j] = a[k][l];
            tmp = rotate(tmp);
            for (int k = i; k < h - 1 + i; k++)
                for (int l = j; l < w - 1 + j; l++)
                    a[k][l] = tmp[k - i][l - j];
            do1(a, i, j, idx + 1);
            for (int k = 0; k < h; k++)
                for (int l = 0; l < w; l++)
                    a[k][l] = b[k][l];
        }
}

void do2(vector<vector<int>> &a, int x, int y, int idx)
{
    string hash = "";
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            hash += to_string(a[i][j]) + "#";
    if (two.find(hash) != two.end())
        two[hash] = min(two[hash], idx);
    else
        two[hash] = idx;
    if (idx == 10)
        return;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            if (i == x and j == y)
                continue;
            vector<vector<int>> b = a;
            vector<vector<int>> tmp(h - 1, vector<int>(w - 1));
            for (int k = i; k < h - 1 + i; k++)
                for (int l = j; l < w - 1 + j; l++)
                    tmp[k - i][l - j] = a[k][l];
            tmp = rotate(tmp);
            for (int k = i; k < h - 1 + i; k++)
                for (int l = j; l < w - 1 + j; l++)
                    a[k][l] = tmp[k - i][l - j];
            do2(a, i, j, idx + 1);
            for (int k = 0; k < h; k++)
                for (int l = 0; l < w; l++)
                    a[k][l] = b[k][l];
        }
}

void solve()
{
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> a[i][j];
    do1(a, -1, -1, 0);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            a[i][j] = i * w + j + 1;
    do2(a, -1, -1, 0);
    int ans = LLONG_MAX;
    for (auto &[s, n] : one)
        if (two.find(s) != two.end())
            ans = min(ans, n + two[s]);
    cout << (ans == LLONG_MAX ? -1 : ans);
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
