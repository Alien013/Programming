#include <bits/stdc++.h>
using namespace std;
#define MAX 50
struct node
{
    int freq;
    char symbol;
    struct node *left, *right;
};

struct heap
{
    int size;
    int capacity;
    struct node **array;
};

struct node *newNode(char symbol, int freq)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->left = temp->right = NULL;
    temp->symbol = symbol;
    temp->freq = freq;
    return temp;
}

struct heap *createMinH(int capacity)
{
    struct heap *minHeap = (struct heap *)malloc(sizeof(struct heap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct node **)malloc(minHeap->capacity * sizeof(struct node *));
    return minHeap;
}

void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i];

    cout << "\n";
}

void swap(struct node **a, struct node **b)
{
    struct node *t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct heap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx)
    {
        swap(&minHeap->array[smallest], &minHeap->array[idx]);
        heapify(minHeap, smallest);
    }
}

int checkSizeOne(struct heap *minHeap)
{
    return (minHeap->size == 1);
}

struct node *extractMin(struct heap *minHeap)
{
    struct node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    heapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct heap *minHeap, struct node *minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct heap *minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        heapify(minHeap, i);
}

int isLeaf(struct node *root)
{
    return !(root->left) && !(root->right);
}

struct heap *createMinHeap(char symbol[], int freq[], int size)
{
    struct heap *minHeap = createMinH(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(symbol[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

struct node *buildHfTree(char symbol[], int freq[], int size)
{
    struct node *left, *right, *top;
    struct heap *minHeap = createMinHeap(symbol, freq, size);
    while (!checkSizeOne(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}
void printHCodes(struct node *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printHCodes(root->left, arr, top + 1);
    }

    if (root->right)
    {
        arr[top] = 1;
        printHCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root))
    {
        cout << root->symbol << "  | ";
        print(arr, top);
    }
}

void HuffmanCodes(char symbol[], int freq[], int size)
{
    struct node *root = buildHfTree(symbol, freq, size);
    int arr[MAX], top = 0;
    printHCodes(root, arr, top);
}

int main()
{
    char arr[] = {'Q', 'P', 'T', 'a', 'd'};
    int freq[] = {3, 23, 30, 12, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Char|  Huffman code ";
    cout << "\n----------------------\n";
    HuffmanCodes(arr, freq, size);
}