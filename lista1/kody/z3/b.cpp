#include <iostream>
using namespace std;

int n = 7;
int A[7] = {1,7,6,2,6,35,52};

int child1(int i) { 
    return 3*i + 1; 
}
int child2(int i) { 
    return 3*i + 2; 
}
int child3(int i) { 
    return 3*i + 3; 
}

void heapify(int A[], int i, int n){
    int c1 = child1(i);
    int c2 = child2(i);
    int c3 = child3(i);

    int largest = i;

    if (c1 < n && A[c1] > A[largest])
        largest = c1;

    if (c2 < n && A[c2] > A[largest])
        largest = c2;

    if (c3 < n && A[c3] > A[largest])
        largest = c3;

    if (largest != i){
        int g = A[i];
        A[i] = A[largest];
        A[largest] = g;

        heapify(A, largest, n);
    }
}

void build_heap(int A[], int n){
    for (int i = n/3 - 1; i >= 0; i--)
        heapify(A, i, n);
}

void heap_sort(int A[], int n){
    build_heap(A, n);

    for (int i = n - 1; i > 0; i--){
        int g = A[0];
        A[0] = A[i];
        A[i] = g;

        heapify(A, 0, i);
    }
}

void output(int A[], int n){
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}

int main(){
    heap_sort(A, n);
    output(A, n);
}
