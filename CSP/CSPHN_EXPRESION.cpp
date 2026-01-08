/*************************
  Author: Defy logic guy
  16:09:50 - 15/02/2025
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
#define NAME "CSPHN_EXPRESION"

int get(string s, int &idx)
{
    if (isdigit(s[idx]))
    {
        int num = 0;
        while (idx < s.size() && isdigit(s[idx]))
        {
            num = num * 10 + (s[idx] - '0');
            idx++;
        }
        return num;
    }

    string f;
    while (idx < s.size() && isalpha(s[idx]))
    {
        f += s[idx];
        idx++;
    }

    idx++;

    int one = get(s, idx);
    idx++;
    int two = get(s, idx);
    idx++;

    if (f == "SUM")
        return one + two;
    if (f == "DIF")
        return one - two;
    if (f == "MAX")
        return max(one, two);
    if (f == "MIN")
        return min(one, two);
    if (f == "GCD")
        return __gcd(one, two);

    return 0;
}

void solve()
{
    string s;
    getline(cin, s);
    int idx = 0;
    cout << get(s, idx);
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
