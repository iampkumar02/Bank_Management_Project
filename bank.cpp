#include <conio.h>
#include <windows.h>
#include <iostream>

using namespace std;

class Bank
{
private:
    // int password;
    int cnt;
    int amt;
    int id;
    string accType;
    float rate;
    int LoanAmount;

public:
    void LoanA(); //Apply for loan
    void LoanB(); //check details of previous loan
    void details(int);

    struct person
    {
        string username, address;
        long long accNumber, contact;
        int cash;
        int tenure;
    } person[100];

public:
    Bank()
    {
        cnt = 0;
    }
    friend class Loan; // friend class so that we can access private data members of class Bank if required
    // void Loan(long long);
    void display();
    void accOpen();
    void accCredit();
    void accWithdraw();
};
void Bank::accOpen()
{
    cout << "____________________________________________________________________________________________\n\n\n\n";

    cout << "Your Account Number is: " << cnt + 1 << endl;
    person[cnt].accNumber = cnt + 1;
    cout << "Enter your Username: ";
    cin >> person[cnt].username;
    cout << "Entere your Contact Number: ";
    cin >> person[cnt].contact;
    cout << "Entere your Address: ";
    cin >> person[cnt].address;
    cout << "Enter the Cash to credit: ";
    cin >> person[cnt].cash;
    cnt++;
    cout << "____________________________________________________________________________________________\n\n\n\n";
}
// int Bank::cnt;
void Bank::accCredit()
{
    cout << "____________________________________________________________________________________________\n\n\n\n";

    cout << "Enter your Account Number: " << endl;
    cin >> id;
    cout << "How much cash you want to deposit??" << endl;
    cin >> amt;
    person[id - 1].cash += amt;
    cout << "Your new account balance is: " << person[id - 1].cash << endl;
}
void Bank::accWithdraw()
{
    cout << "____________________________________________________________________________________________\n\n\n\n";

    cout << "Enter your Account Number: " << endl;
    cin >> id;
    cout << "How much cash you want to withdraw??" << endl;
    cin >> amt;
    if (amt < person[id].cash)
    {
        person[id - 1].cash -= amt;
        cout << "Your existing cash is just " << person[id - 1].cash << endl;
    }
    else
    {
        cout << "Your account balance is insufficient to withdraw" << endl;
    }
}

void Bank::display()
{
    cout << "____________________________________________________________________________________________\n\n\n\n";

    cout << "Enter your Account Number:" << endl;
    cin >> id;
    for (int i = 0; i < cnt; i++)
    {
        if (id == person[i].accNumber)
        {
            cout << "Previous data" << endl;
            cout << "Data of person " << i + 1 << endl;
            cout << "Name: " << person[i].username << endl;

            cout << "Address: " << person[i].address << endl;
            cout << "Contact: " << person[i].contact << endl;
            cout << "Cash: " << person[i].cash << endl;
            // cout << "\nEnter new data" << endl;
            break;
        }
        if (i == cnt - 1)
        {
            cout << "No such record found" << endl;
        }
    }
    cout << "____________________________________________________________________________________________\n\n\n\n";
}
void Bank::LoanB()
{
    cout << "____________________________________________________________________________________________\n\n\n";
    cout << "Enter your account Number to view loan details: ";
    cin >> id;
    cout << "Account No: \t\t\t Outstanding LoanAmount:" << endl;
    cout << "(" << person[id - 1].accNumber << ")\t\t\t\t\t(" << LoanAmount << ")\n\n";
    cout << "Username: "
         << "\n"
         << person[id - 1].username << "\n\n";
    cout << "Description:"
         << "\n"
         << "SBI " << accType << "\n\n";
    cout << "Loan Start Date: "
         << "\n"
         << "NOVEMBER 2015"
         << "\n\n";
    cout << "Loan End Date: "
         << "\n"
         << "December 2025"
         << "\n\n";
    cout << "Loan Tenure: "
         << "\n"
         << person[id - 1].tenure << "\n\n";
    cout << "Rate of Interest: "
         << "\n"
         << rate << "\n\n";
    cout << "Press any key to continue...";
    getch();
    system("cls");
}
void Bank::LoanA()
{
    int err2 = 0, option2;
    cout << "____________________________________________________________________________________________\n\n\n\n";
    cout << "Which type of loan would you like to apply\n"
         << endl;
    do
    {
        try
        {
            cout << "1. Personal Loan" << endl
                 << "2. Student Loan" << endl
                 << "3. Home Loan" << endl
                 << "4. Business Loan" << endl;
            cin >> option2;
            system("cls");
            if (option2 < 1 || option2 > 4)
                throw option2;
            if (option2 == 1)
            {
                cout << "<--------------Personal Loan details------------------->\n\n\n";
                cout << "Interest Rate\t\t|\t8.95% p.a. onwards\n";
                cout << "Loan Amount Limit\t|\tUp to Rs 70 lakhs\n";
                cout << "Loan Tenure\t\t|\tUp to 7 years\n";
                cout << "Processing Fee\t\t|\t0%-3% of the loan amount + GST\n";
                rate = 8.5;
                accType = "Personal Loan";
            }
            else if (option2 == 2)
            {
                cout << "<--------------Student Loan details------------------->\n\n\n";
                cout << "Interest Rate\t\t|\t7.35% p.a. onwards\n";
                cout << "Loan Amount Limit\t|\tUp to Rs 15 lakhs or 25 lakhs for abroad\n";
                cout << "Loan Tenure\t\t|\tUp to 30 years\n";
                cout << "Processing Fee\t\t|\t0%-0.3% of the loan amount + GST\n";
                rate = 7.35;
                accType = "Student Loan";
            }
            else if (option2 == 3)
            {
                cout << "<--------------Home Loan details------------------->\n\n\n";
                cout << "Interest Rate\t\t|\t7.50% p.a. onwards\n";
                cout << "Loan Amount Limit\t|\t5 lakhs - 10 crs\n";
                cout << "Loan Tenure\t\t|\tUp to 30 years\n";
                cout << "Processing Fee\t\t|\t0%-0.35% of the loan amount + GST\n";
                rate = 7.5;
                accType = "Home Loan";
            }
            else
            {
                cout << "<--------------Business Loan details------------------->\n\n\n";
                cout << "Interest Rate\t\t|\t7.25% p.a. onwards\n";
                cout << "Loan Amount Limit\t|\t10 lakhs - 5 crs\n";
                cout << "Loan Tenure\t\t|\t5 years to 7 years\n";
                cout << "Processing Fee\t\t|\t0%-0.5% of the loan amount + GST\n";
                rate = 7.25;
                accType = "Bussiness Loan";
            }
            cout << "\n\n\n\t\tPress any key to continue....";
            getch();
            err2 = 0;
            details(option2);
        }
        catch (int option2)
        {
            system("cls");
            cout << "\nInvalid input!!" << endl
                 << "Please, try again\n"
                 << endl;
            err2 = 1;
        }
    } while (err2);
}
void Bank::details(int option2)
{
    system("cls");

    if (option2 == 1)
        cout << "<--------------Personal Loan------------------->\n\n\n";
    else if (option2 == 2)
        cout << "<--------------Student Loan------------------->\n\n\n";
    else if (option2 == 3)
        cout << "<--------------Home Loan------------------->\n\n\n";
    else
        cout << "<--------------Business Loan------------------->\n\n\n";

    cout << "Enter your Account Number: ";
    cin >> id;
    cout << "Enter your username: " << endl;
    cin >> person[id - 1].username;
    cout << "Enter Desired Loan Amount: ";
    cin >> LoanAmount;
    cout << "Enter Loan Tenure in months: ";
    cin >> person[id - 1].tenure;
    cout << "Enter Mobile Number :";
    cin >> person[id - 1].contact;
    cout << "Enter your address: ";
    cout << person[id - 1].address;
    system("cls");
    cout << "\n\n\t\tYou have Successfully applied for loan" << endl;
    cout << "\n\tNow, Your Outstanding balance is: " << person[id].cash << "\n\n";
    cout << "____________________________________________________________________________________________\n\n";
}
int main()
{
    Bank obj;
    int err = 0, option;
    cout << "____________________________________________________________________________________________\n\n\n\n";
    cout << "\n\n\n\n\t\t\t\tWelcome" << endl
         << "\t\t\t\t  To \n\t\t\t    Bank Management\n\n\n\t\t\tPress any key to continue....";
    cout << "\n\n\n\n___________________________________________________________________________________________\n";
    getch();
    system("cls");
    cout << "____________________________________________________________________________________________\n\n\n\n";

    cout << "Want to open a new account or know the details? Then, please select options one by one\n"
         << endl;

    do
    {
        try
        {
            cout << "\n1. To Open an account" << endl
                 << "2. To Deposite" << endl
                 << "3. To Withdrawl" << endl
                 << "4. To Loan" << endl
                 << "5. To Dispalay all account details" << endl
                 << "6. To Exit" << endl;
            cout << "\nMake Your Choice: ";
            cin >> option;
            if (option < 1 || option > 6)
                throw option;
            if (option == 1)
            {
                system("cls");
                obj.accOpen();
            }
            else if (option == 2)
            {
                system("cls");
                obj.accCredit();
            }
            else if (option == 3)
            {
                system("cls");
                obj.accWithdraw();
            }
            else if (option == 4)
            {

                int option1, err1 = 0;
                system("cls");
                cout << "____________________________________________________________________________________________\n\n\n\n";
                cout << "\nWant to take loan or check details of previous loan?\n"
                     << endl;
                do
                {
                    try
                    {
                        cout << "1. To apply" << endl
                             << "2. To check details" << endl;
                        cin >> option1;
                        if (option1 != 1 && option1 != 2)
                            throw option1;
                        system("cls");
                        if (option1 == 1)
                        {
                            obj.LoanA();
                        }
                        else
                        {
                            obj.LoanB();
                        }
                        err1 = 0;
                    }
                    catch (int option1)
                    {
                        system("cls");
                        cout << "\nInvalid input!!" << endl
                             << "Please, try again\n"
                             << endl;
                        err1 = 1;
                    }
                } while (err1);
            }
            else if (option == 5)
            {
                system("cls");
                cout << "____________________________________________________________________________________________\n\n";
                cout << "Displaying all Details" << endl;
                obj.display();
            }
            else
            {
                system("cls");
                cout << "\n\n\t\tThank You!"
                     << "\n\n";
                exit(0);
            }
            err = 1;
        }
        catch (int option)
        {
            system("cls");
            cout << "\nInvalid input!!" << endl
                 << "Please, try again\n"
                 << endl;
            err = 1;
        }
    } while (err);
    // ------------------------over------------------------
}
