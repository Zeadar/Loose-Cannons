#include <iostream>
#include <curses.h>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

#include "init.h"

#define KEY_ENTER 25
using namespace std;

HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.

char *choices[] = {
			"New Game\n",
			"Load Game\n",
			"Help\n",
			"Credits\n",
			"Exit\n",
		  };
int n_choices = sizeof(choices) / sizeof(char *);


int ch; //KEYBOARD INPUT
int highlight = 1;
void SetWindow(int Width, int Height)
{
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}

void spacecontinue()
{
    ch = getch();
    while(ch != ' ')
    {
        ch = getch();
        if(ch==' ')
        {
            break;
        }




    }

}

void remove_scrollbar()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}




void menusplash()
{
    start_color();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(4, COLOR_BLACK, COLOR_RED);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);

    curs_set(0); //make cursor invisible

    attron(COLOR_PAIR(1));
    printw("                                                                                                                        \n");
    printw("                              :B@NZB@BB  \n");
    printw("                                B@@M  MO   \n");
    printw("                                @B@B:  B                                                                                \n");
    printw("                                B@Bv  ir       .Z@O@E      :M@G@F      :P@B@B0   ,1OBME@B@,                             \n");
    printw("                                @B@: 7S.      LB@B7 @Bi   XB@B  @B.   :B@@ 0@.   r@@@i B@B:                             \n");
    printw("                                B@@U    BM    B@    r@B  :@@ :: Z@B    @@@u.:     M@rZ,r.                               \n");
    printw("                                @B@:  @:@B,  i@B    .B@SLB@B:L0uXB@Z8F. ivBB@Z    @BZB@                                 \n");
    printw("                                B@BB.  1B@    B@.  rO@B   B@    U@B  :@@BG .B@J   B@i i:Mi                              \n");
    printw("                               J@B@B@@@B@BN   :B@P@E@@.   7B@rv7@B    @BMB@J@B    @B@L U@B                              \n");
    printw("                              .5ri:irv7ri7v     BM8Sr       Y@@Zi      :uqE@B    JMOM@MO0@7                             \n");
    printw("                                               B                           :@u                                          \n");
    printw("                                iSF1:         BL                            B@       :OFYj8v                            \n");
    printw("                               Bu  iqBG       @                            i@@r     :B.    B1r                          \n");
    printw("                              B5      L@      @                            @:@7    jB     .u:YB.                        \n");
    printw("                            qZZ7r7,    i@i    @                            B.B8 7ZMu          u@                        \n");
    printw("                            B           .XMBY.B  r                     ..,B;7iBGJ.            FO                        \n");
    printw("                            @r             .v0@uM:                    rLrikGuv,              ;@                         \n");
    printw("                             @F               i@    .                       BX       7kGE8M@MG                          \n");
    printw("                iX            FM@M@MOOPr.     G@  @B@@@P  .        .YqBB8.   B   .jGOY,                   BX            \n");
    printw("               7B7,                   ,jq81;  q@  B@B@B@@ZB@   @ 7B@B@B@@@   @i2OZ7                     .U:@O           \n");
    printw("              XB 1@@Oi                    :JPjBB  2B@@@B@B@B  i@@B@B@B@B@:  ,BU:                     .PB@B@ @B          \n");
    printw("             @B.O@@@@@BO:                      @u  .q@B@B@B@   @B@B@B@B@i   B7                    .P@@B@B@B@:@B.        \n");
    printw("            :8 B@B@B@B@B@BG:                    @7    2M@G,     u7         BG                  ,qB@B@B@B@B@B@ J,        \n");
    printw("                2@B@B@B@B@B@@0:                  @Bv        iiq       .  .Bj                ,NB@B@@@B@B@B@Br            \n");
    printw("                  XB@B@B@B@B@B@BN:              1B BMr:     @B@       7B@@@              :0B@B@B@@@B@B@B@i              \n");
    printw("                    k@B@B@B@B@@@B@B0.       i2NqY@          B@B1  .      :BF8PO@      :EB@B@B@B@B@B@B@Br                \n");
    printw("                      E@JrXB@B@@@@@B@BP. 8MOq;   7@                      B,  .7NZB@LkB@B@B@B@B@MSvirMi                  \n");
    printw("                        LEJ;iJO@B@B@B@B@B@.       i@v:rMB    :,   GY   .B:       .B@@@B@B@BM0B7rj8B0                    \n");
    printw("                       8@@@BBUEL75@B@B@B@: q.  .7Fu:@B@B@    X,   PM@u@@@FU:   O@  B@B@@MU7iUBMB@B@B@                   \n");
    printw("                      0@@@B@B@B@0j7iP@B@  B@Bu1Sr.  B,7      r        Yq  ;SEkB@B@. B@@;iXM@B@MMB@B@ME                  \n");
    printw("                     j0ivB@B@BMB@B@::B@  B@B@B      @..         .   . 7B      @@@B@i Z@iYB@@@BMB@B@:FBB                 \n");
    printw("                    L@B@ @B@B@B@B@B @@ .B@B@Bk      .@ @B Z: @  G S 2 B.      B@B@B@j 1@ @BBB@B@B@B.B@B:                \n");
    printw("                     vk: :PB@BjiMBi5Z LB@B@B@@B      07r@Y@SrB7r@U@BZ @     L@@@@B@B@B G8u@8i7@BX:  .i                  \n");
    printw("                             .FBB0.F:BB@B@BPB@B.     iO B@B@B@@@B@B@.:P     .@B0,EB@B@0rS:B@B@                          \n");
    printw("                              @B@v:i; .::    .        @ @B@B@B@B@B@B Pr                   :B@F                          \n");
    printw("                                                      B r@@@B@B@@@BX @                                                  \n");
    printw("                         .5B@B@S                      Mi B@@@B@@@B@  @                                                  \n");
    printw("                       .B@B@B@B@B                     7B @M@B@B@@8F :B                                                  \n");
    printw("                      LB@P@B,:@B@                      B  ::     ,  8r                                                  \n");
    printw("                     iB@X @q  B@M      LOML     iBkGM2E@B5  ,1X8B50@@O     uMOOu    ,MX0MSM@0M.    ;5MBOE,              \n");
    printw("                     B@B  5B@@@O       @@B@.     .@B@  B@0S:  @B@YvB@    i@B@7 B@.    @B@  B@     @B@Jv@8               \n");
    printw("                     MB@   ;7   2       B@Br      B@B0 vB .LJ7B@B@ .B    @B  . vB@    N@B@ :B     B@BM r                \n");
    printw("                     ,@BB .   U @v   X@8@ @@      @.vB@L@     Zi,B@r@   iB@   .,@@.   Oi,B@7@      i1B@BB               \n");
    printw("                      S@B@,   5@B,   .:@kUB@:     @r i@@B     B1 .@@B    @B    vB@    B5 .@@B    7B@U  @B@              \n");
    printw("                       i@B@B@B@@:  J@P@O:2,B@  ,@@@k. iB@   @B@M...B@:   r@Bii,B@:  @@@M...B@:   S@B:; @@E              \n");
    printw("                         .755J,    JB@u.j  @Bq  B@7.uv :B   B@Y vu  B      XB@B1    B@J vu  @     :EB@BG:               \n\n\n\n");
    attroff(COLOR_PAIR(1));
    printw("                                                 PRESS SPACE TO CONTINUE                                               ");


    refresh();			/* Print it on to the real screen */
    spacecontinue();
    clear();


    attron(COLOR_PAIR(5));
    printw("                                                                                                  \n");
    printw("                                                       1111111111                                      \n");
    printw("                                                 1100011111111111000011                                   \n");
    printw("                                              1001111              1111001                                \n");
    printw("                                           10011       1 1 1 1 1 1      11001                             \n");
    printw("                                         1001     1 1 1 1 11111 1 111 1    1101                           \n");
    printw("                                       1001    11111 1 1 1 1111111 111 1 1   1101                         \n");
    printw("                                      101   11111 1 1111111111111 111 111 1 1  101                        \n");
    printw("                                     001   111 111 1111111 11111 1 1111111 1 1   00                       \n");
    printw("                                    01  1111111 1111111 111 111 1 11111 11111 1   10                      \n");
    printw("                                   01  11111 1 1111111 1         1 1111111 11111   10                     \n");
    printw("                                  101 1 111 11111 1 1   11111111    1111111 11111   10                    \n");
    printw("                                 101 11111 111 1 1   11001111110011  1111111 1 111  101                   \n");
    printw("                                 01   1 111 1 111   101          101  1 1 11111 111  10                   \n");
    printw("                                 01  1 1 11111 1   101             01  1 11111 11111 101                  \n");
    printw("                                101 1111111 111 1 10                01  111111111 1   01                  \n");
    printw("                                10  111111 111 1 111                101  111 1111111  10                  \n");
    printw("                                11  11111 111 1  101        +        01 1111111 1111  10                  \n");
    printw("                                10   11111111111 101                101  11111 1 111  10                  \n");
    printw("                                101 1 111 1 111 1 10                01  111 11111111  01                  \n");
    printw("                                 01  11111 111111  10              01  11111 111 111 101                  \n");
    printw("                                 01  1111 1 1 111   101          101  111 111 1 111  10                   \n");
    printw("                                 101   1 11111 1 1 1 11001     0011  11111111111 1  101                   \n");
    printw("                                  101 1111111111111 1  10      01   1 1 1 111 1 1   10                    \n");
    printw("                                   01  111 1111111 1  101       01   11111 11111   10                     \n");
    printw("                                    01    11111 1 1   01        101 1 111 11111   10                      \n");
    printw("                                     001   1 1 1 11  10          01  1 11111 1   10                       \n");
    printw("                                      101   1 1 111 101           01  11111 1  100                        \n");
    printw("                                       1001  1 1 1 110            101  1 1   1101                  \n");
    printw("                                         1001      10              01      1101                \n");
    printw("                                           10011  101              101  11001                 \n");
    printw("                                              100100                101001                                \n");
    printw("                                                 11                  11                                   \n");
    printw("                                                                                             \n");
    printw("                                                                                             \n");
    printw("                                                                                             \n");
    printw("                  00000   010000    10000   010000       100000   10000   0     01  0 101 000001  10000   \n");
    printw("                 00   00  001  001 00   001 001  001    00    0  00   10  01    00  001  00   01 00   101 \n");
    printw("                101    01 00    00 00111000 00    00    0011     0     01 0     00  0    0       01111100 \n");
    printw("                101    01 00    00 00       00    00      11000  0     01 0     00  0   10       01       \n");
    printw("                100   00  00   101 00   11  00    00          00 01    01 00    00  0    01      01       \n");
    printw("                 1000001  0000001  1000000  00    00    0001100  1000000   0000100  0    1000000  000000  \n");
    printw("                          00                                                                              \n");
    printw("                          00 Source-Code available on: https://github.com/Paradux/Loose-Cannons           \n");
    printw("                          00                                                                              \n");
    printw("                                        \n\n\n\n\n");
    attroff(COLOR_PAIR(5));

    printw("                                                 PRESS SPACE TO CONTINUE                     ");
    spacecontinue();
clear();



//menu:
while(1){
for(int i = 0;i<5;i++){


    if(highlight ==i+1){
    attron(COLOR_PAIR(3));
    printw(choices[i]);
attroff(COLOR_PAIR(3));
    }
 else{
        printw(choices[i]);

    }

}
ch = getch();

if(ch==KEY_DOWN)
        {
            highlight++;
            if(highlight>5){highlight = 1;}
            clear();

       // goto menu;

        }
        else if(ch==KEY_UP)
        {
            highlight--;
            if(highlight<1){highlight = 5;}
            clear();
          //  goto menu;
        }
        else{
            clear();
          //  goto menu;
        }


if(ch==' '){
    break;

}

}
}



int main()
{
// RESIZING AND CHANGING WINDOW BUFFER // //FIRST VERSION IN COMMENTS DOESNT WORK WI

    // Set up the handles for reading/writing:
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    // Change the window title:
    SetConsoleTitle(TEXT("Loose Cannons"));
    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0, 120, 50};
    // Change the console window size:
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    // Create a COORD to hold the buffer size:
    COORD bufferSize = {120, 50};//OBSOLETE
    // Change the internal buffer size:
    SetConsoleScreenBufferSize(wHnd, bufferSize); //OBSOLETE

    remove_scrollbar();
// PDCURSES/NCURSES INITIALIZING//
    initscr();			/* Start curses mode 		*/
    raw();/* Line buffering disabled	*/
    keypad(stdscr, TRUE);		/* We get key input		*/

    noecho();			/* Don't echo() while we do getch */

//STARTING MENU
    menusplash();

   refresh();
// ENDING APPLICATION
    endwin();			/* End curses mode		  */
    return 0;
}

