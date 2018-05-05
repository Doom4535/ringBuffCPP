//! \brief This file contains a simple ring-buffer basis
// that is to be expanded upon by the child classes
// that is built using std::vector
// File:              ringBuffBaseCPP.hpp
// Author:            Aaron Covrig
// Revision:          0.0.01
// Date:
// Dependencies:
//

#ifndef RINGBUFFBASECPP_HPP
#define RINGBUFFBASECPP_HPP

#include <vector>

namespace rBuffSupport {
    template <typename T>
    void rotateLeft(std::vector<T> &v){
        T tempDat;
        tempDat = v[0];
        for(size_t i = 0; i < v.size() -1; i++){
            v[i] = v[i +1];
        }
        v[v.size() -1] = tempDat;
    }
}

template <typename T>
class ringBuffBaseCPP{
    private:
        // Specific buffer type goes here in child classes
        

    protected:
        int head;            // Location of most recent entry
        int maxSize;         // Max size
        virtual void removeOldest(void){}

    public:
        ringBuffBaseCPP(){}
        virtual size_t getSize(void){return(0);}
        virtual size_t getMaxSize(void){return(0);}
        virtual void setmaxSize(size_t newSize){}
        virtual T getHead(void){return(0);}
        virtual T getPeek(size_t entryNum){return(0);}
        virtual void push_back(T newData){}
        virtual bool isEmpty(void){return(true);}
        virtual bool isFull(void){return(true);}
};

#endif /* ringBuffBaseCPP_HPP */