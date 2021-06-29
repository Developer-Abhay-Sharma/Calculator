// Version 1.0.4
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
        if (range <= 100000)
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
        cout << "\n Enter the value of divident= ";
        cin >> divident;
        while (cin.fail()) // deal with non-valid memory and non-useful data
        {
            cin.clear();               // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "\n Invalid Input\n";
            divide_input_and_check_data(choose);
        }
        cout << "\n Enter the value of divisor= ";
        cin >> divisor;
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
        cout << "\n Enter the value you have got= ";
        cin >> value_input;
        while (cin.fail()) // deal with non-valid memory and non-useful data
        {
            cin.clear();               // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "\n Invalid Input\n";
            percentage_input_and_check_data(choose);
        }
        cout << "\n Enter the total value= ";
        cin >> maximum_value;
        while (cin.fail()) // deal with non-valid memory and non-useful data
        {
            cin.clear();               // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "\n Invalid Input\n";
            percentage_input_and_check_data(choose);
        }
        final_data_percentage(value_input, maximum_value);
        cout << "\n The answer is= " << result_percentage << "%";
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

class date_and_time
{
    int leap_year(int day_to_month_validation) //input value of day based on month and leap year
    {
        int day;
        if (day_to_month_validation == 2)
        {
            cout << "\n Enter the value of days(1-29)= ";
            cin >> day;
            while (cin.fail()) // deal with non-valid memory and non-useful data
            {
                cin.clear();               // clear input buffer to restore cin to a usable state
                cin.ignore(INT_MAX, '\n'); // ignore last input
                cout << "\n Invalid Input\n";
                leap_year(day_to_month_validation);
            }
            if (day >= 1 && day <= 29)
            {
                return day;
            }
            else
            {
                cout << "\n Invalid Date Value";
                leap_year(day_to_month_validation);
            }
        }
        else if (day_to_month_validation == 1 || day_to_month_validation == 3 || day_to_month_validation == 5 || day_to_month_validation == 7 || day_to_month_validation == 8 || day_to_month_validation == 10 || day_to_month_validation == 12)
        {
            cout << "\n Enter the value of days(1-31)= ";
            cin >> day;
            while (cin.fail()) // deal with non-valid memory and non-useful data
            {
                cin.clear();               // clear input buffer to restore cin to a usable state
                cin.ignore(INT_MAX, '\n'); // ignore last input
                cout << "\n Invalid Input\n";
                leap_year(day_to_month_validation);
            }
            if (day >= 1 && day <= 31)
            {
                return day;
            }
            else
            {
                cout << "\n Invalid Date Value";
                leap_year(day_to_month_validation);
            }
        }
        else
        {
            cout << "\n Enter the value of days(1-30)= ";
            cin >> day;
            while (cin.fail()) // deal with non-valid memory and non-useful data
            {
                cin.clear();               // clear input buffer to restore cin to a usable state
                cin.ignore(INT_MAX, '\n'); // ignore last input
                cout << "\n Invalid Input\n";
                leap_year(day_to_month_validation);
            }
            if (day >= 1 && day <= 30)
            {
                return day;
            }
            else
            {
                cout << "\n Invalid Date Value";
                leap_year(day_to_month_validation);
            }
        }
    }
    int not_leap_year(int day_to_month_validation)
    {
        int day;
        if (day_to_month_validation == 2)
        {
            cout << "\n Enter the value of days(1-28)= ";
            cin >> day;
            while (cin.fail()) // deal with non-valid memory and non-useful data
            {
                cin.clear();               // clear input buffer to restore cin to a usable state
                cin.ignore(INT_MAX, '\n'); // ignore last input
                cout << "\n Invalid Input\n";
                not_leap_year(day_to_month_validation);
            }
            if (day >= 1 && day <= 28)
            {
                return day;
            }
            else
            {
                cout << "\n Invalid Date Value";
                leap_year(day_to_month_validation);
            }
        }
        else if (day_to_month_validation == 1 || day_to_month_validation == 3 || day_to_month_validation == 5 || day_to_month_validation == 7 || day_to_month_validation == 8 || day_to_month_validation == 10 || day_to_month_validation == 12)
        {
            cout << "\n Enter the value of days(1-31)= ";
            cin >> day;
            while (cin.fail()) // deal with non-valid memory and non-useful data
            {
                cin.clear();               // clear input buffer to restore cin to a usable state
                cin.ignore(INT_MAX, '\n'); // ignore last input
                cout << "\n Invalid Input\n";
                not_leap_year(day_to_month_validation);
            }
            if (day >= 1 && day <= 31)
            {
                return day;
            }
            else
            {
                cout << "\n Invalid Date Value";
                leap_year(day_to_month_validation);
            }
        }
        else
        {
            cout << "\n Enter the value of days(1-30)= ";
            cin >> day;
            while (cin.fail()) // deal with non-valid memory and non-useful data
            {
                cin.clear();               // clear input buffer to restore cin to a usable state
                cin.ignore(INT_MAX, '\n'); // ignore last input
                cout << "\n Invalid Input\n";
                not_leap_year(day_to_month_validation);
            }
            if (day >= 1 && day <= 30)
            {
                return day;
            }
            else
            {
                cout << "\n Invalid Date Value";
                leap_year(day_to_month_validation);
            }
        }
    }
    int day_input_and_check(int year_entered, int month_entered)
    {
        int day_to_month_validation = month_entered;
        if (year_entered % 4 == 0)
        {
            if (year_entered % 100 == 0)
            {
                if (year_entered % 400 == 0)
                    return leap_year(day_to_month_validation); //cout << year_entered << " is a leap year.";
                else
                    return not_leap_year(day_to_month_validation); //cout << year_entered << " is not a leap year.";
            }
            else
                return leap_year(day_to_month_validation); //cout << year_entered << " is a leap year.";
        }
        else
            return not_leap_year(day_to_month_validation); //cout << year_entered << " is not a leap year.";
    }
    int month_input_and_check()
    {
        int month = 0;
        cout << "\n Enter the Month(1-12)= ";
        cin >> month;
        while (cin.fail()) // deal with non-valid memory and non-useful data
        {
            cin.clear();               // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "\n Invalid Input\n";
            month_input_and_check();
        }
        if (month <= 12 && month > 0)
        {
            return month;
        }
        else
        {
            cout << "\n Invalid Month Value";
            month_input_and_check();
        }
    }
    int year_input_and_check()
    {
        int year = 0;
        cout << "\n Enter the Year(1000-10000)= ";
        cin >> year;
        while (cin.fail()) // deal with non-valid memory and non-useful data
        {
            cin.clear();               // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "\n Invalid Input\n";
            year_input_and_check();
        }
        if (year <= 10000 && year >= 1000)
        {
            return year;
        }
        else
        {
            cout << "\n Invalid Year Value";
            year_input_and_check();
        }
    }

public:
    int day_of_week(int y, int m, int d)
    {
        static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        y -= m < 3;
        return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
    }
    void date_difference(int choose)
    {
        int first_date[3];
        int second_date[3];
        int final_date[3];
        int i, j, k, l;
        if (choose == 6)
        {
            cout << "\n \"FROM DATE\"";
            for (i = 2; i >= 0; i--)
            {
                if (i == 0)
                {
                    int first_date_year = first_date[i + 2];
                    int first_date_month = first_date[i + 1];
                    first_date[i] = day_input_and_check(first_date_year, first_date_month); //have to create a new function for the input of day month and year
                }
                else if (i == 1)
                {
                    first_date[i] = month_input_and_check();
                }
                else if (i == 2)
                {
                    first_date[i] = year_input_and_check();
                }
                else
                {
                    cout << "\n Invalid Input";
                }
            }
            cout << "\n \"To Date\"";
            for (j = 2; j >= 0; j--)
            {
                if (j == 0)
                {
                    int second_date_year = second_date[j + 2];
                    int second_date_month = second_date[j + 1];
                    second_date[j] = day_input_and_check(second_date_year, second_date_month); //have to create a new function for the input of day month and year
                }
                else if (j == 1)
                {
                    second_date[j] = month_input_and_check();
                }
                else if (j == 2)
                {
                    second_date[j] = year_input_and_check();
                }
                else
                {
                    cout << "\n Invalid Input";
                }
            }
            cout << "\n \"Date DIfference\"";
            for (k = 2; k >= 0; k--)
            {
                // cout<<"\n LOOP";
                if (k == 2)
                {
                    final_date[k] = second_date[k] - first_date[k]; //subtraction of "from" year to "to" year
                    cout << "\n Years Left= " << final_date[k];
                }
                else if (k == 1)
                {
                    int month_diff = (final_date[k + 1] * 12) - 1; //converting the inputed years to months and subtracting 1 to exclude the last full month added
                    final_date[k] = (month_diff - (first_date[k] - 1)) + second_date[k];
                    cout << "\n Month Left= " << final_date[k];
                }
                else if (k == 0)
                {
                    int leap_days = 0;
                    final_date[k] = final_date[k + 1] * 30.417;
                    for (int i = first_date[k + 2]; i <= second_date[k + 2]; i++)
                    {
                        if (i % 4 == 0)
                        {
                            leap_days++;
                        }
                    }
                    final_date[k] = final_date[k] + leap_days;
                    cout << "\n Days Left= " << final_date[k];
                }
            }
        }
        else
        {
            cout << "\n Enter the date ";
            for (i = 2; i >= 0; i--)
            {
                if (i == 0)
                {
                    int first_date_year = first_date[i + 2];
                    int first_date_month = first_date[i + 1];
                    first_date[i] = day_input_and_check(first_date_year, first_date_month); //have to create a new function for the input of day month and year
                }
                else if (i == 1)
                {
                    first_date[i] = month_input_and_check();
                }
                else if (i == 2)
                {
                    first_date[i] = year_input_and_check();
                }
                else
                {
                    cout << "\n Invalid Input";
                }
            }
            int y = first_date[2];
            int m = first_date[1];
            int d = first_date[0];
            switch (day_of_week(y, m, d))
            {
            case 0:
                cout << "\n It's Sunday\n";
                break;
            case 1:
                cout << "\n It's Monday\n";
                break;
            case 2:
                cout << "\n It's Tuesday\n";
                break;
            case 3:
                cout << "\n It's Wednesday\n";
                break;
            case 4:
                cout << "\n It's Thursday\n";
                break;
            case 5:
                cout << "\n It's Friday\n";
                break;
            case 6:
                cout << "\n It's Saturday\n";
                break;
            }
        }
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
            result = divident - (divisor * quotient);
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
    float calculation::final_data_percentage(float value_input, float maximum_value) //final proccessing of data
    {
        result_percentage = (value_input / maximum_value) * 100;
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
        cout << "\n 5. Percentage";
        cout << "\n 6. Date Calculation";
        cout << "\n 7. Day Finding\n";
        cout << "\n Enter your Choice= ";
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
                subraction.range_check_data(choose); //input function calling
            }
            else if (choose == 3)
            {
                calculation multiplication;
                multiplication.range_check_data(choose); //input function calling
            }
            else if (choose == 4)
            {
                calculation division;
                division.divide_input_and_check_data(choose); //input function calling
            }
            else if (choose == 5)
            {
                calculation percentage;
                percentage.percentage_input_and_check_data(choose); //input function calling
            }
            else if (choose == 6)
            {
                date_and_time date;
                date.date_difference(choose);
            }
            else if (choose == 7)
            {
                date_and_time day_value;
                day_value.date_difference(choose);
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