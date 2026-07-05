#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class StackImplUsingArray
{
public:
    int front = -1;
    int st[10]; M

    StackImplUsingArray()
    {
    }

    void push(int x)
    {

        if (front >= 9)
            cout << "No more Values can be Inserted\n";
            return -1;

        front += 1;
        st[front] = x;
    }

    int pop()
    {
        if (front == -1)
        {
            cout << "No pre-existing value to be deleted\n";
            return -1;
        }

        int val = st[front];
        front--;

        return val;
    }

    int top()
    {
        if (front == -1)
        {
            cout << "No pre-existing value there\n";
            return -1;
        }

        return st[front];
    }

    int size()
    {
        return front + 1;
    }
};

class StackImplUsingLL
{
public:
    ListNode *head;
    int ss = 0;

    StackImplUsingLL() : head(nullptr), ss(0) {}

    void push(int x)
    {
        ListNode *temp = new ListNode(x);
        temp->next = head;
        head = temp;
        temp->val = x;
        ss += 1;
    }

    int pop()
    {
        int val = head->val;

        ListNode *temp = head;
        head = head->next;

        delete (temp);
        ss -= 1;

        return val;
    }

    int top()
    {

        if (head != NULL)
        {
            return head->val;
        }
        return 0;
    }

    int size()
    {

        return ss;
    }
};

class StackImplUsingQueue
{
public:
    queue<int> q;

    StackImplUsingQueue()
    {
    }

    void push(int x)
    {

        int s = q.size();
        q.push(x);

        for (int i = 1; i <= s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {

        int val = q.front();

        q.pop();

        return val;
    }

    int top()
    {

        return q.front();
    }

    int size()
    {

        return q.size();
    }
};

template <typename StackType>
void StackFunction(StackType &s)
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
            cout << "Size of Stack is: " << ss;
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

void MenuForStack()
{

    while (1)
    {
        int n;
        cout << "Choose Option to check Implementation of Stack\n"
                "1. Implementation of Stack Using Arrays\n"
                "2. Implementation of Stack Using Linked List\n"
                "3. Implementation of Stack Using Queue\n"
                "4. Return to MainMenu\n"
                "Please Enter Your Choice: ";
        cin >> n;

        switch (n)
        {
        case 1:
        {
            StackImplUsingArray s1;
            cout << "--- Implementation of Stack Using Array";
            StackFunction(s1);
            break;
        }

        case 2:
        {
            StackImplUsingLL s2;
            cout << "--- Implementation of Stack Using Linked List";
            StackFunction(s2);
            break;
        }

        case 3:
        {
            StackImplUsingQueue s3;
            cout << "--- Implementation of Stack Using Queue";
            StackFunction(s3);
            break;
        }

        case 4:
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
        MenuForStack();
    }

    return 0;
}