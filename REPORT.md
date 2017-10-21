[![Build Status](https://travis-ci.org/nex-7/lab8.svg?branch=master)](https://travis-ci.org/nex-7/lab8)

## Laboratory work VIII

Данная лабораторная работа посвещена изучению средств пакетирования на примере **CPack**

```ShellSession
$ open https://cmake.org/Wiki/CMake:CPackPackageGenerators
```

## Tasks

- [X] 1. Создать публичный репозиторий с названием **lab08** на сервисе **GitHub**
- [X] 2. Выполнить инструкцию учебного материала
- [X] 3. Ознакомиться со ссылками учебного материала
- [X] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

Устанавливаем значение окружения переменной `GITHUB_USERNAME` и `GITHUB_EMAIL`.
```ShellSession
$ export GITHUB_USERNAME=nex-7 # Установка значения GITHUB_USERNAME
$ export GITHUB_EMAIL=a*************@inbox.ru # Установка значения GITHUB_EMAIL
$ alias edit=vim # Настраиваем текстовый редактор
```

Скачиваем предыдущую лабораторную работу №7 в папку `lab08`.
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab07 lab08 # Загружаем гит в папку lab08
$ cd lab08 # Переходим в папку lab08
$ git remote remove origin # Очищаем старый путь загрузки гита
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab08 # Устанавливаем новый путь загрузки гита
```

Редактируем `CMakeLists.txt`, устанавливая новые версии `MAJOR`, `TWEAK`, `PATCH`, `MINOR`.
```ShellSession
$ sed -i '' '/project(print)/a\
set(PRINT_VERSION_STRING "v${PRINT_VERSION}")
' CMakeLists.txt
$ sed -i '' '/project(print)/a\
set(PRINT_VERSION \
\${PRINT_VERSION_MAJOR}.\${PRINT_VERSION_MINOR}.\${PRINT_VERSION_PATCH}.\${PRINT_VERSION_TWEAK})
' CMakeLists.txt
$ sed -i '' '/project(print)/a\
set(PRINT_VERSION_TWEAK 0)
' CMakeLists.txt
$ sed -i '' '/project(print)/a\
set(PRINT_VERSION_PATCH 0)
' CMakeLists.txt
$ sed -i '' '/project(print)/a\ 
set(PRINT_VERSION_MINOR 1)
' CMakeLists.txt
$ sed -i '' '/project(print)/a\ 
set(PRINT_VERSION_MAJOR 0)
' CMakeLists.txt
```

Создаем два файла `DESCRIPTION` и `ChangeLog.md`.
```ShellSession
$ touch DESCRIPTION && edit DESCRIPTION # Создаем и редактируем файл DESCRIPTION
$ touch ChangeLog.md # Создаем файл ChangeLog.md
$ DATE=`date` cat > ChangeLog.md <<EOF
* ${DATE} ${GITHUB_USERNAME} <${GITHUB_EMAIL}> 0.1.0.0
- Initial RPM release
EOF # Вставляем дату времени, имя пользователя и электронную почту
```

Далее редактируем файл `CPackConfig.cmake`.
```ShellSession
$ cat > CPackConfig.cmake <<EOF
include(InstallRequiredSystemLibraries) # Подключаем установленные требуемые файлы библиотек
EOF
```

Устанавливаем все значения.
```ShellSession
$ cat >> CPackConfig.cmake <<EOF
set(CPACK_PACKAGE_CONTACT ${GITHUB_EMAIL}) # Электронная почта
set(CPACK_PACKAGE_VERSION_MAJOR \${PRINT_VERSION_MAJOR}) # Версия MAJOR
set(CPACK_PACKAGE_VERSION_MINOR \${PRINT_VERSION_MINOR}) # Версия MINOR
set(CPACK_PACKAGE_VERSION_PATCH \${PRINT_VERSION_PATCH}) # Версия PATCH
set(CPACK_PACKAGE_VERSION_TWEAK \${PRINT_VERSION_TWEAK}) # Версия TWEAK
set(CPACK_PACKAGE_VERSION \${PRINT_VERSION}) # Версия печати на экран
set(CPACK_PACKAGE_DESCRIPTION_FILE \${CMAKE_CURRENT_SOURCE_DIR}/DESCRIPTION) # Путь к файлу DESCRIPTION
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "static c++ library for printing") # Комментарий
EOF
```

Указываем путь к двум файлам.
```ShellSession
$ cat >> CPackConfig.cmake <<EOF

set(CPACK_RESOURCE_FILE_LICENSE \${CMAKE_CURRENT_SOURCE_DIR}/LICENSE) # Путь к файлу LICENSE
set(CPACK_RESOURCE_FILE_README \${CMAKE_CURRENT_SOURCE_DIR}/README.md) # Путь к файлу к REAMDE.md
EOF
```

Аналогично и здесь.
```ShellSession
$ cat >> CPackConfig.cmake <<EOF

set(CPACK_RPM_PACKAGE_NAME "print-devel") Имя архивирования "print-devel"
set(CPACK_RPM_PACKAGE_LICENSE "MIT") # Лицензия MIT
set(CPACK_RPM_PACKAGE_GROUP "print") # Группа print
set(CPACK_RPM_PACKAGE_URL "https://github.com/${GITHUB_USERNAME}/lab07") # Страница doxygen'а
set(CPACK_RPM_CHANGELOG_FILE \${CMAKE_CURRENT_SOURCE_DIR}/ChangeLog.md) # Путь к файлу лога
set(CPACK_RPM_PACKAGE_RELEASE 1) # Назначаем релиз истиной
EOF
```

```ShellSession
$ cat >> CPackConfig.cmake <<EOF

set(CPACK_DEBIAN_PACKAGE_NAME "libprint-dev") # Имя архивирования "libprint-dev"
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "https://${GITHUB_USERNAME}.github.io/lab07") # Домашняя страница doxygen'а
set(CPACK_DEBIAN_PACKAGE_PREDEPENDS "cmake >= 3.0") # Версия cmake 3.0 и новее
set(CPACK_DEBIAN_PACKAGE_RELEASE 1) # Назначаем архивирование Debian истиной
EOF
```

Подключаем два includ'а
```ShellSession
$ cat >> CPackConfig.cmake <<EOF

include(CPack) # Подключаем CPack
EOF
```

```ShellSession
$ cat >> CMakeLists.txt <<EOF

include(CPackConfig.cmake) # Подключаем файл CPackConfig.cmake
EOF 
```

Замена строки travis'а в `README.md`.
```ShellSession
$ sed -i '' 's/lab07/lab08/g' README.md # Заменяем lab07 на lab08
```

Пушим изменения гита.
```ShellSession
$ git add . # Добавляем все содержимое
$ git commit -m"added cpack config" # Коммитируем гит
$ git push origin master # Загружаем гит
```

Авторизация `travis` и подключение `lab07` к `travis`.
```ShellSession
$ travis login --auto # Процесс авторизации без токена
$ travis enable # Подключаем lab08 к travis'у
```

```ShellSession
$ cmake -H. -B_build # Сканируем CMakeLists.txt
$ cmake --build _build # Создаем папку _build
$ cd _build # Переходим в папку _build
$ cpack -G "TGZ" # Устанавливаем тип архивирования "TGZ"
$ cd .. # Выходим из папки _build
```

```ShellSession
$ cmake -H. -B_build -DCPACK_GENERATOR="TGZ" # Задаем архивирование в tar.gz
$ cmake --build _build --target package # Архивируем
```

```ShellSession
$ mkdir artifacts # Создаем папку artifacts
$ mv _build/*.tar.gz artifacts # Переносим архивацию файла из _build в artifacts
$ tree artifacts # Отображаем древесную папку
artifacts
└── print-0.1.0.0-Linux.tar.gz
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=08
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [DMG](https://cmake.org/cmake/help/latest/module/CPackDMG.html)
- [DEB](https://cmake.org/cmake/help/latest/module/CPackDeb.html)
- [RPM](https://cmake.org/cmake/help/latest/module/CPackRPM.html)
- [NSIS](https://cmake.org/cmake/help/latest/module/CPackNSIS.html)

```
Copyright (c) 2017 Братья Вершинины
```
