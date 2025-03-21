#include "Trunin_LR2_ClassFile.cpp"
#include "Trunin_LR2_ClassFile.h"
#include "Trunin_LR2_ClassFile_def.h"
string fname1 = "File.txt";

struct MenuItem {
  string title;
  function<void()> action;
};

int main() {
  map<int, MenuItem> menu = {
    // создаем вектор из файла
    {1, {"Create vector from file", createFilesFromFile(fname1)}},
    // выводим вектор
    {2, {"Show vector of files", showFiles}},
    // добавляем фильм в базу
    {3, {"Add file to DB", addFileToDB}},
    // сортировка по алфавиту
    {4, {"Found for route number: ", showFilesAlphabetic}},
    // сортировка по размеру
    {5, {"show Files Size Bigger Than: ", showFilesRazmer}},
    // сортировка по количеству обращений
    {6, {"show Files Appeals Bigger Than", showFilesAppeals}},
};

  int choice = 0;

  cout << "Menu:" << endl;
  // меню
  for (const auto &item : menu) {
    cout << item.first << ". " << item.second.title << endl;
  }

  cout << "0. Exit" << endl;

  // бесконечный цикл, пока не пункт "Exit"
  while (true) {
    // какой пункт выбрать
    EnterNumber(choice, "Enter your choice: ")();
    // если выйти, завершаем программу
    if (choice == 0) {
      cout << "Goodbye!" << endl;
      break;
    }

    cout << endl;

    // если меню, то вызывает функцию
    if (menu.find(choice) != menu.end()) {
      menu[choice].action();
    } else {
      // если выбрал пункт, который не существует, то сообщение об ошибке
      cout << "Invalid choice." << endl;
    }

    cout << endl << endl;
  }

  return 0;
}

