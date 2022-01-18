#include "team.h"
void CursorView();

int main(void) {
    char menu;
    srand((unsigned)time(NULL));
    CursorView();
    start_screen();
    char x;
    do {
        menu = choice_game();
        switch (menu) {
        case '1': randomWord(); break;
        case '2': meanWord(); break;
        case '3': pracWord(); break;
        case '4':
        {
            do {
                system("cls");
                gotoxy(30, 12);
                printf("Ȯ���� ������ �����ϼ���:");
                gotoxy(30, 14);
                printf("1. ���� �ܾ�");
                gotoxy(30, 15);
                printf("2. �ǹ��ִ� �ܾ�");
                gotoxy(30, 17);
                x = _getch();
            } while (x != '1' && x != '2');

            if (x == '1')
                scoreChart2();
            else
                scoreChart();
            break;
        }
        case 'h': help(); break;
        case 8: start_screen(); break;
        case 27: gotoxy(33, 20); printf("������ �� ����~\n\n"); break;
        default: break;
        }
    } while (menu != 27);

    return 0;
}

void CursorView() {
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}