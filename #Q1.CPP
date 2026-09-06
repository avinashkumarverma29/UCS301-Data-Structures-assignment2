#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void reverseArray(vector<int>& a) {
    int i = 0, j = (int)a.size() - 1;
    while (i < j) {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}