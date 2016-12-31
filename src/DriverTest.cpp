//
// Created by uriel on 29/12/16.
//

#include "DriverTest.h"
#include "StandardCab.h"

DriverTest::DriverTest(int id, char c) {
    std::cout << "before" << std::endl;
    DriverTest::id = id;
    DriverTest::c = c;
    DriverTest::gridNodeTest = new GridNodeTest(7,"heyyyy",'c');
    maritalStatus = MaritalStatus ::Divorced;
    std::cout << "after" << std::endl;
    DriverTest::baseCab = new StandardCab(7);
}

int DriverTest::getId() {
    return id;
}

DriverTest::DriverTest() {

}

char DriverTest::getChar() {
    return c;
}

void DriverTest::foo1() {
    std::cout << "URIEL HA MANIAK" << std::endl;
}

int DriverTest::foo2() {
    return 7;
}

GridNodeTest* DriverTest::getGridNodeTest() {
    return gridNodeTest;
}

MaritalStatus DriverTest::getMaritalStatus() {
    return maritalStatus;
}
