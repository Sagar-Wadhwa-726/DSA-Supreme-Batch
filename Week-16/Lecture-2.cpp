#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;

        this->isTerminal = false;
    }
};
void insertWord(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    // if the character is already present
    if (root->children[index] != nullptr)
        child = root->children[index];
    else
    {
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode *root, string word)
{
    if (word.length() == 0)
        return root->isTerminal;

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    // present
    if (root->children[index] != nullptr)
        child = root->children[index];
    else
        return false;
    return searchWord(child, word.substr(1));
}
int main()
{
    system("cls");
    TrieNode *root = new TrieNode('-');
    insertWord(root, "coding");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehelp");
    insertWord(root, "baba");
    insertWord(root, "baby");
    insertWord(root, "babu");
    insertWord(root, "shona");

    if (searchWord(root, ""))
        cout << "Present";
    else
        cout << "Not Present";
    return 0;
}