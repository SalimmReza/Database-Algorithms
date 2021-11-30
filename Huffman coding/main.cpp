#include <bits/stdc++.h>

using namespace std;

struct Node
{
    char data;
    unsigned frequency;

    Node *leftC, *rightC;

    Node(char d, unsigned f)/// unsigned means non negeative
    {
        data = d;
        frequency = f;
        leftC = NULL;
        rightC = NULL;
    }
};

struct compare
{

    bool operator()(Node* l, Node* r)
    {
        return (l->frequency > r->frequency); ///-> means pointer initialize a member
    }
};

void display(struct Node* root, string str)
{
    ///if tree is empty return
    if (!root)
        return;

    if (root->data != '$')///$ means null ///jotokhon projonto input root e dhukano shes hoi ni oto khon projonoto cholte thakbe
        cout << root->data << "---->: " << str << "\n";

    ///amra toe jani j ekta root er child ber hoi and rifgt child e 0 jai and left child e 1
    display(root->leftC, str + "0");
    display(root->rightC, str + "1");
}

void create_Huffman_Tree(char data[], int frequency[], int size)
{
    struct Node *leftC, *rightC, *top;

    /// Create a minheap using standard liabrary function
    priority_queue<Node*, vector<Node*>, compare> minheap;

    /// push alphabets, frequency into minheap as leaf nodes
    int i;
    for ( i = 0; i < size; ++i)
        minheap.push(new Node(data[i], frequency[i])); ///amra toe shob value push kore kore original freq te pouchabo.

    /// repeat until heap size becomes one
    while (minheap.size() != 1)///jotojhon projonto 1 hobe na oto khon projonto cholte thakbe
    {
        /// Extract two least frequencyuent items from minheap
        leftC = minheap.top();
        minheap.pop();///because 0 frequency toe ber hobe ber na hoile toe frequencyuency create hobe na

        rightC = minheap.top();
        minheap.pop();

        ///notun ekta  node banailam eijonno j left child and right child add korle parrent hoi
        ///main node ta toe 2 ta child er plus
        top = new Node('$', leftC->frequency + rightC->frequency);

        top->leftC = leftC;
        top->rightC = rightC;

        minheap.push(top);///suru theke shob push kore dilo frequency gula tarpor original frequency value ashlo
    }


    display(minheap.top(), " ");
}


int main()
{
    int charCount = 0;
    char ch;
    int frequency[26] = {0};
    FILE  *file;
    file = fopen("text.txt", "r");
    if (file == NULL)
    {
        cout << "Can't open the file" << endl;
        exit(0);
    }

    /// reads english article from file and counts frequencyuency of each lowercase alphabet
    while (1)
    {
        ch = fgetc(file);
        if (ch == EOF)///end of file
            break;
        if (ch >= 'a' && ch <= 'z')
        {
            frequency[ch - 'a']++;
            /// count total number of lowercase alphabets in file
            charCount++;
        }
    }

    ///To show the text file
    std::ifstream f("text.txt");
    if (f.is_open())
        std::cout << f.rdbuf() <<endl;///returns a pointer to the stream buffer object currently associated///txt r vitore ja ja ase shob ber hoiye ashbe
    cout<<endl;

    cout << "Lowercase alphabets in the file--->: " << charCount << endl<<endl;

    char arr[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    /// display frequency of lowercase characters

    cout << "Frequency occurrence: " << endl;
    cout<<endl;
    int frequency_count = 0;
    for(int i = 0; i < 26; i++)
    {
        if(frequency[i]!=0)
        {
            cout << arr[i] << " --->: " << frequency[i] <<endl;

            frequency_count++;
        }
    }

    char arr1[frequency_count];
    int k = 0,      frequency1[frequency_count];

    /// copy lowercase alphabets with frequency greater than zero into arr1, frequency1
    for(int i = 0; i < 26; i++)
    {
        if(frequency[i]!=0)
        {
            arr1[k] = arr[i], frequency1[k++] = frequency[i];// ei  ta line mane total frequency count kore mile ki na original value r sathe

        }
    }

    /// call method to create Huffman tree
    cout<<"The Huffman code: "<<endl;
    create_Huffman_Tree(arr1, frequency1, frequency_count);
    return 0;
}

