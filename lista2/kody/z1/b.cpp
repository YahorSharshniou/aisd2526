#include <iostream>
using namespace std;

int A[] = {3, 7, 6, 4, 2, 1, 5};
int n = 7;

void output(int A[], int n){
    for (int i = 0; i < n;i++)
    {
        cout << A[i] << " ";
    }
}

void quick_sort_mod(int A[], int p, int k) {
    if (p >= k) return;

    int p1 = A[p];
    int p2 = A[k];

    if (p1 > p2){
        swap(A[p], A[k]);
        p1 = A[p];
        p2 = A[k];
    }


    int i = p + 1;
    int lt = p + 1;
    int gt = k - 1;

    while (i <= gt) {
        if (A[i] < p1) {
            swap(A[i], A[lt]);
            lt = lt + 1;
            i = i + 1;
        }
        else if (A[i] > p2) {
            swap(A[i], A[gt]);
            gt = gt - 1;
        }
        else {
            i = i + 1;
        }
    }

    swap(A[p], A[lt - 1]);
    swap(A[k], A[gt + 1]);

    quick_sort_mod(A, p, lt - 2);
    quick_sort_mod(A, lt, gt);
    quick_sort_mod(A, gt + 2, k);
}


int main() {
    quick_sort_mod(A, 0, n - 1);
    output(A, n);
}
