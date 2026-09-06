#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> multiplySparse(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B) {

    // A and B use triplet representation.
    int rowsA = A[0][0], colsA = A[0][1];
    int rowsB = B[0][0], colsB = B[0][1];

    if (colsA != rowsB) return {};

    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));

    for (int i = 1; i <= A[0][2]; i++) {
        int r = A[i][0], k = A[i][1], valA = A[i][2];

        for (int j = 1; j <= B[0][2]; j++) {
            int k2 = B[j][0], c = B[j][1], valB = B[j][2];

            if (k == k2)
                result[r][c] += valA * valB;
        }
    }

    return result;
}
