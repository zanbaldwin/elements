#include "Board.h"
#include <iostream>
#include <list>
#include <math.h>

    using namespace std;

    Board::Board(RandomNumber &random, Console &console)
    {
        for(int i = 0; i < 10; i++) {
            this->container.push_back(Flotsam(random, console));
            this->container.push_back(Jetsam(random, console));
        }
        // Programming is all about simplicity. Saving the Console object to a class
        // property and calling its clear() method is much more simple than writing
        // a space to each object's co-ordinates. A lazy programmer is an efficient
        // programmer; unless you're talking about speed and memory consumption...
        // In which case, you'll find me sipping pina colada's in the Caribbean
        // after my rather successful move into politics.
        this->console = console;
        this->tick = 0;
    }

    void Board::display()
    {
        // Clear the console of everything before displaying the objects at their
        // co-ordinates for this frame.
        this->console.clear();
        // Declare a list iterator (a special kind of pointer), and set it to the
        // beginning of the list.
        list<Element>::iterator pointer = this->container.begin();
        // Iterate over the list, until the pointer reaches the end.
        while(pointer != this->container.end()) {
            // Call the object's printAt() method to display the object's identifier
            // at its current co-ordinates.
            pointer->printAt();
            // Increment the pointer to that it points to the next object in the
            // list.
            pointer++;
        }
    }

    void Board::loop()
    {
        // Display all the elements in their initial state.
        this->display();
        while(this->tick < 100) {
            // Increment the ticker and display it to the console.
            this->tick++;
            cout << this->tick;
            // Pause execution for a little bit so people can view the objects.
            Sleep(100);
            // Call the moveObjects() method, which will determine which objects
            // are meant to move, and do so.
            this->moveObjects();
            // Display the objects at their updated co-ordinates.
            this->display();
        }
    }

    /**
     * WHY CAN'T C++ HAVE A ROUNDING FUNCTION?!
     * I had to remember stuff from A-Levels to work this out :\
     */
    double round(double number, unsigned places = 0)
    {
        double multiplier = pow(10, places);
        number = number * multiplier;
        number = (number > 0.0)
            ? floor(number + 0.5)
            : ceil(number - 0.5);
        return number / multiplier;
    }

    void Board::moveObjects()
    {
        // OH LOOK, YET ANOTHER THING THE C++ MATH LIBRARY DOESN'T HAVE.
        // LOOKS LIKE I'LL JUST HAVE TO MAKE THE PI CONSTANT. Stupid Math library...
        double pi = atan(1) * 4;
        // Declare the variable that will be used inside the while loop here, we
        // don't wait to redeclare them multiple times.
        double directionRadians;
        int newX;
        int newY;
        // Declare a list iterator (a special kind of pointer), and set it to the
        // beginning of the list.
        list<Element>::iterator pointer = this->container.begin();
        // Iterate over the list, until the pointer reaches the end.
        while(pointer != this->container.end()) {
            if(this->tick % (11 - pointer->getSpeed()) == 0) {
                // Update the co-ordinates for this Element.
                // Firstly, the Math library works in radians, not degrees, so
                // convert accordingly.
                directionRadians = pointer->getDirection() * (pi / 180);
                // Split the direction into X and Y directions, and round each one
                // to the nearest integer; this gives values of either 0, 1 or -1.
                // It also assumes that a direction of 0 means north. Then add it
                // to the original respective value.
                newX = (int) round(sin(directionRadians)) + pointer->getX();
                newY = (int) round(cos(directionRadians)) + pointer->getY();
                pointer->setX(newX);
                pointer->setY(newY);

                // Detect if there is a collision.
                // If collision, update energy and direction. And speed? I can't
                // remember if speed was updated too? I'LL DO THIS IF I HAVE TIME.
                // It's more than likely I'm over-complicating things. Again.

            }
            // If the object's energy is now zero, then it shouldn't exist
            // anymore; remove it from the list.
            if(pointer->getEnergy() == 0) {
                // Assign the pointer the value returned by the erase method, it
                // is the address of a list element that was after the one that
                // has been deleted.
                pointer = this->container.erase(pointer);
            }
            else {
                // Didn't need to delete it, increment the pointer as normal.
                pointer++;
            }
        }
    }