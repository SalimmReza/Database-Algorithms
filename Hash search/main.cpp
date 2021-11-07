#include<bits/stdc++.h>
using namespace std;


struct Node   //linked list for storing
{
    Node(const char* Key1 = " ", const char* fName = " ",
         const char *sex =" " )
    {
        strcpy(Key, Key1);
        strcpy(FullName, fName);
        strcpy(Gender, sex);
        next = NULL;
    }
    char Key[16];
    char FullName[64];
    char Gender[16];
    Node *next;///Node mane ekta place jeita arekta place k ponter diye connect kore
};

class Hashtable
{
public:
 int table_size;
    Node** table;
    int size;
    long hash_String(char* Key);///kono value variable er vitor dhukanor jonno pointer use kora hoi

    Node* current_entry; ///current entry dhukabo ami
    int current_index;
    Hashtable(int T = 467);///ei constructor ta hash table er constructor
    virtual ~Hashtable();///destructor
    bool put(Node *);
    bool get(Node *);
    bool contains(char* Key);
    bool remove(char* Key);
    void remove_all();
    int getSize();
    Node* find(char* Key);
    ///nicher function gula sobar nich e declare kora ase.
    void initIterator();
    bool hash_next();
    void get_next_key(char* Key);
    friend void display(Node *);
};

Hashtable::Hashtable(int T)  // constructor
{
    size = 0;
    table_size = T;
    table = new Node*[table_size];
    for(int i=0; i<table_size; i++)
    {
        table[i] = NULL;
    }
}

Hashtable::~Hashtable()
{
    remove_all();
    delete[] table;
}

void display(Node *S1)
{
    cout << "\nPhone Number-->:      " << S1->Key << "\nFullName-->: "
         << S1->FullName <<"\nGender-->:    " << S1->Gender<< endl;
}
///Node N e shob input hoccee r S1 e shob show hocceee..
bool Hashtable::put(Node *N)
{
    //start put
    if(find(N->Key) != NULL)
    {
        return false;
    }
    Node* entry = new Node(N->Key, N->FullName,N->Gender);
    int bucket = hash_String(N->Key);
    entry->next = table[bucket];///bucket dra k  count kora bhujaicie
    table[bucket] = entry;
    size++;
    return true;
}

bool Hashtable::get(Node* N)
{

    Node* temp = find(N->Key);///temp means temporary
    if(temp == NULL)
    {
        N->FullName[0] = '\0';
        return false;
    }
    else
    {
        strcpy(N->FullName, temp->FullName);///copy kore n ilam string ta temp table e .
        strcpy(N->Gender, temp->Gender);
        return true;
    }
}

bool Hashtable::contains(char* Key)///element include mane contains.
{

    if(find(Key) == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Hashtable::remove(char* Key)
{
    //start remove
    int bucket = hash_String(Key);
    Node* temp = table[bucket];
    if(temp == NULL)
    {
        return false;
    }
    else if(strcmp(Key, temp->Key) == 0)
    {
        //protek bar temp e dhuktice count kortice and ber hocce. jeita pacce na seita out hoar koron e size-- hocee
        table[bucket] = temp->next;
        delete temp;
        size--;
        return true;
    }
    else
    {
        Node* temp_next = temp->next;
        /// joto projonto
        ///joto khom projonto txt theke input neoa shes hobe na oto khon projonto kaj korte thakbe
        while(temp_next != NULL)///joto khon projonto shes hobe na nite thako
        {
            if(strcmp(Key, temp_next->Key) == 0)
            {
                temp->next = temp_next->next;
                delete temp_next;
                size--;
                return true;
            }
            temp = temp->next;
            temp_next = temp_next->next;
        }
    }
    return false;
}

void Hashtable::remove_all()
{

    for(int i=0; i<table_size; i++)
    {
        Node* temp = table[i];
        while(temp != NULL)
        {
            Node* next = temp->next;
            display(temp);
            delete temp;
            temp = next;
        }
    }
    size = 0;
}

int Hashtable::getSize()
{
    return size;// total hash table er size ta
}

Node* Hashtable::find(char* Key)
{

///keyboar diye input er kaj
    int bucket = hash_String(Key);
    Node* temp = table[bucket];
    while(temp != NULL)
    {
        if(strcmp(Key, temp->Key) == 0)//eita toe hobe na
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

long Hashtable::hash_String(char* Key)  //hash table ta create hoar age linked list er kaj ta hocee.
{

    int n = strlen(Key);
    long h = 0;
    for(int i=0; i<n; i++)
    {
        ///To get almost fair distributions of Nodes over the array
        h = (h << 3) ^ Key[i];
    }
    return abs(h % table_size );///abs mane absolute value mane non negative
}

void Hashtable::initIterator()
{

    current_entry = NULL;
    current_index = table_size;
    for(int i=0; i<table_size; i++)
    {
        if(table[i] == NULL)
        {
            continue;
        }
        else
        {
            current_entry = table[i];
            current_index = i;
            break;
        }
    }
}

bool Hashtable::hash_next()
{
    if(current_entry == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void Hashtable::get_next_key(char* Key)
{
    int i;
    if(current_entry == NULL)
    {
        Key[0] = '\0';
        return;
    }
    strcpy(Key, current_entry->Key);
    if(current_entry->next != NULL)
    {
        current_entry = current_entry->next;
    }
    else
    {
        for(i=current_index+1; i<table_size; i++)
        {
            if(table[i] == NULL)
            {
                continue;
            }
            current_entry = table[i];
            current_index = i;
            return;
        }
        current_entry = NULL;
        current_index = table_size;
    }
}

void display_all(Hashtable *hashtable)
{
    Node S1;
    cout << "Current Nodes in Hashtable:" << endl;
    hashtable->initIterator();
    while(hashtable->hash_next())
    {
        hashtable->get_next_key(S1.Key);
        hashtable->get(&S1);
        display(&S1);
    }
}

void File_open(ifstream &inFile, string inFileName)
{

    inFile.open(inFileName);


    if (!inFile)
    {
        cout << "cannot open file" << endl;
        cout << endl;
        return;
    }
}
std::string& left_trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")///search first line in the data file
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

std::string& right_trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")///find last line of the data file
{
    str.erase(str.find_last_not_of(chars) + 1);///+1 mane exact size ber kora
    return str;
}

string& triangle(std::string& str, const std::string& chars = "\t\n\v\f\r ")///join both string and character
{
    return left_trim(right_trim(str, chars), chars);///trim mane join kora
}
int main()
{
    Node S1("18652992991","salim","male");
    char temp1[16];
    Hashtable* hashtable = new Hashtable();///temp e gelo na tai eita new hash
    ifstream inFile;
    string inFileName = "info.txt";
    File_open(inFile, inFileName);
    int choice;
    char key;
    clock_t test_time;
    clock_t time_passed;
    double seconds_Passed;
    choice =0;
    while(choice!=3)
    {
        cout<<endl;
        cout<<"Operations on Hash Table"<<endl<<endl;
        cout<<"[1]  Create Hash Table"<<endl;
        cout<<"[2]  Search element from the data file"<<endl;
        cout<<"[3]  Exit"<<endl<<endl;
        cout<<"Enter your choice-->: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            ///hast table ta dekhanor jonno ja ja korte hobe
            while(inFile)
            {
                inFile>>S1.FullName>>S1.Gender>>S1.Key;

                if(!hashtable->contains(S1.Key))
                {

                    display(&S1);
                    hashtable->put(&S1);
                }
            };
            inFile.close();
            display_all(hashtable);
            break;
        }
        case 2:
        {
            cout<<"Enter the Phone number"<<endl;
            cin>>S1.Key;
            clock_t startTime = clock();
            if (hashtable->contains(S1.Key) == true)
            {

                Node* temp = hashtable->find(S1.Key);
                cout<<"Name-->: "<<temp->FullName<<" Sex-->: "<<temp->Gender<<" Phone Number-->: "<<temp->Key<<endl;
                test_time = clock();
                time_passed = test_time - startTime;
                seconds_Passed = time_passed / (double)CLOCKS_PER_SEC;
                cout<<"Time passed-->: "<<seconds_Passed<<endl;

            }
            else
            {
                cout<<"This number doesn't exist " << endl;
            }
            break;
        }

        case 3:
            exit(1);
        default:
            cout<<"Wrong number, enter the correct number between [1]to[3]"<<endl;
        }
    }
    return 0;
}


