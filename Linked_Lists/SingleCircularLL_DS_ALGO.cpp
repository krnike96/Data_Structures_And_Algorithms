#include <iostream>
#include <string>

using namespace std;

namespace SCLL
{
    struct data
    {
        string name;
        int age;
    };
    struct node
    {
        data user;
        node *next;
    };
    node *createNode()
    {
        node *nn = new (std::nothrow) node;
        if (!nn)
        {
            std::cerr << "Memory allocation failed!" << std::endl; // Handle the error
        }
        else
            return nn;
    }
}

void insertFirst(node **head, string name, int age, int sly);
void insertLast(node **head, string name, int age, int sly);
void insertPos(node **head, string name, int age, int sly, int pos);
void deleteFirst(node **head, string name, int age, int sly);
void deleteLast(node **head, string name, int age, int sly);
void deletePos(node **head, string name, int age, int sly, int pos);
void updateFirst(node **head, string name, int age, int sly);
void updateLast(node **head, string name, int age, int sly);
void updatePos(node **head, string name, int age, int sly, int pos);
void sort(node **head);
void search(node **head, string name); // Function Overloading
void search(node **head, int age);     // Function Overloading
void search(node **head, int sly);     // Function OVerloading
void display(node **head);
void displayReverse(node **head);

int main()
{
    SCLL::node *head{nullptr};
    int choice, pos, age, sly;
    string name;
    cout << endl
         << "Single Circular LL";
    while (1)
    {
        cout << endl
             << "1.Insert at First";
        cout << endl
             << "2.Insert at Last";
        cout << endl
             << "3.Insert at Specific Position";
        cout << endl
             << "4.Insert at First";
        cout << endl
             << "5.Insert at Last";
        cout << endl
             << "6.Insert at Specific Position";
        cout << endl
             << "7.Insert at First";
        cout << endl
             << "8.Insert at Last";
        cout << endl
             << "9.Insert at Specific Position";
        cout << endl
             << "10.Sort(Elemental)";
        cout << endl
             << "11.Search(Linear)";
        cout << endl
             << "12.Display";
        cout << endl
             << "0.Exit";
        cout << endl
             << "Enter Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << endl
                 << "Enter the User's Name : ";
            getline(cin, name);
            cout << endl
                 << "Enter the User's Age : ";
            cin >> age;
            cout << endl
                 << "Enter the User's Salary : ";
            cin >> sly;
            insertFirst(&head, name, age, sly);
            display(&head);
            break;
        default:
            cout << endl
                 << "Error - 400 : Bad Behaviour";
            break;
        }
    }
    return 0;
}