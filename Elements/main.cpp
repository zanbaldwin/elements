#pragma once
#include "Console.h"
#include "RandomNumber.h"
#include "Board.h"
using namespace std;

    int main()
    {

        // "Initialise the seed, so that the numbers will be random on each program execution"
        // ... Random? Pah! Try making a HTTP request to the following which uses atmospheric
        // noise. Now that's random).
        // http://www.random.org/integers/?num=1&min=1&max=10&col=1&base=10&format=plain&rnd=new
        RandomNumber::initialiseSeed();

        /* Prerequisites
        * ==============
        */
        Console console;
        RandomNumber random;

        /* Board Object
        * =============
        */

        // Create an instance of the board.
        Board *board = new Board(random, console);
        // Loop through the "frames" of the board, displaying objects.
        board->loop();

        // Delete the board object now that we have finished with it, good practice to
        // get used to memory management. Or we could define "Board board(random, console)"
        // instead and it will be automatically deleted when this scope ends.
        delete board;

        /* Return; exit main program execution.
         * ====================================
         */
        system("pause");
        return 0;

    }