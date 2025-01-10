/*************************
  Author: Defy logic guy
  14:02:03 - 04/01/2025
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
#define NAME "KT3BAI7"

unordered_map<int, bool> m;
int len;
int a, b, c, d;
string s;

bool DFS(int p, int a, int b, int c, int d)
{
    if (p == len)
        return (a == 0 && b == 0 && c == 0 && d == 0);
    int key = p + a * 10000 + b * 100000000 + c * 10000000000 + d * 1000000000000;
    if (m.find(key) != m.end())
        return m[key];
    bool res = false;
    if (s[p] == '0')
    {
        if (a > 0)
        {
            if (DFS(p + 1, a - 1, b, c, d))
                return m[key] = true;
        }
        if (p + 1 < len && s[p + 1] == '1' && c > 0)
        {
            if (DFS(p + 2, a, b, c - 1, d))
                return m[key] = true;
        }
    }
    if (s[p] == '1')
    {
        if (b > 0)
        {
            if (DFS(p + 1, a, b - 1, c, d))
                return m[key] = true;
        }
        if (p + 1 < len && s[p + 1] == '0' && d > 0)
        {
            if (DFS(p + 2, a, b, c, d - 1))
                return m[key] = true;
        }
    }
    return m[key] = false;
}

void sub2()
{
    int n = a + b + 2 * c + 2 * d;
    vector<pair<int, int>> v;
    int cnt = 0;
    for (int i = 0; i < n - 1 - cnt; i++)
    {
        if (s[i] == '0' && s[i + 1] == '1' && c > 0)
        {
            c--;
            s.erase(i, 2);
            i--;
            cnt += 2;
        }
        if (s[i] == '1' && s[i + 1] == '0' && d > 0)
        {
            d--;
            s.erase(i, 2);
            i--;
            cnt += 2;
        }
    }
    int cnt1 = 0;
    int cnt0 = 0;
    for (int i = 0; i < n - 1 - cnt; i++)
    {
        if (s[i] == '0')
            cnt0++;
        else
            cnt1++;
    }
    if (cnt0 <= a && cnt1 <= b)
        cout << "Yes\n";
    else
        cout << "No\n";
}

void solve()
{
    cin >> a >> b >> c >> d;
    cin >> s;
    int hs = 50;
    if (a > hs && b > hs & c > hs && d > hs)
    {
        sub2();
        return;
    }
    len = s.length();
    int cnt0 = count(s.begin(), s.end(), '0');
    int cnt1 = count(s.begin(), s.end(), '1');
    if (a + c + d != cnt0 || b + c + d != cnt1)
    {
        cout << "No\n";
        return;
    }
    m.clear();
    bool ok = DFS(0, a, b, c, d);
    if (ok)
        cout << "Yes\n";
    else
        cout << "No\n";
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
