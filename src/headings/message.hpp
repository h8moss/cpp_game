#pragma once
#include <string>

class Message
{
protected:
    std::string data;
    std::string id;

public:
    Message(std::string _id, std::string _data);
    std::string getData() const;
    std::string getID() const;
};