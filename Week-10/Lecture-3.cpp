#include <iostream>
#include <unordered_map>
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

/*Function to find the length of the linked list*/
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

/*Function to reverse the linked list in groups of K*/
Node *reverseInK(Node *&head, int &k)
{
    if (head == nullptr)
    {
        cout << "Linked list is already empty !\n";
        return nullptr;
    }

    int len = findLen(head);

    if (k > len)
        return head;

    Node *left = nullptr;
    Node *curr = head;
    Node *right = curr->next;
    for (int i = 0; i < k; i++)
    {
        right = curr->next;
        curr->next = left;
        left = curr;
        curr = right;
    }
    if (right != NULL)
        head->next = reverseInK(right, k);
    return left;
}
/*Function to check if loop is present in the linked list or not */
bool checkLoop(Node *&head)
{
    if (head == nullptr)
        return false;
    if (head->next == nullptr)
        return false;

    unordered_map<Node *, bool> mp;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (mp[temp])
            return true;

        mp[temp] = true;

        temp = temp->next;
    }
    return false;
}
/*Function to detect loop present or not using floyd's cycle detection algorithm*/
bool detectLoopFlyod(Node *&head)
{
    if (head == nullptr)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
            return true;
    }
    return false;
}
/*Function to find the starting point of loop of the linked list*/
Node *startingPointOfLoop(Node *&head)
{
    if (head == nullptr)
    {
        cout << "Linked list is empty!\n";
        return nullptr;
    }
    if (head->next == nullptr)
    {
        return nullptr;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
        {
            slow = head;
            break;
        }
    }
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
/*Function to remove loop from the linked list*/
Node *removeLoop(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked list is empty !\n";
        return nullptr;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow == fast)
        {
            slow = head;
            break;
        }
    }

    Node *prev = fast;
    while (slow != fast)
    {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = NULL;
    return slow;
}
/*Driver function*/
int main()
{
    system("cls");
    Node *head = new Node(10);
    Node *first = new Node(20);
    Node *second = new Node(30);
    Node *third = new Node(40);
    Node *fourth = new Node(50);
    Node *fifth = new Node(60);
    Node *sixth = new Node(70);
    Node *seventh = new Node(80);
    Node *eighth = new Node(90);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = fourth;
    if (detectLoopFlyod(head))
        cout
            << "loop present";
    else
        cout << "loop not present";
    cout << "\n";

    cout << "Starting point of loop is : " << startingPointOfLoop(head)->data;

    Node *temp = removeLoop(head);

    if (detectLoopFlyod(head))
        cout
            << "loop present";
    else
        cout << "loop not present";
    cout << "\n";

    printLinkedList(head);

    // printLinkedList(head);

    // cout << "\n";

    // int k = 2;

    // head = reverseInK(head, k);

    // printLinkedList(head);

    // printLinkedList(head);

    cout << "\n";
    return 0;
}