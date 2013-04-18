#include "Element.h"
#include "RandomNumber.h"
#include "Console.h"
#include <iostream>

    using namespace std;

    Element::Element(RandomNumber &rnd, Console &console)
        : rnd(rnd), console(console)
    {
        this->x = rnd.random(1,10);
        this->y = rnd.random(1,10);
        this->direction = rnd.random(0,359);
        this->speed = rnd.random(1,10);
        this->energy = rnd.random(0,60);
        this->identifier = nextIdentifier;
        this->nextIdentifier++;
        // Set a defafult text colour.
        this->foreground = Console::WHITE;
    }

    void Element::print(void)
    {
        cout << identifier << "\n";
        cout << x          << "\n";
        cout << y          << "\n";
    }

    void Element::printAt(void)
    {
        // Move the cursor to the current (X, Y) co-ordinates.
        console.gotoXY(
            this->x,
            this->y
        );
        // Change the colour, proportionate to the energy.
        if(this->energy < 10) {
            console.setColour(this->foreground, Console::BLUE);
        }
        else if(this->energy < 20) {
            console.setColour(this->foreground, Console::GREEN);
        }
        else if(this->energy < 30) {
            console.setColour(this->foreground, Console::AQUA);
        }
        else if(this->energy < 40) {
            console.setColour(this->foreground, Console::YELLOW);
        }
        else if(this->energy < 50) {
            console.setColour(this->foreground, Console::RED);
        }
        else {
            console.setColour(this->foreground, Console::PURPLE);
        }
        // Output the identifier.
        cout << identifier;
        // Now change the colour back to the default.
        console.setColour(
            Console::WHITE,
            Console::BLACK
        );
        // Move the cursor to below the grid so that we don't overwrite anything.
        console.gotoXY(0, 11);
    }

    // definition of static attribute
    char Element::nextIdentifier = 'A';

    int Element::getX(void)
    {
        return this->x;
    }

    int Element::getY(void)
    {
        return this->y;
    }

    int Element::getEnergy(void)
    {
        return this->energy;
    }

    int Element::getDirection(void)
    {
        return this->direction;
    }

    int Element::getSpeed(void)
    {
        return this->speed;
    }

    // We must make sure the X and Y co-ordinates are within the boundaries
    // of our board, because otherwise the program JUST SUDDENLY STOPS WITHOUT
    // ERRORS AND IT TAKES HALF AN HOUR FOR YOU TO EVEN FIGURE OUT WHAT THE
    // HELL IS GOING ON.
    // We have already determined that the size of the board is 10x10,
    // because those are the values set in the Element constructor, so I'm
    // hard-coding it in as dirty as that feels. Basically, plus 10 in case
    // it's gone below 0, and then modulususususus it in case it went above 10.

    void Element::setX(int x)
    {
        // The X co-ordinate must be between 1 and 10 (inclusive).
        // Make sure it is a positive number by adding 10 until it is positive.
        while(x < 0) {
            x = x + 10;
        }
        // Now that we know it's positive, we need to mod10 it to make sure the
        // number is not above 10.
        x = x % 10;
        // Finally, we cannot have a co-ordinate of 0, so make any X co-ordinate
        // of 0 to 10 (wrap around board).
        if(x == 0) {
            x = 10;
        }
        // Set the X co-ordinate to a class property.
        this->x = x;
    }

    void Element::setY(int y)
    {
        // The Y co-ordinate must be between 1 and 10 (inclusive).
        // Make sure it is a positive number by adding 10 until it is positive.
        while(y < 0) {
            y = y + 10;
        }
        // Now that we know it's positive, we need to mod10 it to make sure the
        // number is not above 10.
        y = y % 10;
        // Finally, we cannot have a co-ordinate of 0, so make any Y co-ordinate
        // of 0 to 10 (wrap around board).
        if(y == 0) {
            y = 10;
        }
        // Set the Y co-ordinate to a class property.
        this->y = y;
    }

    void Element::setEnergy(int energy)
    {
        // The energy level must be between 0 and 60.
        // If it's less than zero, set to zero.
        if(energy < 0) {
            this->energy = 0;
        }
        // If it's more than 60, set to 60.
        else if(energy > 60) {
            this->energy = 60;
        }
        // If it's between 0 and 60, set the energy level to the
        // class property.
        else {
            this->energy = energy;
        }
    }

    void Element::setDirection(int direction)
    {
        while(direction < 0) {
            direction = direction + 360;
        }
        this->direction = direction % 360;
    }

    void Element::setSpeed(int speed)
    {
        if(speed < 1) {
            this->speed = 1;
        }
        else if(speed > 10) {
            this->speed = 10;
        }
        else {
            this->speed = speed;
        }
    }