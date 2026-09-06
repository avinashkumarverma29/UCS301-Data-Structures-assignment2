#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> transposeSparse(const vector<vector<int>>& sparse) {
    if (sparse.empty()) return {};

    vector<vector<int>> result = sparse;
    int nonZero = sparse[0][2];

    result[0][0] = sparse[0][1];
    result[0][1] = sparse[0][0];

    for (int i = 1; i <= nonZero; i++) {
        result[i][0] = sparse[i][1];
        result[i][1] = sparse[i][0];
    }

    sort(result.begin() + 1, result.end(),
         [](const vector<int>& x, const vector<int>& y) {
             if (x[0] != y[0]) return x[0] < y[0];
             return x[1] < y[1];
         });

    return result;
}