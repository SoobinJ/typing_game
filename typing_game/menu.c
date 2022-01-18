#include"team.h"

void gotoxy(int x, int y) {
    COORD Cur = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
void start_screen() {
    int s_key, tic = 0;
    system("cls");
    printf("\n\n\n\n");
    printf("    #####   #   #   ####    #   #   #    ###        ###      #     #   #   #####\n");
    printf("      #      # #    #   #   #   ##  #   #          #        # #    ## ##   #    \n");
    printf("      #       #     ####    #   # # #   # ###      # ###   #   #   # # #   #### \n");
    printf("      #       #     #       #   #  ##   #   #      #   #   #####   # # #   #    \n");
    printf("      #       #     #       #   #   #    ###        ###    #   #   #   #   #####\n");
    printf("\n\n\n\n");
    printf("                                                              Team. 건컴타자연습\n\n");

    while (1) {
        gotoxy(33, 17);
        if (tic % 2 == 0)
            printf("Press 's' to start game");
        else if (tic % 2 == 1)
            printf("                        ");

        Sleep(500);
        tic++;
        if (_kbhit()) {
            s_key = _getch();
            if (s_key == 's') break;
        }
    }
}
char choice_game() {
    char x;
    do {
        system("cls");
        gotoxy(33, 6); printf("1. 랜덤 문자 게임");
        gotoxy(33, 8); printf("2. 의미 있는 단어 게임");
        gotoxy(33, 10); printf("3. 영어 타자 연습");
        gotoxy(33, 12); printf("4. 점수 보기");
        gotoxy(33, 14); printf("h. 도움말");
        gotoxy(33, 18); printf("[BACKSPACE] 뒤로가기");
        gotoxy(33, 20); printf("[ESC] 게임 종료");
        x = _getch();
    } while (x != '1' && x != '2' && x != '3' && x != '4' && x != 'h' && x != 8 && x != 27);
    return x;
}
void help() {
    char x;
    do {
        system("cls");
        gotoxy(31, 2); printf("[건컴 타자 연습 게임]");
        gotoxy(20, 4); printf("- 게임에 따라 생성된 글자를 입력한다.");
        gotoxy(20, 6); printf("- 오답을 입력하면 벌점 시간이 부여된다.");
        gotoxy(20, 8); printf("- 문제 생성 10초 후 자동으로 다음 문제가 나온다.");
        gotoxy(20, 10); printf("- 60점을 넘기면 자동으로 다음 난이도를 진행한다.");
        gotoxy(20, 12); printf("- 마지막 난이도를 클리어하면 점수를 기록할 수 있다.");
        gotoxy(20, 14); printf("- 해당 난이도 불합격 시 r을 3초 이내에 누르면 재도전할 수 있다.");
        gotoxy(33, 18); printf("[영어 타자 연습]");
        gotoxy(20, 20); printf("- 생성된 단어 혹은 문장을 입력한다.");
        gotoxy(20, 22); printf("- 분당 타자속도와 정확도가 확인할 수 있다.");
        gotoxy(26, 26); printf("돌아가려면 [BACKSPACE]를 누르세요.");
        x = _getch();
    } while (x != 8);
}
char difficult() {
    int x;
    do {
        system("cls");
        gotoxy(33, 6); printf("1. 초급");
        gotoxy(33, 8); printf("2. 중급");
        gotoxy(33, 10); printf("3. 상급");
        gotoxy(33, 12); printf("4. 최상급");
        gotoxy(33, 18); printf("[BACKSPACE] 뒤로가기");
        x = _getch();
    } while (x != '1' && x != '2' && x != '3' && x != '4' && x != 8);
    return x;
}
char pracKind() {
    char x;
    do {
        system("cls");
        gotoxy(33, 6); printf("1. 단어");
        gotoxy(33, 8); printf("2. 문장");
        gotoxy(33, 18); printf("[BACKSPACE] 뒤로가기");
        x = _getch();
    } while (x != '1' && x != '2' && x != 8);
    return x;
}
