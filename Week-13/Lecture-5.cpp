#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
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

// function to find the top view of a binary tree
void printTopView(Node *&root)
{
    if (!root)
        return;

    // Map to store the first node corresponding to a new horizontal distance
    // while doing level order traversal using queue associate each node with a horizontal distance, so queue will be of pair type
    map<int, int> topNode;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        if (topNode.find(hd) == topNode.end())
            topNode[hd] = frontNode->data;
        if (frontNode->left)
            q.push({frontNode->left, hd - 1});
        if (frontNode->right)
            q.push({frontNode->right, hd + 1});
    }

    for (auto i : topNode)
        cout << i.second << " ";
}

// function to find the left view of a binary tree
void printLeftView(Node *&root, vector<int> &ans, int levelNumber)
{
    if (!root)
        return;

    if (ans.size() == levelNumber)
        ans.push_back(root->data);

    printLeftView(root->left, ans, levelNumber + 1);
    printLeftView(root->right, ans, levelNumber + 1);
}

// function to find the right view of a binary tree
void printRightView(Node *&root, vector<int> &ans, int levelNumber)
{
    if (!root)
        return;

    if (ans.size() == levelNumber)
        ans.push_back(root->data);

    printRightView(root->right, ans, levelNumber + 1);
    printRightView(root->left, ans, levelNumber + 1);
}

// function to find the bottom view of a binary tree
void printBottomView(Node *&root)
{
    if (!root)
        return;

    // Map to store the first node corresponding to a new horizontal distance
    // while doing level order traversal using queue associate each node with a horizontal distance, so queue will be of pair type
    // in this case whenever a horizontal distance is present in the map and it is encountered again, udpate the map entry since we want to print the bottom view and for that we need to go to as much deep as possible
    map<int, int> topNode;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data; // update in this case

        if (frontNode->left)
            q.push({frontNode->left, hd - 1});
        if (frontNode->right)
            q.push({frontNode->right, hd + 1});
    }

    for (auto i : topNode)
        cout << i.second << " ";
}

// helper function to print all the nodes on the right most side of the tree
void printLeftBoundary(Node *&root)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        return;

    cout << root->data << " ";

    if (root->left)
        printLeftBoundary(root->left);
    else
        printLeftBoundary(root->right);
}

// helper function to print all the nodes on the last level of the tree (leaf nodes)
void printLeafBoundary(Node *&root)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        cout << root->data << " ";

    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

// helper function to print all the nodes on the right most side of the tree
void printRightBoundary(Node *&root)
{
    if (!root)
        return;

    if (!root->left && !root->right)
        return;

    if (root->right)
        printRightBoundary(root->right);
    else
        printRightBoundary(root->left);

    cout << root->data << " ";
}
// function which does boundary traversal of a tree
void boundaryTraversal(Node *&root)
{
    if (!root)
        return;

    // firstly print the root node to avoid the duplicacy of the first root
    cout << root->data << " ";
    // I: print all the leftmost nodes
    printLeftBoundary(root->left);
    // II: print all the leaf nodes
    printLeafBoundary(root);
    // III: print all the rightmost nodes
    printRightBoundary(root->right);
}

int main()
{
    system("cls");
    vector<int> ans{};

    Node *root = buildTree();

    printTopView(root);
    cout << "\n";

    printBottomView(root);
    cout << "\n";

    printLeftView(root, ans, 0);
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    ans.clear();

    printRightView(root, ans, 0);
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    boundaryTraversal(root);
    cout << "\n";

    return 0;
}
