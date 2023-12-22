#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

/*Function to create a BST from inorder traversal array which is always given in ascending order*/
Node *createBSTFromInorderTraversal(vector<int> &inorder, int s, int e)
{
    if (s > e)
        return nullptr;

    int mid = s + (e - s) / 2;
    int element = inorder[mid];
    Node *root = new Node(element);

    root->left = createBSTFromInorderTraversal(inorder, s, mid - 1);
    root->right = createBSTFromInorderTraversal(inorder, mid + 1, e);
    return root;
}

/*Function to convert a BST to a sorted Doubly Linked List*/
void convertBSTToSortedDoublyLL(Node *root, Node *&head)
{
    if (!root)
        return;

    // convert the right subtree into doubly linked list using recursion
    convertBSTToSortedDoublyLL(root->right, head);

    // attach the root node to the doubly linked list created from the right recursion
    root->right = head;
    if (head)
        head->left = root;
    head = root;

    // convert the left subtree to doubly linked list using recursion
    convertBSTToSortedDoublyLL(root->left, head);
}

/*Function to print the doubly linked list*/
void printLinkedList(Node *&head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

/*Function to create a BST from a sorted doubly Linked List*/
Node *convertLinkedListToBST(Node *&head, int n)
{
    // base case
    if (n <= 0 || !head)
        return nullptr;

    Node *leftSubtree = convertLinkedListToBST(head, n - n / 2 - 1);

    // now the head points to the mid node, create node out of it
    Node *root = head;
    root->left = leftSubtree;
    head = head->right;

    root->right = convertLinkedListToBST(head, n / 2);

    return root;
}

/*Function to do level order traversal on a tree*/
void levelOrderTraversal(Node *&root)
{
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (!temp)
        {
            cout << "\n";
            if (!q.empty())
                q.push(nullptr);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
int main()
{
    system("cls");
    vector<int> inorder{1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *root = createBSTFromInorderTraversal(inorder, 0, inorder.size() - 1);

    Node *head = nullptr;
    convertBSTToSortedDoublyLL(root, head);
    printLinkedList(head);
    cout << "\n";

    Node *tempRoot = convertLinkedListToBST(head, 9);
    levelOrderTraversal(tempRoot);

    // LARGEST BST IN A BINARY TREE PROBLEM ON LEETCODE
    // https://www.geeksforgeeks.org/problems/largest-bst/1

        return 0;
}