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
void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/*Function for preorder traversal*/
void preorder(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

/*Function for postorder traversal*/
void postorder(Node *root)
{
    if (!root)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

/*Function to find a node in a BST*/
Node *findNode(Node *&root, int &target)
{
    if (!root)
        return nullptr;
    if (root->data == target)
        return root;
    if (root->data < target)
        return findNode(root->right, target);
    else
        return findNode(root->left, target);
    return nullptr;
}
/*Function to find the minimum value in a BST*/
int findMin(Node *&root)
{
    Node *temp = root;
    while (temp->left)
        temp = temp->left;
    return temp->data;
}

/*Function to find the maximum value in a BST*/
int findMax(Node *&root)
{
    Node *temp = root;
    while (temp->right)
        temp = temp->right;
    return temp->data;
}

/*Function to delete a node from BST*/
Node *deleteNodeFromBST(Node *root, int target)
{
    if (!root)
        return nullptr;

    if (root->data == target)
    {
        // handle the 4 cases here
        if (!root->left && !root->right)
            return nullptr;
        else if (!root->left && root->right)
        {
            Node *child = root->right;
            return child;
        }
        else if (root->left && !root->right)
        {
            Node *child = root->left;
            return child;
        }
        else if (root->left && root->right)
        {
            Node *location = root->left;
            int inorderpred = findMax(location);
            root->data = inorderpred;
            root->left = deleteNodeFromBST(location, inorderpred);
            return root;
        }
    }
    else if (root->data < target)
        root->right = deleteNodeFromBST(root->right, target);
    else if (root->data > target)
        root->left = deleteNodeFromBST(root->left, target);
    return root;
}
int main()
{
    system("cls");
    Node *root = nullptr;
    takeinput(root);
    levelOrderTraversal(root);
    cout << "\nPrinting inorder traversal : ";
    inorder(root);
    cout << "\nPrinting postorder traversal : ";
    postorder(root);
    cout << "\nPrinting preorder traversal : ";
    preorder(root);
    cout << "\n";

    int target = 11;
    if (findNode(root, target))
        cout << "Target node present";
    else
        cout << "Target node not present";
    cout << "\n";
    cout << "Minimum value in BST is : " << findMin(root);
    cout << "\n";
    cout << "Maximum value in BST is : " << findMax(root);
    cout << "\n";
    root = deleteNodeFromBST(root, 150);
    cout << "\n";
    levelOrderTraversal(root);
    return 0;
}