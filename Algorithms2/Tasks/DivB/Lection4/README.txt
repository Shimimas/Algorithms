Словари и сортировка подсчётом.

1) Толя-Карп запросил для себя n посылок с «Аллигатор-экспресс».

Посылка представляет из себя ящик. Внутри ящика лежит целое число ai. Номер на ящике di указывает на цвет числа, лежащего внутри.

Толю-Карпа интересует, чему будут равны значения чисел, если сложить между собой все те, что имеют одинаковый цвет. 
Напишите, пожалуйста, программу, которая выводит результат.

Формат ввода
В первой строке одно число n (0 ≤ n ≤ 2*105).

В следующих n строках заданы по два числа: цвет числа в ящике di и значение числа ai (-1018 ≤ di, ai ≤ 1018).

Гарантируется, что сумма чисел одного цвета не превышает 1018.

Формат вывода
Выведите в порядке возрастания номера цвета пары чисел, каждая в новой строке: номер цвета и сумму всех чисел данного цвета.

2) Как известно, в США президент выбирается не прямым голосованием, а путем двухуровневого голосования. 
Сначала проводятся выборы в каждом штате и определяется победитель выборов в данном штате. 
Затем проводятся государственные выборы: на этих выборах каждый штат имеет определенное число голосов — число выборщиков от этого штата. 
На практике, все выборщики от штата голосуют в соответствии с результами голосования внутри штата, 
то есть на заключительной стадии выборов в голосовании участвуют штаты, имеющие различное число голосов. 
Вам известно за кого проголосовал каждый штат и сколько голосов было отдано данным штатом. 
Подведите итоги выборов: для каждого из участника голосования определите число отданных за него голосов.

Формат ввода
Каждая строка входного файла содержит фамилию кандидата, за которого отдают голоса выборщики этого штата, 
затем через пробел идет количество выборщиков, отдавших голоса за этого кандидата.

Формат вывода
Выведите фамилии всех кандидатов в лексикографическом порядке, затем, через пробел, количество отданных за них голосов.

3) Дан текст. Выведите все слова, встречающиеся в тексте, по одному на каждую строку. 
Слова должны быть отсортированы по убыванию их количества появления в тексте, а при одинаковой частоте появления — в лексикографическом порядке. 
Указание. После того, как вы создадите словарь всех слов, вам захочется отсортировать его по частоте встречаемости слова. 
Желаемого можно добиться, если создать список, элементами которого будут кортежи из двух элементов: частота встречаемости слова и само слово. 
Например, [(2, 'hi'), (1, 'what'), (3, 'is')]. 
Тогда стандартная сортировка будет сортировать список кортежей, при этом кортежи сравниваются по первому элементу, а если они равны — то по второму. 
Это почти то, что требуется в задаче.

Формат ввода
Вводится текст.

Формат вывода
Выведите ответ на задачу.

4) Статья 83 закона “О выборах депутатов Государственной Думы Федерального Собрания Российской Федерации” 
определяет следующий алгоритм пропорционального распределения мест в парламенте.

Необходимо распределить 450 мест между партиями, участвовавших в выборах. 
Сначала подсчитывается сумма голосов избирателей, поданных за каждую партию и подсчитывается сумма голосов, поданных за все партии. 
Эта сумма делится на 450, получается величина, называемая “первое избирательное частное” 
(смысл первого избирательного частного - это количество голосов избирателей, которое необходимо набрать для получения одного места в парламенте).

Далее каждая партия получает столько мест в парламенте, чему равна целая часть от деления числа голосов за данную партию на первое избирательное частное.

Если после первого раунда распределения мест сумма количества мест, отданных партиям, меньше 450, 
то оставшиеся места передаются по одному партиям, в порядке убывания дробной части частного от деления числа голосов за данную партию на первое избирательное частное.
Если же для двух партий эти дробные части равны, то преимущество отдается той партии, которая получила большее число голосов.

Формат ввода
На вход программе подается список партий, участвовавших в выборах. 
Каждая строка входного файла содержит название партии 
(строка, возможно, содержащая пробелы), затем, через пробел, количество голосов, полученных данной партией – число, не превосходящее 108.

Формат вывода
Программа должна вывести названия всех партий и количество голосов в парламенте, полученных данной партией. 
Названия необходимо выводить в том же порядке, в котором они шли во входных данных.

5) Клуб Юных Хакеров организовал на своем сайте форум. 
Форум имеет следующую структуру: каждое сообщение либо начинает новую тему, либо является ответом на какое-либо предыдущее сообщение и принадлежит той же теме.

После нескольких месяцев использования своего форума юных хакеров заинтересовал вопрос - какая тема на их форуме наиболее популярна. Помогите им выяснить это.

Формат ввода
В первой строке вводится целое число N - количество сообщений в форуме (1 <= N <= 1000). 
Следующие строки содержат описание сообщений в хронологическом порядке.

Описание сообщения, которое представляет собой начало новой темы, состоит из трех строк. 
Первая строка содержит число 0. Вторая строка содержит название темы.
Длина названия не превышает 30 символов. Третья строка содержит текст сообщения.

Описание сообщения, которое является ответом на другое сообщение, состоит из двух строк. 
Первая строка содержит целое число - номер сообщения, ответом на которое оно является. 
Сообщения нумеруются, начиная с единицы. Ответ всегда появляется позже, чем сообщение, ответом на которое он является. 
Вторая строка содержит текст сообщения.

Длина каждого из сообщений не превышает 100 символов.

Формат вывода
Выведите название темы, к которой относится наибольшее количество сообщений. 
Если таких тем несколько, то выведите первую в хронологическом порядке