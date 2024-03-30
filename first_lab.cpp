#include <iostream>
#include <string>

//Создаём структуру-узел
struct Part {
    int info; //информация о содержимом элемента стека
    Part* next; //указатель на следующий элемент стека
};

class STACK {
public:
    Part* first; //начало стека
    STACK() : first(nullptr) {};
    int size_stack = 0; //создаём переменную с информацией о количестве элементов в стеке
    void in(int v) { //Метод добавления элемента в стек
        Part* part = new Part(); //Создание нового узла
        (*part).info = v; //Присваивание элемента узлу
        (*part).next = first; //Связывание узла с прошлым первым элементом в стеке
        size_stack++; //увеличиваем размерность стека
        first = part;
    }
    int out() {//Метод извлечения элемента из стека
        Part* first1 = first; // Временный указатель на первый элемент
        int v = (*first1).info; // Сохранение содержимового по этому указателю
        first = (*first).next; // Второй элемент в стеке теперь первый
        delete(first1); // Освобождение памяти
        size_stack--; //уменьшаем размерность стека
        return v;
    }
    bool isEmpty() { //создаём метод с проверкой стека на пустоту
        if (size_stack == 0) return true;
        else return false;
    }
    bool isNotEmpty() { //создаём метод с проверкой стека на наличие хотя бы одного элемента
        if (size_stack == 0) return false;
        else return true;
    }
    int size() { //создаём метод с выводом количества элементов в нём
        return size_stack;
    }
};

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian"); //Подключаем поддержку русского языка в командной строке
    STACK Stack; //Создаём экземпеляр Stack класса STACK
    int x; //Объявляем переменную
    bool argv_after = true;
    if (argv[1] != nullptr) { // проверяем, существует ли аргумент
        std::string s = argv[1];
        if (s == "false") { //проверяем, false или нет
            argv_after = false;
        }
    }
    if (argv_after == false) { //запуск в режиме "Программа-Программа"(без пользовательского интерфейса)
        do
        {
            std::cin >> x;
            if (x == 0) break;
            Stack.in(x);
        } while (x != 0);
    }
    else { //запуск с пользовательским интерефейсом
        std::cout << "На вход программы подается последовательность чисел (0 - признак окончания последовательности). Программа выводит положительные числа последовательности в обратном порядке." << std::endl;
        std::cout << "Технические ограничения программы:" << std::endl;
        std::cout << "1) Только целые числа, по модулю не превышающие 2147483647" << std::endl;
        std::cout << "2) Количество чисел ограничено временной памятью компьютера" << std::endl;
        do {
            std::cout << "Введите число:" << std::endl;
            std::cin >> x; //Вводим число
            if (x == 0) break; //0 не заносится в стек
            Stack.in(x); //Добавляем x в стек
        } while (x != 0);
        std::cout << "Вы ввели 0. Это означает окончание последовательности. Ниже - положительные числа последовательности в обратном порядке:";
    }
    while (Stack.isNotEmpty()) { //выводим содержимое последовательности в обратном порядке без отрицательных чисел, пока в стеке есть числа
        x = Stack.out(); // Сохраняем содержимое 1-ого элемента в стеке в x
        if (x > 0)std::cout << x << std::endl;
    }
    return 0;
}
