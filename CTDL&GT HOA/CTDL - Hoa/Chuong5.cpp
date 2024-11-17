#include <iostream>
using namespace std;

// Dinh nghia cau truc cua mot Node
struct Node {
    int data;
    Node* next;
};

// Ham them phan tu moi vao sau nut M
void insertAfter(Node* M, int value) {
    if (M == NULL) {
        cout << "Node M la NULL, khong the chen sau nut NULL." << endl;
        return;
    }
    
    // Tao nut moi
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = M->next; // Gan con tro cua nut moi tro den nut tiep theo cua M
    M->next = newNode; // Gan con tro next cua M tro den nut moi
}

// Ham in danh sach
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Ham khoi tao danh sach tu ban phim
Node* createList() {
    int n, value;
    cout << "Nhap so luong phan tu trong danh sach: ";
    cin >> n;
    
    Node* head = nullptr; // Khoi tao danh sach rong
    Node* temp = nullptr;
    
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri phan tu " << i+1 << ": ";
        cin >> value;
        
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        
        if (head == nullptr) {
            head = newNode; // Neu danh sach rong, nut moi la dau danh sach
        } else {
            temp->next = newNode; // Gắn nut moi vào cuoi danh sach
        }
        
        temp = newNode; // Cập nhật temp để nó luôn trỏ đến phần tử cuối cùng
    }
    
    return head;
}

int main() {
    // Khoi tao danh sach tu ban phim
    Node* Q = createList();
    
    cout << "Danh sach ban dau: ";
    printList(Q);
    
    // Nhap gia tri muon chen va nut M
    int valueToInsert;
    cout << "Nhap gia tri muon chen: ";
    cin >> valueToInsert;
    
    // Chon nut M, o day gia su chung ta chen sau nut co gia tri 20
    Node* M = Q->next; // M tro den nut co gia tri 20
    
    insertAfter(M, valueToInsert);
    
    cout << "Danh sach sau khi chen: ";
    printList(Q);
    
    return 0;
}
