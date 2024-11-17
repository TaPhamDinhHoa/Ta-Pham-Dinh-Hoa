#include <iostream>
#define MAX 100 // Giới hạn kích thước queue

using namespace std;

class Queue {
    int front, rear;
    int queue[MAX]; // Khởi tạo mảng cho queue

public:
    Queue() {
        front = 0;  // Điểm đầu của queue
        rear = -1;  // Điểm cuối của queue
    }

    // Hàm thêm phần tử vào cuối queue
    void enqueue(int phanTu) {
        if (rear >= (MAX - 1)) {
            cout << "Queue Overflow" << endl;
        } else {
            queue[++rear] = phanTu;
            cout << "Enqueued phan tu: " << phanTu << endl;
        }
    }

    // Hàm lấy phần tử ra khỏi đầu queue
    int dequeue() {
        if (front > rear) {
            cout << "Queue Underflow" << endl;
            return -1;
        } else {
            int phanTu = queue[front++];
            cout << "Dequeued phan tu: " << phanTu << endl;
            return phanTu;
        }
    }

    // Hàm hiển thị trạng thái của queue
    void hienThi() {
        if (front > rear) {
            cout << "Queue rong!" << endl;
        } else {
            cout << "Queue hien tai: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue queue;
    int luaChon, phanTu;

    do {
        cout << "\nChon thao tac: " << endl;
        cout << "1. Enqueue (Them phan tu)" << endl;
        cout << "2. Dequeue (Lay phan tu)" << endl;
        cout << "3. Hien thi queue" << endl;
        cout << "4. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                cout << "Nhap phan tu can enqueue: ";
                cin >> phanTu;
                queue.enqueue(phanTu);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.hienThi();
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
