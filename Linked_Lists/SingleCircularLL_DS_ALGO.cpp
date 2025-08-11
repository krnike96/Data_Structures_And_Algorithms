#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int nCount = 0;

class SCLL {
public:
    struct data {
        string name;
        int age;
    };
    struct node {
        data *user;
        node *next;
    };
    node *head;

    SCLL() {
        head = nullptr;
    }

    node *createNode() {
        node *nn = new (std::nothrow) node;
        if (!nn) {
            std::cerr << "Memory allocation failed!" << std::endl;
            return nullptr;
        }
        nn->user = new (std::nothrow) data;
        if (!nn->user) {
            std::cerr << "Memory Allocation Failed" << std::endl;
            delete nn;
            return nullptr;
        }
        return nn;
    }

    void insertFirst(string name, int age) {
        node *nn = createNode();
        if (!nn) return;

        nn->user->name = name;
        nn->user->age = age;

        if (head == nullptr) {
            nn->next = nn;
        } else {
            node *LastNode = head;
            while (LastNode->next != head) {
                LastNode = LastNode->next;
            }
            nn->next = head;
            LastNode->next = nn;
        }
        head = nn;
        nCount++;
    }

    void insertLast(string name, int age) {
        if (head == nullptr) {
            insertFirst(name, age);
            return;
        }
        node *nn = createNode();
        if (!nn) return;

        nn->user->name = name;
        nn->user->age = age;
        node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = nn;
        nn->next = head;
        nCount++;
    }

    void insertPos(string name, int age, int pos) {
        if (pos < 1 || pos > nCount + 1) {
            cerr << "Invalid Position!";
            return;
        }
        if (pos == 1) {
            insertFirst(name, age);
            return;
        }
        node *temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        node *nn = createNode();
        if (!nn) return;

        nn->user->name = name;
        nn->user->age = age;
        nn->next = temp->next;
        temp->next = nn;
        nCount++;
    }

    void deleteFirst() {
        if (head == nullptr) {
            cerr << "Invalid Operation!";
            return;
        }
        node *temp = head;
        if (temp->next == head) {
            delete temp->user;
            delete temp;
            head = nullptr;
            nCount--;
            return;
        }
        node *temp1 = head;
        head = temp->next;
        while (temp->next != temp1) {
            temp = temp->next;
        }
        temp->next = head;
        delete temp1->user;
        delete temp1;
        nCount--;
    }

    void deleteLast() {
        if (head == nullptr) {
            cerr << "Invalid Operation!";
            return;
        }
        node *temp = head;
        if (temp->next == head) {
            delete temp->user;
            delete temp;
            head = nullptr;
            nCount--;
            return;
        }
        while (temp->next->next != head) {
            temp = temp->next;
        }
        node *temp1 = temp->next;
        temp->next = head;
        delete temp1->user;
        delete temp1;
        nCount--;
    }

    void deletePos(int pos) {
        if (head == nullptr || pos < 1 || pos > nCount) {
            cerr << "Invalid Operation!";
            return;
        }
        if (pos == 1) {
            deleteFirst();
            return;
        }
        node *temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        node *temp1 = temp->next;
        temp->next = temp->next->next;
        delete temp1->user;
        delete temp1;
        nCount--;
    }

    void updateFirst(string name, int age) {
        if (head == nullptr) {
            cerr << "Invalid Operation!";
            return;
        }
        head->user->name = name;
        head->user->age = age;
    }

    void updateLast(string name, int age) {
        if (head == nullptr) {
            cerr << "Invalid Operation!";
            return;
        }
        node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->user->name = name;
        temp->user->age = age;
    }

    void updatePos(string name, int age, int pos) {
        if (head == nullptr || pos < 1 || pos > nCount) {
            cerr << "Invalid Operation!";
            return;
        }
        if (pos == 1) {
            updateFirst(name, age);
            return;
        }
        node *temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        temp->user->name = name;
        temp->user->age = age;
    }

    void bubbleSortByAge() {
        if (head == nullptr) {
            cerr << "Invalid Operation!";
            return;
        }
        node *temp;
        node *end = head;
        bool swap = true;
        while (swap) {
            swap = false;
            temp = head;
            while (temp->next != end) {
                if (temp->user->age > temp->next->user->age) {
                    // Swapping data
                    int age_temp = temp->user->age;
                    temp->user->age = temp->next->user->age;
                    temp->next->user->age = age_temp;
                    
                    string name_temp = temp->user->name;
                    temp->user->name = temp->next->user->name;
                    temp->next->user->name = name_temp;
                    swap = true;
                }
                temp = temp->next;
            }
            end = temp;
        }
    }

    void bubbleSortByName() {
        if (head == nullptr) {
            cerr << "Invalid Operation!";
            return;
        }
        node *temp;
        node *end = head;
        bool swap = true;
        while (swap) {
            swap = false;
            temp = head;
            while (temp->next != end) {
                if (temp->user->name > temp->next->user->name) {
                    // Swapping data
                    int age_temp = temp->user->age;
                    temp->user->age = temp->next->user->age;
                    temp->next->user->age = age_temp;
                    
                    string name_temp = temp->user->name;
                    temp->user->name = temp->next->user->name;
                    temp->next->user->name = name_temp;
                    swap = true;
                }
                temp = temp->next;
            }
            end = temp;
        }
    }

    void search(string name) {
        if (head == nullptr) {
            cerr << "Invalid Operation!";
            return;
        }
        node *temp = head;
        int pos = 0;
        do {
            pos++;
            if (name == temp->user->name) {
                cout << "The Node : (" << temp->user->name << "-" << temp->user->age << ")" << endl;
                cout << "The Name is Found at Position : " << pos << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Name Data not Found!" << endl;
    }

    void search(int age) {
        if (head == nullptr) {
            cerr << "Invalid Operation!";
            return;
        }
        node *temp = head;
        int pos = 0;
        do {
            pos++;
            if (age == temp->user->age) {
                cout << "The Node : (" << temp->user->name << "-" << temp->user->age << ")" << endl;
                cout << "The Age is Found at Position : " << pos << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Age Data not Found!" << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "The List is Empty!" << endl;
            return;
        }
        node *temp = head;
        cout << endl << "The List is : ";
        do {
            cout << "(" << temp->user->name << "-" << temp->user->age << ")->";
            temp = temp->next;
        } while (temp != head);
        cout << "Head" << endl;
        cout << "Nodes : " << nCount << endl;
    }
    
    void displayReverse() {
        if (head == nullptr) {
            cout << "The List is Empty!" << endl;
            return;
        }
        cout << endl << "The List is : ";
        reverse(head, head);
        cout << "Head" << endl;
        cout << "Nodes : " << nCount << endl;
    }

    void reverse(node *start, node *current) {
        if (current->next == start) {
            cout << "(" << current->user->name << "-" << current->user->age << ")->";
            return;
        }
        reverse(start, current->next);
        cout << "(" << current->user->name << "-" << current->user->age << ")->";
    }
};

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Unable to open the file!";
        return 1;
    }
    
    SCLL list;
    int choice, pos, age;
    string name;

    cout << endl << "Single Circular LL";
    while (inputFile >> choice) {
        switch (choice) {
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
            cerr << "Invalid Input From File!";
            break;
        }
    }
    inputFile.close();

    while (true) {
        cout << endl << "1.Insert at First" << endl;
        cout << "2.Insert at Last" << endl;
        cout << "3.Insert at Specific Position" << endl;
        cout << "4.Delete at First" << endl;
        cout << "5.Delete at Last" << endl;
        cout << "6.Delete at Specific Position" << endl;
        cout << "7.Update at First" << endl;
        cout << "8.Update at Last" << endl;
        cout << "9.Update at Specific Position" << endl;
        cout << "10.Sort(By Age)" << endl;
        cout << "11.Sort(By Name)" << endl;
        cout << "12.Search(By Age)" << endl;
        cout << "13.Search(By Name)" << endl;
        cout << "14.Display" << endl;
        cout << "15.Reverse Display" << endl;
        cout << "0.Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice) {
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
            cout << endl << "Enter the Position : ";
            cin >> pos;
            cout << endl << "Enter the Name : ";
            cin >> name;
            cout << endl << "Enter the Age : ";
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
            cout << "Enter the Name : ";
            cin >> name;
            cout << "Enter the Age : ";
            cin >> age;
            list.updateFirst(name, age);
            list.display();
            break;
        case 8:
            cout << "Enter the Name : ";
            cin >> name;
            cout << "Enter the Age : ";
            cin >> age;
            list.updateLast(name, age);
            list.display();
            break;
        case 9:
            cout << "Enter the Position : ";
            cin >> pos;
            cout << "Enter the Name : ";
            cin >> name;
            cout << "Enter the Age : ";
            cin >> age;
            list.updatePos(name, age, pos);
            list.display();
            break;
        case 10:
            list.bubbleSortByAge();
            list.display();
            break;
        case 11:
            list.bubbleSortByName();
            list.display();
            break;
        case 12:
            cout << "Enter the Age : ";
            cin >> age;
            list.search(age);
            break;
        case 13:
            cout << "Enter the Name : ";
            cin >> name;
            list.search(name);
            break;
        case 14:
            list.display();
            break;
        case 15:
            list.displayReverse();
            break;
        case 0:
            cout << "Exiting...";
            return 0;
        default:
            cerr << endl << "Error - 400 : Bad Behaviour" << endl;
            break;
        }
    }
    return 0;
}