/*************************
  Author: Defy logic guy
  13:40:17 - 18/02/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "DIFSTRING"

int maxn = 6e5 + 7;

int keygen(int a, int b) { return (a << 32) | b; }

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> power(maxn, 1);
    for (int i = 1; i < maxn; i++)
        power[i] = (power[i - 1] * 31) % MOD;

    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int h = 0;
        for (char c : s)
            h = (h * 31 + (c - 'a')) % MOD;
        st.insert(keygen(s.size(), h));
    }

    while (m--)
    {
        string s;
        cin >> s;
        int h = 0;
        for (char c : s)
            h = (h * 31 + (c - 'a')) % MOD;

        bool flag = false;
        for (int i = 0; i < s.size() && !flag; i++)
        {
            for (char c : {'a', 'b', 'c'})
            {
                if (c == s[i])
                    continue;
                int idk = h;
                idk = (idk + MOD - ((s[i] - 'a') * power[s.size() - i - 1]) % MOD) % MOD;
                idk = (idk + ((c - 'a') * power[s.size() - i - 1]) % MOD) % MOD;
                if (st.find(keygen(s.size(), idk)) != st.end())
                {
                    flag = true;
                    break;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
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
