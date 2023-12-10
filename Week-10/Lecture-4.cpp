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
Node *reverseLinkedList(Node *&head)
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
    return left;
}

/*Function to check whether a linked list is a palindrome or not*/
// https://leetcode.com/problems/palindrome-linked-list/
bool isPalindromeLinkedList(Node *&start, Node *finish)
{
    if (start == nullptr)
        return true;

    while (finish != nullptr)
    {
        if (start->data != finish->data)
            return false;
        start = start->next;
        finish = finish->next;
    }
    return true;
}

/*Function to sort a list consisting of 0's 1's and 2's*/
Node *sort012(Node *&head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
        return head;

    // STEP A : CREATION OF DUMMY NODES
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    // STEP B : TRAVERSING THE ORIGINAL LINKED LIST AND CREATING THE NEW LISTS
    Node *curr = head;
    while (curr != nullptr)
    {
        if (curr->data == 0)
        {
            Node *temp = curr;
            curr = curr->next;
            temp->next = nullptr;

            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (curr->data == 1)
        {
            Node *temp = curr;
            curr = curr->next;
            temp->next = nullptr;

            oneTail->next = temp;
            oneTail = temp;
        }
        else
        {
            Node *temp = curr;
            curr = curr->next;
            temp->next = nullptr;

            twoTail->next = temp;
            twoTail = temp;
        }
    }

    // STEP C : MODIFY 0, 1 AND 2's LIST
    Node *temp = oneHead;
    oneHead = oneHead->next;
    temp->next = nullptr;
    delete temp;

    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = nullptr;
    delete temp;

    // STEP D : JOIN THESE NEW LISTS
    if (oneHead != nullptr)
    {
        zeroTail->next = oneHead;
        if (twoHead != nullptr)
            oneTail->next = twoHead;
    }
    else if (twoHead != nullptr)
        zeroTail->next = twoHead;

    // STEP E : RETURN THE HEAD OF THE NEW lIST
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    return zeroHead;
}

/*Function to add two numbers using linked list*/
Node *addTwoNumbers(Node *&head1, Node *&head2)
{
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;
    /*STEP A: REVERSE BOTH THE LINKED LIST*/
    head1 = reverseLinkedList(head1);
    head2 = reverseLinkedList(head2);

    /*STEP B : ADD BOTH THE NUMBERS*/
    Node *ansHead = nullptr;
    Node *ansTail = nullptr;
    int carry = 0;

    while (head1 != nullptr && head2 != nullptr)
    {
        int sum = head1->data + head2->data + carry;
        int digit = sum % 10;
        carry = sum / 10;

        Node *newNode = new Node(digit);

        if (ansHead == nullptr)
        {
            ansHead = newNode;
            ansTail = newNode;
        }
        else
        {
            ansTail->next = newNode;
            ansTail = newNode;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    while (head1 != nullptr)
    {
        int sum = head1->data + carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head1 = head1->next;
    }
    while (head2 != nullptr)
    {
        int sum = head2->data + carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head2 = head2->next;
    }

    while (carry != 0)
    {
        int sum = carry;
        int digit = carry % 10;
        carry = carry / 10;
        Node *newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }

    /*STEP C : REVERSE THE ANSWER LINKED LIST*/
    ansHead = reverseLinkedList(ansHead);
    return ansHead;
}
int main()
{
    system("cls");
    Node *head1 = nullptr;
    Node *tail1 = nullptr;
    Node *head2 = nullptr;
    Node *tail2 = nullptr;
    insertAtTail(head1, tail1, 2);
    insertAtTail(head1, tail1, 4);
    insertAtTail(head2, tail2, 2);
    insertAtTail(head2, tail2, 3);
    insertAtTail(head2, tail2, 4);

    /*1.) Below commented code is for check whether a linked list is a palindrome or not*/
    // int len = findLen(head);

    // int mid = len / 2;

    // Node *temp = head;
    // for (int i = 0; i < mid - 1; i++)
    // {
    //     temp = temp->next;
    // }
    // if (len % 2 != 0)
    // {
    //     temp = temp->next;
    // }

    // Node *end = temp;
    // while (end->next != nullptr)
    //     end = end->next;

    // Node *left = temp;
    // Node *curr = left->next;
    // Node *right = curr->next;

    // while (curr != nullptr)
    // {
    //     right = curr->next;
    //     curr->next = left;
    //     left = curr;
    //     curr = right;
    // }

    // temp->next->next = nullptr;
    // temp->next = end;

    // printLinkedList(head);
    // cout << "\n";

    // /*start and finish pointer are used to check whether the linked list is a palindrome or not*/

    // Node *start = head;
    // Node *finish = temp->next;
    // if (isPalindromeLinkedList(start, finish))
    //     cout << "Palindrome linked list !\n";
    // else
    //     cout << "Not a palindrome linked list !\n";
    // return 0;

    /*2.) Remove duplicates from a sorted linked list */
    // https://leetcode.com/problems/remove-duplicates-from-sorted-list/
    // On the similar lines can be done for unsorted linked list

    /*3.) Code to sort 0's 1's and 2's linked list*/
    // Node *newHead = sort012(head);
    // printLinkedList(newHead);

    /*4.) Add two numbers using linked list*/
    Node *answer = addTwoNumbers(head1, head2);

    printLinkedList(answer);

    cout << "\n";
}