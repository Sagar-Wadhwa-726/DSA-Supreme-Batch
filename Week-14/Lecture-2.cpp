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
int main()
{
    system("cls");

    // VALIDATE BST QUESTION ON LEETCODE
    // https://leetcode.com/problems/validate-binary-search-tree/

    // LCA OF BST QUESTION ON LEETCODE
    // https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

    // KTH SMALLEST ELEMENT IN BST ON LEETCODE
    // https://leetcode.com/problems/kth-smallest-element-in-a-bst/

    vector<int> inorder{1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *root = createBSTFromInorderTraversal(inorder, 0, inorder.size() - 1);
    levelOrderTraversal(root);

    // TWO SUM IN A BST QUESTION ON LEETCODE
    // https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

    return 0;
}