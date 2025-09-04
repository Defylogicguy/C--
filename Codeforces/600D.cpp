/*************************
  Author: Defy logic guy
  11:20:19 - 04/09/2025
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
#define NAME "600D"

float subsector(float r, float theta)
{
    float sector = r * r * acosl(theta);
    float triangle = r * r * sinl(acosl(theta)) * theta;
    return sector - triangle;
}

float area(float ax, float ay, float r1, float bx, float by, float r2)
{
    float d2 = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
    float d = sqrtl(d2);
    if (r1 + r2 <= d)
        return 0;
    if (abs(r1 - r2) >= d)
        return min(r1, r2) * min(r1, r2) * 4 * atanl(1);
    float theta1 = (r1 * r1 + d * d - r2 * r2) / (2.0 * d * r1);
    float theta2 = (r2 * r2 + d * d - r1 * r1) / (2.0 * d * r2);
    if (d + min(r1, r2) < max(r1, r2))
        return abs(subsector(r1, theta1) - subsector(r2, theta2));
    return subsector(r1, theta1) + subsector(r2, theta2);
}

void solve()
{
    float ax, ay, r1, bx, by, r2;
    cin >> ax >> ay >> r1 >> bx >> by >> r2;
    cout << fixed << setprecision(20) << area(ax, ay, r1, bx, by, r2) << '\n';

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
