#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r)
{ // sinh ngẫu nhiên một số trong đoạn [L, R]
    return uniform_int_distribution<int>(l, r)(rng);
}

string NAME = ""; // điền tên bài ở đây

const int NUMTEST = 30; // số test bạn muốn sinh

int main()
{
    for (int iTest = 1; iTest <= NUMTEST; i++)
    {
        ofstream inp((NAME + ".inp").c_str());
        // Bắt đầu sinh test ở đây

        /* Ví dụ sinh một mảng n phần tử
         * int n = Rand(1, 1000);
         * inp << n << endl;
         * for (int i = 1; i <= n; i++){
         *     inp << Rand(1, 1000000000) << " ";
         * }
         * inp << endl;
         * */

        // Kết thúc sinh test
        inp.close();

        // Chạy hai chương trình code.
        // Lưu ý là bạn phải compile và run trước chúng để tạo ra file .exe
        system((NAME + ".exe").c_str());
        system((NAME + "_ans.exe").c_str());

        // So sánh hai file
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0) // Hai file không trùng
        {
            cout << "Test " << iTest << ": Wrong Answer" << endl;
            return 0;
        }
        cout << "Test " << iTest << ": Accepted" << endl;
    }
}
