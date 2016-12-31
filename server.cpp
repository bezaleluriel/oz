#include <iostream>
#include "src/sockets/Udp.h"
#include "src/DriverTest.h"


int main() {
    std::cout << "Hello, from server" << std::endl;

    Udp udp(1, 5555);///opening port
    udp.initialize();///connecting to port

    char buffer[1024];
    udp.reciveData(buffer, sizeof(buffer));///receiving data from the client
    string str(buffer, sizeof(buffer));
    DriverTest *driverTest;///creating a pointer to driver test
    GridNodeTest* gridNodeTest;///creating grid node test
    boost::iostreams::basic_array_source<char> device(str.c_str(), str.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> driverTest;///serialized object will be put in this pointer to driversTest
    std::cout << driverTest->getId() << endl;///printing the id
    std::cout << driverTest->getChar() <<endl;///printing the char.
    gridNodeTest = driverTest->getGridNodeTest();
    std::cout<< gridNodeTest->getA()<< std::endl;
    std::cout<< gridNodeTest->getC()<< std::endl;


    // cout << buffer << endl;
    udp.sendData("sup?");
    udp.reciveData(buffer, sizeof(buffer));///will wait forever - client wont answer.
    string str2(buffer, sizeof(buffer));
    BaseCab* p;///creating a pointer to driver test
    boost::iostreams::basic_array_source<char> device2(str.c_str(), str.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s3(device);
    boost::archive::binary_iarchive ia2(s3);
    ia2 >> p;///serialized object will be put in this pointer to driversTest
   // udp.sendData("suprr?");
/*
   usleep(5000);
    Udp udp2(1, 5554);
    udp2.initialize();

    char buffer2[1024];
    udp2.reciveData(buffer2, sizeof(buffer2));
   // string str(buffer, sizeof(buffer));
    //std::string serial_str = std::string s(buffer2,sizeof(buffer2));

    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s1(device);
    //ia >> *driverTest;
    ia >> *driverTest;
    std::cout << driverTest->getId();
    //std::cout << driverTest->getChar();
   // cout << buffer2 << endl;
    udp2.sendData("sup?");

    // support more than one client?*/
    return 0;
}
