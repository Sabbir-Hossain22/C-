#include <iostream>
#include <string>

using namespace std;

class Passenger
{
public:
    string pname;
    string fname;
    Passenger* nextval;

    Passenger(const string pname, const string fname, Passenger* p = nullptr)
    {
        this->pname = pname;
        this->fname = fname;
        this->nextval = p;
    }
};

class ticket
{
private:
    Passenger* headval;
    Passenger* tailval;

public:
    ticket();
    ~ticket();

    void reverse_Ticket();
    void cancel_Ticket();
    void check_Ticket();
    void display();
};

ticket::ticket()
{
    headval = tailval = nullptr;
}

ticket::~ticket()
{
    Passenger* p1 = headval;
    while (p1 != nullptr)
    {
        Passenger* p2 = p1->nextval;
        delete p1;
        p1 = p2;
    }
    tailval = nullptr;
}

void ticket::reverse_Ticket()
{
    string pname, fname;
    cout << "Please Enter Passenger name: " << endl;
    cin >> pname;
    cout << "Flight name: " << endl;
    cin >> fname;

    if (headval == nullptr)
    {
        headval = tailval = new Passenger(pname, fname);
        cout << "Ticket reserved" << endl;
        return;
    }
    else
    {
        Passenger* p1 = headval;
        Passenger* p2 = nullptr;

        while (p1 != nullptr)
        {
            if (pname < p1->pname)
            {
                break;
            }
            else
            {
                p2 = p1;
                p1 = p1->nextval;
            }
        }

        if (p2 == nullptr)
        {
            headval = new Passenger(pname, fname, headval);
        }
        else
        {
            p2->nextval = new Passenger(pname, fname, p2->nextval);
        }

        cout << "Ticket reserved" << endl;
    }
}

void ticket::cancel_Ticket()
{
    string pname, fname;
    cout << "Please Enter Passenger Name: " << endl;
    cin >> pname;
    cout << "Flight name: " << endl;
    cin >> fname;
}

void ticket::check_Ticket()
{
    string pname;
    cout << "Passenger Name: " << endl;
    cin >> pname;
}

void ticket::display()
{
    Passenger* p1 = headval;
    while (p1 != nullptr)
    {
        cout << " The passenger name is : " << p1->pname <<endl << " Flight Name: " << p1->fname << endl;
        p1 = p1->nextval;
    }
}

int main()
{
    ticket t1;

    while (true)
    {
        cout << "************MENU*************" << endl;
        cout << "==============================" << endl;
        cout << "Airline Ticket Reservation System" << endl;
        cout << "Enter Your Choice" << endl;
        cout << "1. Reserve Ticket" << endl;
        cout << "2. Cancel Ticket" << endl;
        cout << "3. Check Ticket" << endl;
        cout << "4. Display Ticket" << endl;
        cout << "5. End" << endl;
        cout << "==============================" << endl;
        cout << "******************************" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            t1.reverse_Ticket();
            break;
        case 2:
            t1.cancel_Ticket();
            break;
        case 3:
            t1.check_Ticket();
            break;
        case 4:
            t1.display();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}
