#include <iostream>
#include <queue>
#include <stack>
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
bool kthAncestor(Node *&root, int &p, int &k)
{
    if (!root)
        return false;

    if (root->data == p)
        return true;

    bool leftAns = kthAncestor(root->left, p, k);
    bool rightAns = kthAncestor(root->right, p, k);

    if (leftAns || rightAns)
        k--;
    if (k == 0)
    {
        cout << root->data << " ";
        k = -1;
    }

    return leftAns || rightAns;
}
int main()
{
    system("cls");

    // Q1: CHECK WHETHER TWO TREES ARE SAME OR NOT
    // https://leetcode.com/problems/same-tree/

    // Q2: CHECK WHETHER TWO TREES ARE MIRROR IMAGES OF EACH OTHER OR NOT

    // Q3: CHECK IF A TREE IS SYMMETRIC OR NOT
    // https://leetcode.com/problems/symmetric-tree/

    //  Q4: CHECK WHETHER A BINARY TREE IS A BALANCED BINARY TREE OR NOT
    // https://leetcode.com/problems/balanced-binary-tree/

    // Q5: CHECK WHETHER A BINARY TREE IS A SUM TREE OR NOT

    // Q6: KTH ANCESTOR OF A NODE
    // https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

    // Q7: LOWEST COMMON ANCESTOR OF TWO NODES
    // https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

    // Q8: KTH ANCESTOR OF A NODE
    Node *root = buildTree();
    int k = 1;
    int p = 4;
    bool found = kthAncestor(root, p, k);

    // Path sum II
    // https://leetcode.com/problems/path-sum-ii/

    // HOME WORK QUESTION
    // SUM OF LONGEST BLOODLINE OF A BINARY TREE
    // PATH SUM III (LC#437)

    return 0;
}