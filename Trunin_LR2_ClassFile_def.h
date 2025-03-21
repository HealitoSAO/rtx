#ifndef Trunin_LR2_ClassFile_def_h
#define Trunin_LR2_ClassFile_def_h
#include <algorithm>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <cstring>
#include <type_traits>
#include <vector>
using namespace std;
bool UserInput(string input) {
  if (input.empty())
    return false;
  // попытаться
  try {
    // преобразование введенного значения в тип
    int number = stoi(input);
    if (number < 0)
      return false;
  } catch (...) // если возникла ошибка в блоке try
  {
    return false;
  }
  return false;
  // вспомогательная функция для ввода целых чисел
}
// Проверка, является ли строка числом
bool isValidNumber(const string &input) {
  if (input.empty())
    return false; // Пустая строка не является корректным числом
  for (char c : input) {
    if (!isdigit(c) && c != '-')
      return false; // Разрешаем отрицательные числа
  }
  return true;
}
// Функция для ввода числа
function<void()> EnterNumber(int &varLink, string label) {
  return [&varLink, label]() {
    string raw_input;
    cout << label;
    getline(cin, raw_input);
    // Цикл для повторного запроса числа, пока не будет введено корректное
    // значение
    while (!isValidNumber(raw_input)) {
      cout << "Invalid input. " << label;
      getline(cin, raw_input);
    }
    varLink = stoi(raw_input); // Преобразуем строку в целое число
  };
}

function<void()> EnterNumber2(double &varLink, string label) {
  return [&varLink, label]() {
    string raw_input;
    cout << label;
    getline(cin, raw_input);
    // Цикл для повторного запроса числа, пока не будет введено корректное
    // значение
    while (!isValidNumber(raw_input)) {
      cout << "Invalid input. " << label;
      getline(cin, raw_input);
    }
    varLink = stod(raw_input); // Преобразуем строку в число типа double
  };
}
bool isValidNumber2(const string &str) {
  char *end;
  strtod(str.c_str(), &end);
  return end != str.c_str() && *end == '\0';
}
function<void()> EnterString(string &varLink, string label) {
  return [&varLink, label]() {
    cout << label;
    getline(cin, varLink);
  };
}
#endif
