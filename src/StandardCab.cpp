#include <boost/serialization/export.hpp>
#include "StandardCab.h"
StandardCab::StandardCab(){
    b=9;
}

StandardCab::StandardCab(int a) {
}

void StandardCab::hoo1() {

}


BOOST_CLASS_EXPORT(StandardCab)