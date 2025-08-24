// Head & Tail Approach - Class Implementation
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class DCLL
{
private:
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
    
    node *head;
    node *tail;
    int nCount;
    
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

public:
    DCLL()
    {
        head = nullptr;
        tail = nullptr;
        nCount = 0;
    }
    
    // Destructor to properly clean up memory
    ~DCLL()
    {
        while (head != nullptr)
        {
            deleteFirst();
        }
    }
    
    void insertFirst(string name, int age)
    {
        node *nn = createNode();
        nn->user->name = name;
        nn->user->age = age;
        if (head == nullptr)
        {
            nn->next = nn;
            nn->prev = nn;
            head = nn;
            tail = nn;
        }
        else
        {
            nn->next = head;
            head->prev = nn;
            nn->prev = tail;
            tail->next = nn;
            head = nn;
        }
        nCount++;
    }
    
    void insertLast(string name, int age)
    {
        if (head == nullptr || tail == nullptr)
        {
            insertFirst(name, age);
            return;
        }
        node *nn = createNode();
        nn->user->name = name;
        nn->user->age = age;
        nn->prev = tail;
        tail->next = nn;
        tail = nn;
        nn->next = head;
        nCount++;
    }
    
    void insertPos(string name, int age, int pos)
    {
        if (pos < 1 || pos > nCount + 1)
        {
            cout << "Invalid Position!";
            return;
        }
        if (pos == 1)
        {
            insertFirst(name, age);
            return;
        }
        if (pos == nCount + 1)
        {
            insertLast(name, age);
            return;
        }
        node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        node *nn = createNode();
        nn->user->name = name;
        nn->user->age = age;
        nn->next = temp->next;
        nn->prev = temp;
        temp->next->prev = nn;
        temp->next = nn;
        nCount++;
    }
    
    void deleteFirst()
    {
        if (head == nullptr)
        {
            return;
        }
        // Single node case
        if (head->next == head)
        {
            delete head->user;  // Fix memory leak
            delete head;
            head = nullptr;
            tail = nullptr;
            nCount--;
            return;
        }
        // Multiple nodes case
        node *temp = head;
        head->next->prev = tail;
        tail->next = head->next;
        head = head->next;
        delete temp->user;  // Fix memory leak
        delete temp;
        nCount--;
    }
    
    void deleteLast()
    {
        if (head == nullptr)
        {
            return;
        }
        // Single node case
        if (head->next == head)
        {
            delete head->user;  // Fix memory leak
            delete head;
            head = nullptr;
            tail = nullptr;
            nCount--;
            return;
        }
        // Multiple nodes case
        node *temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp->user;  // Fix memory leak
        delete temp;
        nCount--;
    }
    
    void deletePos(int pos)
    {
        if (pos < 1 || pos > nCount)
        {
            cout << "Invalid Position!";
            return;
        }
        if (pos == 1)
        {
            deleteFirst();
            return;
        }
        if (pos == nCount)
        {
            deleteLast();
            return;
        }
        node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        node *temp1 = temp->next->next;
        delete temp->next->user;  // Fix memory leak
        delete temp->next;
        temp->next = temp1;
        temp1->prev = temp;
        nCount--;
    }
    
    void update(string name, int age, int pos)
    {
        if (head == nullptr)
        {
            cout << "List is empty! ";
            return;
        }
        if (pos < 1 || pos > nCount)
        {
            cout << "Invalid Position! ";
            return;
        }
        int currPos = 0;
        node *temp = head;
        do
        {
            currPos++;
            if (pos == currPos)
            {
                temp->user->name = name;
                temp->user->age = age;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }
    
    void sortAge()
    {
        if (head == nullptr)
        {
            return;
        }
        node *temp = nullptr;
        node *end = tail;
        bool swap = true;
        while (swap)
        {
            swap = false;
            temp = head;
            while (temp != end)
            {
                if (temp->user->age > temp->next->user->age)
                {
                    // Simple swap using temporary variables - more readable
                    int tempAge = temp->user->age;
                    temp->user->age = temp->next->user->age;
                    temp->next->user->age = tempAge;
                    
                    string tempName = temp->user->name;
                    temp->user->name = temp->next->user->name;
                    temp->next->user->name = tempName;
                    swap = true;
                }
                temp = temp->next;
            }
            end = temp;
        }
    }
    
    void sortName()
    {
        if (head == nullptr)
        {
            return;
        }
        node *temp = nullptr;
        node *end = tail;
        bool swap = true;
        while (swap)
        {
            swap = false;
            temp = head;
            while (temp != end)
            {
                if (temp->user->name > temp->next->user->name)
                {
                    // Simple swap using temporary variables - more readable
                    int tempAge = temp->user->age;
                    temp->user->age = temp->next->user->age;
                    temp->next->user->age = tempAge;
                    
                    string tempName = temp->user->name;
                    temp->user->name = temp->next->user->name;
                    temp->next->user->name = tempName;
                    swap = true;
                }
                temp = temp->next;
            }
            end = temp;
        }
    }
    
    void search(string name) // Function Overloading
    {
        if (head == nullptr)
        {
            cout << "List is empty!";
            return;
        }
        node *temp = head;
        int currPos = 0;
        do
        {
            currPos++;
            if (temp->user->name == name)
            {
                cout << "The Node : (" << temp->user->name << "-" << temp->user->age << ")" << endl;
                cout << "The Name is found at Position : " << currPos;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Not Found!";
    }
    
    void search(int age) // Function Overloading
    {
        if (head == nullptr)
        {
            cout << "List is empty!";
            return;
        }
        node *temp = head;
        int currPos = 0;
        do
        {
            currPos++;
            if (temp->user->age == age)
            {
                cout << "The Node : (" << temp->user->name << "-" << temp->user->age << ")" << endl;
                cout << "The Age is found at Position : " << currPos;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Not Found!";
    }
    
    void display()
    {
        if (head == nullptr)
        {
            cout << "The list is empty!" << endl;
            return;
        }
        node *temp = head;
        cout << "Head->";
        do
        {
            cout << "(" << temp->user->name << "-" << temp->user->age << ")->";
            temp = temp->next;
        } while (temp != head);
        cout << "Tail" << endl;
        cout << "Nodes : " << nCount << endl;
    }
    
    void displayReverse() //display in reverse
    {
        if (head == nullptr)
        {
            cout << "The List is empty!" << endl;
            return;
        }
        node *temp = tail;
        cout << "Tail->";
        do
        {
            cout << "(" << temp->user->name << "-" << temp->user->age << ")->";
            temp = temp->prev;
        } while (temp != tail);
        cout << "Head" << endl;
        cout << "Nodes : " << nCount << endl;
    }
};

int main()
{
    ifstream inputFile("DCLL_input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Unable to open the input file!";
        return 1;
    }
    DCLL list;
    int choice, pos, age;
    string name;
    cout << endl << "Single Circular LL" << endl;
    while (inputFile >> choice)
    {
        switch (choice)
        {
        case 1:
            inputFile >> name >> age;
            list.insertFirst(name, age);
            break;
        case 2:
            inputFile >> name >> age;
            list.insertLast(name, age);
            break;
        case 3:
            inputFile >> pos >> name >> age;
            list.insertPos(name, age, pos);
            break;
        case 4:
            list.display();
            break;
        default:
            cerr << "Error taking input from file!";
            break;
        }
    }
    while (true)
    {
        cout << endl << "1.Insert at First";
        cout << endl << "2.Insert at Last";
        cout << endl << "3.Insert at Specific Position";
        cout << endl << "4.Delete at First";
        cout << endl << "5.Delete at Last";
        cout << endl << "6.Delete at Specific Position";
        cout << endl << "7.Update at Specific Position";
        cout << endl << "8.Sort(By Name)";
        cout << endl << "9.Sort(By Age)";
        cout << endl << "10.Search(By Name)";
        cout << endl << "11.Search(By Age)";
        cout << endl << "12.Display";
        cout << endl << "13.Display(Reverse)";
        cout << endl << "0.Exit";
        cout << endl << "Enter Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << endl << "Enter the User's Name : ";
            cin >> name;
            cout << endl << "Enter the User's Age : ";
            cin >> age;
            list.insertFirst(name, age);
            list.display();
            break;
        case 2:
            cout << endl << "Enter the User's Name : ";
            cin >> name;
            cout << endl << "Enter the User's Age : ";
            cin >> age;
            list.insertLast(name, age);
            list.display();
            break;
        case 3:
            cout << "Enter the Position : ";
            cin >> pos;
            cout << endl << "Enter the User's Name : ";
            cin >> name;
            cout << endl << "Enter the User's Age : ";
            cin >> age;
            list.insertPos(name, age, pos);
            list.display();
            break;
        case 4:
            list.deleteFirst();
            list.display();
            break;
        case 5:
            list.deleteLast();
            list.display();
            break;
        case 6:
            cout << "Enter the Position : ";
            cin >> pos;
            list.deletePos(pos);
            list.display();
            break;
        case 7:
            cout << "Enter the Position : ";
            cin >> pos;
            cout << "Enter the name : ";
            cin >> name;
            cout << "Enter the age : ";
            cin >> age;
            list.update(name, age, pos);
            list.display();
            break;
        case 8:
            list.sortName();
            list.display();
            break;
        case 9:
            list.sortAge();
            list.display();
            break;
        case 10:
            cout << "Enter the Name : ";
            cin >> name;
            list.search(name);
            break;
        case 11:
            cout << "Enter the Name : ";
            cin >> age;
            list.search(age);
            break;
        case 12:
            list.display();
            break;
        case 13:
            list.displayReverse();
            break;
        case 0:
            cout << endl << "Exiting...";
            return 0;
        default:
            cout << endl << "Error - 400 : Bad Behaviour";
            break;
        }
    }
    return 0;
}