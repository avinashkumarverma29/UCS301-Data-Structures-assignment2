#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> zigzagDiagonal(const vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) return {};

    int n = mat.size();
    int m = mat[0].size();
    vector<int> ans;

    for (int d = 0; d <= n + m - 2; d++) {
        vector<int> diagonal;

        int rStart = max(0, d - (m - 1));
        int rEnd = min(n - 1, d);

        for (int r = rStart; r <= rEnd; r++) {
            int c = d - r;
            diagonal.push_back(mat[r][c]);
        }

        if (d % 2 == 0)
            reverse(diagonal.begin(), diagonal.end());

        for (int x : diagonal)
            ans.push_back(x);
    }

    return ans;
}

void printArray(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << '\n';
}

void printMatrix(const vector<vector<int>>& a) {
    for (const auto& row : a) {
        for (int x : row) cout << x << " ";
        cout << '\n';
    }
}