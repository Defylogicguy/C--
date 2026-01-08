/*************************
  Author: Defy logic guy
  10:25:15 - 22/02/2025
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
#define NAME "HASH_ADDSTRING"

vector<int> f(const string &t)
{
    int n = t.size();
    vector<int> a(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = a[i - 1];
        while (j > 0 && t[i] != t[j])
            j = a[j - 1];
        if (t[i] == t[j])
            j++;
        a[i] = j;
    }
    return a;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    string tmp = s;
    reverse(all(tmp));

    string t = tmp + ' ' + s;
    vector<int> a = f(t);

    string add = s.substr(0, n - a[t.size() - 1]);
    reverse(all(add));

    cout << s + add << endl;
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

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
