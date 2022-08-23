#include "headings/message.hpp"

Message::Message(std::string _id, std::string _data) : data{_data}, id{_id} {}

std::string Message::getData() const { return data; }
std::string Message::getID() const { return id; }