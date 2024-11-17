#include <iostream>
#define MAX 100 // Giới hạn kích thước stack

using namespace std;

class Stack {
    int top;
    int stack[MAX]; // Khởi tạo mảng cho stack

public:
    Stack() { top = -1; } // Khởi tạo top = -1 để stack rỗng

    // Hàm thêm phần tử vào stack
    void push(int phanTu) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow" << endl;
        } else {
            stack[++top] = phanTu;
            cout << "Pushed phan tu: " << phanTu << endl;
        }
    }

    // Hàm lấy phần tử ra khỏi stack
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return -1;
        } else {
            int phanTu = stack[top--];
            cout << "Popped phan tu: " << phanTu << endl;
            return phanTu;
        }
    }

    // Hàm hiển thị trạng thái của stack
    void hienThi() {
        if (top < 0) {
            cout << "Stack rong!" << endl;
        } else {
            cout << "Stack hien tai: ";
            for (int i = 0; i <= top; i++) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;
    int luaChon, phanTu;

    do {
        cout << "\nChon thao tac: " << endl;
        cout << "1. Push (Them phan tu)" << endl;
        cout << "2. Pop (Lay phan tu)" << endl;
        cout << "3. Hien thi stack" << endl;
        cout << "4. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                cout << "Nhap phan tu can push: ";
                cin >> phanTu;
                stack.push(phanTu);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.hienThi();
                break;
            case 4:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
        }
    } while (luaChon != 4);

    return 0;
}
