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
        printf("입력된 점수가 없습니다\n\n");
    }
    else
    {
        printf("최종결과\n\n");
        printf("순서\t\t이름(학번)\t\t\t초급\t\t중급\t\t상급\t\t최상\t\t총점\n\n");
        for (j = 0; j < ss_count; j++)
        {
            printf("%d\t\t%s (%s)\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n\n",
                j + 1, stud[j].name, stud[j].num, stud[j].score1, stud[j].score2, stud[j].score3, stud[j].score4, stud[j].totalscore);
        }
    }

    char ch;
    gotoxy(30, 20);
    printf("종료하려면 [BACKSPACE]를 누르세요\n");
    ch = _getch();
    if (ch == 8)
        choice_game();


}