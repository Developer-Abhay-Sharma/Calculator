#include "date.h"
#include <iostream>

int
main()
{
    using namespace date;
    using namespace std;
    auto x = 2012_y/1/24;
    auto y = 2013_y/1/8;
    cout << x << '\n';
    cout << y << '\n';
    cout << "difference = " << (sys_days{y} - sys_days{x}).count() << " days\n";
}