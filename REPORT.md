## Laboratory work IV

Данная лабораторная работа посвещена изучению систем автоматизации сборки проекта на примере **CMake**

```ShellSession
$ open https://cmake.org/
```

## Tasks

- [X] 1. Создать публичный репозиторий с названием **lab04** на сервисе **GitHub**
- [X] 2. Ознакомиться со ссылками учебного материала
- [X] 3. Выполнить инструкцию учебного материала
- [X] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial


Устанавливаем значение `GITHUB_USERNAME`.
```ShellSession
$ export GITHUB_USERNAME=nex-7 # Установка значения GITHUB_USERNAME
```

Скачиваем гит с сервера в папку `lab04`. Перенастраиваем путь для загрузки на сервер в `.git`.
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab03 lab04 # Загрузка гит с сервера в папку lab04
$ cd lab04 # Переход в папку lab04
$ git remote remove origin # Очистка пути для загрузки гита на сервер
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab04 # Установка нового пути
```

Компилируем все содержимое в папке `lab04`.
```ShellSession
$ g++ -I./include -std=c++11 -c sources/print.cpp # Компиляция файла на C++ стандарта 11 версии
$ ls print.o # Вывод файла на экран
$ ar rvs print.a print.o # Создание архива с файлом
$ file print.a # Определяет тип файла
$ g++ -I./include -std=c++11 -c examples/example1.cpp # Компиляция файла на C++ стандарта 11 версии
$ ls example1.o # Вывод файла на экран
$ g++ example1.o print.a -o example1 # Компиляция файлов на C++
$ ./example1 && echo # Выбираем и выводим файл на экран
```

Аналогично и здесь.
```ShellSession
$ g++ -I./include -std=c++11 -c examples/example2.cpp # Компиляция файла на C++ стандарта 11 версии
$ ls example2.o # Вывод файла на экран
$ g++ example2.o print.a -o example2 # Создаем слияние двух файлов example2.o и print.a под новым именем example
$ ./example2 # Выбираем файл
$ cat log.txt && echo # Открываем файл и выводим на экран
```

Удаляем 4 файла, с ними работать не будем.
```ShellSession
$ rm -rf example1.o example2.o print.o # Удаление файлов example1.o и example2.o
$ rm -rf print.a # Удаление файла print.a
$ rm -rf example1 example2 # Удаление файлов example1 example2
$ rm -rf log.txt # Удаление файла log.txt
```

В `CMakeLists.txt` прописываем все необходимые командные строки для управления файлов.
```ShellSession
$ cat > CMakeLists.txt <<EOF
cmake_minimum_required(VERSION 3.0)
project(print)
EOF # Указание версии cmake и создание проекта
```

```ShellSession
$ cat >> CMakeLists.txt <<EOF
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
EOF # Включаем поддержку C++ стандарта 11 версии
```

```ShellSession
$ cat >> CMakeLists.txt <<EOF
add_library(print STATIC \${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)
EOF # Подключаем файл print.cpp в папке sources
```

```ShellSession
$ cat >> CMakeLists.txt <<EOF
include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/include)
EOF # Подключаем заголовочный файл print.hpp в папке include
```

```ShellSession
$ cmake -H. -B_build 4 # Сканируем файл CMakeLists.txt с исходными кодами
$ cmake --build _build # Запускаем cmake
```

```ShellSession
$ cat >> CMakeLists.txt <<EOF

add_executable(example1 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
add_executable(example2 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example2.cpp)
EOF # Подключаем исполняемые файлы example1.cpp и example2.cpp
```

```ShellSession
$ cat >> CMakeLists.txt <<EOF

target_link_libraries(example1 print)
target_link_libraries(example2 print)
EOF # Прописываем ссылку на библиотеку для запуска исполняемых файлов
```

Запускаем `CMakeLists.txt` через `cmake`.
```ShellSession
$ cmake --build _build
$ cmake --build _build --target print
$ cmake --build _build --target example1
$ cmake --build _build --target example2
```

Проверяем файлы.
```ShellSession
$ ls -la _build/libprint.a # Вывод файла на экран
$ _build/example1 && echo # Открываем файл example1 и выводим на экран
hello
$ _build/example2 # Переключаем на файл example2
$ cat log.txt && echo # Открываем файл log.txt и выводим на экран
hello
```

```ShellSession
$ git clone https://github.com/tp-labs/lab04 tmp # Загрузка гита в папку tmp
$ mv -f tmp/CMakeLists.txt . # Переходим в папку tmp без предупреждения о несуществующем файле
$ rm -rf tmp # Удаляем папку tmp
```

Собираем готовые файлы в `_install` и выводим их на экран.
```ShellSession
$ cat CMakeLists.txt # Вывод на экран
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install # Путь для установки собранных файлов
$ cmake --build _build --target install # Установка собранных файлов в _install
$ tree _install # Список каталога _install
```

```ShellSession
$ git add CMakeLists.txt # Добавляем файл в гит
$ git commit -m"added CMakeLists.txt" # Коммит гита
$ git push origin master # Загрузка гита на сервер
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=04
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [Autotools](http://www.gnu.org/software/automake/manual/html_node/Autotools-Introduction.html)
- [CMake](https://cgold.readthedocs.io/en/latest/index.html)

```
Copyright (c) 2017 Братья Вершинины
```

