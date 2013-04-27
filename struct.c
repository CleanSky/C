#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct CARD {
    char suit[10];
    char face[10];
};

/*模拟洗牌和发牌的过程*/
int main()
{
    char *Suit[] = {"Spades", "Hearts", "Clubs", "Diamonds"};
    char *Face[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    int i, j;
    struct CARD card[52], temp;

    /*将牌顺序存放*/
    for (i = 0; i < 52; i++) {
        strcpy(card[i].suit, Suit[i / 13]);
        strcpy(card[i].face, Face[i % 13]);
    }

    srand(time(NULL));//产生随机数的种子函数

    /*洗牌过程，打乱牌的先后顺序*/
    for (i = 0; i < 52; i++) {
        j = rand() % 52;
        temp = card[i];
        card[i] = card[j];
        card[j] = temp;
    }

    /*输出发牌结果*/
    for (i = 0; i < 52; i++) {
        printf("%10s%10s\n", card[i].suit, card[i].face);
    }

    return 0;
}
