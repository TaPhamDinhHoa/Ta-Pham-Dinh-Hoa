#include <iostream>
#include <vector>

using namespace std;

// Hàm sắp xếp nổi bọt
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Hàm sắp xếp chọn
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

// Hàm sắp xếp chèn
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Hàm sắp xếp nhanh
vector<int> quickSort(vector<int> arr) {
    if (arr.size() <= 1) return arr;

    int pivot = arr[arr.size() / 2];
    vector<int> left, middle, right;

    for (int x : arr) {
        if (x < pivot) left.push_back(x);
        else if (x == pivot) middle.push_back(x);
        else right.push_back(x);
    }

    vector<int> result = quickSort(left);
    result.insert(result.end(), middle.begin(), middle.end());
    vector<int> rightSorted = quickSort(right);
    result.insert(result.end(), rightSorted.begin(), rightSorted.end());
    return result;
}

// Hàm hợp nhất (merge) cho sắp xếp hợp nhất
vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    // Thêm phần tử còn lại
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

// Hàm sắp xếp hợp nhất
vector<int> mergeSort(const vector<int>& arr) {
    if (arr.size() <= 1) return arr;

    int mid = arr.size() / 2;
    vector<int> left = mergeSort(vector<int>(arr.begin(), arr.begin() + mid));
    vector<int> right = mergeSort(vector<int>(arr.begin() + mid, arr.end()));

    return merge(left, right);
}

// Chương trình chính
int main() {
    int n, choice;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Nhap " << n << " phan tu cua mang : ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
	do{
		system("cls");
    cout << "\nChon thuat toan sap xep:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Quick Sort\n";
    cout << "5. Merge Sort\n";
    cout << "Nhap lua chon cua ban (1-5): ";
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr);
            cout << "Mang sau khi sap xep bang Bubble Sort: ";
            break;
        case 2:
            selectionSort(arr);
            cout << "Mang sau khi sap xep bang Selection Sort: ";
            break;
        case 3:
            insertionSort(arr);
            cout << "Mang sau khi sap xep bang Insertion Sort: ";
            break;
        case 4:
            arr = quickSort(arr);
            cout << "Mang sau khi sap xep bang Quick Sort: ";
            break;
        case 5:
            arr = mergeSort(arr);
            cout << "Mang sau khi sap xep bang Merge Sort: ";
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            return 0;
    }

    // In ra mảng đã sắp xếp
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
 	system("pause");
}while(choice!=0);
    return 0;
}
