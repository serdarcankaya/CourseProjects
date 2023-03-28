#include<iostream>
#include<limits>

using namespace std;

int inputControlInt()
{
    int a;

    cout << "Enter an integer number\n";
    cin >> a;
    while (true)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "You have entered wrong input" << endl;
            cin >> a;
        }
        if (!cin.fail())
            break;
    }

    cout << "the number is : " << a << endl;
    return 0;
}