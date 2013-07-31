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

#define WIDTH 100
#define HEIGHT 150
#define KEY_ENTER 0x157
using namespace std;

HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.

int ch; //KEYBOARD INPUT

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

void spacecontinue(){
 while(ch != ' ')
    {
        ch = getch();
        if(ch==' ')
        {
            break;
        }




    }

}

void menusplash()
{
   start_color();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(4, COLOR_BLACK, COLOR_RED);

curs_set(0); //make cursor invisible

    attron(COLOR_PAIR(1));
    printw("\n");
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
    printw("                         .755J,    JB@u.j  @Bq  B@7.uv :B   B@Y vu  B      XB@B1    B@J vu  @     :EB@BG:    \n\n");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    printw("                                                   PRESS SPACE TO CONTINUE                                               ");

    attroff(COLOR_PAIR(2));

    refresh();			/* Print it on to the real screen */
    ch = getch();
    spacecontinue();

    refresh();
}
int main()
{
    SetConsoleTitle("Loose Cannons");
    initscr();			/* Start curses mode 		*/
    raw();/* Line buffering disabled	*/
    keypad(stdscr, TRUE);		/* We get key input		*/

    noecho();			/* Don't echo() while we do getch */

	//SetWindow(125,125);

    // END CONFIGURING WINDOW //
    menusplash();



    endwin();			/* End curses mode		  */
    return 0;
}
