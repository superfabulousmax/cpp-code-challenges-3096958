// C++ Code Challenges, LinkedIn Learning

// Challenge #12: Age in Days Calculator
// Write an application that asks the user's birth date and responds with the user's age in days. 
// If the user claims to be over 120 years old, output a message calling the bluff.

#include <iostream>
#include <string>
#include <ctime>
#include <vector>


bool is_leap_year(int year)
{
    if (year % 4)
        return false;
    if (year % 100)
        return true;
    if (year % 400)
        return false;
    return true;
}


// Age in Days, main()
// Summary: This application asks the user's birth date and prints their age in days.
int main(){
    int birth_y, birth_m, birth_d, today_y, today_m, today_d, age;

    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;
    
    if(birth_m < 1)
        birth_m = 1;
    if(birth_m > 12)
        birth_m = 12;

    // Write your code here
    // get current date
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    today_y = ltm->tm_year + 1900;
    today_m = ltm->tm_mon + 1;
    today_d = ltm->tm_mday;

    std::vector<int> monthDays = 
    {
        31, 
        28, 
        31,
        30, 
        31, 
        30, 
        31, 
        31, 
        30, 
        31, 
        30, 
        31
    };

    if (birth_y * 365 + birth_m * 30 + birth_d 
        > today_y * 365 + today_m * 30 + today_d)
        {
            std::cout << "\nYou have not been born yet \n" << std::flush;
            return 0;
        }

    age = 0;
    int day = birth_d;
    int month = birth_m;
    int year = birth_y;

    while(day != today_d || month != today_m || year != today_y)
    {
        age++;
        day++;
        if (day > monthDays[month-1])
        {
            if (month == 2 && day == 29 && is_leap_year(year))
            {
                continue;
            }
            else
            {
                day = 1;
                month++;
                if (month > 12)
                {
                    month = 1;
                    year++;
                }
            }
        }
    }
    std::cout << "\n";
    // add the days of the month and the days to age
    // return age result 
    if(age < 43830)
        std::cout << "You are " << age << " days old.";
    else
        std::cout << "Come on. You can't be " << age << " days old!";
    std::cout << "\n\n" << std::flush;
}
