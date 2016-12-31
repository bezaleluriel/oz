// Created by uriel on 30/12/16.
//
#ifndef OZ_STANDARDCAB_H
#define OZ_STANDARDCAB_H
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
#include "BaseCab.h"
class StandardCab: public BaseCab {
private:
    int b;
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version) {

        ar & b;
        ar & boost::serialization::base_object<BaseCab>(*this);

    }
public:
    StandardCab();
    StandardCab(int a);
    void hoo1();
};
#endif //OZ_STANDARDCAB_H
