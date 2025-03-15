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
void insertLast(SCLL::node **head, string name, int age)
{
     if (*head == nullptr)
     {
          insertFirst(head, name, age);
          return;
     }
     SCLL::node *nn = SCLL::createNode();
     nn->user->name = name;
     nn->user->age = age;
     SCLL::node *temp = *head;
     while (1)
     {
          temp = temp->next;
          if (temp->next == *head)
               break;
     }
     temp->next = nn;
     nn->next = *head;
     nCount++;
     return;
}
void insertPos(SCLL::node **head, string name, int age, int pos)
{
     if (pos < 1 || pos > nCount + 1)
     {
          cout << "Invalid Position!";
          return;
     }
     if (pos == 1)
     {
          insertFirst(head, name, age);
          return;
     }
     SCLL::node *temp = *head;
     for(int i = 1; i < pos - 1; i++){
          temp = temp->next;
     }
     SCLL::node *nn = SCLL::createNode();
     nn->user->name = name;
     nn->user->age = age;
     nn->next = temp->next;
     temp->next = nn;
     nCount++;
}
void deleteFirst(SCLL::node **head){
     if(*head == nullptr){
          cout<<"Invalid Operation!";
          return;
     }
     SCLL::node *temp = *head;
     if(temp->next == *head){
          free(*head);
          *head = nullptr;
          nCount--;
          return;
     }
     while(temp->next != *head){
          temp = temp->next;
     }
     SCLL::node *temp1 = *head;
     temp->next = temp->next->next;
     *head = temp->next->next;
     delete temp1;
     temp1 = nullptr;
     nCount--;
}
void deleteLast(SCLL::node **head){
     if(*head == nullptr){
          cout<<"Invalid Operation!";
          return;
     }
     SCLL::node *temp = *head;
     if(temp->next == *head){
          free(*head);
          *head = nullptr;
          nCount--;
          return;
     }
     while(temp->next->next != *head){
          temp = temp->next;
     }
     SCLL::node *temp1 = temp->next;
     temp->next = *head;
     delete temp1;
     temp1 = nullptr;
     nCount--;
}
// void deletePos(SCLL::node **head, int pos);
// void updateFirst(SCLL::node **head, string name, int age);
// void updateLast(SCLL::node **head, string name, int age);
// void updatePos(SCLL::node **head, string name, int age, int pos);
// void sort(SCLL::node **head);
// void search(SCLL::node **head, string name); // Function Overloading
// void search(SCLL::node **head, int age);     // Function Overloading
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
               << "4.Delete at First";
          cout << endl
               << "5.Delete at Last";
          cout << endl
               << "6.Delete at Specific Position";
          cout << endl
               << "7.Update at First";
          cout << endl
               << "8.Update at Last";
          cout << endl
               << "9.Update at Specific Position";
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
          case 3:
               cout << endl
                    << "Enter the Position : ";
                    cin >> pos;
               cout << endl
                    <<"Enter the Name : ";
                    cin >> name;
               cout << endl
                    << "Enter the Age : ";
                    cin >> age;
               insertPos(&head,name,age,pos);
               display(&head);
               break;
          case 4:
               deleteFirst(&head);
               display(&head);
               break;
          case 5:
               deleteLast(&head);
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