/*
 Author: Defy logic guy
 21:50:45 - 29/12/2024
*/
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
#define NAME "Skibidi"

int overlap(pair<int, int> a, pair<int, int> b, vector<vector<int>> &pf, int n, int r) {
    pair<int, int> top = {max(a.first, b.first), max(a.second, b.second)};
    pair<int, int> bot = {min(a.first + r - 1, b.first + r - 1), min(a.second + r - 1, b.second + r - 1)};

    if (top.first >= bot.first || top.second >= bot.second) // No overlap
        return 0;

    // Calculate sum of overlapping region using prefix sums
    return pf[bot.first + 1][bot.second + 1] 
           - pf[top.first][bot.second + 1] 
           - pf[bot.first + 1][top.second] 
           + pf[top.first][top.second];
}

void solve() {
    int n, r, k;
    cin >> n >> r >> k;
    vector<vector<int>> a(n, vector<int>(n));

    // Input grid values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Build prefix sum array
    vector<vector<int>> pf(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pf[i][j] = pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1] + a[i - 1][j - 1];
        }
    }

    vector<pair<int, int>> v(k);
    int ans = 0;

    // Calculate initial sum for all k squares
    for (int i = 0; i < k; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].first--; v[i].second--; // Convert to 0-based indices

        int x1 = v[i].first, y1 = v[i].second;
        int x2 = min(n, x1 + r), y2 = min(n, y1 + r);

        ans += pf[x2][y2] - pf[x1][y2] - pf[x2][y1] + pf[x1][y1];
    }

    // Subtract overlapping areas
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            ans -= overlap(v[i], v[j], pf, n, r);
        }
    }

    cout << ans << endl;
}

signed main() {
    if (fopen(NAME ".INP", "r")) {
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