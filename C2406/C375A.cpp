/*************************
  Author: Defy logic guy
  20:40:37 - 07/01/2025
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
#define NAME "C375A"

void solve()
{
    string s;
    cin >> s;
    vector<int> a = {1, 6, 8, 9};
    map<int, int> mp;
    do
    {
        int idk = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
        mp[idk % 7] = idk;
    } while (next_permutation(all(a)));

    vector<int> freq(10, 0);
    for (char c : s)
        freq[c - '0']++;
    for (int i : a)
        freq[i]--;
    int idk = 0;
    for (int i = 1; i <= 9; i++)
        for (int j = 0; j < freq[i]; j++)
        {
            cout << i;
            idk = (idk * 10 + i) % 7;
        }
    int need = idk * 10000 % 7;
    cout << mp[(7 - need) % 7];
    for (int i = 0; i < freq[0]; i++)
        cout << 0;
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
