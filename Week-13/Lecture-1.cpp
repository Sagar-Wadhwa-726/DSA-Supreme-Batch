#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data = data;
        this->right = nullptr;
        this->left = nullptr;
    }
};

// function to build a tree using recursion logic
Node *buildTree()
{
    int data;
    cout << "Enter the data : ";
    cin >> data;
    if (data == -1)
        return nullptr;

    // STEP A,B,C
    Node *root = new Node(data);

    cout << "Enter data for left part of " << data << " node "
         << "\n";
    root->left = buildTree();
    cout << "Enter data for right part of " << data << " node "
         << "\n";
    root->right = buildTree();
    return root;
}

// function to do level order traversal on a tree
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

// function to perform inorder traveral of a tree
void inOrderTraversal(Node *root)
{
    if (!root)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// function to perform preorder traveral of a tree
void preOrderTraversal(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// function to perform postorder traveral of a tree
void postOrderTraver(Node *root)
{
    if (!root)
        return;
    postOrderTraver(root->left);
    postOrderTraver(root->right);
    cout << root->data << " ";
}

// function that returns the height of the binary tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
int heightOfTheBinaryTree(Node *&root)
{
    if (!root)
        return 0;

    int height = 1;
    height += max(heightOfTheBinaryTree(root->left), heightOfTheBinaryTree(root->right));
    return height;
}

int main()
{
    system("cls");
    Node *root = nullptr;
    root = buildTree();
    levelOrderTraversal(root);
    cout << "Height of the binary tree is : " << heightOfTheBinaryTree(root);

    // Diameter of a binary tree
    // https://leetcode.com/problems/diameter-of-binary-tree/description/
    return 0;
}