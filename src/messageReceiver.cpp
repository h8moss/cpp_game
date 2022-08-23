#include "headings/messageReciever.hpp"

MessageReceiver::MessageReceiver(
    std::string _id,
    std::function<void(Message)> _receiver)
    : receiver{_receiver}, messageID{_id} {}