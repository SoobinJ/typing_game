#include"team.h"
#define SIZE 30
#define TIME_LIMIT 10
#define NUM 10
#define XSIZE 20

void randomWord() {
    system("cls");
    char menu;
    menu = difficult();
    system("cls");
    randomGame(menu);
}

extern int ss_count = 0; //XX�迭�� �ε���
extern int kk = 0; //�������� �Է��ѻ�� ī��Ʈ��, stud �迭�� �ε���
void rresult(int time, int menu);
void pprint_result(int time, int wrong, int menu);


void randomGame(char menu) {
    if (menu == 8);
    else {
        printf("\n- ���� �����ڰ� �� 10���� ��Ÿ���ϴ�.\n");
        printf("- ������ �Է��ϸ� 5�� ������ �ֽ��ϴ�.\n");
        printf("- ������ �ִ� 10�� �־����ϴ�.\n");
        printf("- ������ �����Ϸ��� [ESC]�� �����ּ���.\n");
        printf("-----------------------------------------------------\n");
        switch (menu) {
        case '1': printf("- �ʱ� ���̵� �Դϴ�.\n- �ҹ��ڸ� �Է��ϼ���.\n"); break;
        case '2': printf("- �߱� ���̵� �Դϴ�.\n- ��ҹ��ڸ� �Է��ϼ���.\n"); break;
        case '3': printf("- ��� ���̵� �Դϴ�.\n- �����̴� ���ڸ� �Է��ϼ���.\n"); break;
        case '4': printf("- �ֻ�� ���̵� �Դϴ�.\n- ���ڸ� �Ųٷ� �Է��ϼ���.\n"); break;
        }
        printf("-----------------------------------------------------\n");
        for (int i = 5; i >= 1; i--) {
            printf("  %d      ", i);
            Sleep(1000);
        }
        printf("Start!!\n\a");
        printf("-----------------------------------------------------\n");
        char word[SIZE] = { '\0' }, ch, input[SIZE] = { '\0' };       // ���, �Է�, �Է�
        int s_time, j = 0, num = 1, wrong = 0;             // ����, �迭��ġ
        int t1, t2, t_time, score;
        //int score1, score2, score3, score4;

        gotoxy(0, 4 * num + 7);
        switch (menu) {                         // ó�� ���
        case '1':make_r1(word); printf("%s\n", word); break;
        case '2':make_r2(word); printf("%s\n", word); break;
        case '3':make_r2(word); show_r3(word); break;
        case '4':show_r4(word); break;
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
                printf("�ʾ����ϴ�. ����: %d/10 ����: %d\a", num, wrong);
                num++;
                j = 0;
                s_time = time(0);
                gotoxy(0, 4 * num + 7);
                switch (menu) {
                case '1':make_r1(word); printf("%s\n", word); break;
                case '2':make_r2(word); printf("%s\n", word); break;
                case '3':make_r2(word); show_r3(word); break;
                case '4':show_r4(word); break;
                }
            }
            if (_kbhit()) {
                gotoxy(j, 4 * num + 8);
                ch = _getch();
                if (ch == 27) break;
                if (ch == 8 && j != 0) {
                    printf("\b \b");
                    j--;
                }
                if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'z')) {
                    input[j] = ch;
                    if (word[j] != input[j])
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //����ٲٱ�
                    printf("%c", ch);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    j++;
                }
                if (j >= strlen(word)) {
                    input[strlen(word)] = 0;
                    gotoxy(0, 4 * num + 9);
                    if (!strcmp(word, input)) {
                        printf("�����Դϴ�. ����: %d/10 ����: %d", num, wrong);
                    }
                    else {
                        wrong++;
                        printf("�����Դϴ�. ����: %d/10 ����: %d\a", num, wrong);
                    }
                    gotoxy(0, 4 * num + 7);
                    printf("%s", word);
                    Sleep(1000);
                    num++;
                    j = 0;
                    s_time = time(0);
                    gotoxy(0, 4 * num + 7);
                    if (num <= NUM) {
                        switch (menu) {
                        case '1':make_r1(word); printf("%s\n", word); break;
                        case '2':make_r2(word); printf("%s\n", word); break;
                        case '3':make_r2(word); show_r3(word); break;
                        case '4':show_r4(word); break;
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
                rresult(t_time, menu);
                break;
            case '2':
                rresult(t_time, menu);
                break;
            case '3':
                rresult(t_time, menu);
                break;
            case '4':
                rresult(t_time, menu);
                break;
            }
        }


        switch (menu)
        {
        case '1':
            pprint_result(t2 - t1, wrong, menu);
            break;
        case '2':
            pprint_result(t2 - t1, wrong, menu);
            break;
        case '3':
            pprint_result(t2 - t1, wrong, menu);
            break;
        case '4':
            pprint_result(t2 - t1, wrong, menu);
            break;
        }
    }
}

void rresult(int time, int menu) //�ܰ躰 ���������
{
    if (menu == '1')
    {
        if (time < 40) XX[ss_count].score1 = 100;
        else if (time > 90) XX[ss_count].score1 = 0;
        else XX[ss_count].score1 = 180 - time * 2;
    }
    else if (menu == '2')
    {
        if (time < 40) XX[ss_count].score2 = 100;
        else if (time > 90) XX[ss_count].score2 = 0;
        else XX[ss_count].score2 = 180 - time * 2;
    }
    else if (menu == '3')
    {
        if (time < 40) XX[ss_count].score3 = 100;
        else if (time > 90) XX[ss_count].score3 = 0;
        else XX[ss_count].score3 = 180 - time * 2;
    }
    else if (menu == '4')
    {
        if (time < 40) XX[ss_count].score4 = 100;
        else if (time > 90) XX[ss_count].score4 = 0;
        else XX[ss_count].score4 = 180 - time * 2;
    }
}

void pprint_result(int time, int wrong, int menu) //�������Լ�
{
    char ch;
    if (menu == '1')
    {
        printf("�ð�: %d�� ����: %dȸ ����: %d��\n", time, wrong, XX[ss_count].score1);
        if (XX[ss_count].score1 >= 60) {
            if (menu == '4') {
                printf("�հ��Դϴ�. ������ �ܰ踦 ����ϼ̽��ϴ�.");
                Sleep(3000);
            }
            else {
                printf("�հ��Դϴ�. ���� �ܰ�� �Ѿ�ϴ�.\n");
                menu += 1;
                Sleep(3000);
                system("cls");
                randomGame(menu);
            }
        }
        else {
            printf("Ż���Դϴ�.\a\n");
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
                if (ch == 'r') randomGame(menu);
            }
            else {
                printf("GAME OVER");
                Sleep(3000);
            }
        }
    }

    else if (menu == '2')
    {
        printf("�ð�: %d�� ����: %dȸ ����: %d��\n", time, wrong, XX[ss_count].score2);
        if (XX[ss_count].score2 >= 60) {
            if (menu == '4') {
                printf("�հ��Դϴ�. ������ �ܰ踦 ����ϼ̽��ϴ�.");
                Sleep(3000);
            }
            else {
                printf("�հ��Դϴ�. ���� �ܰ�� �Ѿ�ϴ�.\n");
                menu += 1;
                Sleep(3000);
                system("cls");
                randomGame(menu);
            }
        }
        else {
            printf("Ż���Դϴ�.\a\n");
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
                if (ch == 'r') randomGame(menu);
            }
            else {
                printf("GAME OVER");
                Sleep(3000);
            }
        }
    }
    else if (menu == '3')
    {
        printf("�ð�: %d�� ����: %dȸ ����: %d��\n", time, wrong, XX[ss_count].score3);
        if (XX[ss_count].score3 >= 60) {
            if (menu == '4') {
                printf("�հ��Դϴ�. ������ �ܰ踦 ����ϼ̽��ϴ�.");
                Sleep(3000);
            }
            else {
                printf("�հ��Դϴ�. ���� �ܰ�� �Ѿ�ϴ�.\n");
                menu += 1;
                Sleep(3000);
                system("cls");
                randomGame(menu);
            }
        }
        else {
            printf("Ż���Դϴ�.\a\n");
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
                if (ch == 'r') randomGame(menu);
            }
            else {
                printf("GAME OVER");
                Sleep(3000);
            }
        }
    }

    else if (menu == '4')
    {

        printf("�ð�: %d�� ����: %dȸ ����: %d��\n", time, wrong, XX[ss_count].score4);
        if (XX[ss_count].score4 >= 60) {
            if (menu == '4') {
                printf("�հ��Դϴ�. ������ �ܰ踦 ����ϼ̽��ϴ�.");
                Sleep(3000);
                ss_count++;
                system("cls");
                gotoxy(33, 10);
                printf("�̸��� �Է��ϼ���: ");
                gets_s(stud[kk].name, XSIZE);
                gotoxy(33, 12);
                printf("�й��� �Է��ϼ���: ");
                gets_s(stud[kk].num, XSIZE);
                gotoxy(33, 14);
                printf("%s���� ������ ����Ǿ����ϴ�. �����ϼ̽��ϴ�!!", stud[kk].name);
                kk++;
                Sleep(3000);
            }
            else {
                printf("�հ��Դϴ�. ���� �ܰ�� �Ѿ�ϴ�.\n");
                menu += 1;
                Sleep(3000);
                system("cls");
                randomGame(menu);
            }
        }
        else {
            printf("Ż���Դϴ�.\a\n");
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
                if (ch == 'r') randomGame(menu);
            }
            else {
                printf("GAME OVER");
                Sleep(3000);
            }
        }
    }
}

void make_r1(char* string) //���̵� �� �������ڻ���
{
    int i;
    int p = rand() % 4 + 4;
    for (i = 0; i < p; i++) {
        string[i] = 'a' + (rand() % 26);
    }
    string[i] = 0;
}

void make_r2(char* string)  //���̵� ��, �� �������ڻ���
{
    int i;
    int p = rand() % 4 + 5;
    for (i = 0; i < p; i++) {
        if (rand() % 2 == 1)
            string[i] = 'a' + (rand() % 26);
        else
            string[i] = 'A' + (rand() % 26);
    }
    string[i] = 0;
}
void show_r3(char* string) {
    if (time(0) % 2 == 0) printf("%s", string);
    else printf("          ");
}
void show_r4(char* string)  //���̵� �ֻ� ���ڿ�����
{

    make_r2(string);
    for (int i = strlen(string); i >= 0; i--)
        printf("%c", string[i]);
    printf("\n");
}