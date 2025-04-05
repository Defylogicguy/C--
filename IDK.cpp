/*************************
  Author: Defy logic guy
  09:24:47 - 05/04/2025
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
#define NAME "IDK"

const int maxn = 1e6 + 7;
vector<bool> prime(maxn, false);

void sieve()
{
    for (int i = 2; i < maxn; i++)
        if (!prime[i])
            for (int j = i * i; j < maxn; j += i)
                prime[j] = true;
}

vector<int> pf(maxn + 1, 0);
void pre()
{
    for (int i = 2; i <= maxn; i++)
        pf[i] = pf[i - 1] + prime[i];
}

void solve()
{
    // int k, p;
    // cin >> k >> p;
    // cout << (pf[min(maxn+ 1, k + p)] - pf[max(0ll, p - k - 1)]) << endl;
    int n, k;
    cin >> n >> k;
    #include <iostream>
#include <vector>
using namespace std;

long long diagonalSum(int N, int K) {
    // Calculate row and column for K (1-based index)
    int row = (K - 1) / N + 1;
    int col = (K - 1) % N + 1;

    // Determine diagonal type (left or right)
    long long sum = 0;
    if (row + col - 1 == N + 1) {
        // Anti-diagonal (bottom-left to top-right)
        int length = min(row, col);
        for (int i = 0; i < length; i++) {
            sum += (N * (row - i - 1) + (col - i));
        }
    } else if (row - col == 0) {
        // Main diagonal (top-left to bottom-right)
        int length = min(N - row + 1, N - col + 1);
        for (int i = 0; i < length; i++) {
            sum += (N * (row + i - 1) + (col + i));
        }
    }
    return sum;
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << diagonalSum(N, K) << endl;
    return 0;
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

    sieve();
    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();
    return 0;
}
