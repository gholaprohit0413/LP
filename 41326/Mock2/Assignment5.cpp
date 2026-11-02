
#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

int partition(int a[], int l, int h) {
    int p = a[h], i = l - 1;
    for (int j = l; j < h; j++) {
        cnt++;
        if (a[j] <= p) {
            swap(a[++i], a[j]);
        }
    }
    swap(a[i + 1], a[h]);
    return i + 1;
}

void quickSort(int a[], int l, int h, bool random) {
    if (l < h) {
        if (random) swap(a[l + rand() % (h - l + 1)], a[h]);
        int p = partition(a, l, h);
        quickSort(a, l, p - 1, random);
        quickSort(a, p + 1, h, random);
    }
}

int main() {
    srand(time(0));
    int a[] = {8, 3, 1, 7, 0, 10, 2}, n = 7;
    int b[7];
    copy(a, a + n, b);

    quickSort(a, 0, n - 1, false);
    cout << "Deterministic comparisons: " << cnt << endl;

    cnt = 0;
    quickSort(b, 0, n - 1, true);
    cout << "Randomized comparisons: " << cnt << endl;

    return 0;
}
