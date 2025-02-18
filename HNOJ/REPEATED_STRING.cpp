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
#define NAME "REPEATED_STRING"

void solve()
{
    string s;
    cin >> s;

    string cur = "";
    for (int i = 0; i < s.size(); i++)
    {
        cur += s[i];
        bool flag = true;
        for (int j = 0; j < s.size(); j += i + 1)
        {
            if (s.size() - j < cur.size())
                flag &= s.substr(j, s.size() - j) == cur.substr(0, s.size() - j);
            else
                flag &= s.substr(j, i + 1) == cur;
        }
        if (flag)
        {
            cout << cur << endl;
            return;
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
