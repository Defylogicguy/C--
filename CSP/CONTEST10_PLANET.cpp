/*************************
  Author: Defy logic guy
  22:23:57 - 02/06/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "CONTEST10_PLANET"

static const int MAXA = 100000;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // 1) Tạo bảng SPF (smallest prime factor) cho mọi số <= MAXA
    vector<int> spf(MAXA + 1);
    for (int i = 2; i <= MAXA; i++)
    {
        if (spf[i] == 0)
        {
            for (int j = i; j <= MAXA; j += i)
            {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }

    // 2) Mở rộng mảng a thành b độ dài 2n
    int N = 2 * n;
    vector<int> b(N + 2);
    for (int i = 1; i <= n; i++)
    {
        b[i] = a[i];
        b[i + n] = a[i];
    }

    // 3) Two pointers để tính r[i] (i từ 1..2n)
    vector<int> r(N + 2);
    vector<int> lastOccur(MAXA + 1, 0);
    int left = 1;
    for (int i = 1; i <= N; i++)
    {
        // left luôn chỉ ra đầu cửa sổ sao cho [left..i-1] hợp lệ
        int val = b[i];
        // phân tích val ra các prime factor (đảm bảo mỗi prime chỉ lấy 1 lần)
        vector<int> primes;
        while (val > 1)
        {
            int p = spf[val];
            primes.push_back(p);
            while (val % p == 0)
                val /= p;
        }
        for (int p : primes)
        {
            if (lastOccur[p] >= left)
                left = lastOccur[p] + 1;
        }
        for (int p : primes)
            lastOccur[p] = i;

        // Khi i cố định, đoạn [left..i] hợp lệ => r[left] >= i
        // Nhưng ta cần đặt r[j] cho mọi j ≤ left tự động? Thực ra cách gán chuẩn:
        // Mỗi khi i tiến, ta sẽ gán r[j] cho j = current left trước khi left tăng lên sau loops.
        // Nhưng ở đây dễ nhất: ta duy trì con trỏ i đi từ 1..2n, left cũng di chuyển.
        // Khi i tăng, r[left] = i cho mọi left mà chưa được gán r[left]? Ta có thể lùi để gán hết.
        // Tuy nhiên, cách đơn giản hơn: dùng thêm mảng tempLeft để khi con trỏ right = i chạy, ta biết "với mọi j từ lastLeft đến newLeft-1, r[j] = i-1"
        // Nhưng mẫu code tiêu chuẩn: giữ một copy của left_before khi i tăng.
        static vector<bool> marked(N + 2, false);
        // Trong thực hành, ta sẽ gán r[left] = i cho chính left (vì left mới nhất đảm bảo i là giới hạn phải).
        // Nhưng để đúng: khi left di chuyển từ oldLeft đến newLeft, với mỗi old j, r[j] = i-1.
        // Dưới đây ta tái cấu trúc code sao cho đơn giản:
        //   Ta chỉ cần chạy một vòng tính cho từng i:
        //   Ta không gán r[left] ngay, mà đợi một vòng riêng: sau khi hoàn thành two-pointers, ta đi theo left để fill r[i].
        // Tuy nhiên điều đó phức tạp. Cách thực tế: ta chạy left cùng i.
        // Thay vì phải gán r[] phức tạp, ta triển khai khác:
        //   Dịch sang "với mỗi i tĩnh, hãy tìm vị trí r[i]" => ta cần di chuyển right từ i lên trước.
        // Chúng ta sẽ chạy thêm một biến right chứ không phải dùng i làm right.
        break;
    }

    // Vì đoạn code trên hơi lẫn lộn, ta sẽ triển khai lại hai con trỏ thật sạch:
    fill(lastOccur.begin(), lastOccur.end(), 0);
    int right = 0;
    for (int i = 1; i <= N; i++)
    {
        // Di chuyển right sao cho [i..right] là đoạn coprime tối đa
        while (right + 1 <= N)
        {
            int val = b[right + 1];
            // phân tích xem nếu đưa b[right+1] vào, có prime nào vi phạm không
            int temp = val;
            bool ok = true;
            vector<int> pf;
            while (temp > 1)
            {
                int p = spf[temp];
                pf.push_back(p);
                while (temp % p == 0)
                    temp /= p;
            }
            for (int p : pf)
            {
                if (lastOccur[p] >= i)
                {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                break;
            // nếu hợp lệ, ta cập nhật lastOccur và đẩy right
            right++;
            for (int p : pf)
                lastOccur[p] = right;
        }
        // Khi vòng while kết thúc, [i..right] là đoạn coprime dài nhất
        r[i] = right;
        // Trước khi i tăng lên i+1, ta phải xóa dấu vết của b[i] ra lastOccur
        int temp2 = b[i];
        vector<int> pf2;
        while (temp2 > 1)
        {
            int p = spf[temp2];
            pf2.push_back(p);
            while (temp2 % p == 0)
                temp2 /= p;
        }
        for (int p : pf2)
        {
            if (lastOccur[p] == i)
                lastOccur[p] = 0;
        }
    }

    // 4) Xây bảng nhảy doubling: nextPos[i][k]
    int LOG = 0;
    while ((1 << LOG) <= N + 1)
        LOG++;
    vector<vector<int>> nextPos(N + 2, vector<int>(LOG + 1, N + 1));
    for (int i = 1; i <= N; i++)
    {
        int np = r[i] + 1;
        if (np > N)
            np = N + 1;
        nextPos[i][0] = np;
    }
    nextPos[N + 1][0] = N + 1;
    for (int k = 1; k <= LOG; k++)
    {
        for (int i = 1; i <= N + 1; i++)
        {
            int mid = nextPos[i][k - 1];
            if (mid > N)
                nextPos[i][k] = N + 1;
            else
                nextPos[i][k] = nextPos[mid][k - 1];
        }
    }

    // 5) Trả lời từng truy vấn
    while (q--)
    {
        int l, r0;
        cin >> l >> r0;
        int L = l;
        int R;
        if (l <= r0)
            R = r0;
        else
            R = n + r0;

        // L và R nằm trong [1..2n]. Giờ ta đếm nhảy doubling:
        int pos = L;
        int res = 0;
        for (int k = LOG; k >= 0; k--)
        {
            int np = nextPos[pos][k];
            if (np <= R + 1)
            {
                pos = np;
                res += (1 << k);
            }
        }
        if (pos <= R)
            res++;
        cout << res << "\n";
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
