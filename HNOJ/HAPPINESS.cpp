#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "Skibidi"

int n, h;
vector<int> a, b;
vector<pair<int, int>> one;
vector<pair<int, int>> two; 

void do1(int idx, int sA, int sB)
{
    if (idx == n / 2)
    {
        one.pb({sA, sB});
        return;
    }
    do1(idx + 1, sA + a[idx], sB);          
    do1(idx + 1, sA, sB + b[idx]);          
    do1(idx + 1, sA + a[idx], sB + b[idx]); 
}

void do2(int idx, int sA, int sB)
{
    if (idx == n)
    {
        two.pb({sA, sB}); 
        return;
    }
    do2(idx + 1, sA + a[idx], sB);         
    do2(idx + 1, sA, sB + b[idx]);         
    do2(idx + 1, sA + a[idx], sB + b[idx]);
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}

void solve()
{
    cin >> n >> h;
    a.resize(n);
    b.resize(n);
    one.clear();
    two.clear();

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    do1(0, 0, 0);
    do2(n / 2, 0, 0);
    sort(all(two));

    int ans = 0;
    for (auto [sA, sB] : one)
    {
        int rA = h - sA;
        int rB = h - sB;

        auto lo = lower_bound(all(two), make_pair(rA, rB), cmp);
        auto up = upper_bound(all(two), make_pair(rA, LONG_LONG_MAX), cmp);
        ans += (up - lo);
    }

    cout << ans << endl;
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
