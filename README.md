QJS
===

QJS - кроссплатформенная библиотека для Qt, позволяющая легко производить манипуляции с JSON-структурами в коде Qt-программы.

QJS состоит из двух основных классов:

  - QJS
  - QJSSharedNode

Системные требования
====================

	1. Операционная система UNIX или WINDOWS
	2. Qt 5.0 или выше
	3. GCC 4.7 и выше или MSVC2010 и выше

Установка
---------

В UNIX установка QJS выглядит следующим образом:

	git clone https://github.com/maxvas/qjs
	cd qjs
	qmake
	make install


В Windows установка QJS производится следующими командами:

	git clone https://github.com/maxvas/qjs
	cd qjs
	qmake
	nmake install

Удаление
--------

Для удаления библиотеки из вашей системы выполните команду:

	make clean