#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, string> lcs(string x, string y) {
    int m = x.length();
    int n = y.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int length = dp[m][n];
    string lcsString;

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            lcsString = x[i - 1] + lcsString;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return {length, lcsString};
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        string x, y;
        cin >> x >> y;
        if ((x.length() == 1) && (y.length() == 1) && (x[0] == y[0])) {
            cout << '1' << ' ' << x << '\n';
        } else {
            auto result = lcs(x, y);
            cout << result.first << ' ' << result.second << '\n';
        }
    }
    return 0;
}
