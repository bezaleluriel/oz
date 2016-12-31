//
// Created by uriel on 30/12/16.
//

#ifndef OZ_BASECAB_H
#define OZ_BASECAB_H
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

class BaseCab {
private:
    int a;
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version) {

        ar & a;

    }
public:
    BaseCab();
    BaseCab(int a);
    virtual void hoo1()=0;
    int getNum();

};
BOOST_SERIALIZATION_ASSUME_ABSTRACT(BaseCab)


#endif //OZ_BASECAB_H
