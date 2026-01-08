/*************************
  Author: Defy logic guy
  16:23:40 - 01/03/2025
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
#define NAME "CSPHN_CHANGE1"

int rotate_num(int n)
{
    if (n < 10)
        return n;
    string s = to_string(n);
    s = s.substr(1) + s[0];
    int pos = s.find_first_not_of('0');
    if (pos == string::npos)
        return 0;
    s = s.substr(pos);
    if (s.empty())
        return 0;
    return stoll(s);
}

void solve()
{
    int k, x, y;
    cin >> k >> x >> y;

    if (x == y)
    {
        cout << "0\n"
             << x << endl;
        return;
    }

    int _max = 1;
    for (int i = 0; i < k; i++)
        _max *= 10;
    queue<int> q;
    unordered_map<int, int> par;
    unordered_set<int> check;

    q.push(x);
    check.insert(x);
    par[x] = -1;

    bool flag = false;
    while (q.size())
    {
        int cur = q.front();
        q.pop();

        if (cur == y)
        {
            flag = true;
            break;
        }

        if (cur < _max)
        {
            int nxt = cur + 1;
            if (check.find(nxt) == check.end())
            {
                check.insert(nxt);
                par[nxt] = cur;
                q.push(nxt);
            }
        }

        int nxt = rotate_num(cur);
        if (nxt != 0 && check.find(nxt) == check.end())
        {
            check.insert(nxt);
            par[nxt] = cur;
            q.push(nxt);
        }
    }

    if (!flag)
    {
        cout << "-1\n";
        return;
    }

    vector<int> a;
    int cur = y;
    while (cur != -1)
    {
        a.pb(cur);
        cur = par[cur];
    }
    reverse(all(a));

    cout << a.size() - 1 << "\n";
    for (int i : a)
        cout << i << "\n";
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
