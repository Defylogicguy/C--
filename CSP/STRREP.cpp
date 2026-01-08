/*************************
  Author: Defy logic guy
  00:42:30 - 05/04/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "STRREP"

vector<int> f(const string &s)
{
    int n = s.size();
    vector<int> a(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = a[i - 1];
        while (j > 0 && s[i] != s[j])
            j = a[j - 1];
        if (s[i] == s[j])
            j++;
        a[i] = j;
    }
    return a;
}

bool check(const string &t, const string &s)
{
    int m = t.size(), n = s.size();
    int k = (n + m - 1) / m + 1;
    string idk;
    for (int i = 0; i < k; i++)
        idk += t;
    return idk.find(s) != string::npos;
}

int cmp(const string &s)
{
    int n = s.size();
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int j = 0; j < i; j++)
        {
            char c = s[j];
            for (int u = j; u < n; u += i)
            {
                if (s[u] != c)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
        if (flag)
            return i;
    }
    return n;
}

void solve()
{
    string t, s;
    cin >> t >> s;
    int m = t.size(), n = s.size();

    vector<int> a = f(t);
    int p = m - a[m - 1];
    if (m % p == 0 && p < m)
    {
        cout << "NO\n";
        return;
    }

    if (!check(t, s))
    {
        cout << "NO\n";
        return;
    }

    int tmp = cmp(s);
    cout << (m == tmp ? "YES\n" : "NO\n");
}

signed main()
{
    if (fopen(NAME ".INP", "j"))
    {
        freopen(NAME ".INP", "j", stdin);
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
