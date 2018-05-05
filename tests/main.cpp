#include <iostream>
#include "../ringBuffDynamicCPP.hpp"

int main(){
    std::cout << "Welcome to the test routine" << std::endl;
    ringBuffDynamicCPP<int> rBuff(6);
    rBuff.push_back(4);
    ringBuffDynamicCPP<float> rBuffFloat(5);
    rBuffFloat.push_back(7.5);
    std::cout << "Constructed ring buffers" << std::endl;

    std::cout << "Testing rBuff" << std::endl;
    std::cout << "The first entry of rBuff should be: 4" << std::endl;
    std::cout << "The 1st recorded entry of rBuff is: " << rBuff.getHead() << std::endl;
    std::cout << "Using getPeak() the 1st entry is: " << rBuff.getPeek(0) << std::endl;

    std::cout << "Testing rBuffFloat" << std::endl;
    std::cout << "The first entry of rBuff should be: 7.5" << std::endl;
    std::cout << "The 1st recorded entry of rBuff is: " << rBuffFloat.getHead() << std::endl;
    std::cout << "Using getPeak() the 1st entry is: " << rBuffFloat.getPeek(0) << std::endl;

    std::cout << "Adding more items to rBuff" << std::endl;
    rBuff.push_back(75);
    rBuff.push_back(34);
    
    std::cout << "Listing all rBuff contents (oldest to newest" << std::endl;
    std::cout << "The contents should be 4, 75, 34" << std::endl;
    std::cout << "The contents of rBuff are: ";
    for(int i = 2; i >= 0; i--){
        std::cout << rBuff.getPeek(i) <<", ";
    }
    std::cout << std::endl;
    
    std::cout << "Testing if current head is correct, value should be: 34" << std::endl;
    std::cout << "Current head: " << rBuff.getHead() << std::endl;

    std::cout << "Testing to see how rBuff handles a wrap around" << std::endl;
    rBuff.push_back(99);
    rBuff.push_back(1);
    rBuff.push_back(15);
    rBuff.push_back(66);
    rBuff.push_back(45);

    std::cout << "Listing all rBuff contents (newest to oldest)" << std::endl;
    std::cout << "The contents should be 45, 66, 15, 1, 99, 34" << std::endl;
    std::cout << "The contents of rBuff are: ";
    for(int i = 0; i <= 5; i++){
        std::cout << rBuff.getPeek(i) <<", ";
    }
    std::cout << std::endl;

    rBuff.push_back(80);
    rBuff.push_back(81);
    rBuff.push_back(82);
    rBuff.push_back(83);
    rBuff.push_back(84);
    rBuff.push_back(85);
    rBuff.push_back(86);
    rBuff.push_back(87);
    rBuff.push_back(88);
    rBuff.push_back(89);

    std::cout << "Listing all rBuff contents (newest to oldest)" << std::endl;
    std::cout << "The contents should be 89, 88, 87, 86, 85, 84" << std::endl;
    std::cout << "The contents of rBuff are: ";
    for(int i = 0; i <= 5; i++){
        std::cout << rBuff.getPeek(i) <<", ";
    }
    std::cout << std::endl;
    std::cout << "The head value of the buffer should be 89" << std::endl;
    std::cout << "The head contents based on rBuff.getHead(): " << rBuff.getHead() << std::endl;
    std::cout << "The head contents based on rBuff.getPeek(): " << rBuff.getPeek(0) << std::endl;
    std::cout << "The entry wrapped around (7th item out of 6): " << rBuff.getPeek(6) << std::endl;
    std::cout << "The entry wrapped around (6th item out of 6): " << rBuff.getPeek(5) << std::endl;
    std::cout << "The most recent entry using rBuff.getPeek(0): " << rBuff.getPeek(0) << std::endl;

    std::cout << "Testing constructors" << std::endl;
    ringBuffDynamicCPP<int> buff1;
    ringBuffDynamicCPP<int> buff2(2);
    ringBuffDynamicCPP<int> buff3(1, 3);
    buff1.push_back(1);
    buff2.push_back(2);
    buff3.push_back(4);

    std::cout << "The size of buff1: " << buff1.getSize() << " The max size of buff1: " << buff1.getMaxSize() << std::endl;
    std::cout << "The size of buff2: " << buff2.getSize() << " The max size of buff2: " << buff2.getMaxSize() << std::endl;
    std::cout << "The size of buff3: " << buff3.getSize() << " The max size of buff3: " << buff3.getMaxSize() << std::endl;

    std::cout << "The contents of buff1: " << std::endl;
    for(int i = 0; i < buff1.getSize(); i++){
        std::cout << "Entry: " << i << " Value: " << buff1.getPeek(i) << std::endl;
    }
    std::cout << "The contents of buff2: " << std::endl;
    for(int i = 0; i < buff2.getSize(); i++){
        std::cout << "Entry: " << i << " Value: " << buff2.getPeek(i) << std::endl;
    }
    std::cout << "The contents of buff3: " << std::endl;
    for(int i = 0; i < buff3.getSize(); i++){
        std::cout << "Entry: " << i << " Value: " << buff3.getPeek(i) << std::endl;
    }

    return(0);
}