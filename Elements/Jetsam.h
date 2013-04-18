#pragma once
#include "Element.h"

    using namespace std;

    class Jetsam : public Element
    {

        public:

            /**
             * Jetsam Constructor (Declaration)
             *
             * @declaration
             * @access public
             * @return void
             */
            Jetsam(RandomNumber &rnd, Console &console);

    };