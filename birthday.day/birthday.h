//позначаємо заголовний файл,тут тільки оголошенння,ми показуємо що це існує.але не визначаємо тут
#pragma once
#include <string>
using namespace std;
extern int global_day;
extern int global_mon;
extern int global_year;
extern string global_res;
bool isLeapYear(int year);
int daysInMonth(int month, int year);
bool isValidDate(int day, int month, int year);
void inputData();
long long countDaysFrom1960(int day, int month, int year);
string getDayOfWeek(int day, int month, int year);
void processData();
void displayResult();