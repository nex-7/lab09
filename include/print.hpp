#include <string>
#include <fstream>
#include <iostream>
/*!
    \brief Функция копирования текстовой строки
    \param[in] text Копирование текстовой строки
    \param[out] out Вывод текстовой строки на экран для контроля
    
    Код функции выглядит следующим образом:
    \code
        void print(const std::string& text, std::ostream& out = std::cout);
    \endcode
*/
void print(const std::string& text, std::ostream& out = std::cout);
/*!
    \brief Функция копирования текстовой строки
    \param[in] text Копирование текстовой строки
    \param[out] out Вывод текстовой строки на экран для контроля
    
    Код функции выглядит следующим образом:
    \code
        void print(const std::string& text, std::ostream& out = std::cout);
    \endcode
*/
void print(const std::string& text, std::ofstream& out);
