#include"team.h"
#define SIZE 100
#define NUM 5

void pracWord() {
    system("cls");
    char menu;
    menu = pracKind();
    system("cls");
    pracGame(menu);
}
void pracGame(char menu) {
    if (menu == 8);
    else {
        pracHelp(menu);
        gotoxy(0, 9);
        for (int i = 5; i >= 1; i--) {
            printf("  %d      ", i);
            Sleep(1000);
        }
        printf("Start!!\n");
        pracHelp(menu);
        char ch, input[SIZE] = { '\0' };
        int  j = 0, num = 1, wrong = 0, k_hit = 0;
        int t1, t2;
        float accury;
        char* word = { '\0' };

        gotoxy(0, 4 * num + 7);
        switch (menu) {
        case '1':get_string1(&word); printf("%s\n", word); break;
        case '2':get_string3(&word); printf("%s\n", word); break;
        }
        t1 = time(0) - 1;

        while (1) {
            gotoxy(0, 9);
            accury = ((double)k_hit - wrong) / k_hit * 100;
            if (k_hit == 0)
                printf("타자속도: 0 (hit/min)  정확도: 0.0%%");
            else
                printf("타자속도: %.0f (hit/min)  정확도: %.1f%%", (float)k_hit / (((int)time(0) - t1) / 60.0), accury);
            if (num > NUM) {
                system("cls");
                pracHelp(menu);         // 타자속도, 정확도
                num = 1;
                switch (menu) {
                case '1':get_string1(&word); printf("%s\n", word); break;
                case '2':get_string3(&word); printf("%s\n", word); break;
                }
            }
            if (_kbhit()) {
                gotoxy(j, 4 * num + 8);
                ch = _getch();
                if (ch == '\n');
                if (ch == 27) break;
                if (ch == 8 && j != 0) {
                    printf("\b \b");
                    j--;
                    if (word[j] != input[j])
                        wrong--;
                    k_hit--;
                }
                if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'z') || (ch == 32)) {
                    input[j] = ch;
                    if (word[j] != input[j]) {
                        wrong++;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    }
                    printf("%c", ch);  //spacebar 아스키 코드값 32
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    j++;                //오타시 오타 1씩 증가 시켜야함
                    k_hit++;
                }
                if (j >= strlen(word)) {
                    input[strlen(word)] = 0;
                    gotoxy(0, 4 * num + 9);
                    if (!strcmp(word, input))
                        printf("정답입니다.");
                    else {
                        printf("오답입니다.");
                    }
                    num++;
                    gotoxy(0, 4 * num + 7);
                    switch (menu) {
                    case '1':get_string1(&word); printf("%s\n", word); break;
                    case '2':get_string3(&word); printf("%s\n", word); break;
                    }
                    j = 0;

                }
            }
        }
        system("cls");
        t2 = time(0);
        gotoxy(33, 8); printf("타자속도: %.0f (hit/min)", (float)k_hit / ((int)(time(0) - t1) / 60.0));
        gotoxy(33, 10);
        if (k_hit == 0)
            printf("정확도: 0.0% %");
        else
            printf("정확도: %.1f", accury);
        gotoxy(33, 12); printf("진행시간: %d", t2 - t1);
        gotoxy(33, 16); printf("[r] to restart");
        for (int i = 3; i > 0; i--) {
            gotoxy(33, 20); printf("      %d     ", i);
            Sleep(1000);
        }
        if (_kbhit()) {
            ch = _getch();
            if (ch == 'r') {
                gotoxy(33, 20); printf("    RESTART  ");
                Sleep(3000);
                pracGame(menu);
            }
        }
        else {
            gotoxy(33, 20); printf("  GAME OVER  ");
            Sleep(3000);
        }
    }
}
void pracHelp(char menu) {
    system("cls");
    gotoxy(0, 0);
    printf("\n- 영어 단어 혹은 문장이 등장합니다.\n");
    printf("- 오타는 빨간 글씨로 나타납니다.\n");
    printf("- 분당 타자속도와 정확도를 확인하세요\n");
    printf("- 게임을 종료하려면 [ESC]를 눌러주세요\n");
    printf("-----------------------------------------------------\n");
    switch (menu) {
    case '1': printf("- 영어 단어가 등장합니다.\n- 따라서 입력하세요.\n"); break;
    case '2': printf("- 영어 문장이 등장합니다.\n- 따라서 입력하세요.\n"); break;
    }
    printf("-----------------------------------------------------\n\n");
    printf("-----------------------------------------------------\n");
}
void get_string1(char** q)
{
    char* word[] = { "almonds", "already", "knife", "glass", "class", "smart", "bell", "carry", "climb", "between", "album", "among", "animal",
        "board", "child", "classmate", "bridge", "clean", "elephant", "include", "robot", "average", "screen", "stage", "classic",
        "bright", "chopstick", "coffee", "chance", "chalk", "chair", "cheap", "phone", "bottle", "school", "programming", "student",
        "before", "bowl", "aunt", "away", "bicycle", "church", "chose", "come", "drink", "wsing", "throw",
        "write", "spend", "stand", "sweep", "account", "achieve", "across", "accept", "ability", "abuse",
        "abnormal", "absurd", "acceptance", "according", "absent", "nation", "past", "value", "though", "person", "machine", "stand",
        "culture", "experience", "education", "symbol", "effect", "liberty", "affair", "comfort", "tradition", "subject", "invader", "trick", "flight",
        "castle", "envelope", "pal", "vacation", "desert", "fault", "lantern", "import",
        "angle", "match", "stripe", "pulse", "powder", "flood", "bush", "branch",
        "hero", "heaven", "exit", "beast", "century", "coeducation", "twin", "wound",
        "metal", "insect", "track", "deserve", "survive", "create", "describe", "select",
        "hesitate", "declare", "pretend", "struggle", "explore", "astonish", "disappoint", "attract",
        "celebrate", "explode", "include", "protect", "introduce", "produce", "arrest", "prove",
        "yell", "howl", "halt", "leak", "behave", "wrap", "locate", "charge",
        "review", "refuse", "complain", "remain", "warn", "bend", "suffer", "whisper",
        "prepare", "roar", "float", "drag", "overhear", "slide", "suck", "bother", "deal", "treat",
        "destroy", "accept", "depend", "nod", "waste", "borrow", "complete", "excellent",
        "competent", "religious", "favorite", "entire", "primary", "similar", "frankly" };
    int size = sizeof(word) / sizeof(word[0]);
    int index = rand() % size;
    *q = word[index];
}
void get_string3(char** q)
{
    char* word[] = { "I never dreamed about success I worked for it",
        "Do not try to be original just try to be good",
        "Do not be afraid to give up the good to go for the great",
        "If you cannot fly then run If you cannot run then walk",
        "And if you cannot walk then crawl but whatever you do you have to keep moving forward",
        "Our greatest weakness lies in giving up",
        "The most certain way to succeed is always to try just one more time",
        "Some people dream of success while other people get up every morningand make it happen",
        "The only thing worse than starting somethingand failing is not starting something",
        "Think like a man of action and act like man of thought",
        "Courage is very important Like a muscle it is strengthened by use",
        "Life is the art of drawing sufficient conclusions from insufficient premises",
        "By doubting we come at the truth",
        "A man that hath no virtue in himself ever envieth virtue in others",
        "When money speaks the truth keeps silent",
        "Better the last smile than the first laughter",
        "In the morning of life work in the midday give counsel in the evening pray",
        "Painless poverty is better than embittered wealth",
        "A poet is the painter of the soul",
        "Error is the discipline through which we advance",
        "Faith without deeds is useless",
        "Weak things united become strong",
        "We give advice but we cannot give conduct",
        "Nature never deceives us it is always we who deceive ourselves",
        "Forgiveness is better than revenge",
        "We never know the worth of water till the well is dry",
        "Pain past is pleasure",
        "Books are ships which pass through the vast seas of time",
        "Who begins too much accomplishes little",
        "Better the last smile than the first laughter",
        "Faith is a higher faculty than reason",
        "Until the day of his death no man can be sure of his courage",
        "Great art is an instant arrested in eternity",
        "Faith without deeds is useless",
        "The world is a beautiful book but of little use to him who cannot read it",
        "Heaven gives its favourites early death",
        "I never think of the future It comes soon enough",
        "Suspicion follows close on mistrust",
        "All good things which exist are the fruits of originality",
        "The will of a man is his happiness",
        "He that has no shame has no conscience",
        "Weak things united become strong",
        "United we stand divided we fall",
        "To doubt is safer than to be secure",
        "Time is but the stream I go afishing in",
        "A full belly is the mother of all evil",
        "Love your neighbor as yourself",
        "It is a wise father that knows his own child",
        "By doubting we come at the truth",
        "Absence makes the heart grow fonder",
        "Habit is second nature",
        "Who knows much believes the less",
        "Only the just man enjoys peace of mind",
        "Waste not fresh tears over old griefs",
        "Life itself is a quotation",
        "Envyand wrath shorten the life",
        "Where there is no desire there will be no industry",
        "To be trusted is a greater compliment than to be loved",
        "Education is the best provision for old age",
        "To jaw jaw is better than to war war" };
    int size = sizeof(word) / sizeof(word[0]);
    int rindex = rand() % size;
    *q = word[rindex];
}