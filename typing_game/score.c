#include"team.h"
#define SIZE 100
#define SNUM 5


void scoreChart(void)
{
    system("cls");
    extern int s_count; //meanWord에서의 s_count
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
        printf("입력된 점수가 없습니다\n\n");
    }
    else
    {
        printf("최종결과\n\n");
        printf("순서\t\t이름(학번)\t\t\t초급\t\t중급\t\t상급\t\t최상\t\t총점\n\n");
        for (j = 0; j < s_count; j++)
        {
            printf("%d\t\t%s (%s)\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n\n",
                j + 1, student[j].name, student[j].num, student[j].score1, student[j].score2, student[j].score3, student[j].score4, student[j].totalscore);
        }
    }

    char ch;
    gotoxy(30, 20);
    printf("종료하려면 [BACKSPACE]를 누르세요\n");
    ch = _getch();
    if (ch == 8)
        choice_game();


}