//
// Created by uriel on 30/12/16.
//

#include "GridNodeTest.h"

GridNodeTest::GridNodeTest() {
 std::cout << "default GridNode constructor" << std::endl;
}

GridNodeTest::GridNodeTest(int a, std::string s, char c) {
    std::cout << "GridNode constructor" << std::endl;
    GridNodeTest::a = a;
    GridNodeTest::c = c;

}

void GridNodeTest::goo1() {
    std::cout <<"goo1"<< std::endl;
}

int GridNodeTest::goo2(int a) {
    std::cout <<"goo2"<< std::endl;
}

int GridNodeTest::getA() {
    return a;
}

char GridNodeTest::getC() {
    return c;
}
