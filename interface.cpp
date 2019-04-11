#include <ncurses.h>
#include <iostream>
#include "interface.h"
using namespace std;

// optionMenu: prompts option menu
// Inputs: user input
// Outputs: int highlight: index corresponding to the menu item selected
int optionMenu() {
    int maxRow, maxCol;
    getmaxyx(stdscr,maxRow,maxCol); // gets number of lines and columns on screen

    curs_set(0); // hides cursor
    noecho(); // hides user input
    keypad(stdscr, true); // enables keypad
    move(maxRow-2,0);
    clrtoeol();

    const int numOptions = 4; // number of options. Remember to update whenever options is changed
    string options[numOptions] = {"Add Record", "Check Records", "Edit Records", "Exit"}; // string of options
    
    printw("%-*s", 20,  "Select Option:");
    for (int i = 0; i < numOptions; i++) {
        printw("%-*s", 20,  options[i].c_str());
    }

    int choice;
    int highlight = 0;

    // while loop that check which menu item is highlighted by the user, and breaks when the enter key is pressed. Changes int highlight.
    while (true) {
        for (int i = 0; i < numOptions; i++) {
            if (i == highlight)
                attron(A_REVERSE); // turn on attribute that reverses text colour and bg colour when menu item is highlighted
            mvprintw(maxRow-2, 20*(i+1), options[i].c_str());
            attroff(A_REVERSE); // turn off attribute if menu item is not highlighted
        }
        choice = getch(); // gets user input

        // switch to allow user to highlight each menu item with arrow keys
        switch (choice) 
        {
            case KEY_LEFT:
                highlight--;
                if (highlight < 0)
                    highlight = 0;
                break;
            case KEY_RIGHT:
                highlight++;
                if (highlight > numOptions-1)
                    highlight = numOptions-1;
                break;
            default:
                break;
        }
        if (choice == 10) // breaks while loop when enter key is pressed
            break;
    }

    keypad(stdscr, false); // disables keypad input
    return highlight; 
}

// userStringInput: prompts input box to allow user to input a string
// Inputs: user input
// Outputs: string s: string with user input
string userStringInput () {
    int maxRow, maxCol;
    getmaxyx(stdscr,maxRow,maxCol); // gets number of lines and columns on screen

    // moves cursor to last line, shows cursor and takes user input
    move(maxRow-1,0);
    curs_set(1);
    echo();

    char str[100];
    getnstr(str, 100);

    move(maxRow-1,0);
    clrtoeol();

    return str;
}

// clears screen besides the menu section
void clearScreen() {
    int maxRow, maxCol;
    getmaxyx(stdscr,maxRow,maxCol); // gets number of lines and columns on screen

    for (int i = 0; i < maxRow-2; i++) {
        move(i,0);
        clrtoeol();
    }
}

void addRecordInterface() {
    int maxRow, maxCol;
    getmaxyx(stdscr,maxRow,maxCol); // gets number of lines and columns on screen

    clearScreen();
    int y, x;
    mvprintw(0,0,"Please enter type of income/expense: ");
    getyx(stdscr,y,x);  
    string s = userStringInput();
    mvprintw(y,x,s.c_str());
    mvprintw(1,0,"Please enter amount: ");
    getyx(stdscr,y,x);  
    s = userStringInput();
    mvprintw(y,x,s.c_str());
    mvprintw(2,0,"Please enter account: ");
    getyx(stdscr,y,x);  
    s = userStringInput();
    mvprintw(y,x,s.c_str());
}

void checkRecordsInterface() {
    int maxRow, maxCol;
    getmaxyx(stdscr,maxRow,maxCol); // gets number of lines and columns on screen

    clearScreen();
}

void editRecordsInterface() {
    int maxRow, maxCol;
    getmaxyx(stdscr,maxRow,maxCol); // gets number of lines and columns on screen

    clearScreen();
}