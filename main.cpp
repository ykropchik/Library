#include <iostream>
#include "src/library.h"


int main() {
    Book b1 = {"Оно", "Стивен Кинг", true};
    Book b2 = {"Зеленая миля", "Стивен Кинг", true};
    Book b3 = {"Сияние", "Стивен Кинг", true};
    Book b4 = {"Мизери", "Стивен Кинг", true};
    Book b5 = {"Стихи", "Сола Монова", true};
    Book b6 = {"Стихи", "Владимир Набоков", true};
    Book b7 = {"Ведьмин день", "Эдуард Веркин", true};

    Library library = Library({&b1, &b2, &b3, &b4, &b5, &b6, &b7});
    library.printRange();

    Reader testAcc = Reader (1);
    library.takeBook(testAcc, &b1);
    library.takeBook(testAcc, &b2);
    library.takeBook(testAcc, &b7);
    testAcc.printRange();
    library.printRange();
}
