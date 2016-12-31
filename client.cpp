//
// Created by yanaiela on 12/10/16.
//blabla

#include "src/sockets/Udp.h"
#include "src/DriverTest.h"
#include "src/StandardCab.h"
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]) {
    std::cout << "Hello, from client" << std::endl;

    cout << argv[1] << endl;
    Udp udp(0, atoi(argv[1]));
    udp.initialize();
    DriverTest *driver = new DriverTest(5,'v');

    std::string serial_str;
    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    oa << driver;
    s.flush();


    char buffer[1024];
    udp.sendData(serial_str);
    udp.reciveData(buffer, sizeof(buffer));
    cout << buffer << endl;
    //////////////////////////////////////////////////
    BaseCab* baseCab;
    baseCab = new StandardCab(7);
    std::string serial_str2;
    boost::iostreams::back_insert_device<std::string> inserter2(serial_str2);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s2(inserter);
    boost::archive::binary_oarchive oa2(s2);
    oa2 << baseCab;
    s2.flush();
    udp.sendData(serial_str2);







/*
    udp.sendData("sup?");
    udp.reciveData(buffer, sizeof(buffer));
    cout << buffer << endl;*/
    return 0;
}