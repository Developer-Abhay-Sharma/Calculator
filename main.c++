// Version 1.0.2
#include <time.h> //to know execution time
#include <iostream>
#include <stdlib.h>
#include <climits> //for INT_MAX scope
using namespace std;

class calculation
{
    float result = 0.0; //float
    int long result_multi = 1;
    float result_percentage = 0.0;
    float final_data_addition(int range, float value_check[]);
    float final_data_subtraction(int range, float value_check[]);
    float final_data_multiplication(int range, float value_check[]);
    float final_data_division(float divident, float divisor);
    float final_data_percentage(float value_input, float maximum_value);

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
    void divide_input_and_check_data(int choose)
    {
        float divident = 0.0;
        float divisor = 0.0;
        cout<<"\n Enter the value of divident= ";
        cin>>divident;
        while (cin.fail()) // deal with non-valid memory and non-useful data
        {
            cin.clear();               // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "\n Invalid Input\n";
           divide_input_and_check_data(choose);
        }
        cout<<"\n Enter the value of divisor= ";
        cin>>divisor;
        while (cin.fail()) // deal with non-valid memory and non-useful data
        {
            cin.clear();               // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "\n Invalid Input\n";
            divide_input_and_check_data(choose);
        }
        final_data_division(divident, divisor);
        cout << "\n The answer is=" << result << endl;
    }
    void percentage_input_and_check_data(int choose)
    {
        int final_choice = choose;
        float value_input;
        float maximum_value;
        cout<<"\n Enter the value you have got= ";
        cin>>value_input;
         while (cin.fail()) // deal with non-valid memory and non-useful data
        {
            cin.clear();               // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "\n Invalid Input\n";
            percentage_input_and_check_data(choose);
        }
        cout<<"\n Enter the total value= ";
        cin>>maximum_value;
        while (cin.fail()) // deal with non-valid memory and non-useful data
        {
            cin.clear();               // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "\n Invalid Input\n";
            percentage_input_and_check_data(choose);
        }
        final_data_percentage(value_input, maximum_value);
        cout<<"\n The answer is= "<<result_percentage<<"%";
    }
    void array_check_data(int final_choice, int range)
    {
        int i; 
        float value_check[range]; //float
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
        else
        {
            final_data_multiplication(range, value_check);
            cout << "\n The answer is=" << result_multi << endl;
        }
        /*else
        {
            final_data_division(range, value_check);
            cout << "\n The answer is=" << result_division << endl;
        }*/
    }
};
float calculation::final_data_addition(int range, float value_check[]) //final proccessing of data
{
    for (int i = 0; i < range; i++)
    {
        result += value_check[i];
    }
    return result;
}
float calculation::final_data_subtraction(int range, float value_check[]) //final proccessing of data
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
float calculation::final_data_multiplication(int range, float value_check[]) //final proccessing of data
{
    for (int i = 0; i < range; i++)
    {
        result_multi *= value_check[i];
    }
    return result_multi;
}
float calculation::final_data_division(float divident, float divisor) //final proccessing of data
{
    float quotient = 0.0;
    int division_option;
    cout << "\n Choose what you want";
    cout << "\n 1.Reminder";
    cout << "\n 2.Quotient \n";
    cin >> division_option;
    quotient = divident / divisor;
    if (division_option == 1)
    {
       result = divident - (divisor*quotient);
    }
    else if (division_option == 2)
    {
        result = quotient;
    }
    else
        try //expection handling
        {
            while (cin.fail()) // deal with non-valid memory and non-useful data
            {
                cin.clear();               // clear input buffer to restore cin to a usable state
                cin.ignore(INT_MAX, '\n'); // ignore last input
                cout << "Invalid Input\n";
                final_data_division(divident, divisor);
            }
            throw 505;
        }
    catch (...) //deal with valid memory and non useful data
    {
        cout << "\n Invalid Input\n";
        final_data_division(divident, divisor);
    }
    return result;
}
float calculation::final_data_percentage(float value_input, float maximum_value)
{
    result_percentage = (value_input / maximum_value)*100;
    return result_percentage;
}

int main()
{
    // clock_t tStart = clock();
    int choose = 0;
    cout << "\n Choose What Function You Want to Perform (1-4)";
    cout << "\n 1. Addition";
    cout << "\n 2. Subtraction";
    cout << "\n 3. Multiplication";
    cout << "\n 4. Divide";
    cout << "\n 5. Percentage \n";
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
            division.divide_input_and_check_data(choose);
        }else if (choose == 5)
        {
            calculation percentage;
            percentage.percentage_input_and_check_data(choose);
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