/*
С помощью именованного канала организовать клиент-серверную обработку данных следующим образом.
Процесс-сервер запускается первым, обнуляет целую переменную-сумматор,
создает именованный канал, открывает его на чтение, затем в бесконечном цикле 
читает очередное целое из канала (во внутреннем представлении int)
и добавляет считанное число к сумматору. 
Получив сигнал SIGINT (сделать соответствующий обработчик сигнала),
сервер выводит на экран текущее значение сумматора, 
закрывает и удаляет именованный канал, и завершается.
    
Процесс-клиент получает в качестве argv[1] число в строковом виде, 
переводит его во внутреннее представление (число типа int) , 
открывает именованный канал на запись и отправляет число серверу, после чего завершается.

Запустить сразу несколько параллельных клиентов из командной строки можно так: 
$>  client 5 &  client 3  & client 4 & client 1 &
Ответ сервера после нажатия Ctl-C:  sum=13
*/

// Серверный процесс:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/myfifo"   // Имя именованного канала

static int sum = 0;

void handler(int sig)
{
    printf("\nОтвет сервера: sum=%d\n", sum);
    unlink(FIFO_NAME);
    exit(0);
}

int main()
{
    signal(SIGINT, handler);   // Установка обработчика сигнала SIGINT
    
    mkfifo(FIFO_NAME, 0666);   // Создание именованного канала

    int fd = open(FIFO_NAME, O_RDONLY);   // Открытие именованного канала на чтение

    while (1)
    {
        int num;
        read(fd, &num, sizeof(num));   // Чтение очередного числа из канала

        sum += num;   // Добавление числа к сумматору
    }

    return 0;
}

// gcc server.c -o server
// ./server