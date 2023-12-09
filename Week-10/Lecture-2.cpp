#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    ~Node()
    {
        cout << "\nNode with value " << this->data << " deleted !\n";
    }
};
/*Function to print the linked list*/
int getLen(Node *&head)
{
    int count = 0;
    if (head == nullptr)
        return count;

    Node *temp = head;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}
/*Function to print the linked list*/
void printLinkedList(Node *&head)
{
    if (head == nullptr)
    {
        cout << "Linked list is already empty !\n";
        return;
    }
    Node *temp1 = head;

    cout << "Printing the linked list from forward: \n";
    while (temp1->next != nullptr)
    {
        cout << temp1->data << "->";
        temp1 = temp1->next;
    }
    cout << temp1->data << "\n";

    cout << "Printing the linked list from backward:\n";
    while (temp1->prev != nullptr)
    {
        cout << temp1->data << "->";
        temp1 = temp1->prev;
    }
    cout << temp1->data << "\n";
}
/*Function to insert a node at the head of the linked list*/
void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
/*Function to insert at the tail of the linked list*/
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
/*Function to insert at a position in linked list*/
void insertAtPosition(Node *&head, Node *&tail, int data, int pos)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    int len = getLen(head);
    if (pos < 0 || pos >= len)
    {
        cout << "Invalid position !\n";
        return;
    }
    if (pos == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }
    Node *temp = head;
    for (int i = 0; i < pos - 1; i++)
        temp = temp->next;

    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
}
/*Function to delete a node from the linked list*/
void deleteNode(Node *&head, Node *&tail, int pos)
{
    if (head == nullptr)
    {
        cout << "Linked list is already empty !\n";
        return;
    }
    int len = getLen(head);
    if (pos < 0 || pos >= len)
    {
        cout << "Invalid position !\n";
        return;
    }
    if (len == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    if (pos == 0)
    {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        head->prev = nullptr;
        delete temp;
        return;
    }
    if (pos == len - 1)
    {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return;
    }
    Node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    Node *curr = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    curr->next = nullptr;
    curr->prev = nullptr;
    delete curr;
}
int main()
{
    system("cls");
    Node *head = NULL;
    Node *tail = NULL;
    // insertAtPosition(head, tail, 111, 0);
    // insertAtPosition(head, tail, 112, 0);
    // insertAtPosition(head, tail, 113, 0);
    // insertAtPosition(head, tail, 114, 2);
    // insertAtPosition(head, tail, 115, 1);
    // Node *head = new Node(10);
    // Node *first = new Node(20);
    // Node *second = new Node(30);
    // Node *third = new Node(40);
    // Node *fourth = new Node(50);
    // Node *fifth = new Node(60);

    // head->next = first;
    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;

    // fifth->prev = fourth;
    // fourth->prev = third;
    // third->prev = second;
    // second->prev = first;
    // first->prev = head;

    // insertAtHead(head, tail, 10);
    // insertAtHead(head, tail, 20);
    // insertAtHead(head, tail, 30);
    // insertAtHead(head, tail, 40);
    // insertAtHead(head, tail, 50);

    // printLinkedList(head);

    // insertAtPosition(head, tail, 111, 4);

    insertAtTail(head, tail, 222);
    insertAtTail(head, tail, 322);
    insertAtTail(head, tail, 422);
    insertAtTail(head, tail, 522);
    insertAtTail(head, tail, 622);
    insertAtTail(head, tail, 722);
    insertAtTail(head, tail, 822);
    insertAtTail(head, tail, 922);
    insertAtTail(head, tail, 1022);

    printLinkedList(head);

    deleteNode(head, tail, 9);

    printLinkedList(head);
    return 0;
}