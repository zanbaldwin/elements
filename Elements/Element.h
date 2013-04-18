#pragma once
#include "RandomNumber.h"
#include "Console.h"

using namespace std;

class Element
{
    protected:
	    RandomNumber &rnd;
	    Console &console;
	    int x;
	    int y;
	    int energy;
	    int direction;
	    int speed;
	    char identifier;
	    static char nextIdentifier;
        Console::COLOUR foreground;
	
    public:
        /**
         * Element Contstructor
         *
         * @access public
         * @param RandomNumber rnd
         * @param Console console
         * @return void
         */
	    Element(RandomNumber &rnd, Console &console);

        /**
         * Print Properties
         *
         * Prints the values of the class properties "x" and "y" to standout output.
         *
         * @access public
         * @return void
         */
	    virtual void print(void);

        /**
         * Print Properties At
         *
         * Prints the Element object's identifier to standard-output at the co-ordinates "x, y" with a background
         * colour representing its energy level (in the order BLUE, GREEN, AQUA, YELLOW, RED, and PURPLE - for
         * example, an Element object with an energy level of 23 would have an AQUA background).
         *
         * @access public
         * @return void
         */
	    virtual void printAt(void);

        /**
         * Get X Co-ordinate
         *
         * @access public
         * @return integer
         */
        int getX(void);

        /**
         * Get Y Co-ordinate
         *
         * @access public
         * @return integer
         */
        int getY(void);

        /**
         * Get Energy
         *
         * @access public
         * @return integer
         */
        int getEnergy(void);

        /**
         * Get Direction
         *
         * @access public
         * @return integer
         */
        int getDirection(void);

        /**
         * Get Speed
         *
         * @access public
         * @return integer
         */
        int getSpeed(void);

        /**
         * Set X Co-ordinate
         *
         * @access public
         * @param integer x
         * @return void
         */
        void setX(int x);

        /**
         * Set Y Co-ordinate
         *
         * @access public
         * @param integer y
         * @return void
         */
        void setY(int y);

        /**
         Set Energy Level
         *
         * @access public
         * @param integer energy
         * @return void
         */
        void setEnergy(int energy);

        /**
         * Set Direction
         *
         * @access public
         * @param integer direction
         * @return void
         */
        void setDirection(int direction);

        /**
         * Set Speed
         *
         * @access public
         * @param integer speed
         * @return void
         */
        void setSpeed(int speed);
};