#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#define NSIZE 100
#define SNUM 10

//menu.c
void gotoxy(int, int);		// Ŀ���̵�
void start_screen();		// ����ȭ��
char choice_game();			// ���� ����
void help();
char difficult();			// ���̵� ����
char pracKind();
//randomWord.c
void randomWord();			// ���� ���� ����
void randomGame(char);      // ���� ���ڿ� ����
void make_r1(char*);		// �ʱ�
void make_r2(char*);		// �߱�
void show_r3(char*);
void show_r4(char*);

//meanWord.c
void meanWord();
void meanGame(char);
void make_m1(char**);
void make_m2(char*, char*);

//pracWord.c
void pracWord();			// �ǹ� �ִ� ���� ����
void pracGame(char);
void pracHelp(char);
void get_string1(char**);
void get_string3(char**);

//scoreChart.c
void scoreChart();          //�ǹ��ִ� ���� ����
void scoreChart2();         //�������� ����

struct information //�ǹ��ִ´ܾ� ���������
{
    char name[NSIZE];
    char num[NSIZE];
    int score1; //��
    int score2; //��
    int score3; //��
    int score4; //�ֻ�
    int totalscore;
};

struct score //�ǹ��ִ´ܾ� ���������
{
    int score1;
    int score2;
    int score3;
    int score4;
};


struct score X[SNUM];
struct information student[SNUM];

struct information2 //�������� ���������
{

    char name[NSIZE];
    char num[NSIZE];
    int score1; //��
    int score2; //��
    int score3; //��
    int score4; //�ֻ�
    int totalscore;
};

struct score2 //�������� ���������
{
    int score1;
    int score2;
    int score3;
    int score4;
};

struct information2 stud[SNUM];
struct score2 XX[SNUM];
