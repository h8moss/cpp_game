#pragma once

#include <functional>
#include <string>

#include "message.hpp"

class MessageReceiver
{
public:
    std::function<void(Message)> receiver;
    std::string messageID;

    MessageReceiver(
        std::string messageID,
        std::function<void(Message)>
            receiver);
};