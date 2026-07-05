#include <iostream>
#include <cstring>

using namespace std;

int getLength(char ch[])
{
    int count = 0;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void reverseString(char ch[])
{
    int s = 0;
    int e = strlen(ch) - 1;

    while (s <= e)
    {
        swap(ch[s++], ch[e--]);
    }
}

char doLowerCase(char ch)
{

    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
bool isPalindrome(char ch[])
{
    int s = 0;
    int e = strlen(ch) - 1;
    while (s <= e)
    {
        while (s < e && !isalnum(static_cast<unsigned char>(ch[s])))
        {
            s++;
        }

        while (s < e && !isalnum(static_cast<unsigned char>(ch[e])))
        {
            e--;
        }

        if (doLowerCase(ch[s]) != doLowerCase(ch[e]))
        {
            return false;
        }

        s++;
        e--;
    }
    return true;
}

int main()
{
    char name[20];

    cout << "Enter Your Name: ";
    cin >> name;

    cout << "Your Name is: ";
    cout << name << endl;

    cout << "Length of Name is: " << getLength(name) << endl;
    reverseString(name);
    cout << "Reverse Of Your Name is: " << name << endl;
    cout << "Is your Name Palindrome or not(1 for yes, 0 for no): " << isPalindrome(name) << endl;
}