/*************************
  Author: Defy logic guy
  13:48:00 - 07/01/2025
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
#define NAME "RECEIPT"

// int stoll(string s)
// {
//     int ans = 0;
//     for (int i = 0; i < s.size(); i++)
//         ans = ans * 10 + (s[i] - '0');
//     return ans;
// }

void solve()
{
    string s;
    getline(cin, s);

    string idk = "";
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '(')
            idk += "( ";
        else if (s[i] == ')')
            idk += " ) ";
        else
            idk += s[i];
    s = idk;

    vector<string> a;
    stringstream ss(s);
    while (ss >> idk)
        a.pb(idk);

    set<string> st;
    map<string, int> mp;
    int one = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == "(")
            continue;
        if (a[i] == ")")
        {
            if (i + 1 < a.size())
                one += stoll(a[i + 1]);
        }
        else
        {
            if (isdigit(a[i][0]))
                continue;
            st.insert(a[i]);
            if (i + 1 < a.size())
                mp[a[i]] += stoll(a[i + 1]);
        }
    }

    cout << one << endl;
    for (auto it : st)
        cout << it << ' ' << mp[it] << endl;
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
