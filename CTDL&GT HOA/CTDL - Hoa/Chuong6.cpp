#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Hàm duyệt theo thứ tự trước (Pre-order)
void preOrder(Node* root) {
    if (root == nullptr) return; // Nếu cây rỗng, không làm gì
    cout << root->data << " ";   // Thăm nút gốc
    preOrder(root->left);        // Duyệt cây con trái
    preOrder(root->right);       // Duyệt cây con phải
}

// Hàm duyệt theo thứ tự giữa (In-order)
void inOrder(Node* root) {
    if (root == nullptr) return; // Nếu cây rỗng, không làm gì
    inOrder(root->left);         // Duyệt cây con trái
    cout << root->data << " ";   // Thăm nút gốc
    inOrder(root->right);        // Duyệt cây con phải
}

// Hàm duyệt theo thứ tự sau (Post-order)
void postOrder(Node* root) {
    if (root == nullptr) return; // Nếu cây rỗng, không làm gì
    postOrder(root->left);       // Duyệt cây con trái
    postOrder(root->right);      // Duyệt cây con phải
    cout << root->data << " ";   // Thăm nút gốc
}

// Hàm thêm một nút mới vào cây nhị phân (Thêm theo cách đơn giản)
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value); // Nếu cây rỗng, tạo nút mới
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);  // Thêm vào cây con trái
    } else {
        root->right = insert(root->right, value); // Thêm vào cây con phải
    }
    
    return root; // Trả về cây đã thêm phần tử
}

// Hàm in ra thứ tự các phần tử đã thêm vào cây (in theo cách đơn giản)
void printInitialOrder(int values[], int size) {
    cout << "Thu tu ban dau (Tham gia theo order): ";
    for (int i = 0; i < size; i++) {
        cout << values[i] << " "; // In phần tử theo thứ tự nhập ban đầu
    }
    cout << endl;
}

int main() {
    Node* root = nullptr; // Cây nhị phân bắt đầu rỗng
    
    // Danh sách các giá trị sẽ được thêm vào cây
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    int size = sizeof(values) / sizeof(values[0]);
    
    // In thứ tự ban đầu các giá trị
    printInitialOrder(values, size);

    // Thêm các phần tử vào cây
    for (int i = 0; i < size; i++) {
        root = insert(root, values[i]);
    }
    
    // Duyệt cây theo các thứ tự
    cout << "Duyet theo truoc (Pre-order): ";
    preOrder(root);
    cout << endl;
    
    cout << "Duyet theo giua (In-order): ";
    inOrder(root);
    cout << endl;
    
    cout << "Duyet theo sau (Post-order): ";
    postOrder(root);
    cout << endl;
    
    return 0;
}
