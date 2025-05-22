#include <iostream>

#ifndef MESSAGE_HPP
#define MESSAGE_HPP

class Message{
    public:
        Message():bodyLength_(0){}
        enum {maxBytes=512};
        enum {header=4};


        Message(std::string message){
            bodyLength_=getNewBodyLength(message.size());
        }

        size_t getNewBodyLength(size_t newLength){
            if(newLength>maxBytes){
                return maxBytes;
            }
            return newLength;
        }
    
    private:
        char data[header+maxBytes];
        size_t bodyLength_;
};

#endif MESSAGE_HPP