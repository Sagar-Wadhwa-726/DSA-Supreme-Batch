#include <iostream>
#include <vector>
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
void storeSuggestions(TrieNode *curr, vector<string> &temp, string &prefix)
{
    if (curr->isTerminal)
        temp.push_back(prefix);

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        int index = ch - 'a';
        TrieNode *next = curr->children[index];
        if (next)
        {
            prefix.push_back(ch);
            storeSuggestions(next, temp, prefix);
            prefix.pop_back();
        }
    }
}
vector<vector<string>> getSuggestions(TrieNode *root, string &input)
{
    TrieNode *prev = root;
    vector<vector<string>> output;
    string prefix = "";

    for (int i = 0; i < input.length(); i++)
    {
        char lastCharacter = input[i];
        int index = lastCharacter - 'a';
        TrieNode *curr = prev->children[index];

        if (!curr)
            break; // if the character in input string not in any string
        else
        {
            vector<string> temp; // stores all the suggestions
            prefix.push_back(lastCharacter);
            storeSuggestions(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
    }
    return output;
};
int main()
{
    // LONGEST COMMON PREFIX QUESTION PERFORMED ON LEETCODE USING TRIESd
    system("cls");
    vector<string> v;
    v.push_back("love");
    v.push_back("lover");
    v.push_back("loving");
    v.push_back("last");
    v.push_back("lost");
    v.push_back("lane");
    v.push_back("lord");

    string input = "lovi";

    TrieNode *root = new TrieNode('-');
    for (int i = 0; i < v.size(); i++)
        insertWord(root, v[i]);

    vector<vector<string>> ans = getSuggestions(root, input);
    cout << "Printing the answer : \n";
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }

    return 0;
}