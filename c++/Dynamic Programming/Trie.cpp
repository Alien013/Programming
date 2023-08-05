#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// Trie node class
class TrieNode
{
public:
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = nullptr;
    }
};

// Trie class
class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(string word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (curr->children[index] == nullptr)
                curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }

    // Search for a word in the trie
    bool search(string word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (curr->children[index] == nullptr)
                return false;
            curr = curr->children[index];
        }
        return (curr != nullptr && curr->isEndOfWord);
    }

    // Delete a word from the trie
    bool deleteWord(TrieNode *curr, string word, int depth)
    {
        if (curr == nullptr)
            return false;

        // Base case
        if (depth == word.length())
        {
            if (curr->isEndOfWord)
                curr->isEndOfWord = false;
            return (isEmpty(curr));
        }

        // Recursive case
        int index = word[depth] - 'a';
        if (deleteWord(curr->children[index], word, depth + 1))
        {
            delete curr->children[index];
            curr->children[index] = nullptr;
            return (isEmpty(curr) && !curr->isEndOfWord);
        }
        return false;
    }

    // Helper function to check if a node has any children
    bool isEmpty(TrieNode *node)
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (node->children[i] != nullptr)
                return false;
        }
        return true;
    }
};

int main()
{
    Trie trie;

    // Insert words into the trie
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("orange");

    // Search for a word in the trie
    if (trie.search("banana"))
        cout << "Found banana in the trie!" << endl;

    // Delete a word from the trie
    trie.deleteWord(trie.root, "banana", 0);
    if (!trie.search("banana"))
        cout << "Successfully deleted banana from the trie!" << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// const int ALPHABET_SIZE = 26;

// // Trie node class
// class TrieNode
// {
// public:
//     bool isEndOfWord;
//     vector<TrieNode *> children;

//     TrieNode()
//     {
//         isEndOfWord = false;
//         children = vector<TrieNode *>(ALPHABET_SIZE, nullptr);
//     }
// };

// // Trie class
// class Trie
// {
// private:
//     TrieNode *root;

// public:
//     Trie()
//     {
//         root = new TrieNode();
//     }

//     // Insert a word into the Trie
//     void insert(string word)
//     {
//         TrieNode *current = root;
//         for (char c : word)
//         {
//             int index = c - 'a';
//             if (!current->children[index])
//             {
//                 current->children[index] = new TrieNode();
//             }
//             current = current->children[index];
//         }
//         current->isEndOfWord = true;
//     }

//     // Search for a word in the Trie
//     bool search(string word)
//     {
//         TrieNode *current = root;
//         for (char c : word)
//         {
//             int index = c - 'a';
//             if (!current->children[index])
//             {
//                 return false;
//             }
//             current = current->children[index];
//         }
//         return current->isEndOfWord;
//     }

//     // Check if a prefix exists in the Trie
//     bool startsWith(string prefix)
//     {
//         TrieNode *current = root;
//         for (char c : prefix)
//         {
//             int index = c - 'a';
//             if (!current->children[index])
//             {
//                 return false;
//             }
//             current = current->children[index];
//         }
//         return true;
//     }
// };

// int main()
// {
//     Trie trie;
//     trie.insert("hello");
//     trie.insert("world");

//     cout << trie.search("hello") << endl; // Output: 1
//     cout << trie.search("world") << endl; // Output: 1
//     cout << trie.search("hi") << endl;    // Output: 0

//     cout << trie.startsWith("hell") << endl; // Output: 1
//     cout << trie.startsWith("wor") << endl;  // Output: 1
//     cout << trie.startsWith("hi") << endl;   // Output: 0

//     return 0;
// }
