#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

/*Function to find the lenght of the linked list*/
int findLen(Node *&head)
{
    int count = 0;
    if (head == nullptr)
        return count;

    Node *temp = head;
    while (temp != nullptr)
    {
        temp = temp->next;
        ++count;
    }
    return count;
}

/*Function to print the linked list*/
void printLinkedList(Node *&head)
{
    if (head == nullptr)
    {
        cout << "Linked list is empty !\n";
        return;
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data;
}

/*Function to insert at the head of the linked list*/
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
    head = newNode;
}

/*Function to insert at the tail of the linked list*/
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (tail == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

/*Function to insert at a particular position of a linked list, pos assumed to be 0 based index*/
void insertAtPosition(Node *&head, Node *&tail, int data, int pos)
{
    int len = findLen(head);
    if (pos < 0)
    {
        cout << "Invalid position !\n";
        return;
    }
    if (pos == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    if (pos >= len)
    {
        cout << "Invalid position !\n";
        return;
    }
    Node *newNode = new Node(data);
    Node *prev = head;
    Node *curr;
    for (int i = 0; i < pos - 1; i++)
    {
        prev = prev->next;
    }
    curr = prev->next;
    newNode->next = curr;
    prev->next = newNode;
}

/*Function to delete a node from the linked list, position is assumed to be 0 index based*/
void deleteNode(Node *&head, Node *&tail, int pos)
{
    if (pos < 0)
    {
        cout << "Invalid position !\n";
        return;
    }
    if (head == nullptr)
    {
        cout << "Linked list is already empty !\n";
        return;
    }
    int len = findLen(head);
    if (pos >= len)
    {
        cout << "Invalid position !\n";
        return;
    }
    if (pos == 0)
    {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return;
    }

    Node *prev = head;
    for (int i = 0; i < pos - 1; i++)
    {
        prev = prev->next;
    }
    Node *curr = prev->next;
    prev->next = curr->next;
    curr->next = nullptr;
    delete curr;
    if (pos == len - 1)
        tail = prev;
}

/*Function to reverse a linked list (iteratively)*/
void reverseLinkedList(Node *&head)
{
    Node *left = nullptr;
    Node *curr = head;
    while (curr != nullptr)
    {
        Node *right = curr->next;
        curr->next = left;
        left = curr;
        curr = right;
    }
    head = left;
}

/*Function to reverse a linked list (recursively)*/
void reverseLinkedList(Node *&left, Node *&curr, Node *&head)
{
    if (curr == nullptr)
    {
        head = left;
        return;
    }

    Node *right = curr->next;
    curr->next = left;

    reverseLinkedList(curr, right, head);
}

/*Driver function*/
int main()
{
    system("cls");
    Node *head = NULL;
    Node *tail = NULL;

    // insertAtHead(head, tail, 77);

    // printLinkedList(head);

    // cout << "\n";

    // deleteNode(head, tail, 0);

    // printLinkedList(head);

    // insertAtTail(head, tail, 77);
    // insertAtTail(head, tail, 66);
    // insertAtTail(head, tail, 55);
    // insertAtPosition(head, tail, 1, 0);
    // insertAtPosition(head, tail, 2, 0);
    // insertAtPosition(head, tail, 3, 1);
    // insertAtPosition(head, tail, 88, 10);
    // insertAtPosition(head, tail, 69, 5);
    // printLinkedList(head);
    // cout << "\n";
    // deleteNode(head, tail, 4);
    // printLinkedList(head);
    // cout << "\n";

    // for (int i = 1; i <= 5; i++)
    // {
    //     insertAtHead(head, tail, i);
    // }

    // deleteNode(head, tail, 7);

    // // INVALID CASES
    // // insertAtPosition(head, tail, 3, -1);
    // // insertAtPosition(head, tail, 4, 12);
    // // insertAtPosition(head, tail, 3, -1);
    // // insertAtPosition(head, tail, 3, -1);
    // printLinkedList(head);

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    printLinkedList(head);
    cout << "\n";
    // reverseLinkedList(head);
    Node *left = nullptr;
    Node *curr = head;
    reverseLinkedList(left, curr, head);
    printLinkedList(head);
    cout << "\n";
    reverseLinkedList(head);
    printLinkedList(head);
    cout << "\n";
    return 0;
}
