#ifndef Trunin_LR1_Bus_DEF_H
#define Trunin_LR1_Bus_DEF_H
#include "Trunin_LR2_ClassFile_def.h"
using namespace std;
class File {
  string file_name; // Имя файла
  int razmer;       // Размер файла
  int date;         // Дата создания
  int appeals;      // Кол-во обращений
public:
  File(string file_name = "", int razmer = 0, int date = 0, int appeals = 0, int number_mursrut = 0)
      : file_name(file_name), razmer(razmer), date(date), appeals(appeals) {}
  void set_file_name(const string &file_name) {
    this->file_name = file_name;
  }
  void set_razmer(int razmer) { this->razmer = razmer; }
  void set_date(int date) {this->date = date;}
  void set_appeals(int appeals) { this->appeals = appeals; }
  string get_file_name() const { return this->file_name; }
  int get_razmer() const { return int(this->razmer); }
  int get_date() const { return int(this->date); }
  int get_appeals() const { return int(this->appeals); }
  // Метод для вывода информации о файлах
  void print() const {
    cout << "File: " << file_name << ", Razmer: " << razmer << ", Date: " << date << ", Appeals: " << appeals << endl;}
  bool fbool1(string route_number);
  bool fbool2(int busis);
  bool fbool3(int busis);
};
// вектор (БД) файлов
#endif
