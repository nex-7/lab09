#include <string>
#include <fstream>
#include <iostream>
/*!
    \brief
    \param[in] Копирование текстовой строки
    \param[out] out Вывод текстово строки на экран для контроля
    Код функции выглядит следующим образом:
    \code
        void print(const std::string& text, std::ostream& out = std::cout);
    \endcode
*/
void print(const std::string& text, std::ostream& out = std::cout);
/*!
    \brief
    \param[in] Копирование текстовой строки
    \param[out] out Вывод текстово строки на экран для контроля
    Код функции выглядит следующим образом:
    \code
        void print(const std::string& text, std::ofstream& out);
    \endcode
*/
void print(const std::string& text, std::ofstream& out);
