// Head & Tail Approach
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int nCount = 0;
namespace DCLL
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
          node *prev;
     };
     node *createNode()
     {
          node *nn = new (std::nothrow) node;
          if (!nn)
          {
               std::cerr << "Memory allocation failed!" << std::endl; // Handle the error
          }
          nn->user = new (std::nothrow) data;
          if (!nn->user)
          {
               std::cerr << "Memory Allocation Failed" << std::endl;
               return nullptr;
          }
          nn->next = nullptr;
          nn->prev = nullptr;
          return nn;
     }
}

void insertFirst(DCLL::node **head, DCLL::node **tail, string name, int age)
{
     DCLL::node *nn = DCLL::createNode();
     nn->user->name = name;
     nn->user->age = age;
     if (*head == nullptr)
     {
          nn->next = nn;
          nn->prev = nn;
          *head = nn;
          *tail = nn;
     }
     else
     {
          nn->next = *head;
          (*head)->prev = nn;
          nn->prev = *tail;
          (*tail)->next = nn;
          *head = nn;
     }
     nCount++;
}
void insertLast(DCLL::node **head, DCLL::node **tail, string name, int age)
{
     if (*head == nullptr || *tail == nullptr)
     {
          insertFirst(head, tail, name, age);
          return;
     }
     DCLL::node *nn = DCLL::createNode();
     nn->user->name = name;
     nn->user->age = age;
     nn->prev = *tail;
     (*tail)->next = nn;
     *tail = nn;
     nn->next = *head;
     nCount++;
}
void insertPos(DCLL::node **head, DCLL::node **tail, string name, int age, int pos)
{
     if (pos < 1 || pos > nCount + 1)
     {
          cout << "Invalid Position!";
          return;
     }
     if (pos == 1)
     {
          insertFirst(head, tail, name, age);
          return;
     }
     if (pos == nCount + 1)
     {
          insertLast(head, tail, name, age);
          return;
     }
     DCLL::node *temp = *head;
     for (int i = 1; i < pos - 1; i++)
     {
          temp = temp->next;
     }
     DCLL::node *nn = DCLL::createNode();
     nn->user->name = name;
     nn->user->age = age;
     nn->next = temp->next;
     nn->prev = temp;
     temp->next->prev = nn;
     temp->next = nn;
     nCount++;
}
void deleteFirst(DCLL::node **head, DCLL::node **tail)
{
     if (*head == nullptr || *tail == nullptr)
     {
          return;
     }
     if((*head)->next == *tail){
          delete *head;
          *head = nullptr;
          nCount--;
          return;
     }
     (*head)->next->prev = *tail;
     (*tail)->next = (*head)->next;
     delete *head;
     *head = (*tail)->next;
     nCount--;
}
void deleteLast(DCLL::node **head,DCLL::node **tail){
     if(*head == nullptr){
          return;
     }
     if((*head)->next == *head){
          delete *head;
          *head = nullptr;
          nCount--;
          return;
     }
     DCLL::node *temp = *tail;
     *tail = (*tail)->prev;
     (*tail)->next = *head;
     (*head)->prev = *tail;
     delete temp;
     temp = nullptr;
     nCount--;
}
void deletePos(DCLL::node **head,DCLL::node **tail, int pos){
     if(pos < 1 || pos > nCount){
          cout<<"Invalid Position!";
          return;
     }
     if(pos == 1){
          deleteFirst(head,tail);
          return;
     }
     if(pos == nCount){
          deleteLast(head,tail);
          return;
     }
     DCLL::node *temp = *head;
     for(int i = 1; i < pos - 1; i++){
          temp = temp->next;
     }
     DCLL::node *temp1 = temp->next->next;
     delete temp->next;
     temp->next = temp1;
     temp1->prev = temp;
     nCount--;
}
void update(DCLL::node **head,DCLL::node **tail, string name, int age, int pos){
     if(*head == nullptr){
          return;
     }
     if(pos < 1 || pos > nCount){
          cout<<"Invalid Operation! ";
          return;
     }
     int currPos = 0;
     DCLL::node *temp = *head;
     while(true){
          currPos++;
          if(pos == currPos){
               temp->user->name = name;
               temp->user->age = age;
               return;
          }
          if(temp == *tail) break;
          temp = temp->next;
     }
     cout<<"Invalid Operation! ";
}
// void sort(DCLL::node **head);
// void search(DCLL::node **head, string name); // Function Overloading
// void search(DCLL::node **head, int age);     // Function Overloading
void display(DCLL::node **head, DCLL::node **tail)
{
     if (*head == nullptr)
     {
          cerr << "The list is empty!";
          return;
     }
     DCLL::node *temp = *head;
     cout << "Head->";
     while (true)
     {
          cout << "(" << temp->user->name << "-" << temp->user->age << ")->";
          temp = temp->next;
          if (temp == *head)
               break;
     }
     cout << "Tail" << endl;
     cout << "Nodes : " << nCount;
}
// void displayReverse(DCLL::node **head);

int main()
{
     ifstream inputFile("DCLL_input.txt");
     if(!inputFile.is_open()){
          cerr<<"Unable to open the input file!";
          return 1;
     }
     DCLL::node *head{nullptr};
     DCLL::node *tail{nullptr};
     int choice, pos, age;
     string name;
     cout << endl
          << "Single Circular LL"<<endl;
     while(inputFile >> choice){
          switch(choice){
               case 1:
                    inputFile >> name >> age;
                    insertFirst(&head,&tail,name,age);
                    break;
               case 2:
                    inputFile >> name >>age;
                    insertLast(&head,&tail,name,age);
                    break;
               case 3:
                    inputFile >>pos>> name >> age;
                    insertPos(&head,&tail,name,age,pos);
                    break;
               case 4:
                    display(&head,&tail);
                    break;
               default:
                    cerr<<"Error taking input from file!";
                    break;
          }
     }
     while (true)
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
               << "7.Update at Specific Position";
          cout << endl
               << "8.Sort(Elemental)";
          cout << endl
               << "9.Search(Linear)";
          cout << endl
               << "10.Display";
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
               insertFirst(&head, &tail, name, age);
               display(&head, &tail);
               break;
          case 2:
               cout << endl
                    << "Enter the User's Name : ";
               cin >> name;
               cout << endl
                    << "Enter the User's Age : ";
               cin >> age;
               insertLast(&head, &tail, name, age);
               display(&head, &tail);
               break;
          case 3:
               cout << "Enter the Position : ";
               cin >> pos;
               cout << endl
                    << "Enter the User's Name : ";
               cin >> name;
               cout << endl
                    << "Enter the User's Age : ";
               cin >> age;
               insertPos(&head, &tail, name, age, pos);
               display(&head, &tail);
               break;
          case 4:
               deleteFirst(&head, &tail);
               display(&head, &tail);
               break;
          case 5:
               deleteLast(&head,&tail);
               display(&head,&tail);
               break;
          case 6:
               cout<<"Enter the Position : ";
               cin>>pos;
               deletePos(&head,&tail,pos);
               display(&head,&tail);
               break;
          case 7:
               cout<<"Enter the Position : ";
               cin>>pos;
               cout<<"Enter the name : ";
               cin>>name;
               cout<<"Enter the age : ";
               cin>> age;
               update(&head,&tail,name,age,pos);
               display(&head,&tail);
               break;
          case 10:
               display(&head,&tail);
               break;
          case 0:
               cout << endl
                    << "Exiting...";
               delete head;
               delete tail;
               head = nullptr;
               tail = nullptr;
               return 0;
          default:
               cout << endl
                    << "Error - 400 : Bad Behaviour";
               break;
          }
     }
     return 0;
}