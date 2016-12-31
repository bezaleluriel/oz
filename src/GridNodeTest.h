//
// Created by uriel on 30/12/16.
//
#include <iostream>
#ifndef OZ_GRIDNODETEST_H
#define OZ_GRIDNODETEST_H
#include <boost/serialization/access.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>


class GridNodeTest {
private:
    int a;
    char c;

    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version) {

        ar & a;
        ar & c;

    }

public:
    GridNodeTest();
    GridNodeTest(int b, std::string str2, char c2);
    void goo1();
    int goo2(int a);
    int getA();
    char getC();


};


#endif //OZ_GRIDNODETEST_H
