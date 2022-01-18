#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#define NSIZE 100
#define SNUM 10

//menu.c
void gotoxy(int, int);		// 커서이동
void start_screen();		// 시작화면
char choice_game();			// 게임 선택
void help();
char difficult();			// 난이도 선택
char pracKind();
//randomWord.c
void randomWord();			// 랜덤 문자 게임
void randomGame(char);      // 랜덤 문자열 길이
void make_r1(char*);		// 초급
void make_r2(char*);		// 중급
void show_r3(char*);
void show_r4(char*);

//meanWord.c
void meanWord();
void meanGame(char);
void make_m1(char**);
void make_m2(char*, char*);

//pracWord.c
void pracWord();			// 의미 있는 문자 게임
void pracGame(char);
void pracHelp(char);
void get_string1(char**);
void get_string3(char**);

//scoreChart.c
void scoreChart();          //의미있는 문자 점수
void scoreChart2();         //랜덤문자 점수

struct information //의미있는단어 점수저장용
{
    char name[NSIZE];
    char num[NSIZE];
    int score1; //하
    int score2; //중
    int score3; //상
    int score4; //최상
    int totalscore;
};

struct score //의미있는단어 점수저장용
{
    int score1;
    int score2;
    int score3;
    int score4;
};


struct score X[SNUM];
struct information student[SNUM];

struct information2 //랜덤문자 점수저장용
{

    char name[NSIZE];
    char num[NSIZE];
    int score1; //하
    int score2; //중
    int score3; //상
    int score4; //최상
    int totalscore;
};

struct score2 //랜덤문자 점수저장용
{
    int score1;
    int score2;
    int score3;
    int score4;
};

struct information2 stud[SNUM];
struct score2 XX[SNUM];
