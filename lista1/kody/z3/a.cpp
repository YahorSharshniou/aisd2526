#include <iostream>
using namespace std;


int n = 7;
int A[7] = {1,7,6,2,6,35,52};
int por;
int przyp;

int left(int i){
    return 2*i + 1;
}
int right(int i){
    return 2*i+2;
}

void heapify(int A[], int i, int n){
    int l = left(i);
    int r = right(i);
    int largest = i;
    por = por + 2;
    if(l < n && A[l] > A[largest])
        largest = l;
    por = por + 2;
    if (r < n && A[r] > A[largest])
        largest = r;
    por = por + 1;
    if(largest != i){
        przyp = przyp + 3;
        int g = A[i];
        A[i] = A[largest];
        A[largest] = g;
        heapify(A,largest,n);
    }
}

void build_heap(int A[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(A,i,n);
    }
}

void heap_sort(int A[], int n){
    build_heap(A, n);

    for (int i = n - 1; i > 0; i--) {
        int g = A[0];
        przyp = przyp + 3;
        A[0] = A[i];
        A[i] = g;
        heapify(A, 0, i);
    }
}

void output(int A[], int n){
    for (int i = 0; i < n;i++)
    {
        cout << A[i] << " ";
    }
}

int main() 
{
    heap_sort(A,n);
    output(A, n);
}