#include <iostream>
#include <vector>
using namespace std;

float A[] = {72, 24, 32, 66, 67, 99, 77, 12, 38, 87};
int n = 10;




void output(float A[], int n){
    for (int i = 0; i < n;i++)
    {
        cout << A[i] << " ";
    }
}

void insertion_sort(vector<float>& bucket) {
    for (int i = 1; i < bucket.size(); ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j = j - 1;
        }
        bucket[j + 1] = key;
    }
}

void bucket_sort(float A[], int n) {
    vector<float> B[n];

    for (int i = 0; i < n; i++) {
        int bi = (n-1) * A[i];
        B[bi].push_back(A[i]);
    }

    for (int i = 0; i < n; i++) {
        insertion_sort(B[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < B[i].size(); j++) {
            A[index] = B[i][j];
            index = index + 1;
        }
    }
}

int main() {
    bucket_sort(A, n);
    output(A,n);
}