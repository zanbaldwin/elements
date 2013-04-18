#include "Jetsam.h"
#include "Element.h"

    using namespace std;

    /**
     * Jetsam Constructor
     *
     * @definition
     * @access public
     * @return void
     */
    Jetsam::Jetsam(RandomNumber &rnd, Console &console) : Element(rnd, console)
    {
        this->foreground = Console::WHITE;
    }