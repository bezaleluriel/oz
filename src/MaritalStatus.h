#ifndef EX1_MARITALSTATUS_H
#define EX1_MARITALSTATUS_H

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

/**
 * enum class for maitalstatus options.
 */


enum class MaritalStatus{

    Single, Married, Divorced , Widowed
};

namespace boost
{
    namespace serialization
    {

        template< class Archive >
        void save(Archive & ar, const MaritalStatus & t, unsigned int version)
        {
            unsigned char c = (unsigned char) t;
            ar & c;
        }

        template< class Archive >
        void load(Archive & ar, MaritalStatus & t, unsigned int version)
        {
            unsigned char c;
            ar & c;
            t = (MaritalStatus) c;
        }

    } // namespace serialization
} // namespace boost

BOOST_SERIALIZATION_SPLIT_FREE(MaritalStatus)


#endif //EX1_MARITALSTATUS_H
