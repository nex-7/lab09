[![Build Status](https://travis-ci.org/nex-7/lab05.svg?branch=master)](https://travis-ci.org/nex-7/lab05)

## Laboratory work V

Данная лабораторная работа посвещена изучению систем непрерывной интеграции на примере сервиса **Travis CI**

```ShellSession
$ open https://travis-ci.org
```

## Tasks

- [X] 1. Авторизоваться на сервисе **Travis CI** с использованием **GitHub** аккаунта
- [X] 2. Создать публичный репозиторий с названием **lab05** на сервисе **GitHub**
- [X] 3. Ознакомиться со ссылками учебного материала
- [X] 4. Включить интеграцию сервиса **Travis CI** с созданным репозиторием
- [X] 5. Получить токен для **Travis CLI** с правами **repo** и **user**
- [X] 6. Получить фрагмент вставки значка сервиса **Travis CI** в формате **Markdown**
- [X] 7. Установить [**Travis CLI**](https://github.com/travis-ci/travis.rb#installation)
- [X] 8. Выполнить инструкцию учебного материала
- [X] 9. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=TalkedDevotee # Установка значения GITHUB_USERNAME
$ export GITHUB_TOKEN=fd484403717c403ba255b7955775863d # Установка значения GITHUB_TOKEN
```

Скачиваем предыдущую лабораторную работу в папку `lab05` и переходим туда.
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab04 lab05
$ cd lab05
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab05
```

Создаем файл `.travis.yml` для интеграции сервиса `travis-ci.org` с `GitHub.com`.
```ShellSession
$ cat > .travis.yml <<EOF
language: cpp
EOF
```

```ShellSession
$ cat >> .travis.yml <<EOF

script:
- cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
- cmake --build _build
- cmake --build _build --target install
EOF
```

```ShellSession
$ cat >> .travis.yml <<EOF

addons:
  apt:
    sources:
      - george-edison55-precise-backports
    packages:
      - cmake
      - cmake-data
EOF
```

Подключаем `travis`к `GitHub`. Если все прошло успешно, значит, связь для интеграции установлена.
```ShellSession
$ travis login --github-token ${GITHUB_TOKEN} # Аутентификация и сохранение token от GitHub
```

```ShellSession
$ travis lint # Включаем отображение предупреждений для .travis.yml
```

Добавляем значок статуса в файл README.md для того, чтобы узнавать, установлена ли связь между `travis` и `GitHub`.
```ShellSession
$ ex -sc '1i|<фрагмент_вставки_значка>' -cx README.md # Вставляем значок travis-ci.org для статуса
```

Выбираем два файла и коммитируем их.
```ShellSession
$ git add .travis.yml # Добавляем файл для коммита
$ git add README.md # Добавляем файл для коммита
$ git commit -m"added CI" # Коммитируем гит
$ git push origin master # Загружаем гит на сервер
```

Проводим процедуру `travis`.
```ShellSession
$ travis lint # Включаем отображение предупреждений для .travis.yml
$ travis accounts # Отображает учетную запись и её подписку
$ travis sync # Синхронизируется с GitHub
$ travis repos # Просматривает список репозиториев на разрешение для синхронизации
$ travis enable # Подключает проект
$ travis whatsup # Перечисляет обновленные сборки проекта
$ travis branches # Отображает обновленную версию сборки проекта
$ travis history # Отображает процесс создания проекта
$ travis show # Отображает проект
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=05
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [Travis Client](https://github.com/travis-ci/travis.rb)
- [AppVeyour](https://www.appveyor.com/)
- [GitLab CI](https://about.gitlab.com/gitlab-ci/)

```
Copyright (c) 2017 Братья Вершинины
```
