#include "team.h"
#define SIZE 20
#define TIME_LIMIT 10
#define NUM 10
#define XSIZE 20

void meanWord() {
    system("cls");
    char menu;
    menu = difficult();
    system("cls");
    meanGame(menu);
}
void show_m4(char* string);
void result(int time, int menu);
void print_result(int time, int wrong, int menu);
extern int s_count = 0; //X배열의 인덱스, 단계별 점수 구분용도
extern int k = 0; //student배열의 인덱스, 입력자 구분용도
extern int count; //make_m2에서 사용됨

void meanGame(char menu) {
    if (menu == 8);
    else {
        printf("\n- 영단어가 총 10문제 나타납니다.\n");
        printf("- 오답을 입력하면 5초 벌점이 있습니다.\n");
        printf("- 문제당 최대 10초 주어집니다.\n");
        printf("- 게임을 종료하려면 [ESC]를 눌러주세요.\n");
        printf("-----------------------------------------------------\n");
        switch (menu) {
        case '1': printf("초급 난이도 입니다.\n소문자를 입력하세요.\n"); break;
        case '2': printf("중급 난이도 입니다.\n대소문자를 입력하세요.\n"); break;
        case '3': printf("상급 난이도 입니다.\n깜빡이는 글자를 입력하세요.\n"); break;
        case '4': printf("최상급 난이도 입니다.\n글자를 거꾸로 입력하세요.\n"); break;
        }
        printf("-----------------------------------------------------\n");
        for (int i = 5; i >= 1; i--) {
            printf("  %d      ", i);
            Sleep(1000);
        }
        printf("Start!!\n\a");
        printf("-----------------------------------------------------\n");
        char ch, input[SIZE] = { '\0' };
        int s_time, j = 0, num = 1, wrong = 0;
        int t1, t2, t_time, score;
        extern int m;
        char* word = NULL;
        char w[SIZE] = { '\0' };

        gotoxy(0, 4 * num + 7);
        switch (menu) {
        case '1':get_string1(&word); printf("%s\n", word); break;
        case '2':get_string1(&word); make_m2(word, w); break;
        case '3':get_string1(&word); show_r3(word); break;
        case '4':get_string1(&word); show_m4(word); break;
        }
        t1 = time(0);
        s_time = time(0);
        while (num <= NUM) {
            if (menu == '3') {
                gotoxy(0, 4 * num + 7);
                show_r3(word);
                Sleep(100);
            }
            if (time(0) == s_time + TIME_LIMIT) {
                gotoxy(0, 4 * num + 9);
                wrong++;
                printf("늦었습니다. 문제: %d/10 오답: %d", num, wrong);
                num++;
                j = 0;
                s_time = time(0);

                gotoxy(0, 4 * num + 7);
                if (num <= NUM) {
                    switch (menu) {
                    case '1':get_string1(&word); printf("%s\n", word); break;
                    case '2':get_string1(&word); make_m2(word, w); break;
                    case '3':get_string1(&word); show_r3(word); break;
                    case '4':get_string1(&word); show_m4(word); break;
                    }
                }
            }
            if (_kbhit()) {
                gotoxy(j, 4 * num + 8);
                ch = _getch();
                if (ch == 27) {
                    X[s_count].score1 = X[s_count].score2 = X[s_count].score3 = X[s_count].score4 = 0;
                    break;
                }
                if (ch == 8 && j != 0) {
                    printf("\b \b");
                    j--;
                }
                if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'z')) {
                    input[j] = ch;
                    if (menu == '2') {
                        if (w[j] != input[j])
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        printf("%c", ch);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        j++;
                    }
                    else {
                        if (word[j] != input[j])
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        printf("%c", ch);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        j++;
                    }
                }
                if (j >= strlen(word)) {
                    input[strlen(word)] = 0;
                    gotoxy(0, 4 * num + 9);
                    if (menu == '2') {
                        if (!strcmp(w, input)) {
                            printf("정답입니다. 문제: %d/10 오답: %d", num, wrong);
                        }
                        else {
                            wrong++;
                            printf("오답입니다. 문제: %d/10 오답: %d\a", num, wrong);
                        }
                        gotoxy(0, 4 * num + 7);
                        printf("%s", w);
                    }
                    if (menu == '1' || menu == '3' || menu == '4') {
                        if (!strcmp(word, input)) {
                            printf("정답입니다. 문제: %d/10 오답: %d", num, wrong);
                        }
                        else {
                            wrong++;
                            printf("오답입니다. 문제: %d/10 오답: %d\a", num, wrong);
                        }
                        gotoxy(0, 4 * num + 7);
                        printf("%s", word);
                    }
                    Sleep(1000);
                    num++;
                    j = 0;
                    s_time = time(0);
                    gotoxy(0, 4 * num + 7);
                    if (num <= NUM) {
                        switch (menu) {
                        case '1':get_string1(&word); printf("%s\n", word); break;
                        case '2':get_string1(&word); make_m2(word, w); break;
                        case '3':get_string1(&word); show_r3(word); break;
                        case '4':get_string1(&word); show_m4(word); break;
                        }
                    }
                }
            }
        }
        t2 = time(0);
        t_time = (t2 - t1) + wrong * 5;

        if (num == NUM + 1)
        {
            switch (menu)
            {
            case '1':
                result(t_time, menu);
                break;
            case '2':
                result(t_time, menu);
                break;
            case '3':
                result(t_time, menu);
                break;
            case '4':
                result(t_time, menu);
                break;
            }
        }

        switch (menu)
        {
        case '1':
            print_result(t2 - t1, wrong, menu);
            break;
        case '2':
            print_result(t2 - t1, wrong, menu);
            break;
        case '3':
            print_result(t2 - t1, wrong, menu);
            break;
        case '4':
            print_result(t2 - t1, wrong, menu);
            break;
        }
    }
}

void result(int time, int menu) //단계별 점수저장용
{
    if (menu == '1')
    {
        if (time < 40) X[s_count].score1 = 100;
        else if (time > 90) X[s_count].score1 = 0;
        else X[s_count].score1 = 180 - time * 2;
    }
    else if (menu == '2')
    {
        if (time < 40) X[s_count].score2 = 100;
        else if (time > 90) X[s_count].score2 = 0;
        else X[s_count].score2 = 180 - time * 2;
    }
    else if (menu == '3')
    {
        if (time < 40) X[s_count].score3 = 100;
        else if (time > 90) X[s_count].score3 = 0;
        else X[s_count].score3 = 180 - time * 2;
    }
    else
    {
        if (time < 40) X[s_count].score4 = 100;
        else if (time > 90) X[s_count].score4 = 0;
        else X[s_count].score4 = 180 - time * 2;
    }
}

void print_result(int time, int wrong, int menu) //결과출력함수
{
    char ch;
    if (menu == '1')
    {
        printf("시간: %d초 오답: %d회 점수: %d점\n", time, wrong, X[s_count].score1);
        if (X[s_count].score1 >= 60) {
            if (menu == '4') {
                printf("합격입니다. 마지막 단계를 통과하셨습니다.");
                Sleep(3000);
            }
            else {
                printf("합격입니다. 다음 단계로 넘어갑니다.\n");
                menu += 1;
                Sleep(3000);
                system("cls");
                meanGame(menu);
            }
        }
        else {
            printf("탈락입니다.\a\n");
            printf("Press [r] to restart.\n");
            printf("-----------------------------------------------------\n");
            for (int i = 3; i > 0; i--) {
                printf("  %d      ", i);
                Sleep(1000);
            }
            if (_kbhit()) {
                ch = _getch();
                printf("RESTART");
                Sleep(2000);
                system("cls");
                if (ch == 'r') meanGame(menu);
            }
            else {
                printf("GAME OVER");
                Sleep(3000);
            }
        }
    }

    else if (menu == '2')
    {
        printf("시간: %d초 오답: %d회 점수: %d점\n", time, wrong, X[s_count].score2);
        if (X[s_count].score2 >= 60) {
            if (menu == '4') {
                printf("합격입니다. 마지막 단계를 통과하셨습니다.");
                Sleep(3000);
            }
            else {
                printf("합격입니다. 다음 단계로 넘어갑니다.\n");
                menu += 1;
                Sleep(3000);
                system("cls");
                meanGame(menu);
            }
        }
        else {
            printf("탈락입니다.\a\n");
            printf("Press [r] to restart.\n");
            printf("-----------------------------------------------------\n");
            for (int i = 3; i > 0; i--) {
                printf("  %d      ", i);
                Sleep(1000);
            }
            if (_kbhit()) {
                ch = _getch();
                printf("RESTART");
                Sleep(2000);
                system("cls");
                if (ch == 'r') meanGame(menu);
            }
            else {
                printf("GAME OVER");
                Sleep(3000);
            }
        }
    }

    else if (menu == '3')
    {
        printf("시간: %d초 오답: %d회 점수: %d점\n", time, wrong, X[s_count].score3);
        if (X[s_count].score3 >= 60) {
            if (menu == '4') {
                printf("합격입니다. 마지막 단계를 통과하셨습니다.");
                Sleep(3000);
            }
            else {
                printf("합격입니다. 다음 단계로 넘어갑니다.\n");
                menu += 1;
                Sleep(3000);
                system("cls");
                meanGame(menu);
            }
        }
        else {
            printf("탈락입니다.\a\n");
            printf("Press [r] to restart.\n");
            printf("-----------------------------------------------------\n");
            for (int i = 3; i > 0; i--) {
                printf("  %d      ", i);
                Sleep(1000);
            }
            if (_kbhit()) {
                ch = _getch();
                printf("RESTART");
                Sleep(2000);
                system("cls");
                if (ch == 'r') meanGame(menu);
            }
            else {
                printf("GAME OVER");
                Sleep(3000);
            }
        }
    }

    else if (menu == '4')
    {

        printf("시간: %d초 오답: %d회 점수: %d점\n", time, wrong, X[s_count].score4);
        if (X[s_count].score4 >= 60) {
            if (menu == '4') {
                printf("합격입니다. 마지막 단계를 통과하셨습니다.");
                Sleep(3000);
                s_count++;
                system("cls");
                gotoxy(33, 10);
                printf("이름을 입력하세요: ");
                gets_s(student[k].name, XSIZE);
                gotoxy(33, 12);
                printf("학번을 입력하세요: ");
                gets_s(student[k].num, XSIZE);
                gotoxy(33, 14);
                printf("%s님의 점수가 저장되었습니다. 수고하셨습니다!!", student[k].name);
                k++;
                Sleep(3000);
            }
            else {
                printf("합격입니다. 다음 단계로 넘어갑니다.\n");
                menu += 1;
                Sleep(3000);
                system("cls");
                meanGame(menu);
            }
        }
        else {
            printf("탈락입니다.\a\n");
            printf("Press [r] to restart.\n");
            printf("-----------------------------------------------------\n");
            for (int i = 3; i > 0; i--) {
                printf("  %d      ", i);
                Sleep(1000);
            }
            if (_kbhit()) {
                ch = _getch();
                printf("RESTART");
                Sleep(2000);
                system("cls");
                if (ch == 'r') meanGame(menu);
            }
            else {
                printf("GAME OVER");
                Sleep(3000);
            }
        }
    }
}


void make_m2(char* string, char* s) {
    char a[SIZE] = { 0 };
    strcpy(a, string);
    int count = 0;
    int i;
    do {
        i = rand() % strlen(string);
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            a[i] = 'A' + (a[i] - 'a');
        }
        else
            a[i];
        count++;
    } while (count < 3);
    strcpy(s, a);
    printf("%s", a);
}

void show_m4(char* string)
{
    for (int i = strlen(string); i >= 0; i--)
        printf("%c", string[i]);
    printf("\n");
}