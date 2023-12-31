# Ping-Pong Game
Пошаговая консольная игра Пинг-Понг для Linux, написанная на языке С.
## Описание
Эта программа - реализация игры [Понг](https://ru.wikipedia.org/wiki/Pong_(игра)) для Linux-подобных ОС, написанная на языке С.
## Технологии в проекте
Игра написана на языке С. Игра собирается из проекта с помощью утилиты Make и файла Makefile.
## Техническое описание проекта
### Сборка и запуск игры
Для того, чтобы собрать игру, необходимо открыть папку с проектом в терминале и выполнить команду:

make all

В папке будет создан файл game.out. Выполнив в том же терминале команду:

./game.out

можно запустить игру.
## Использование программы
После запуска игры откроется поле игры:

![image](https://github.com/futurewillbeours/ping-pong_game/assets/134860207/931d4c64-1149-43ba-b3c2-cb50b2bba5b7)

В самом внизу поля отображаются подсказки для игрока. Кнопки a/z и k/m управляют движением доски вверх/вниз для левого и правого игрока соответственно. Нажатие пробела пропускает ход. Чтобы подтвердить ход, нужно нажать Enter. Мяч перемещается после каждого нажатия Enter.

В самом начале матча мяч нахлодится посередине и летит к правому игроку. Если игрок не сможет отбить мяч доской, другой игрок зарабатывает 1 балл и матч начинается заново. Игра заверщается, когда один из игроков не выиграет, заработав 20 очков.
