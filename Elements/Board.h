#pragma once
#include "Flotsam.h"
#include "Jetsam.h"
#include <list>

using namespace std;

class Board
{

    protected:

        list<Element> container;
        Console console;
        int tick;

    public:

        /**
         * Flotsam Constructor (Declaration)
         *
         * @access public
         * @return void
         */
        Board(RandomNumber &rnd, Console &console);

        /**
         * Display Objects
         *
         * @access public
         * @return void
         */
        void display(void);

        /**
         * Run Board Simulation
         *
         * @access public
         * @return void
         */
        void loop(void);

        /**
         * Move Object Co-ordinates
         *
         * @access public
         * @return void
         */
        void moveObjects(void);

};