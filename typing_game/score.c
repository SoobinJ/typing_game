#include"team.h"
#define SIZE 100
#define SNUM 5


void scoreChart(void)
{
    system("cls");
    extern int s_count; //meanWord������ s_count
    srand(time(NULL));
    int j, k;
    for (k = 0; k < s_count; k++)
    {
        student[k].score1 = X[k].score1;
        student[k].score2 = X[k].score2;
        student[k].score3 = X[k].score3;
        student[k].score4 = X[k].score4;
        student[k].totalscore = student[k].score1 + student[k].score2 + student[k].score3 + student[k].score4;

    }



    if (s_count == 0)
    {
        gotoxy(30, 10);
        printf("�Էµ� ������ �����ϴ�\n\n");
    }
    else
    {
        printf("�������\n\n");
        printf("����\t\t�̸�(�й�)\t\t\t�ʱ�\t\t�߱�\t\t���\t\t�ֻ�\t\t����\n\n");
        for (j = 0; j < s_count; j++)
        {
            printf("%d\t\t%s (%s)\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n\n",
                j + 1, student[j].name, student[j].num, student[j].score1, student[j].score2, student[j].score3, student[j].score4, student[j].totalscore);
        }
    }

    char ch;
    gotoxy(30, 20);
    printf("�����Ϸ��� [BACKSPACE]�� ��������\n");
    ch = _getch();
    if (ch == 8)
        choice_game();


}