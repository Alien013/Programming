#include <bits/stdc++.h>
using namespace std;

// Suffix tree node class
class SuffixTreeNode
{
public:
    int start, end, suffixIndex;
    vector<SuffixTreeNode *> children;

    SuffixTreeNode(int start, int end, int suffixIndex)
    {
        this->start = start;
        this->end = end;
        this->suffixIndex = suffixIndex;
        children.resize(256, nullptr);
    }

    void insertSuffix(string s, int suffixIndex)
    {
        this->suffixIndex = suffixIndex;
        if (s.length() > 0)
        {
            char c = s[0];
            if (children[c] == nullptr)
                children[c] = new SuffixTreeNode(start + 1, end, -1);
            children[c]->insertSuffix(s.substr(1), suffixIndex + 1);
        }
    }

    void getAllIndexes(vector<int> &indexes)
    {
        if (suffixIndex != -1)
        {
            indexes.push_back(suffixIndex);
            return;
        }
        for (int i = 0; i < 256; i++)
        {
            if (children[i] != nullptr)
                children[i]->getAllIndexes(indexes);
        }
    }
};

// Suffix tree class
class SuffixTree
{
public:
    SuffixTreeNode *root;
    string text;

    SuffixTree(string text)
    {
        root = new SuffixTreeNode(-1, -1, -1);
        this->text = text;
        for (int i = 0; i < text.length(); i++)
        {
            root->insertSuffix(text.substr(i), i);
        }
    }

    vector<int> search(string pattern)
    {
        SuffixTreeNode *curr = root;
        vector<int> result;
        for (int i = 0; i < pattern.length(); i++)
        {
            char c = pattern[i];
            if (curr->children[c] == nullptr)
                return result;
            curr = curr->children[c];
        }
        curr->getAllIndexes(result);
        return result;
    }
};

int main()
{
    string text = "banana";
    SuffixTree suffixTree(text);
    vector<int> indexes = suffixTree.search("an");
    if (indexes.size() == 0)
        cout << "Pattern not found in text!" << endl;
    else
    {
        cout << "Pattern found at indexes: ";
        for (int i = 0; i < indexes.size(); i++)
            cout << indexes[i] << " ";
        cout << endl;
    }
    return 0;
}
