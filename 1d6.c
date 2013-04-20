//
//  main.c
//  dice
//
//  Created by Raichu on 4/20/13.
//  Copyright (c) 2013 Raichu. All rights reserved.
//

#include <stdio.h>
#include <string.h>     // strlen
#include <ctype.h>      // isdigit
#include <stdlib.h>     // atoi
#include "boolean.h"

//2 PRINT TAB(34); "DICE"
//4 PRINT TAB(15); "CREATIVE COMPUTING NORRISTOWN, NEW JERSEY"
//6 PRINT:PRINT:PRINT
//10 DIM F(12)
//20 REM DANNY FREIDUS
//30 PRINT "THIS PROGRAM SIMULATES THE ROLLING OF A"
//40 PRINT "PAIR OF DICE."
//50 PRINT "YOU ENTER THE NUMBER OF TIMES YOU WANT THE COMPUTER TO"
//60 PRINT "'ROLL' THE DICE. WATCH OUT, VERY LARGE NUMBERS TAKE"
//70 PRINT "A LONG TIME. IN PARTICULAR, NUMBER OVER 5000."
//80 FOR Q=1 TO 12
//90 F(Q)=0
//100 NEXT Q
//110 PRINT:PRINT "HOW MANY ROLLS";
//120 INPUT X
//130 FOR S=1 TO X
//140 A=INT(6*RND(1)+1)
//150 B=INT(6*RND(1)+1)
//160 R=A+B
//170 F(R)=F(R)+1
//180 NEXT S
//185 PRINT
//190 PRINT "TOTAL SPOTS","NUMBER OF TIMES"
//200 FOR V=2 TO 12
//210 PRINT V,F(V)
//220 NEXT V
//222 PRINT:PRINT "TRY AGAIN";
//223 INPUT Z$
//224 IF Z$="YES" THEN 80

void instructions ( void );
int get_int ( char * prompt );
void rolling_of_dice (int rolls);

int array_of_rolls [7];

int main(int argc, const char * argv[])
{
//  instructions();
    
    char prompt [] = "How many dice rolls (up to 99)? ";
    
//  printf ( "\n%d", get_int ( prompt ) );
    int rolls = get_int ( prompt );
    
    rolling_of_dice ( rolls );

    return 0;
}

void instructions ( void )
{
    printf("This program simulates the rolling of pairs of dice. \n"
           "You enter the number of times you want the computer \n"
           "to 'roll' the dice. Watch out, very large numbers \n"
           "take a long time. In particular, number over 5000. \n");
}

int get_int ( char * prompt )
{
    boolean good_value = true;
    
    int     return_value        = 0;
    char    buffer [ 2 ];
   
//  unsigned long buffer_length = strlen ( buffer );
    
    do
    {
        printf ( "%s", prompt );
        
        gets ( buffer );
        
        for ( int i = 0; i < strlen ( buffer ); i++ )
        {
            if ( ! isdigit ( buffer [ i ] ) )
            {
                printf ( "invalid entry: %c\n", buffer [ i ] );
                good_value = false;
                
                break;
            }
            else
            {
                good_value = true;
            }
        }
    }
    while ( good_value == false );
    
    return_value = atoi ( buffer );
    
    return return_value;
}

void rolling_of_dice (int rolls)
{
    int number_rolled [99];
    
    for (int i = 0; i < rolls; i++)
    {
        number_rolled [i]  = ( rand() % 6 ) + 1;
        //printf("%d\n", number_rolled [i] );
        
        array_of_rolls [ number_rolled [ i ] ] += 1;
    }
    
    for (int i = 1; i < 7; i++)
    {
        printf("%d - %d \n", i, array_of_rolls[i] );
    }
}



