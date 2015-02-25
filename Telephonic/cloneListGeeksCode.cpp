#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
    node *arbit;
};

node *create(int n)
{
    if (n == 0)
        return NULL;

    node *head = new node();
    node *p = head;

    cin >> (p -> data);

    p -> next = NULL;

    for (int i = 1; i < n; i++) {
        p -> next = new node();
        p = p -> next;

        cin >> (p -> data);

        p -> next = NULL;
    }

    return head;
}

void print(node *head)
{
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }

}


node * copy(node *head)
{
    node *p = head;
    node *q;

    while(p) {
        node *dummy = new node();
        dummy -> data = p -> data;
        node *temp = p -> next;
        p -> next = dummy;
        dummy -> next = temp;

        p = p -> next -> next;
    }

    node *head1 = head -> next;
    p = head;
    q = head1;

    while (p) {
        p -> next -> arbit = p -> arbit -> next;
        p = p -> next -> next;
    }

    while(1) {
        head -> next = head -> next -> next;
        head = head -> next;

        if (!head)
            break;

        q -> next = q -> next -> next;
        q = q -> next;

    }


    q -> next = NULL;

    return head1;
}

void test(node *head, node *head1)
{
    while (head) {
        cout << "In list:\n"<< head -> data << " and copy = " << head1 -> data << endl << "Arbitrary Node:\n" << head -> arbit -> data << " and copy = " << head1 -> arbit -> data << endl;
        head = head -> next;
        head1 = head1 -> next;
    }
}



int main()
{
    node *head = NULL;
    node *head1 = NULL;
    head = create(5);

    head -> arbit = head -> next -> next;
    head -> next -> arbit = head -> next -> next -> next;
    head -> next -> next -> arbit = head;
    head -> next -> next -> next -> arbit = head -> next -> next;
    head -> next -> next -> next -> next -> arbit = head -> next -> next;

    head1 = copy(head);

    test(head, head1);

    cout << "\n";

    return 0;
}
