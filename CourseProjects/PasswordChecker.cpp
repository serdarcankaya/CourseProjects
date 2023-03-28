#include	<iostream>
#include	<limits>
using namespace std;


/*
Project W1P1
	1.Ask for username and password
	2.Keep asking if password not correct
	3.If password wrong 3 times then shut down program

Project W1E1
1. Input control for numaric input on int datatype
*/

int main()

{
	//Global Variables
	string userName = "";
	string passWord = "";
	int luckyNumber;
	string userNameEntered = "";
	string passwordEntered = "";
	int loginErrorCounter = 3;
	bool getLucky = true;
	bool recoveryMode = false;
	int recoveryInput;
	int recoveryLuckNumber;

	//Account creation
	cout << "Welcome to Admin Panel Account Creation" << endl;
	cout << "Please Choose a Username : ";
	cin >> userName;
	cout << "Please Choose a Password : ";
	cin >> passWord;
	cout << "Please Choose a Lucky Number : ";
	cin >> luckyNumber;
	//Input check for int size
	while (getLucky)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cout << "You have entered wrong input. You must enter an integer" << endl;
			cout << "Please Choose a Lucky Number : ";

			cin >> luckyNumber;
		}
		else
		{
			cout << "the number is : " << luckyNumber << endl;
			getLucky = false;
		}

		
		continue;
	}

	//Input logs for debug
	cout << endl << endl;
	cout << "Debug Info\n" << " username: " << userName << " password : " << passWord << " Lucky Number : " << luckyNumber <<  endl;
	cout << endl << endl;

	cout << "Please Enter Username to Login: ";
	cin >> userNameEntered;

	while (loginErrorCounter > 0) //Login check with login attemps
	{
		if (userName == userNameEntered) //Correct username -> password check
		{

			cout << "Username Accepted." << endl;
			cout << "Please enter your password : ";
			cin >> passwordEntered;

			if (passWord == passwordEntered && loginErrorCounter > 0) //Correct password + login error count -> done
			{
				cout << "Welcome to Admin Panel." << endl;
				loginErrorCounter = 3;
				break;
			}
			else { //Wrong password -> try again.
				loginErrorCounter--;
				cout << "Wrong password. You can try again " << loginErrorCounter << " time(s) before system shutdowns." << endl;
			}
		}
		else { //Wrong username -> recovery options.
			cout << "Wrong Username. Please Get in Touch with Support or Enter Your Lucky Number to Recover Username" << endl;
			cout << "1. Contact Support" << endl;
			cout << "2. Username Recovery with Lucky Number" << endl;
			cout << endl << endl;
			cout << "Please Choose an Option : ";
			cin >> recoveryInput;
			recoveryMode = true;
			while (recoveryMode)
			{
				switch (recoveryInput)
				{
				case 1: //option 1 -> text mail address.
					cout << "You can reach Support via support@support.com";
					recoveryMode = false;
					break;
				case 2:	//option 2 -> recover with Luck Number.
					cout << "Pleae Enter Your Lucky Number : ";
					cin >> recoveryLuckNumber;
					getLucky = true;
					while (getLucky)
					{
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<int>::max(), '\n');
							cout << "You have entered wrong input. You must enter an integer" << endl;
							cout << "Please Enter Your Lucky Number : ";

							cin >> recoveryLuckNumber;
						}
						else
						{
							cout << "the number is : " << recoveryLuckNumber << endl;
							getLucky = false;
						}


						continue;
					}

					if (recoveryLuckNumber == luckyNumber) //Recovery successful
					{
						cout << "Your username is : " << userName << " Please DO NOT forget next time. " << endl;
						recoveryMode = false;
					}
					else //Recovery failed
					{
						cout << "Sorry, Wrong Luck Number. Please Get in touch with support via support@support.com";
						recoveryMode = false;
					}
				default: //Wrong recovery option choosen -> break
					cout << "Wrong Recovery Option.Please try later." << endl;
					recoveryMode = false;
					break;
				}
			}
			break;
		}
	}


	cout << endl << endl;
	system("Pause");
}