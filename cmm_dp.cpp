#include <iostream>
#include <climits>
#include <vector>
using namespace std;

vector<vector<int>> memo;

int cmm(int arr[], int i, int j, vector<vector<int>>& v) {
    if (i == j) {
        v[i][j] = i;
        return 0;
    } else if (memo[i][j] != -1) {
        return memo[i][j];
    } else {
        int minval = INT_MAX;
        for (int k = i; k < j; k++) {
            int val = cmm(arr, i, k, v) + cmm(arr, k + 1, j, v) + arr[i - 1] * arr[k] * arr[j];
            if (val < minval) {
                minval = val;
                v[i][j] = k;
            }
        }
        memo[i][j] = minval;
        return minval;
    }
}

string constructExpression(int i, int j, vector<vector<int>>& v) {
    if (i == j) {
        return "M" + to_string(i);
    } else {
        return "(" + constructExpression(i, v[i][j], v) +
               constructExpression(v[i][j] + 1, j, v) + ")";
    }
}

int main() {
    int k, n;
    cin >> k;
    while (k--) {
        cin >> n;
        int arr[n+1];
        memo.clear();
        memo.resize(n+1, vector<int>(n+1, -1));
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for (int i = 0; i <= n; i++) {
            cin >> arr[i];
        }
        int minMultiplications = cmm(arr, 1, n, v);
        cout << constructExpression(1, n, v) << '\n';
        cout << minMultiplications << '\n';
    }
    return 0;
}
