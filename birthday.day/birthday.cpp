//в cpp ми вже реалізуємо функцію і визначаємо змінні
#include "birthday.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
//оголошення глобальних зміних які шукають дату,місяць і рік народження
string global_res  = "";// змінна яка відповідає за виведення результату,наприклад середа
int global_day     = 0;
int global_mon     = 0;
int global_year    = 0;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29;
    return days[month - 1];
}

bool isValidDate(int day, int month, int year) {
    if (year < 1960) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > daysInMonth(month, year)) return false;
    return true;
}

void inputData() {
    char dot;
    cout << "Введіть дату народження (день.місяць.рік): ";
    cin >> global_day >> dot >> global_mon >> dot >> global_year;
}

long long countDaysFrom1960(int day, int month, int year) {
    long long total = 0;
    for (int y = 1960; y < year; y++)
        total += isLeapYear(y) ? 366 : 365;
    for (int m = 1; m < month; m++)
        total += daysInMonth(m, year);
    total += day - 1;
    return total;
}

string getDayOfWeek(int day, int month, int year) {
    string days[] = {
        "понеділок", "вівторок", "середа",
        "четвер",    "п'ятниця", "субота", "неділя"
    };
    int dayIndex = (4 + countDaysFrom1960(day, month, year)) % 7;
    return days[dayIndex];
}

void processData() {
    if (!isValidDate(global_day, global_mon, global_year))
        throw invalid_argument(
            "Некоректна дата! Рік має бути >= 1960, дата має існувати."
        );
    global_res = getDayOfWeek(global_day, global_mon, global_year);
}

void displayResult() {
    cout << "\nДата:       "
         << global_day << "." << global_mon << "." << global_year << endl;
    cout << "День тижня: " << global_res << endl;
}




