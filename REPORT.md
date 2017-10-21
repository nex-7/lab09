[![Build Status](https://travis-ci.org/nex-7/lab08.svg?branch=master)](https://travis-ci.org/nex-7/lab08)

## Laboratory work VII

Данная лабораторная работа посвещена изучению систем документирования исходного кода на примере **Doxygen**

```ShellSession
$ open https://www.stack.nl/~dimitri/doxygen/manual/index.html
```

## Tasks

- [X] 1. Создать публичный репозиторий с названием **lab08** на сервисе **GitHub**
- [X] 2. Выполнить инструкцию учебного материала
- [X] 3. Ознакомиться со ссылками учебного материала
- [X] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

Устанавливаем переменную окружения `GITHUB_USERNAME`.
```ShellSession
$ export GITHUB_USERNAME=TalkedDevotee # Установка переменной окружения
$ alias edit=vim # Выбираем текстковый редактор Vim
```

Скачиваем лабораторную работу №6 в папку `lab08`.
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab06 lab08 # Загрузка гита в папку lab08
$ cd lab08 # Переходим в папку lab08
$ git remote remove origin # Очищаем путь загрузки гита
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab08 # Устанавливаем путь загрузки гита
```

Создаем папку и файл конфигурации.
```ShellSession
$ mkdir docs # Создаем папку docs
$ doxygen -g docs/doxygen.conf # Конфигурируем doxygen.conf
$ cat docs/doxygen.conf # Проверяем файл конфигурации doxygen
```

В `doxygen.conf` прописываем некоторые значения.
```ShellSession
$ sed -i '' 's/\(PROJECT_NAME.*=\).*$/\1 print/g' docs/doxygen.conf # Называем проект print
$ sed -i '' 's/\(EXAMPLE_PATH.*=\).*$/\1 examples/g' docs/doxygen.conf # Указываем путь к examples
$ sed -i '' 's/\(INCLUDE_PATH.*=\).*$/\1 examples/g' docs/doxygen.conf # Указываем путь к examples, содержащей include
$ sed -i '' 's/\(INPUT *=\).*$/\1 README.md include/g' docs/doxygen.conf # Вводим файл README.md
$ sed -i '' 's/\(USE_MDFILE_AS_MAINPAGE.*=\).*$/\1 README.md/g' docs/doxygen.conf # Назначаем файл README.md основным
$ sed -i '' 's/\(OUTPUT_DIRECTORY.*=\).*$/\1 docs/g' docs/doxygen.conf # Указываем путь каталога docs
```

```ShellSession
$ sed -i '' 's/lab06/lab08/g' README.md # Заменяем lab06 на lab08
```

```ShellSession
# документируем функции print
$ edit include/print.hpp
```

Пушим изменения.
```ShellSession
$ git add . # Добавляем все содержащее в папке lab08
$ git commit -m"added doxygen.conf" # Коммитируем гит
$ git push origin master # Загружаем гит на GitHub
```

```ShellSession
$ travis login --auto # Вход в travis
$ travis enable # Подключаем интеграцию lab08
```

```ShellSession
$ doxygen docs/doxygen.conf # Указываем путь к файл с конфигурацией
$ ls | grep "[^docs]" | xargs rm -rf # Находим docs и удаляем
$ mv docs/html/* . && rm -rf docs # Переносим все файлы в html и удаляем docs
$ git checkout -b gh-pages # Переключаем на коммит gh-pages
$ git add . # Добавляем все содержимое
$ git commit -m"added documentation" # Коммитируем
$ git push origin gh-pages # Пушим изменения
$ git checkout master # Переключаем на коммит master
```

```ShellSession
$ mkdir artifacts && cd artifacts # Создаем папку artifacts и переходим туда
$ gnome-screenshot screenshot.png # Делаем скриншот и сохраняем в artifacts
$ open https://${GITHUB_USERNAME}.github.io/lab08/print_8hpp_source.html # Открываем сайт
$ gdrive upload screenshot.png # или png # Загружаем скриншот на Google Drive
$ SCREENSHOT_ID=`gdrive list | grep screenshot | awk '{ print $1; }'` # Задаем имя скриншота
$ gdrive share ${SCREENSHOT_ID} --role reader --type user --email rusdevops@gmail.com # Открываем доступ в режиме "Просмотр" rusdevops@gmail.com
$ echo https://drive.google.com/open?id=${SCREENSHOT_ID} # Открываем сайт
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=07
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [HTML](https://ru.wikipedia.org/wiki/HTML)
- [LAΤΕΧ](https://ru.wikipedia.org/wiki/LaTeX)
- [man](https://ru.wikipedia.org/wiki/Man_(%D0%BA%D0%BE%D0%BC%D0%B0%D0%BD%D0%B4%D0%B0_Unix))
- [CHM](https://ru.wikipedia.org/wiki/HTMLHelp)
- [PostScript](https://ru.wikipedia.org/wiki/PostScript)

```
Copyright (c) 2017 Братья Вершинины
```
