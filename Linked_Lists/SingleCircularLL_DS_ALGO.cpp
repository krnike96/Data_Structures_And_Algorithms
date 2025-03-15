#include <iostream>
#include <string>
#include <fstream>

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
          cerr << "Invalid Position!";
          return;
     }
     if (pos == 1)
     {
          insertFirst(head, name, age);
          return;
     }
     SCLL::node *temp = *head;
     for (int i = 1; i < pos - 1; i++)
     {
          temp = temp->next;
     }
     SCLL::node *nn = SCLL::createNode();
     nn->user->name = name;
     nn->user->age = age;
     nn->next = temp->next;
     temp->next = nn;
     nCount++;
}
void deleteFirst(SCLL::node **head)
{
     if (*head == nullptr)
     {
          cerr << "Invalid Operation!";
          return;
     }
     SCLL::node *temp = *head;
     if (temp->next == *head)
     {
          delete *head;
          *head = nullptr;
          nCount--;
          return;
     }
     SCLL::node *temp1 = *head;
     *head = temp->next;
     while (temp->next != temp1)
     {
          temp = temp->next;
     }
     temp->next = *head;
     delete temp1;
     temp1 = nullptr;
     nCount--;
}
void deleteLast(SCLL::node **head)
{
     if (*head == nullptr)
     {
          cerr << "Invalid Operation!";
          return;
     }
     SCLL::node *temp = *head;
     if (temp->next == *head)
     {
          delete *head;
          *head = nullptr;
          nCount--;
          return;
     }
     while (temp->next->next != *head)
     {
          temp = temp->next;
     }
     SCLL::node *temp1 = temp->next;
     temp->next = *head;
     delete temp1;
     temp1 = nullptr;
     nCount--;
}
void deletePos(SCLL::node **head, int pos)
{
     if (*head == nullptr || pos < 1 || pos > nCount)
     {
          cerr << "Invalid Operation!";
          return;
     }
     if (pos == 1)
     {
          deleteFirst(head);
          return;
     }
     SCLL::node *temp = *head;
     for (int i = 1; i < pos - 1; i++)
     {
          temp = temp->next;
     }
     SCLL::node *temp1 = temp->next;
     temp->next = temp->next->next;
     delete temp1;
     temp1 = nullptr;
     nCount--;
}
void updateFirst(SCLL::node **head, string name, int age)
{
     if (*head == nullptr)
     {
          cerr << "Invalid Operation!";
          return;
     }
     (*head)->user->name = name;
     (*head)->user->age = age;
}
void updateLast(SCLL::node **head, string name, int age)
{
     if (*head == nullptr)
     {
          cerr << "Invalid Operation!";
          return;
     }
     SCLL::node *temp = *head;
     while (temp->next != *head)
     {
          temp = temp->next;
     }
     temp->user->name = name;
     temp->user->age = age;
}
void updatePos(SCLL::node **head, string name, int age, int pos)
{
     if (*head == nullptr)
     {
          cerr << "Invalid Operation!";
          return;
     }
     if (pos < 1 || pos > nCount)
     {
          cerr << "Invalid Operation!";
          return;
     }
     if (pos == 1)
     {
          updateFirst(head, name, age);
          return;
     }
     int currPos = 0;
     SCLL::node *temp = *head;
     while (true)
     {
          currPos++;
          if (pos == currPos)
          {
               temp->user->name = name;
               temp->user->age = age;
               return;
          }
          temp = temp->next;
     }
     cerr << "Invalid Operation!";
}
void bubbleSortByAge(SCLL::node **head){
     if(*head == nullptr){
          cerr<<"Invalid Operation!";
          return;
     }
     SCLL::node *temp;
     SCLL::node *end= *head;
     bool swap = true;
     while(swap){
          swap = false;
          temp = *head;
          while(temp->next != end){
               if(temp->user->age > temp->next->user->age){
                    temp->user->age ^= temp->next->user->age ^= temp->user->age ^= temp->next->user->age;
                    string temp0 = temp->user->name;
                    temp->user->name = temp->next->user->name;
                    temp->next->user->name = temp0;
                    swap = true;
               }
               temp = temp->next;
          }
          end = temp;
     }
}
void bubbleSortByName(SCLL::node **head){
     if(*head == nullptr){
          cerr<<"Invalid Operation!";
          return;
     }
     SCLL::node *temp;
     SCLL::node *end= *head;
     bool swap = true;
     while(swap){
          swap = false;
          temp = *head;
          while(temp->next != end){
               if(temp->user->name > temp->next->user->name){
                    temp->user->age ^= temp->next->user->age ^= temp->user->age ^= temp->next->user->age;
                    string temp0 = temp->user->name;
                    temp->user->name = temp->next->user->name;
                    temp->next->user->name = temp0;
                    swap = true;
               }
               temp = temp->next;
          }
          end = temp;
     }
}
void search(SCLL::node **head, string name){  // Function Overloading
     if(*head == nullptr){
          cerr<<"Invalid Operation!";
          return;
     }
     SCLL::node *temp = *head;
     int pos;
     while(temp->next != *head){
          pos++;
          if(name == temp->user->name){
               cout<<"The Node : ("<<temp->user->name<<"-"<<temp->user->age<<")"<<endl;
               cout<<"The Name is Found at Position : "<< pos;
               return;
          }
          temp = temp->next;
     }
     cout<<"Name Data not Found!";
}
void search(SCLL::node **head, int age){    // Function Overloading
     if(*head == nullptr){
          cerr<<"Invalid Operation!";
          return;
     }
     SCLL::node *temp = *head;
     int pos;
     while(temp->next != *head){
          pos++;
          if(age == temp->user->age){
               cout<<"The Node : ("<<temp->user->name<<"-"<<temp->user->age<<")"<<endl;
               cout<<"The Age is Found at Position : "<< pos;
               return;
          }
          temp = temp->next;
     }
     cout<<"Age Data not Found!";
}   
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
     ifstream inputFile("input.txt"); // opening a input text file for automatic input ,saves time
     if (!inputFile.is_open())
     {
          cerr << "Unable to open the file!";
          return 1;
     }
     SCLL::node *head{nullptr};
     int choice, pos, age;
     string name;
     cout << endl
          << "Single Circular LL";
     while (inputFile >> choice)
     { // Taking input from input.txt file
          switch (choice)
          {
          case 1:
               inputFile >> name >> age;
               insertFirst(&head, name, age);
               break;
          case 2:
               inputFile >> name >> age;
               insertLast(&head, name, age);
               break;
          case 3:
               inputFile >> pos >> name >> age;
               insertPos(&head, name, age, pos);
               break;
          case 4:
               display(&head);
               break;
          default:
               cerr << "Invalid Input From File!";
               break;
          }
     }
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
               << "10.Sort(By Age)";
          cout << endl
               << "11.Sort(By Name)";
          cout << endl
               << "12.Search(By Age)";
          cout << endl
               << "13.Search(By Name)";
          cout << endl
               << "14.Display";
          cout << endl
               << "15.Reverse Display";
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
                    << "Enter the Name : ";
               cin >> name;
               cout << endl
                    << "Enter the Age : ";
               cin >> age;
               insertPos(&head, name, age, pos);
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
          case 6:
               cout << "Enter the Position : ";
               cin >> pos;
               deletePos(&head, pos);
               display(&head);
               break;
          case 7:
               cout << "Enter the Name : ";
               cin >> name;
               cout << "Enter the Age : ";
               cin >> age;
               updateFirst(&head, name, age);
               display(&head);
               break;
          case 8:
               cout << "Enter the Name : ";
               cin >> name;
               cout << "Enter the Age : ";
               cin >> age;
               updateLast(&head, name, age);
               display(&head);
               break;
          case 9:
               cout << "Enter the Position : ";
               cin >> pos;
               cout << "Enter the Name : ";
               cin >> name;
               cout << "Enter the Age : ";
               cin >> age;
               updatePos(&head, name, age, pos);
               display(&head);
               break;
          case 10:
               bubbleSortByAge(&head);
               display(&head);
               break;
          case 11:
               bubbleSortByName(&head);
               display(&head);
               break;
          case 12:
               cout<<"Enter the Age : ";
               cin>>age;
               search(&head,age);
               break;
          case 13:
               cout<<"Enter the Name : ";
               cin>>name;
               search(&head,name);
               break;
          case 14:
               display(&head);
               break;
          case 0:
               cout << "Exiting...";
               return 0;
          default:
               cerr << endl
                    << "Error - 400 : Bad Behaviour";
               break;
          }
     }
     return 0;
}