#include <iostream>
#include <string>

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

void insertFirst(DCLL::node **head,DCLL::node **tail, string name, int age){
     DCLL::node * nn = DCLL::createNode();
     nn->user->name = name;
     nn->user->age = age;
     if(*head == nullptr){
         nn->next = nn;
         nn->prev = nn;
         *head = nn;
         *tail = nn;
     }else{
         nn->next = *head;
         (*head)->prev = nn;
         nn->prev = *tail;
          (*tail)->next = nn;
          *head = nn;
     }
     nCount++;
}
void insertLast(DCLL::node **head,DCLL::node **tail, string name, int age){
     if(*head == nullptr || *tail == nullptr){
          insertFirst(head,tail,name,age);
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
// void insertPos(DCLL::node **head, string name, int age, int pos);
// void deleteFirst(DCLL::node **head, string name, int age);
// void deleteLast(DCLL::node **head, string name, int age);
// void deletePos(DCLL::node **head, string name, int age, int pos);
// void updateFirst(DCLL::node **head, string name, int age);
// void updateLast(DCLL::node **head, string name, int age);
// void updatePos(DCLL::node **head, string name, int age, int pos);
// void sort(DCLL::node **head);
// void search(DCLL::node **head, string name); // Function Overloading
// void search(DCLL::node **head, int age);     // Function Overloading
// void search(DCLL::node **head);     // Function OVerloading
void display(DCLL::node **head,DCLL::node **tail){
     if(*head == nullptr){
          cerr<<"The list is empty!";
          return;
     }
     DCLL::node *temp = *head;
     cout<<"Head->";
     while(true){
          cout<<"("<<temp->user->name<<"-"<<temp->user->age<<")->";
          temp = temp->next;
          if(temp == *head) break;
     }
     cout<<"Tail"<<endl;
     cout<<"Nodes : "<<nCount;
}
// void displayReverse(DCLL::node **head);

int main()
{
     DCLL::node *head{nullptr};
     DCLL::node *tail{nullptr};
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
               << "0.Exit";
          cout << endl
               << "Enter Your Choice : ";
          cin >> choice;
          switch (choice)
          {
          case 1:
               cout << endl
                    << "Enter the User's Name : ";
               cin>>name;
               cout << endl
                    << "Enter the User's Age : ";
               cin >> age;
               insertFirst(&head, &tail, name, age);
               display(&head,&tail);
               break;
          case 2:
               cout << endl
                    << "Enter the User's Name : ";
               cin>>name;
               cout << endl
                    << "Enter the User's Age : ";
               cin >> age;
               insertLast(&head, &tail, name, age);
               display(&head,&tail);
               break;
          case 0:
               cout<<endl<<"Exiting...";
               return 0;
          default:
               cout << endl
                    << "Error - 400 : Bad Behaviour";
               break;
          }
     }
     return 0;
}