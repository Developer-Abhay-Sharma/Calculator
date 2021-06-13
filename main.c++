// Version 1.0.1
#include <time.h> //to know execution time
#include <iostream>
#include <stdlib.h>
#include <climits> //for INT_MAX scope
using namespace std;

class calculation
{
    int result = 0;
    int long result_multi = 1;
    int result_division = 1;
    int final_data_addition(int range, int value_check[]);
    int final_data_subtraction(int range, int value_check[]);
    int final_data_multiplication(int range, int value_check[]);
    int final_data_division(int range, int value_check[]);

public:
    void range_check_data(int choose) //get the data and check the validation of data
    {
        int final_choice = choose;
        int range;
        cout << "\n Enter your total number=";
        cin >> range;
        if (range <=100000)
        {
            array_check_data(final_choice, range);
        }
        else
        while (cin.fail()) // deal with non-valid memory and non-useful data
        {
            cin.clear();               // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "\n Invalid Input\n";
            range_check_data(choose);
        }
    }
    void array_check_data(int final_choice, int range)
    {
        int i;
        int value_check[range];
        for (i = 0; i < range; i++)
        {
            cout << "\n Enter your " << i + 1 << " number= ";
            cin >> value_check[i];
            while (cin.fail()) // deal with non-valid memory and non-useful data
            {
                cin.clear();               // clear input buffer to restore cin to a usable state
                cin.ignore(INT_MAX, '\n'); // ignore last input
                system("CLS");
                cout << "\n Invalid Input\n";
                array_check_data(final_choice, range);
            }
        }
        if (final_choice == 1) //selectinn of calling of function based on what task user want to perform i.e., Addition, Subtraction etc.
        {
            final_data_addition(range, value_check);
            cout << "\n The answer is=" << result << endl;
        }
        else if (final_choice == 2)
        {
            final_data_subtraction(range, value_check);
            cout << "\n The answer is=" << result << endl;
        }
        else if (final_choice == 3)
        {
            final_data_multiplication(range, value_check);
            cout << "\n The answer is=" << result_multi << endl;
        }
        else
        {
            final_data_division(range, value_check);
            cout << "\n The answer is=" << result_division << endl;
        }
    }
};
int calculation::final_data_addition(int range, int value_check[]) //final proccessing of data
{
    for (int i = 0; i < range; i++)
    {
        result += value_check[i];
    }
    return result;
}
int calculation::final_data_subtraction(int range, int value_check[]) //final proccessing of data
{
    for (int i = 0; i < range; i++)
    {
        if (i == 0)
        {
            result = value_check[i] - result;
        }
        else
            result = result - value_check[i];
    }
    return result;
}
int calculation::final_data_multiplication(int range, int value_check[]) //final proccessing of data
{
    for (int i = 0; i < range; i++)
    {
        result_multi *= value_check[i];
    }
    return result_multi;
}
int calculation::final_data_division(int range, int value_check[]) //final proccessing of data
{
    int division_option;
    cout << "\n Choose what you want";
    cout << "\n 1.Reminder";
    cout << "\n 2.Quotient \n";
    cin >> division_option;
    if (division_option == 1)
    {
        for (int i = 0; i < range; i++)
        {
            if (i == 0)
            {
                result_division = value_check[i]; //take the first value of array in result_division
            }
            else
                result_division = result_division % value_check[i];
        }
    }
    else if (division_option == 2)
    {
        for (int i = 0; i < range; i++)
        {
            if (i == 0)
            {
                result_division = value_check[i];
            }
            else
                result_division = result_division / value_check[i];
        }
    }
    else
        try //expection handling
        {
            while (cin.fail()) // deal with non-valid memory and non-useful data
            {
                cin.clear();               // clear input buffer to restore cin to a usable state
                cin.ignore(INT_MAX, '\n'); // ignore last input
                cout << "Invalid Input\n";
                final_data_division(range, value_check);
            }
            throw 505;
        }
    catch (...) //deal with valid memory and non useful data
    {
        cout << "\n Invalid Input\n";
        final_data_division(range, value_check);
    }
    return result_division;
}

int main()
{
    // clock_t tStart = clock();
    int choose = 0;
    cout << "\n Choose What Function You Want to Perform (1-4)";
    cout << "\n 1. Addition";
    cout << "\n 2. Subtraction";
    cout << "\n 3. Multiplication";
    cout << "\n 4. Divide \n";
    //  printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    cin >> choose;
    try //expection handling
    {
        if (choose == 1)
        {
            calculation addition;
            addition.range_check_data(choose);
        }
        else if (choose == 2)
        {
            calculation subraction;
            subraction.range_check_data(choose);
        }
        else if (choose == 3)
        {
            calculation multiplication;
            multiplication.range_check_data(choose);
        }
        else if (choose == 4)
        {
            calculation division;
            division.range_check_data(choose);
        }
        else
            throw 505;
    }
    catch (...) //deal with valid memory input and non useful data
    {
        cin.clear();               // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        //system("CLS");
        cout << "\n Invalid Input \n";
        main();
    }
    cout << "\n TO EXIT PRESS CTRL+C\n";
    main();
    return 0;
}