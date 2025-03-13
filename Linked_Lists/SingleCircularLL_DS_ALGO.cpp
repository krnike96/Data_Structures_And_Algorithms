#include <iostream>
#include <string>

using namespace std;

int nCount = 0;

namespace SCLL
{
     struct data
     {
          string name;
          int age;
     };
     struct node
     {
          data *user;
          node *next;
     };
     SCLL::node *createNode()
     {
          node *nn = new (std::nothrow) node;
          if (!nn)
          {
               std::cerr << "Memory allocation failed!" << std::endl; // Handle the error
               return nullptr;
          }
          nn->user = new (std::nothrow) data;
          if (!nn->user)
          {
               std::cerr << "Memory Allocation Failed" << std::endl;
               return nullptr;
          }
          return nn;
     }
}

void insertFirst(SCLL::node **head, string name, int age)
{
     SCLL::node *nn = SCLL::createNode();
     nn->user->name = name;
     nn->user->age = age;
     if (*head == nullptr)
     {
          nn->next = nn;
     }
     else
     {
          SCLL::node *LastNode = *head;
          while (LastNode->next != *head)
          {
               LastNode = LastNode->next;
          }
          nn->next = *head;
          LastNode->next = nn;
     }
     *head = nn;
     nCount++;
     return;
}
void insertLast(SCLL::node **head, string name, int age){
     if(*head ==nullptr){
          insertFirst(head,name,age);
          return;
     }
     SCLL::node *nn = SCLL::createNode();
     nn->user->name = name;
     nn->user->age = age;
     SCLL::node *temp = *head;
     while(1){
          temp=temp->next;
          if(temp->next == *head) break;
     }
     temp->next = nn;
     nn->next = *head;
     nCount++;
     return;
}
// void insertPos(node **head, string name, int age, int sly, int pos);
// void deleteFirst(node **head, string name, int age, int sly);
// void deleteLast(node **head, string name, int age, int sly);
// void deletePos(node **head, string name, int age, int sly, int pos);
// void updateFirst(node **head, string name, int age, int sly);
// void updateLast(node **head, string name, int age, int sly);
// void updatePos(node **head, string name, int age, int sly, int pos);
// void sort(node **head);
// void search(node **head, string name); // Function Overloading
// void search(node **head, int age);     // Function Overloading
// void search(node **head, int sly);     // Function OVerloading
void display(SCLL::node **head)
{
     if (*head == nullptr)
     {
          cout << "The List is Empty!" << endl;
          return;
     }
     SCLL::node *temp = *head;
     cout << endl
          << "The List is : ";
     while (true)
     {
          cout << "(" << temp->user->name << "-" << temp->user->age << ")->";
          temp = temp->next;
          if (temp == *head)
               break;
     }
     cout << "Head" << endl;
     cout << "Nodes : " << nCount << endl;
}
// void displayReverse(node **head);

int main()
{
     SCLL::node *head{nullptr};
     int choice, pos, age;
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
               << "13.Reverse Display";
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
               cin >> name;
               cout << endl
                    << "Enter the User's Age : ";
               cin >> age;
               insertFirst(&head, name, age);
               display(&head);
               break;
          case 2:
               cout << endl
                    << "Enter the User's Name : ";
               cin >> name;
               cout << endl
                    << "Enter the User's Age : ";
               cin >> age;
               insertLast(&head, name, age);
               display(&head);
               break;
          case 12:
               display(&head);
               break;
          case 0:
               cout << "Exiting...";
               return 0;
          default:
               cout << endl
                    << "Error - 400 : Bad Behaviour";
               break;
          }
     }
     return 0;
}