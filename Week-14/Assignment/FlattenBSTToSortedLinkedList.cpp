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

/*Function to create the BST from the input provided by the user*/
Node *insertIntoBST(Node *&root, int data)
{
    // denotes the first node to be inserted in the BST
    if (!root)
    {
        root = new Node(data);
        return root;
    }
    if (data < root->data)
        root->left = insertIntoBST(root->left, data);
    else
        root->right = insertIntoBST(root->right, data);
    return root;
}

/*Function to take the input from the user, till the input is not -1, then create the BST*/
void takeinput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
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

/*Function for inorder traversal*/
void inorder(Node *root, Node *&prev)
{
    if (!root)
        return;

    inorder(root->left, prev);
    prev->left = nullptr;
    prev->right = root;
    prev = root;
    inorder(root->right, prev);
}

/*Function which flattens a BST*/
Node *flatten(Node *root)
{
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    inorder(root, prev);
    // for the last node
    prev->left = prev->right = nullptr;
    root = dummy->right;
    return root;
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

int main()
{
    system("cls");
    Node *root = nullptr;
    takeinput(root);
    levelOrderTraversal(root);
    cout << "\n";
    root = flatten(root);
    printLinkedList(root);
    return 0;
}