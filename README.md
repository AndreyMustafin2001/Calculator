![image](https://github.com/AndreyMustafin2001/Calculator/assets/150649500/67f036c0-ec1e-49d8-9bd6-c46df43e9f33)
# Простой калькулятор на Qt

Этот проект представляет собой простой калькулятор, реализованный на языке C++ с использованием фреймворка Qt. Калькулятор поддерживает основные арифметические операции: сложение, вычитание, умножение и деление.

## Описание методов

### void Clear();

Метод `Clear()` используется для очистки поля ввода калькулятора. При вызове этого метода последний символ в строке ввода удаляется.

### bool lastCheck();

Метод `lastCheck()` выполняет проверку последнего символа в строке ввода. Если последний символ является цифрой, метод возвращает `true`, в противном случае возвращает `false`. Это используется для предотвращения ввода двух операторов подряд.

### void addSymbol(QChar c);

Метод `addSymbol(QChar c)` добавляет символ `c` в строку ввода калькулятора. Если последний символ в строке является цифрой или проверка `lastCheck()` возвращает `true`, символ добавляется к строке, в противном случае последний символ заменяется новым.

### void OnEq();

Метод `OnEq()` выполняет вычисление арифметического выражения, введенного пользователем в строку ввода калькулятора, и выводит результат в эту же строку. Алгоритм работы метода следующий:

1. Получает строку из поля ввода.
2. Выполняет арифметические вычисления.  Выражение разбивается на числа и операторы, а затем вычисляется в соответствии с приоритетом операций.
3. Выводит результат вычислений в строку ввода.

Калькулятор работает только с целыми числами. Дробные числа не поддерживаются.

## Использование

1. Введите числа и операции с помощью кнопок на калькуляторе или с клавиатуры.
2. Для выполнения операции нажмите на кнопку "=".
3. Для очистки поля ввода нажмите на кнопку "Clear".

## Как запустить

1. Убедитесь, что у вас установлен Qt и его среда разработки Qt Creator.
2. Откройте проект в Qt Creator.
3. Соберите и запустите проект.