#include "Flotsam.h"
#include "Element.h"

    using namespace std;

    /**
     * Flotsam Constructor
     *
     * @definition
     * @access public
     * @return void
     */
    Flotsam::Flotsam(RandomNumber &rnd, Console &console) : Element(rnd, console)
    {
        this->foreground = Console::BLACK;
    }