#include <iostream>
#include "birthday.h"

using namespace std;

extern int g_day;//ця змінна означає,що вона існує,але не в цьому файлі,інклудом позначається в якому файлі її лукати
extern int g_month;
extern int g_year;
extern string g_result;

int main() {
    int exitCode = 0;
    try {
        inputData();
        processData();
        displayResult();
    }
    catch (const invalid_argument& e) {
        cerr << "Помилка: " << e.what() << endl;
        exitCode = 1;
    }
    return exitCode;
}
