#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class QueueImplUsingArray
{
public:
    int qs = 10;
    int q[10];
    int curSize = 0;
    int start = -1, end = -1;

    QueueImplUsingArray()
    {
    }

    void push(int x)
    {

        if (curSize == qs)
        {
            cout << "No More Space to insert Data\n";
            return;
        }

        if (curSize == 0)
        {
            start = 0;
            end = 0;
        }

        else
        {
            end = (end + 1) % qs;
        }

        q[end] = x;
        curSize += 1;
    }

    int pop()
    {
        if (curSize == 0)
        {
            cout << "Queue is Already Empty\n";
            return -1;
        }

        int el = q[start];

        if (curSize == 1)
        {
            start = -1;
            end = -1;
        }

        else
        {
            start = (start + 1) % qs;
        }

        curSize -= 1;
        return el;
    }

    int top()
    {
        if (curSize == 0)
        {
            cout << "Queue is Already Empty\n";
            return -1;
        }

        return q[start];
    }

    int size()
    {
        return curSize;
    }
};

class QueueImplUsingLL
{
public:
    ListNode *start, *end;
    int ss = 0;

    QueueImplUsingLL() : start(nullptr), end(nullptr), ss(0) {}

    void push(int x)
    {

        ListNode *temp = new ListNode(x);
        temp->val = x;

        if (start == NULL && end == NULL)
        {
            start = end = temp;
        }

        else
        {
            end->next = temp;
            temp->next = NULL;
            end = temp;
        }
        ss += 1;
    }

    int pop()
    {

        if (start == NULL)
        {
            cout << "Queue is Already Empty\n";
            return -1;
        }

        ListNode *temp = start;

        int el = start->val;
        start = start->next;
        delete (temp);

        ss -= 1;

        return el;
    }

    int top()
    {

        if (start != NULL)
        {
            return start->val;
        }
        return -1;
    }

    int size()
    {
        return ss;
    }
};

class QueueImplUsingStack1
{
public:
    stack<int> s1, s2;

    QueueImplUsingStack1()
    {
    }

    void push(int x)
    {
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {

        if (s1.empty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }

        int el = s1.top();

        s1.pop();

        return el;
    }

    int top()
    {
        if (s1.empty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }

        return s1.top();
    }

    int size()
    {
        return s1.size();
    }
};

class QueueImplUsingStack2
{
public:
    stack<int> s1, s2;

    QueueImplUsingStack2()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int el;

        if (s1.empty() && s2.empty())
        {
            cout << "Queue is Already Empty\n";
            return -1;
        }

        if (s2.empty())
            while (s1.size())
                s2.push(s1.top()), s1.pop();

        int x = s2.top();
        s2.pop();
        return x;
    }

    int top()
    {
        if (s2.empty())
            while (s1.size())
                s2.push(s1.top()), s1.pop();
        return s2.top();
    }

    int size()
    {

        int el1 = s1.size();
        int el2 = s2.size();

        return el1 + el2;
    }
};

template <typename QueueType>
void QueueFunction(QueueType &s)
{

    while (1)
    {
        int n;

        cout << "Choose the operation you want to perform on the Stack\n"
                "1. push()\n"
                "2. pop()\n"
                "3. top()\n"
                "4. size()\n"
                "5. Return to MainMenu\n"
                "Please Enter Your Choice: ";

        cin >> n;

        switch (n)
        {
        case 1:
        {
            int val1;
            cout << "Enter Value for push: ";
            cin >> val1;
            s.push(val1);
            break;
        }

        case 2:
        {
            int val2 = s.pop();
            cout << "Valued popped is: " << val2 << endl;
            break;
        }

        case 3:
        {
            int val3 = s.top();
            cout << "Top Value is: " << val3 << endl;
            break;
        }

        case 4:
        {
            int ss = s.size();
            cout << "Size of Stack is: " << ss<<endl;
            break;
        }

        case 5:
        {
            return;
        }

        default:
            break;
        }
    }
}

void MenuForQueue()
{

    while (1)
    {
        int n;
        cout << "Choose Option to check Implementation of Queue\n"
                "1. Implementation of Queue Using Arrays\n"
                "2. Implementation of Queue Using Linked List\n"
                "3. Implementation of Queue Using Stack1\n"
                "4. Implementation of Queue Using Stack2\n"
                "5. Return to MainMenu\n"
                "Please Enter Your Choice: ";
        cin >> n;

        switch (n)
        {
        case 1:
        {
            QueueImplUsingArray s1;
            cout << "--- Implementation of Queue Using Array ";
            QueueFunction(s1);
            break;
        }

        case 2:
        {
            QueueImplUsingLL s2;
            cout << "--- Implementation of Queue Using Linked List ";
            QueueFunction(s2);
            break;
        }

        case 3:
        {
            QueueImplUsingStack1 s3;
            cout << "--- Implementation of Queue Using Stack 1";
            QueueFunction(s3);
            break;
        }

        case 4:
        {
            QueueImplUsingStack2 s4;
            cout << "--- Implementation of Queue Using Stack 2";
            QueueFunction(s4);
            break;
        }

        case 5:
        {
            return;
        }

        default:
            break;
        }
    }
}

int main()
{
    while (1)
    {
        MenuForQueue();
    }

    return 0;
}