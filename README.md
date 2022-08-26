# Программа для решения квадратных уравнений
## (ax^2 + bx + c)




От пользователя ожидается ввод трех коэффициентов (через пробел) a, b, c - где a, b, c - действительные числа.
Программа выводит количество корней и сами корни.

- Для запуска программы введите в терминал: 
`$ make run`
## Пример
```
Enter coefficients a b c
1 2 1
One root
-1
```
- Для тестирования программы введите в терминал: make run_test
`$ make run_test`
## Пример(все тесты пройдены)
```
Accept, test=1
Accept, test=2
Accept, test=3
Accept, test=4
Accept, test=5
Accept, test=6
Accept, test=7
Accept, test=8
Accepted - 8, errors - 0
```


## Пример(тесты с ошибкой)
```
Accept, test=1
Accept, test=2
Error, test=3, true_root_numbers = 2, root_numbers = 1
Accept, test=4
Accept, test=5
Accept, test=6
Error, test=7, one_root = -2, second_root = -1, true_first_root = -1, true_second_root = -1
Accept, test=8
Accepted - 6, errors - 2
```

