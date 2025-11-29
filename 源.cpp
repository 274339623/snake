#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct p {
    int x;
    int y;
} p;
typedef struct act {
    p head;
    p tail[100];

} act;
act snake = { 0 };
int L = 0;
p g;
int gameover = 0;
int score = 0;
void prime() {
    srand(time(NULL));
    g.x = rand() % 18+1;
    g.y = rand() % 38+1;
    
}

void map() {
    static int firstCall = 1;
    if (firstCall) {
        system("cls");
        firstCall = 0;
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0, 0 };
    SetConsoleCursorPosition(hConsole, coord);

    
    int i, j;
    int a[20][40] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

    };
    a[snake.head.x][snake.head.y] = 2;
    for (int q = 0;q < L;q++)
        a[snake.tail[q].x][snake.tail[q].y] = 3;
    a[g.x][g.y] = 4;
    while (snake.head.x == g.x && snake.head.y == g.y) {
        L++;
        score += 10;
        prime();
    }
    for (i = 0;i < 20;i++) {
        for (j = 0;j < 40;j++) {
            if (a[i][j] == 1) printf("++");
            if (a[i][j] == 0) printf("  ");
            if (a[i][j] == 2) printf("啊");//头
            if (a[i][j] == 3) printf("嘿");//尾巴
            if (a[i][j] == 4) printf("()");//果实
        }
        printf("\n");
    }
}

void Acttail() {
    
    p oldHead = snake.head;

    
    for (int i = L; i > 0; i--) {
        snake.tail[i].x = snake.tail[i - 1].x;
        snake.tail[i].y = snake.tail[i - 1].y;
    }

    
    if (L > 0) {
        snake.tail[0].x = oldHead.x;
        snake.tail[0].y = oldHead.y;
    }
}

void Actsnake(int n) {
    switch (n) {
    case 1: // 右
        snake.head.y++;
        break;
    case 2: // 左
        snake.head.y--;
        break;
    case 3: // 上
        snake.head.x--;
        break;
    case 4: // 下
        snake.head.x++;
        break;
    }
}

int getInput(int n) {
    static int currentDirection = 1;  // 默认向右

    if (_kbhit()) {  // 检查是否有按键输入
        char ch = _getch();  // 获取按键

        switch (ch) {
        case 'a': case 'A':
            if (currentDirection != 1)  // 防止反向移动
                currentDirection = 2;   // 左
            break;
        case 'd': case 'D':
            if (currentDirection != 2)
                currentDirection = 1;   // 右
            break;
        case 'w': case 'W':
            if (currentDirection != 4)
                currentDirection = 3;   // 上
            break;
        case 's': case 'S':
            if (currentDirection != 3)
                currentDirection = 4;   // 下
            break;
        case'p':case'P':
            printf("按任意键继续游戏");
            _getch();
            break;
        case'x':case'X':
            gameover = 1;
            break;
        }
    }

    return currentDirection;
}

int main() {
    FILE* fp = fopen("D:\\666\\snackGrade\\bestgrade.txt", "r");
    int h;
    fscanf(fp, "%d", &h);
    fclose(fp);
    snake.head.x = 3;
    snake.head.y = 4;
    for (int i = 0; i < 100; i++) {
        snake.tail[i].x = -1;
        snake.tail[i].y = -1;
    }
    prime();
    int n = 1;
    while (1) {
       n= getInput(n);
       Acttail();
        Actsnake(n);     
        if (gameover) {
            printf("游戏结束，你得了%d分\n",score);
            _getch();
            break;
        }
        int b = 0;
        for (int i = 0;i < L;i++) {
            if (snake.head.x == snake.tail[i].x && snake.head.y == snake.tail[i].y) {
                printf("你撞到自己了");
                printf("游戏结束，你得了%d分\n", score);
                b = 1;
                _getch();
                  break;
            }
        }
        if (b) break;
        if (snake.head.x <= 0 || snake.head.x >= 19 ||
            snake.head.y <= 0 || snake.head.y >= 39) {
            printf("撞墙了！");
            printf("游戏结束，你得了%d分\n", score);
            _getch();
            break;
        }
                           
        
        map();
        Sleep(200);
        printf("当前分数：%d\n", score);
        
        printf("最佳纪录：%d分\n",h);
        
    }

    if (score > h) {
        FILE* fpp = fopen("D:\\666\\snackGrade\\bestgrade.txt", "w");
        printf("恭喜你打破最佳纪录！\n");
        fprintf(fpp, "%d", score);
        fclose(fpp);
    }

    
 

    
    return 0;
}


