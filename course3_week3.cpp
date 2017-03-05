#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
    char data;
    unsigned weight;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned weight)
    {
        left = right = NULL;
        this->data = data;
        this->weight = weight;
    }
};

struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->weight > r->weight);
    }
};

void printCodes(struct MinHeapNode* root, string str)
{
    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
int max_len=INT_MIN;  // put it INT_MAX when calculating minimum codeword length
void codeword(struct MinHeapNode* root, int s)
{
    if (!root)
        return;

    if ((root->left==NULL)&&(root->right==NULL))
    {
        if(s > max_len)
        {
            max_len=s;
        }
    }

    codeword(root->left, s+1);
    codeword(root->right, s+1);
}


void HuffmanCodes(char data[], int weight[], int size)
{
    struct MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], weight[i]));

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->weight + right->weight);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
     codeword(minHeap.top(),0);// call it
    cout<<max_len<<endl;
}

int main()
{
     //faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int weight[n];
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }

    HuffmanCodes(arr, weight, n);

    return 0;
}
