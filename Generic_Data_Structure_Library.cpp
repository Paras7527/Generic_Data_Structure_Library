#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//              Singly Linear Linked List
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct nodeLL
{
    T data;
    struct nodeLL<T> *next;
};

template <class T>
class SinglyLL
{
public:
    struct nodeLL<T> *head;
    int iCount;

    SinglyLL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
    void Display();
    int Count();
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct nodeLL<T> *newn = NULL;

    newn = new nodeLL<T>;
    newn->data = no;
    newn->next = NULL;

    if (head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct nodeLL<T> *newn = NULL;
    struct nodeLL<T> *temp = NULL;

    newn = new nodeLL<T>;
    newn->data = no;
    newn->next = NULL;

    if (head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int ipos)
{
    int i = 0;
    struct nodeLL<T> *newn = NULL;
    struct nodeLL<T> *temp = NULL;

    if ((ipos < 1) || (ipos > iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new nodeLL<T>;
        newn->data = no;
        newn->next = NULL;

        temp = head;

        for (i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeLL<T> *temp = NULL;

    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;

        head = head->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeLL<T> *temp = NULL;

    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int ipos)
{
    int i = 0;
    struct nodeLL<T> *temp = NULL;
    struct nodeLL<T> *target = NULL;

    if ((ipos < 1) || (ipos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = head;

        for (i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        iCount--;
    }
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeLL<T> *temp = head;

    cout << "\nElements of Singly Linear Linked List are : \n";

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//              Singly Circular Linked List
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct nodeCL
{
    T data;
    struct nodeCL<T> *next; 
};

template <class T>
class SinglyCLL
{
public:
    struct nodeCL<T> *head;
    struct nodeCL<T> *tail;
    int iCount;

    SinglyCLL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
    void Display();
    int Count();
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct nodeCL<T> *newn = NULL;
    newn = new nodeCL<T>;
    newn->data = no;
    newn->next = NULL;

    if ((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    tail->next = head;
    iCount++;
}

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct nodeCL<T> *newn = NULL;
    newn = new nodeCL<T>;
    newn->data = no;
    newn->next = NULL;

    if ((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        tail->next = newn;
        tail = newn;
    }
    tail->next = head;
    iCount++;
}

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int ipos)
{
    int i = 0;
    struct nodeCL<T> *newn = NULL;
    struct nodeCL<T> *temp = NULL;
    if ((ipos < 1) || (ipos > iCount + 1))
    {
        printf("Invalid Position\n");
        return;
    }
    else if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new nodeCL<T>;
        newn->data = no;
        newn->next = NULL;

        temp = head;

        for (i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    struct nodeCL<T> *temp = NULL;
    if ((head == NULL) && (tail == NULL))
    {
        return;
    }
    else if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        delete temp;
        tail->next = head;
    }
    iCount--;
}

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    struct nodeCL<T> *temp = NULL;
    if ((head == NULL) && (tail == NULL))
    {
        return;
    }
    else if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = head;
    }
    iCount--;
}

template <class T>
void SinglyCLL<T>::DeleteAtPos(int ipos)
{
    int i = 0;
    struct nodeCL<T> *temp = NULL;
    struct nodeCL<T> *target = NULL;
    if ((ipos < 1) || (ipos > iCount))
    {
        cout << "Invalid Position\n";
        return;
    }
    else if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        for (i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;

        iCount--;
    }
}

template <class T>
void SinglyCLL<T>::Display()
{
    struct nodeCL<T> *temp = head;
    if (head == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }
    temp = head;
    cout << "\nElements in Singly Circular Linked List :\n";
    do
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    } while (temp != head);
    cout << "\n";
}

template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//              Doubly Linear Linked List
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct nodeDLL
{
    T data;
    struct nodeDLL <T>*next;
    struct nodeDLL <T>*prev;
};

template <class T>
class DoublyLL
{
public:
    int iCount;
    struct nodeDLL<T> *head;

    DoublyLL();
    void Display();

    void InsertFirst(T no);
    void InsertLast(T no);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
    int Count();
    void InsertAtPos(T no, int ipos);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>:: Display()
{
    struct nodeDLL<T> *temp = head;

    cout << "\nElements in Doubly Linear Linked List:\n";
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|<->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
void DoublyLL<T>:: InsertFirst(T no)
{
    struct nodeDLL<T> *newn = NULL;
    newn = new nodeDLL<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (head == NULL) // List is empty
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>:: InsertLast(T no)
{
    struct nodeDLL<T> *newn = NULL;
    struct nodeDLL<T> *temp = NULL;
    newn = new nodeDLL<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (head == NULL) 
    {
        head = newn;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>:: DeleteFirst()
{
    struct nodeDLL<T> *temp = NULL;
    if (head == NULL) // List is empty
    {
        return;
    }
    else if (head->next == NULL) // Only one element
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>:: DeleteLast()
{
    struct nodeDLL<T> *temp = NULL;
    if (head == NULL) 
    {
        return;
    }
    else if (head->next == NULL) 
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>:: DeleteAtPos(int ipos)
{
    int i = 0;
    struct nodeDLL<T> *temp = NULL;
    struct nodeDLL<T> *target = NULL;
    if (ipos < 1 || ipos > iCount)
    {
        cout << "Invalid position!\n";
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = head;
        for (i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }

        target = NULL;
        target=temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete target;

        iCount--;
    }
}

template <class T>
int DoublyLL<T>:: Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>:: InsertAtPos(T no, int ipos)
{
    int i = 0;
    struct nodeDLL<T> *newn = NULL;
    struct nodeDLL<T> *temp = NULL;
    if (ipos < 1 || ipos > iCount + 1)
    {
        cout << "Invalid position!\n";
        return;
    }
    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new nodeDLL<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = head;
        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//              Doubly Circular Linked List
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct nodeDCL
{
    T data;
    struct nodeDCL<T> *next;
    struct nodeDCL<T> *prev;
};

template <class T>
class DoublyCLL
{
    public:
        struct nodeDCL<T> *head;
        struct nodeDCL<T> *tail;
        int iCount;

        DoublyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}

template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    struct nodeDCL<T> *newn = NULL;
    newn = new nodeDCL<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    tail->next = head;
    head->prev = tail;
    iCount++;
}

template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    struct nodeDCL<T> *newn = NULL;

    newn = new nodeDCL<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        tail->next = newn;
        newn->prev = tail;
        tail = newn;
    }
    tail->next = head;
    head->prev = tail;

    iCount++;
}

template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int ipos)
{
    int i = 0;
    struct nodeDCL<T> *newn = NULL;
    struct nodeDCL<T> *temp = NULL;
    if ((ipos < 1) || (ipos > iCount + 1))
    {
        cout << "Invalid Position\n";
        return;
    }
    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new nodeDCL<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = head;
        for (i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    struct nodeDCL<T> *temp = NULL;
    if ((head == NULL) && (tail == NULL))
    {
        return;
    }
    else if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        delete temp;

        tail->next = head;
        head->prev = tail;
    }
    iCount--;
}

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    struct nodeDCL<T> *temp = NULL;
    if ((head == NULL) && (tail == NULL))
    {
        return;
    }
    else if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        temp = tail;
        tail = tail->prev;
        delete temp;

        tail->next = head;
        head->prev = tail;
    }
    iCount--;
}

template <class T>
void DoublyCLL<T>::DeleteAtPos(int ipos)
{
    int i = 0;
    struct nodeDCL<T> *temp = NULL;
    struct nodeDCL<T> *target = NULL;

    if ((ipos < 1) || (ipos > iCount))
    {
        cout << "Invalid Position\n";
        return;
    }
    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = head;
        for (i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;

        delete target;
        iCount--;
    }
}

template <class T>
void DoublyCLL<T>::Display()
{

    struct nodeDCL<T> *temp = NULL;
    temp = NULL;
    if (head == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }
    temp = head;
    cout << "\nElements in Doubly Circular Linked List :\n";
    do
    {
        cout << "|" << temp->data << "|<=>";
        temp = temp->next;
    } while (temp != head);
    cout << "\n";
}

template <class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//              Stack
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct nodeS
{
    int data;
    struct nodeS <T>*next;
};

template <class T>
class Stack
{
public:
    struct nodeS<T> *head;
    int iCount;

    Stack();
    void push(T no);
    int pop();
    void Display();
    int Count();
};

template <class T>
Stack<T>::Stack()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void Stack<T>::push(T no)
{
    struct nodeS<T> *newn = NULL;
    newn = new nodeS<T>;
    newn->data = no;
    newn->next = head;
    head = newn;
    iCount++;
}

template <class T>
int Stack<T>::pop()
{
    struct nodeS<T> *temp = NULL;
    if (head == NULL)
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }

    T no = head->data;
    temp = head;
    head = head->next;
    delete temp;
    iCount--;
    return no;
}

template <class T>
void Stack<T>::Display()
{
    struct nodeS<T> *temp = NULL;
    temp = head;
    cout << "Elements in the Stack:" << endl;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|" << endl;
        temp = temp->next;
    }
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//              Queue
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct nodeQ
{
    int data;
    struct nodeQ<T> *next;
};

template <class T>
class Queue
{
public:
    struct nodeQ<T> *head;
    int iCount;

    Queue();
    void enqueue(T no);
    int dequeue();
    void Display();
    int Count();
};

template <class T>
Queue<T>::Queue()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void Queue<T>::enqueue(T no) // InsertLast
{
    struct nodeQ<T> *newn = NULL;
    struct nodeQ<T> *temp = NULL;
    newn = new nodeQ<T>;
    newn->data = no;
    newn->next = NULL;

    if (head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
int Queue<T>::dequeue() // DeleteFirst
{
    T no = -1;
    struct nodeQ<T> *temp = NULL;
    if (head == NULL)
    {
        cout << "Queue is empty\n";
        return -1;
    }
    else
    {
        no = head->data;
        temp = head;
        head = head->next;
        delete temp;
    }
    iCount--;
    return no;
}

template <class T>
void Queue<T>::Display()
{
    struct nodeQ<T> *temp = NULL;
    cout << "\nElements of queue are : \n";
    temp = head;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |\n";
        temp = temp->next;
    }
}

template <class T>
int Queue<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//              Main Function
////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    SinglyLL <int>obj1;
    SinglyCLL <int>obj2;
    DoublyLL <int>obj3;
    DoublyCLL <int>obj4;
    Stack <int>obj5;
    Queue <int>obj6;

    int iRet=0;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.InsertLast(121);
    obj1.Display();
    iRet=obj1.Count();
    cout<<"Number of Elements in the Singly Linear Linked List:"<<iRet;


    obj2.InsertFirst(51);
    obj2.InsertFirst(21);
    obj2.InsertFirst(11);

    obj2.InsertLast(101);
    obj2.InsertLast(111);
    obj2.InsertLast(121);
    obj2.Display();
    iRet=obj2.Count();
    cout<<"Number of Elements in the Doubly Linear Linked List:"<<iRet;

    obj3.InsertFirst(51);
    obj3.InsertFirst(21);
    obj3.InsertFirst(11);

    obj3.InsertLast(101);
    obj3.InsertLast(111);
    obj3.InsertLast(121);
    obj3.Display();
    iRet=obj3.Count();
    cout<<"Number of Elements in the Singly Circular Linked List:"<<iRet;

    obj4.InsertFirst(51);
    obj4.InsertFirst(21);
    obj4.InsertFirst(11);

    obj4.InsertLast(101);
    obj4.InsertLast(111);
    obj4.InsertLast(121);
    obj4.Display();
    iRet=obj4.Count();
    cout<<"Number of Elements in the Doubly Linked List:"<<iRet;

    obj5.push(11);
    obj5.push(21);
    obj5.push(51);
    obj5.push(101);
    obj5.push(111);
    obj5.push(121);
    obj5.Display();
    iRet=obj5.Count();
    cout<<"Number of Elements in the Stack:"<<iRet;
    
    obj6.enqueue(11);
    obj6.enqueue(21);
    obj6.enqueue(51);
    obj6.enqueue(101);
    obj6.enqueue(111);
    obj6.enqueue(121);
    obj6.Display();
    iRet=obj5.Count();
    cout<<"Number of Elements in the Queue:"<<iRet;
    return 0;
}