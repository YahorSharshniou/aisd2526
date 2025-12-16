#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

void push(Node*& head, int x) {
    Node* n = new Node{x, head};
    head = n;
}

void output(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
            cout << "\n";
}


Node* insertion_sort(Node* head) {
    if (!head || !head->next)
        return head;

    Node* sorted = nullptr;   
    Node* curr = head;

    while (curr) {
        Node* next = curr->next;
       
        if (!sorted || curr->val < sorted->val) {
            curr->next = sorted;
            sorted = curr;
        }
        else {
            Node* temp = sorted;
            while (temp->next && temp->next->val < curr->val) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }

        curr = next;
    }
    return sorted;
}
int main() {
    Node* head = nullptr;
    push(head, 87);
    push(head, 23);
    push(head, 789);
    push(head, 21);
    push(head, 1);
    push(head, 45);
    push(head, 3);
        output(head);

    head = insertion_sort(head);
    output(head);
}
