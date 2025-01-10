/*
 Author: Defy logic guy
 23:24:36 - 29/12/2024
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "Skibidi"

char turnLeft(char c)
{
    if (c == 'N')
        return 'W';
    if (c == 'W')
        return 'S';
    if (c == 'S')
        return 'E';
    return 'N';
}

char turnRight(char c)
{
    if (c == 'N')
        return 'E';
    if (c == 'E')
        return 'S';
    if (c == 'S')
        return 'W';
    return 'N';
}

pair<int, int> move(int x, int y, char face)
{
    if (face == 'N')
        return {x, y + 1};
    if (face == 'S')
        return {x, y - 1};
    if (face == 'W')
        return {x - 1, y};
    return {x + 1, y};
}

void solve()
{
    int n1, n2;
    cin >> n1 >> n2;
    map<pair<int, int>, bool> mp;
    cin.ignore();

    vector<string> ans;
    string inp;
    while (getline(cin, inp))
    {
        istringstream iss(inp);
        int x, y;
        char face;
        iss >> x >> y >> face;
        string s;
        getline(cin, s);
        bool flag = false;
        for (char c : s)
        {
            if (c == 'L')
                face = turnLeft(face);
            else if (c == 'R')
                face = turnRight(face);
            else if (c == 'F')
            {
                pair<int, int> next = move(x, y, face);
                int cx = next.first, cy = next.second;
                if (cx == -1 or cy == -1 or cx == n1 + 1 or cy == n2 + 1)
                {
                    if (!mp[{x, y}])
                    {
                        mp[{x, y}] = flag = true;
                        break;
                    }
                }
                else
                    x = cx, y = cy;
            }
        }
        if (!flag)
            ans.pb(to_string(x) + " " + to_string(y) + " " + string(1, face));
        else
            ans.pb(to_string(x) + " " + to_string(y) + " " + string(1, face) + " LOST");
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
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
