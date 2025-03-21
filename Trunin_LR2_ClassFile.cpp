#ifndef Surname_LR1_vector_h
#define Surname_LR1_vector_h
#include "Trunin_LR2_ClassFile_def.h"
#include "Trunin_LR2_ClassFile.h"
// Вектор (БД) файлов
vector<File> DB_File;
cout << "DB is empty" << endl;
// Функция для создания вектора из файла
function<void()> createFilesFromFile(string filename) {
  return [filename]() {
    ifstream file(filename);
    if (!file.is_open()) {
      cout << "Failed to open file: " << filename << endl;
    }
    DB_File.clear();
    string line = "";
    while (getline(file, line)) {
      // Разделение строки на части
      stringstream ss(line);
      string file_name;
      int razmer, date, appeals;
      // Чтение имени
      getline(ss, file_name, ',');
      // Чтение номера зачетной книжки
      ss >> razmer;
      ss.ignore(); // Пропуск запятой
      // Чтение возраста
      ss >> date;
      ss.ignore(); // Пpопуск запятой // Чтение оценок
      ss >> appeals;
      ss.ignore(); // Пpопуск запятой // Чтение оценок
      // Создание объекта Bus и добавление в вектор
      DB_File.emplace_back(file_name, razmer, date, appeals);
    }
    cout << "DB is complite" << endl;
    file.close();
  };
}

// Функция для вывода вектора
void showFiles() {
  for (const auto &File : DB_File) {
    File.print();
  }
}

// Функция для добавления файла в вектор
File addFile() {
  string file_name;
  int razmer, date, appeals;

  EnterString(file_name, "Enter file_name: ")();
  EnterNumber(razmer, "Enter razmer: ")();
  EnterNumber(date, "Enter date: ")();
  EnterNumber(appeals, "Enter appeals: ")();

  return File(file_name, razmer, date, appeals);
}

// Функция для добавления файла в вектор
void addFileToDB() {
  DB_File.push_back(addFile());
  cout << "DB is complite_2\n" << endl;
}

// Функции для фильтрации
// bool1 - сравнивает имена файлов, возвращает true, если они равны
bool File::fbool1(string route_number) { return (this->file_name == route_number); }

// bool2 - проверяет, является ли размер файла больше, чем заданный
bool File::fbool2(int razmer) { return ((this->razmer) > razmer); }

// bool3 - проверяет, является ли количество обращений больше, чем заданное
bool File::fbool3(int appeals) { return ((this->appeals) > appeals); }

void showFilesAlphabetic() {
  sort(DB_File.begin(), DB_File.end(), [](const File &lhs, const File &rhs) {
    return lhs.get_file_name() < rhs.get_file_name();
  });
  for (const auto &file : DB_File) {
      file.print();
  }
}

void showFilesRazmer() {
  int razmer;
  EnterNumber(razmer, "Enter razmer: ")();
  for ( auto &file : DB_File) {

    if (file.fbool2(razmer) == true) {
      file.print();
    }
  } 
}

void showFilesAppeals() {
  int appeals;
  EnterNumber(appeals, "Enter appeals: ")();
  for (auto &file : DB_File) {
    if (file.fbool3(appeals)) {
      file.print();
    }
  }
}
#endif


