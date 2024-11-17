#include <iostream>
#include <vector>

using namespace std;

// Định nghĩa lớp cho đồ thị
class Graph {
private:
    int V; // Số lượng đỉnh
    vector<vector<int>> adj; // Danh sách kề để lưu trữ các cạnh

public:
    // Hàm khởi tạo đồ thị với số lượng đỉnh
    Graph(int vertices) {
        V = vertices; // Gán số lượng đỉnh
        adj.resize(V); // Kích thước của danh sách kề tương ứng với số đỉnh
    }

    // Thêm cạnh vào đồ thị
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Thêm đỉnh w vào danh sách kề của v
        adj[w].push_back(v); // Thêm đỉnh v vào danh sách kề của w (đồ thị vô hướng)
    }

    // Duyệt theo chiều sâu (DFS)
    void DFS(int v, vector<bool>& visited) {
        visited[v] = true; // Đánh dấu đỉnh v là đã thăm
        cout << v + 1 << " "; // In ra đỉnh v, cộng thêm 1 vì đỉnh đầu là 1

        // Duyệt tất cả các đỉnh kề chưa được thăm
        for (int i : adj[v]) {
            if (!visited[i]) {
                DFS(i, visited); // Gọi đệ quy cho đỉnh kề
            }
        }
    }

    // Hiển thị đồ thị
    void displayGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Dinh " << i + 1 << ": "; // In ra số đỉnh, cộng thêm 1 vì đỉnh bắt đầu từ 1
            for (int j : adj[i]) {
                cout << j + 1 << " "; // In ra các đỉnh kề, cộng thêm 1 vì đỉnh bắt đầu từ 1
            }
            cout << endl; // Xuống dòng
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Nhap so luong dinh: "; // Nhập số lượng đỉnh
    cin >> vertices; // Đọc số lượng đỉnh
    Graph g(vertices); // Tạo đồ thị với số lượng đỉnh đã nhập

    cout << "Nhap so luong canh: "; // Nhập số lượng cạnh
    cin >> edges; // Đọc số lượng cạnh

    cout << "Nhap cac canh (dinh(x) dinh(y)): \n"; // Hướng dẫn nhập các cạnh
    for (int i = 0; i < edges; i++) {
        cout << "Canh thu " << i + 1 << ":\n";
        int v, w;
        cout << "Nhap dinh x: ";
        cin >> v;
        cout << "Nhap dinh y: ";
        cin >> w; // Nhập hai đỉnh cho cạnh
        g.addEdge(v - 1, w - 1); // Chuyển sang chỉ số bắt đầu từ 0
    }

    cout << "Nhap dinh bat dau cho DFS: ";
    int startDFS;
    cin >> startDFS; // Nhập đỉnh bắt đầu
    vector<bool> visitedDFS(vertices, false); // Mảng đánh dấu cho DFS
    cout << "Ket qua DFS: ";
    g.DFS(startDFS - 1, visitedDFS); // Thực hiện DFS, chuyển chỉ số về 0
    cout << endl;

    return 0; // Kết thúc chương trình
}
