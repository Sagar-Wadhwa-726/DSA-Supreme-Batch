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

/*Function which finds the position of an element in the array*/
int findPosition(vector<int> &inOrder, int &element)
{
    for (int i = 0; i < inOrder.size(); i++)
        if (inOrder[i] == element)
            return i;
    return -1;
}

/*Function which builds a tree from inorder and postorder traversal*/
// The parameters include:
// 1.) inOrder array
// 2.) preOrder array
// 3.) Since at every recursive call as in the diagram, we are using a part of the inorder array, hence pass the starting and the ending index.
// 4.) preOrder Index is passed for the same reason
// 5.) Preindex should be passed by reference since once we have traversed an element we don't come back
// to it again as it is processed. So in this case the index should be maintained and not go backwards.
// 6.) the find position method can be improved from O(N)->O(1), instead of traversing the array to find the element, we can use an unordered_map in C++
Node *buildTreeFromInorderAndPreOrderTraversal(vector<int> &inOrder, vector<int> &preOrder, int inOrderStartIndex, int inOrderEndIndex, int &preOrderIndex)
{
    if (preOrderIndex >= preOrder.size() || inOrderStartIndex > inOrderEndIndex)
        return nullptr;

    int rootElement = preOrder[preOrderIndex++];
    Node *root = new Node(rootElement);

    // Find this root element in the inorder traversal array to find the left and right part of tree
    int index = findPosition(inOrder, rootElement);

    root->left = buildTreeFromInorderAndPreOrderTraversal(inOrder, preOrder, inOrderStartIndex, index - 1, preOrderIndex);

    root->right = buildTreeFromInorderAndPreOrderTraversal(inOrder, preOrder, index + 1, inOrderEndIndex, preOrderIndex);

    return root;
}
Node *buildTreeFromInorderAndPostOrderTraversal(vector<int> &inOrder, vector<int> &postOrder, int inOrderStartIndex, int inOrderEndIndex, int &postOrderIndex)
{
    if (postOrderIndex < 0 || inOrderStartIndex > inOrderEndIndex)
        return nullptr;

    int rootElement = postOrder[postOrderIndex--];
    Node *root = new Node(rootElement);

    // Find this root element in the inorder traversal array to find the left and right part of tree
    int index = findPosition(inOrder, rootElement);

    root->right = buildTreeFromInorderAndPostOrderTraversal(inOrder, postOrder, index + 1, inOrderEndIndex, postOrderIndex);

    root->left = buildTreeFromInorderAndPostOrderTraversal(inOrder, postOrder, inOrderStartIndex, index - 1, postOrderIndex);

    return root;
}
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
    vector<int> inOrder{40, 20, 10, 50, 30, 60};
    // vector<int> preOrder{10, 20, 40, 50, 30, 60, 70};
    vector<int> postOrder{40, 20, 50, 60, 30, 10};
    // int preOrderIndex = 0;
    int postOrderIndex = postOrder.size() - 1;

    // Node *root = buildTreeFromInorderAndPreOrderTraversal(inOrder, preOrder, 0, inOrder.size() - 1, preOrderIndex);
    // levelOrderTraversal(root);
    // cout << "\n";

    Node *rootAnother = buildTreeFromInorderAndPostOrderTraversal(inOrder, postOrder, 0, inOrder.size() - 1, postOrderIndex);
    levelOrderTraversal(rootAnother);
    cout << "\n";
    return 0;
}