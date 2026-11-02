#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

long long comp = 0;
mt19937 rng(random_device{}());

int partition(vector<int>& a, int l, int h) {
    int p = a[h], i = l - 1;
    for (int j = l; j < h; j++) {
        comp++;
        if (a[j] <= p)
            swap(a[++i], a[j]);
    }
    swap(a[i + 1], a[h]);
    return i + 1;
}

void quickSort(vector<int>& a, int l, int h, bool randomPivot) {
    if (l >= h) return;

    if (randomPivot)
        swap(a[uniform_int_distribution<int>(l, h)(rng)], a[h]);

    int p = partition(a, l, h);
    quickSort(a, l, p - 1, randomPivot);
    quickSort(a, p + 1, h, randomPivot);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b;

    for (int& x : a) cin >> x;
    b = a;

    quickSort(a, 0, n - 1, false);
    cout << "Deterministic comparisons: " << comp << "\n";

    comp = 0;
    quickSort(b, 0, n - 1, true);
    cout << "Randomized comparisons: " << comp << "\n";

    cout << "Sorted array: ";
    for (int x : b) cout << x << " ";
    cout << '\n';
}
