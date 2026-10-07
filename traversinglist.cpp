#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

/* Structure definition for a singly linked list node */
struct node {
    int data;
    node* link;
};

/* Count the number of nodes in the list */
void count_of_nodes(node* head) {
    int count = 0;

    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    node* ptr = head;

    while (ptr != NULL) {
        count++;
        ptr = ptr->link;
    }

    cout << "Nodes are: " << count << endl;
}

/* Print all nodes in the list */
void printlist(node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    node* ptr = head;

    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->link;
    }

    cout << "NULL" << endl;
}

/* Insert a new node at the end of the list */
void add_at_end(node* head, int data) {
    node* temp = new node();   // create new node
    temp->data = data;
    temp->link = NULL;

    node* ptr = head;

    while (ptr->link != NULL) {   // traverse to last node
        ptr = ptr->link;
    }

    ptr->link = temp;   // attach new node
}

/* Insert a new node at the beginning of the list */
node* add_beg(node* head, int data) {
    node* ptr = new node();   // create new node
    ptr->data = data;

    ptr->link = head;   // new node points to old head
    return ptr;         // return new head
}

int main() {

    auto start = high_resolution_clock::now();   // Start time measurement

    /* Create initial linked list */
    node* head = new node();
    head->data = 125;
    head->link = NULL;

    node* current = new node();
    current->data = 256;
    current->link = NULL;
    head->link = current;

    node* current2 = new node();
    current2->data = 145;
    current2->link = NULL;
    current->link = current2;

    node* current3 = new node();
    current3->data = 158;
    current3->link = NULL;
    current2->link = current3;

    /* Insert new elements */
    add_at_end(head, 1200);
    add_at_end(head, 8900);
    add_at_end(head, 7800);

    head = add_beg(head, 12125);
    head = add_beg(head, 1589);
    head = add_beg(head, 1700);

    /* Display results */
    count_of_nodes(head);
    printlist(head);

    auto stop = high_resolution_clock::now();   // End time measurement
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Execution time: " << duration.count() << " milliseconds" << endl;

    return 0;
}