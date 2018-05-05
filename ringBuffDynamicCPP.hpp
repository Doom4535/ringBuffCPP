//! \brief This file contains a simple ring-buffer implementation
// that is built using std::vector
// File:              ringBuffDynamicCPP.hpp
// Author:            Aaron Covrig
// Revision:          0.0.01
// Date:
// Dependencies: ringBuffBaseCPP.hpp, std::vector
//

#ifndef RINGBUFFDYNAMICCPP_HPP
#define RINGBUFFDYNAMICCPP_HPP

#include <vector>

#include "ringBuffBaseCPP.hpp"

template <typename T>
class ringBuffDynamicCPP : public ringBuffBaseCPP<T> {
    private:
        std::vector<T> rBuff;       // Specific buffer type used by child

    protected:
        void removeOldest(void){
            bool done = false;
            while(!done){
                if(this->head +1 >= rBuff.size()){     // If oldest value at end
                    rBuff.pop_back();
                    done = true;
                }
                else{
                    rBuffSupport::rotateLeft(rBuff);
                }
            }
        }

    public:
        ringBuffDynamicCPP(size_t startingSize){
            rBuff.reserve(startingSize);
            this->maxSize = startingSize;
            this->head = 0;
            this->maxSize = startingSize;
        }
        ringBuffDynamicCPP() : ringBuffDynamicCPP(5){
            this->maxSize = 5;
            this->head = 0;
        }
        ringBuffDynamicCPP(T firstEntry, size_t startingSize) : ringBuffDynamicCPP(startingSize){
            this->maxSize = startingSize;
            this->head = 0;
            rBuff.push_back(firstEntry);
        }
        size_t getSize(void){
            return(rBuff.size());
        }
        size_t getMaxSize(void){
            return(this->maxSize);
        }
        void setmaxSize(size_t newSize){
            while(rBuff.size() > newSize){              // We're going to lose some data
                removeOldest();                         // Remove the oldest entry
            }
            this->maxSize = newSize;
            rBuff.reserve(this->maxSize);                     // Reserving, if smaller it will slowly grow
        }
        T getHead(void){
            return(rBuff[this->head]);
        }
        T getPeek(int entryNum){
            //size_t target = (rBuff.size() - (entryNum +1)) % rBuff.size();
            int location = this->head - (entryNum % rBuff.size());
            int target = (location >= 0) ? location : rBuff.size() + location;
            return(rBuff[target]);
        }
        void push_back(T newData){
            size_t wLocation = (this->head >= (this->maxSize -1) ? 0 : this->head +1);
            if(rBuff.size() < this->maxSize){
                rBuff.push_back(newData);
                this->head = rBuff.size() -1;
            }
            else{
                rBuff[wLocation] = newData;
                this->head = wLocation;
            }
        }
        bool isEmpty(void){
            return( (rBuff.size() == 0) ? true : false );
        }
        bool isFull(void){
            return ( (rBuff.size() == this->maxSize ? true : false) );
        }
};

#endif /* RINGBUFFDYNAMICCPP_HPP */
