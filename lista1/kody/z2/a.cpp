#include <iostream>
using namespace std;


int k = 7;
int p = 0;
int A[7] = {1,7,6,2,6,35,52};
int por;
int przyp;

void merge(int A[], int p, int s, int k){
    int n1 = s - p + 1;
    int n2 = k - s;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) {
                    przyp = przyp + 1;
        L[i] = A[i + p];
    }
    for (int i = 0; i < n2; i++) {
                    przyp = przyp + 1;
        R[i] = A[s + i + 1];
    }
    int il = 0;
    int ir = 0;
    int i = p;

    while (il < n1 && ir < n2) {
        por = por + 1;
        if (L[il] <= R[ir]) {
            przyp = przyp + 1;
            A[i] = L[il];
            i = i + 1;
            il = il + 1;
        } else {
            przyp = przyp + 1;
            A[i] = R[ir];
            i = i + 1;
            ir = ir + 1;
        }
    }

    while (il < n1) {
        przyp = przyp + 1;
        A[i] = L[il];
        i = i + 1;
        il = il + 1;
    }
}

void output(int A[], int n){
            for (int i = 0; i < n;i++)
    {
        cout << A[i] << " ";
    }
}

void merge_sort(int A[], int p, int k){
    if (p < k){
        int s = (p+k)/2;
        merge_sort(A,p,s);
        merge_sort(A,s+1,k);
        merge(A, p, s, k);
    }
}



int main() 
{
    merge_sort(A,p,k-1);
    output(A, k);
}