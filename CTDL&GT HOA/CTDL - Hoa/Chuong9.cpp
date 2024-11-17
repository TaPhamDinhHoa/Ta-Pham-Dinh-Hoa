#include <iostream>
#include <vector>
#include <algorithm> // De su dung ham sort
using namespace std;

// Tim kiem tuan tu
int sequentialSearch(const vector<int>& arr, int key) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == key) {
            return i; // Tra ve chi so cua phan tu
        }
    }
    return -1; // Neu khong tim thay
}

// Tim kiem nhi phan
int binarySearch(const vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid; // Tra ve chi so cua phan tu
        } else if (arr[mid] < key) {
            left = mid + 1; // Tim trong nua ben phai
        } else {
            right = mid - 1; // Tim trong nua ben trai
        }
    }
    return -1; // Neu khong tim thay
}

// Cau truc cay nhi phan
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Ham tao nut moi
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Ham chen nut vao cay
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Tim kiem trong cay nhi phan
bool search(Node* root, int key) {
    if (root == nullptr) {
        return false; // Khong tim thay
    }
    if (root->data == key) {
        return true; // Tim thay
    }
    return (key < root->data) ? search(root->left, key) : search(root->right, key);
}

// Ham main
int main() {
    int choice;
    cout << "Chon thuat toan tim kiem: \n";
    cout << "1. Tim kiem tuan tu\n";
    cout << "2. Tim kiem nhi phan\n";
    cout << "3. Tim kiem trong cay nhi phan\n";
    cout << "Nhap lua chon cua ban (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            // Tim kiem tuan tu
            int n;
            cout << "Nhap so luong phan tu trong mang: ";
            cin >> n;

            vector<int> arr(n);
            cout << "Nhap cac phan tu cua mang: ";
            for (int i = 0; i < n; ++i) {
            	cout<<"\nNhap phan tu thu "<<i+1<<":";
                cin >> arr[i];
            }

            int key;
            cout << "Nhap gia tri can tim: ";
            cin >> key;

            int result = sequentialSearch(arr, key);
            cout << "Tim kiem tuan tu: Phan tu " << key << " nam o chi so " << result << endl;
            break;
        }
        case 2: {
            // Tim kiem nhi phan
            int n;
            cout << "Nhap so luong phan tu trong mang: ";
            cin >> n;

            vector<int> arr(n);
            cout << "Nhap cac phan tu cua mang: ";
            for (int i = 0; i < n; ++i) {
            	cout<<"\nNhap phan tu thu "<<i+1<<":";
                cin >> arr[i];
            }

            int key;
            cout << "Nhap gia tri can tim: ";
            cin >> key;

            // Sap xep mang truoc khi tim kiem nhi phan
            sort(arr.begin(), arr.end());
            cout << "Mang da duoc sap xep: ";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << endl;

            int result = binarySearch(arr, key);
            cout << "Tim kiem nhi phan: Phan tu " << key << " nam o chi so " << result << endl;
            break;
        }
        case 3: {
            // Tim kiem trong cay nhi phan
            Node* root = nullptr;
            int m;
            cout << "Nhap so luong phan tu trong cay: ";
            cin >> m;

            cout << "Nhap cac phan tu cua cay: ";
            for (int i = 0; i < m; ++i) {
                int num;
                cout<<"\nNhap phan tu thu "<<i+1<<" cua cay: ";
                cin >> num;
                root = insert(root, num);
            }

            int key;
            cout << "Nhap gia tri can tim: ";
            cin >> key;

            bool found = search(root, key);
            cout << "Tim kiem trong cay: Phan tu " << key << (found ? " ton tai." : " khong ton tai.") << endl;
            break;
        }
        default:
            cout << "Lua chon khong hop le." << endl;
    }

    return 0;
}
