#include <iostream>
using namespace std;

int TinhTong(int n) {
    if (n == 1) {
        return 1; // Điều kiện dừng
    } else {
        return n + TinhTong(n - 1); // Gọi đệ quy
    }
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Tong S = " << TinhTong(n) << endl;
    return 0;
}
