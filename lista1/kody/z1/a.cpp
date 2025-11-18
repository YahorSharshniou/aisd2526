#include <iostream>
using namespace std;


int n = 7;
int A[7] = {1,7,6,4,5,3,2};
int x;
int por;
int przyp;

void insert_sort(int A[], int n)
{
    for (int i = 1; i < n; i++){
        przyp = przyp + 1;
        x = A[i];
        int j = i - 1;
        por = por + 1;
        while (j >= 0 && A[j] > x){
            por = por + 1;
            przyp = przyp + 1;
            A[j+1] = A[j];
            j = j - 1;
        }
        przyp = przyp + 1;
        A[j+1] = x;
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
    insert_sort(A,n);
    output(A,n);

}