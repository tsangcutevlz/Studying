#include<iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	// Khai báo con trỏ cấp 2 arr
	int** arr;

	// Cấp phát vùng nhớ động cho mảng 1 chiều các con trỏ kiểu int*
	// Có thể hiểu arr là mảng n phần tử, mỗi phần tử là 1 con trỏ kiểu int*
	arr = new int* [n];
	for (int i = 0; i < n; i++) {
		// Cấp phát động cho các n mảng 1 chiều
		arr[i] = new int[m];
	}

	// Nhập dữ liệu cho các phần tử trong mảng
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	// Tính tổng từng hàng và hiển thị ra màn hình
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += arr[i][j];
		}
		cout << sum << endl;
	}

	// Giải phóng bộ nhớ
	for (int i = 0; i < n; i++) {
		// Giải phóng bộ nhớ con các mảng một chiều
		delete[] arr[i];
	}
	// Giải phóng bộ nhớ cho mảng các con trỏ
	delete[]arr;
	return 0;
}