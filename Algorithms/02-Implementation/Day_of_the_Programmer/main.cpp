#include <iostream>
#include <fstream>
#include <iomanip>

enum CalendarType {
    JULIAN,
    GREGORIAN,
    TRANSITION
};

CalendarType getCalendarType(int year) {
    if (year < 1918) {
        return JULIAN;
    }
    else if (year > 1918) {
        return GREGORIAN;
    }
    else {
        return TRANSITION;
    }
}

bool isLeapYear(int year) {
    switch (getCalendarType(year)) {
        case JULIAN:
            return year % 4 == 0;
        case TRANSITION:
        case GREGORIAN:
            return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        default:
            return false;
    }
}

int getDaysInMonth(int month, int year) {
    if (month == 2) {
        if (getCalendarType(year) == TRANSITION) {
            // in 1918, a transition from Julian to Gregorian calendar was made, and after January 31st came February
            // 14th. So there were 15 days in that February
            return 15;
        }
        else if (isLeapYear(year)) {
            return 29;
        }
        return 28;
    }
    if ((month < 8 && month % 2) || (month >= 8 && !(month % 2))) {
        return 31;
    }
    else {
        return 30;
    }
}

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    const int DAY_OF_THE_PROGRAMMER = 256;

    int year;
    std::cin >> year;

    int total_days = 0;
    for (int month = 1; month < 13; ++month) {
        int days_in_month = getDaysInMonth(month, year);

        if (DAY_OF_THE_PROGRAMMER - total_days <= days_in_month) {
            fout << std::setw(2) << std::setfill('0') << DAY_OF_THE_PROGRAMMER - total_days << '.'
                 << std::setw(2) << std::setfill('0') << month << "."
                 << std::setw(4) << std::setfill('0') << year << "\n";
            break;
        }
        else {
            total_days += days_in_month;
        }
    }

    return 0;
}
