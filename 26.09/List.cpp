#include <iostream>
using namespace std;

struct Elem
{
    int data;
    Elem* next, * prev;
};
class List
{
    Elem* Head, * Tail;
    int Count;

public:
    List();
    List(const List&);
    ~List();

    int GetCount();
    void DelAll();

    void Add(int n);
    void Del();
    void Print();

    List& operator = (const List&);
    List operator + (const List&);

    bool operator == (const List&);
    bool operator != (const List&);
    bool operator <= (const List&);
    bool operator >= (const List&);
    bool operator < (const List&);
    bool operator > (const List&);
};
List::List()
{
    Head = Tail = NULL;
    Count = 0;
}
List::List(const List& L)
{
    Head = Tail = NULL;
    Count = 0;
    Elem* temp = L.Head;
    while (temp != 0)
    {
        Add(temp->data);
        temp = temp->next;
    }
}
List::~List()
{
    DelAll();
}
void List::Add(int n)
{
    Elem* temp = new Elem;

    temp->next = 0;
    temp->data = n;
    temp->prev = Tail;

    if (Tail != 0)
    {
        Tail->next = temp;
    }
    if (Count == 0)
    {
        Head = Tail = temp;
    }
    else
    {
        Tail = temp;
    }
    Count++;
}
void List::Del()
{

    if (Count == 0)
    {
        cout << "The list is empty. Nothing to delete." << endl;
        return;
    }

    Elem* Del = Head;
    Head = Head->next;

    if (Count == 1)
    {
        Tail = nullptr;
    }

    delete Del;
    Count--;
}
void List::Print()
{
    if (Count != 0)
    {
        Elem* temp = Head;
        cout << "( ";
        while (temp->next != 0)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }

        cout << temp->data << " )\n";
    }
}
void List::DelAll()
{
    while (Count != 0)
    {
        Del();
    }
}
int List::GetCount()
{
    return Count;
}
List& List::operator = (const List& L)
{
    if (this == &L)
        return *this;

    this->~List();

    Elem* temp = L.Head;

    while (temp != 0)
    {
        Add(temp->data);
        temp = temp->next;
    }

    return *this;
}
List List::operator + (const List& L)
{
    List Result(*this);

    Elem* temp = L.Head;

    while (temp != 0)
    {
        Result.Add(temp->data);
        temp = temp->next;
    }

    return Result;
}
bool List::operator == (const List& L)
{
    if (Count != L.Count)
    {
        return false;
    }

    Elem* t1, * t2;

    t1 = Head;
    t2 = L.Head;

    while (t1 != 0)
    {
        if (t1->data != t2->data)
        {
            return false;
        }
        t1 = t1->next;
        t2 = t2->next;
    }

    return true;
}
bool List::operator != (const List& L)
{

    return !(*this == L);
}
bool List::operator >= (const List& L)
{
    if (Count > L.Count)
        return true;
    if (*this == L)
        return true;

    return false;
}
bool List::operator <= (const List& L)
{
    if (Count < L.Count)
        return true;
    if (*this == L)
        return true;

    return false;
}
bool List::operator > (const List& L)
{
    if (Count > L.Count)
        return true;

    return false;
}
bool List::operator < (const List& L)
{
    if (Count < L.Count)
        return true;

    return false;
}

void main()
{
    List L;
    const int n = 10;
    int a[n] = { 0,1,2,3,4,5,6,7,8,9 };

    for (int i = 0; i < n; i++)
    {
        L.Add(a[i]);
    }

    cout << "List L:\n";
    L.Print();

    cout << endl;
    cout << "Add\n";
    L.Add(10);
    L.Print();
    cout << "Delete\n";
    L.Del();
    L.Print();
    cout << "Delete\n";
    L.Del();
    L.Print();
}

