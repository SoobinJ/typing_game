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
    printf("                                                              Team. ����Ÿ�ڿ���\n\n");

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
        gotoxy(33, 6); printf("1. ���� ���� ����");
        gotoxy(33, 8); printf("2. �ǹ� �ִ� �ܾ� ����");
        gotoxy(33, 10); printf("3. ���� Ÿ�� ����");
        gotoxy(33, 12); printf("4. ���� ����");
        gotoxy(33, 14); printf("h. ����");
        gotoxy(33, 18); printf("[BACKSPACE] �ڷΰ���");
        gotoxy(33, 20); printf("[ESC] ���� ����");
        x = _getch();
    } while (x != '1' && x != '2' && x != '3' && x != '4' && x != 'h' && x != 8 && x != 27);
    return x;
}
void help() {
    char x;
    do {
        system("cls");
        gotoxy(31, 2); printf("[���� Ÿ�� ���� ����]");
        gotoxy(20, 4); printf("- ���ӿ� ���� ������ ���ڸ� �Է��Ѵ�.");
        gotoxy(20, 6); printf("- ������ �Է��ϸ� ���� �ð��� �ο��ȴ�.");
        gotoxy(20, 8); printf("- ���� ���� 10�� �� �ڵ����� ���� ������ ���´�.");
        gotoxy(20, 10); printf("- 60���� �ѱ�� �ڵ����� ���� ���̵��� �����Ѵ�.");
        gotoxy(20, 12); printf("- ������ ���̵��� Ŭ�����ϸ� ������ ����� �� �ִ�.");
        gotoxy(20, 14); printf("- �ش� ���̵� ���հ� �� r�� 3�� �̳��� ������ �絵���� �� �ִ�.");
        gotoxy(33, 18); printf("[���� Ÿ�� ����]");
        gotoxy(20, 20); printf("- ������ �ܾ� Ȥ�� ������ �Է��Ѵ�.");
        gotoxy(20, 22); printf("- �д� Ÿ�ڼӵ��� ��Ȯ���� Ȯ���� �� �ִ�.");
        gotoxy(26, 26); printf("���ư����� [BACKSPACE]�� ��������.");
        x = _getch();
    } while (x != 8);
}
char difficult() {
    int x;
    do {
        system("cls");
        gotoxy(33, 6); printf("1. �ʱ�");
        gotoxy(33, 8); printf("2. �߱�");
        gotoxy(33, 10); printf("3. ���");
        gotoxy(33, 12); printf("4. �ֻ��");
        gotoxy(33, 18); printf("[BACKSPACE] �ڷΰ���");
        x = _getch();
    } while (x != '1' && x != '2' && x != '3' && x != '4' && x != 8);
    return x;
}
char pracKind() {
    char x;
    do {
        system("cls");
        gotoxy(33, 6); printf("1. �ܾ�");
        gotoxy(33, 8); printf("2. ����");
        gotoxy(33, 18); printf("[BACKSPACE] �ڷΰ���");
        x = _getch();
    } while (x != '1' && x != '2' && x != 8);
    return x;
}
