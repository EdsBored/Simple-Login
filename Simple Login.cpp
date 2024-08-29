#include <iostream>
#include <fstream>
#include <string>



using namespace std;

bool loggedIn()
    {
        string username, password;
        string compareUser, comparePass;

        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;

        ifstream read(username + ".txt");
        getLine(read, compareUser);
        getLine(read, comparePass);

        if(compareUser == username && comparePass == password) //checks user & password against txt file, either declining login, or authorizing login
            return true;
        else
            return false;

    }

int main()
{
    int choice;

    cout << endl;
    cout << "Main Menu: " << endl;
    cout << "_________________" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Please choose one." << endl;
    cin >> choice;

    if(choice == 1)
    {
        string username, password;
        
        cout << "Registration: " << endl;
        cout << "Please create a username." << endl;
        cin >> username;
        cout << "Please create a password." << endl;
        cin >> password;

        ofstream file;
        file.open(username + ".txt");
        file << username << endl << password;
        file.close();
        cout << "Welcome " << username << "!" << endl;
    } else if (choice == 2)
    {
        bool status = loggedIn();

        if(!status)
        {
            system("clear");
            cout << endl;
            cout << "Login credentials are invalid. Please try again."
            main();
            return 0;
        }
        else{
            cout << "Login successful.";
            int choiceTwo;

            cout << "Welcome back!" << endl;
            cout << endl;
            cout << "There is nothing yet, please come back soon!" << endl;
            cout << "1. Sign Out" << endl;
            cout << "2. Main Menu" << endl;
            cin >> choiceTwo;

            if(choiceTwo == 1)
                system("exit");
            else if(choiceTwo == 2)
                main();
            else
                return 1;

        }

    }
}