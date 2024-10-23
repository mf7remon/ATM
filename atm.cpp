#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User
{
private:
    string username;
    string password;
    int balance;



public:
    User(string n, string p) : username(n), password(p), balance(0) {}

    bool check_password(string pass)
    {
        return password == pass;
    }

    bool check_username(string user)
    {
        return username == user;
    }

    int getBalance() const
    {
        return balance;
    }

    void deposit(int amount)
    {
        balance += amount;
    }

    bool withdraw(int amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            return true;
        }
        return false;
    }
};

int display()
{
    cout << "*** Main Menu ***" << endl;
    cout << endl;

    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Balance" << endl;
    cout << "4. Exit" << endl;

    cout << "Where would you like to go: ";
    int op;
    cin >> op;
    cout << endl;

    return op;
}

void handle_user(User &user)
{
    while (true)
    {
        int i = display();
        switch (i)
        {
        case 1:
        {
            int in;
            cout << "Enter the amount: ";
            cin >> in;

            if (in > 0)
            {
                user.deposit(in);
                cout << "Successfully added" << endl;
            }
            else
            {
                cout << "Invalid amount. Please enter a positive value." << endl;
            }
            break;
        }
        case 2:
        {
            int out;
            cout << "Enter the amount: ";
            cin >> out;

            if (user.withdraw(out))
            {
                cout << "Successfully debited" << endl;
            }
            else
            {
                cout << "Insufficient Balance" << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Your current balance is " << user.getBalance() << " USD" << endl;
            break;
        }
        case 4:
            return;
        default:
            cout << "Invalid option. Please try again." << endl;
        }

        cout << endl;
        cout << "Would you like to continue..? (1. Yes  2. No): ";
        int choice;
        cin >> choice;
        if (choice != 1)
        {
            break;
        }
    }
}

int main()
{
    vector<User> users = {
        User("remon", "1702"),
        User("tamim", "1285"),
        User("abrar", "1269")
    };

    while (true)
    {
        cout << "*** Welcome to our service ***" << endl;

        string input_id;
        cout << "Enter username: ";
        cin >> input_id;

        string input_pass;
        cout << "Enter password: ";
        cin >> input_pass;

        bool authenticated = false;

        for (User &user : users)
        {
            if (user.check_username(input_id) && user.check_password(input_pass))
            {
                handle_user(user);
                authenticated = true;
                break;
            }
        }

        if (!authenticated)
        {
            cout << "Invalid username or password. Please try again." << endl;
        }

        cout << "Would you like to switch user? (1. Yes  2. No): ";
        int logout;
        cin >> logout;
        if (logout != 1)
        {
            break;
        }

         system("cls");
    }

    return 0;
}
