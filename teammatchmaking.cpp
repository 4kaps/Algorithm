#include <iostream>
using namespace std;

int visited[101] = {0,};

void dfs(int a[], int num) {
    visited[num] = 1;
    int next = a[num];
    if (!visited[next]) {
        dfs(a, next);
    }
}

int main() {
    int k, n;
    cin >> k;

    while (k--) {
        for (int i = 0; i < 101; i++) {
            visited[i] = 0;
        }

        cin >> n;
        int arr[n];
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                result++;
                dfs(arr, i);
            }
        }

        cout << result << '\n';
    }
}
