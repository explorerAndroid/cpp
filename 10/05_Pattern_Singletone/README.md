Singletone - одиночка
---------------------
Singletone
Дружественный класс
Конструктор
Деструктор
Простейшая реализация Singletone - сделать
все методы и поля статическими
Инициализация генератора случайных чисел
A a1, a2; // Не компилируется
A *a2 = new A(); // Тоже не компилируется
[main.cpp](main.cpp)

Если объект ещё не создан
Создаём его
Можно вызывать private конструктор, т.к.
мы внутри класса T
[singletone.cpp](singletone.cpp)

T - из какого класса хотим сделать Singletone
-static uniqueInstance
Один-единственный экземпляр класса T
+static instance()
Если объект ещё не создан
Создаём его
Можно вызывать private конструктор, т.к.
мы внутри класса T
Первоначально экземпляр класса не создан
[singletone.h](singletone.h)

