#include"team.h"
#define SIZE 100
#define SNUM 5


void scoreChart2(void)
{
    system("cls");
    extern int ss_count;
    srand(time(NULL));
    int j, k;

    for (k = 0; k < ss_count; k++)
    {
        stud[k].score1 = XX[k].score1;
        stud[k].score2 = XX[k].score2;
        stud[k].score3 = XX[k].score3;
        stud[k].score4 = XX[k].score4;
        stud[k].totalscore = stud[k].score1 + stud[k].score2 + stud[k].score3 + stud[k].score4;

    }


    if (ss_count == 0)
    {
        gotoxy(30, 10);
        printf("�Էµ� ������ �����ϴ�\n\n");
    }
    else
    {
        printf("�������\n\n");
        printf("����\t\t�̸�(�й�)\t\t\t�ʱ�\t\t�߱�\t\t���\t\t�ֻ�\t\t����\n\n");
        for (j = 0; j < ss_count; j++)
        {
            printf("%d\t\t%s (%s)\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n\n",
                j + 1, stud[j].name, stud[j].num, stud[j].score1, stud[j].score2, stud[j].score3, stud[j].score4, stud[j].totalscore);
        }
    }

    char ch;
    gotoxy(30, 20);
    printf("�����Ϸ��� [BACKSPACE]�� ��������\n");
    ch = _getch();
    if (ch == 8)
        choice_game();


}