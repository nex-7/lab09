[![Build Status](https://travis-ci.org/nex-7/lab06.svg?branch=master)](https://travis-ci.org/nex-7/lab06)

## Laboratory work VI

Данная лабораторная работа посвещена изучению фреймворков для тестирования на примере **Catch**

```ShellSession
$ open https://github.com/philsquared/Catch
```

## Tasks

- [X] 1. Создать публичный репозиторий с названием **lab06** на сервисе **GitHub**
- [X] 2. Выполнить инструкцию учебного материала
- [X] 3. Ознакомиться со ссылками учебного материала
- [X] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

Устанавливаем значение окружения `GITHUB_USERNAME`.
```ShellSession
$ export GITHUB_USERNAME=nex-7
```

Скачиваем предыдущую лабораторную работу в папку `lab06`.
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab05 lab06 # Скачиваем гит с GitHub
$ cd lab06 # Переходим в папку lab06
$ git remote remove origin # Очищаем путь загрузки гита
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab06 # Назначаем новый путь для будущей загрузки гита
```

Создаем тесты.
```ShellSession
$ mkdir tests # Создаем папку tests
$ wget https://github.com/philsquared/Catch/releases/download/v1.9.3/catch.hpp -O tests/catch.hpp # Загружаем файл catch.hpp
$ cat > tests/main.cpp <<EOF
#define CATCH_CONFIG_MAIN # Предоставляем main()
#include "catch.hpp"
EOF
```

```ShellSession
$ sed -i '' '/option(BUILD_EXAMPLES "Build examples" OFF)/a\ # Выделяем определенную строку
option(BUILD_TESTS "Build tests" OFF) # После выделенной строки вставим следующую строку
' CMakeLists.txt # Указываем файл, где будем вставить
$ cat >> CMakeLists.txt <<EOF

$ sed -i '' '/option(BUILD_EXAMPLES "Build examples" OFF)/a\
option(BUILD_TESTS "Build tests" OFF)
' CMakeLists.txt
$ cat >> CMakeLists.txt <<EOF  # добавление в CMakeLists.txt информации и конфигурации тестов
if(BUILD_TESTS)
	enable_testing()
	file(GLOB \${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
	add_executable(check \${\${PROJECT_NAME}_TEST_SOURCES})
	target_link_libraries(check \${PROJECT_NAME} \${DEPENDS_LIBRARIES})
	add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes")	#задаем параметры теста 
											# -s = показываем успешные выполнения теста
											# -r compact = формат вывода
											
endif()
EOF
```

```ShellSession
$ cat >> tests/test1.cpp <<EOF
#include "catch.hpp"
#include <print.hpp>

TEST_CASE("output values should match input values", "[file]") {
  std::string text = "hello";
  std::ofstream out("file.txt");
  
  print(text, out);
  out.close();
  
  std::string result;
  std::ifstream in("file.txt");
  in >> result;
  
  REQUIRE(result == text);  # При условии, что оба потока файла совпали
}
EOF
```

Сборка проекта.
```ShellSession
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install -DBUILD_TESTS=ON
$ cmake --build _build
$ cmake --build _build --target test # Если test задан, он будет запущен после сборки
```

В файле `README.md` в строке заменяем `lab05` на `lab06`, и в `.travis.yml` аналогично, после добавляем новую строку.
```ShellSession
$ sed -i '' 's/lab05/lab06/g' README.md # Заменяем lab05 на lab06
$ sed -i '' 's/\(DCMAKE_INSTALL_PREFIX=_install\)/\1 -DBUILD_TESTS=ON/' .travis.yml # Заменяем строку на DBUILD_TESTS=ON
$ sed -i '' '/cmake --build _build --target install/a\ # Добавляем следующую строку
- cmake --build _build --target test
' .travis.yml
```

```ShellSession
$ travis lint # Включаем отображение предупреждений для .travis.yml
```

Пушим файлы.
```ShellSession
$ git add . # Добавляем все содержимое в папке
$ git commit -m "added tests" # Коммитируем
$ git push origin master # Загружаем гит на GitHub
```

Вход в travis и активация проекта.
```ShellSession
$ travis login --auto # Авторуземся без токена
$ travis enable # Включаем интеграцию к lab06
```

Сделаем скриншот и сохраняем в папку `artifacts`.
```ShellSession
$ mkdir artifacts # Создаем папку artifacts
$ gnome-screenshot
После ввода команды в консоли сохраняем в папку artifacts
$ open https://github.com/${GITHUB_USERNAME}/lab06 # Открываем сайт GitHub с лабораторной работой
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=06
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [Boost.Tests](http://www.boost.org/doc/libs/1_63_0/libs/test/doc/html/)
- [Google Test](https://github.com/google/googletest)

```
Copyright (c) 2017 Братья Вершинины
```

