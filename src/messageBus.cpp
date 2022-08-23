#include "headings/messageBus.hpp"

#include "headings/entityManager.hpp"

std::string MessageBus::messageBusID = "MESSAGE BUS";

MessageBus::MessageBus() : Entity(static_cast<std::string>(messageBusID)) {}
MessageBus::~MessageBus() {}

void MessageBus::addReceiver(MessageReceiver messageReceiver)
{
    receivers.push_back(messageReceiver);
}
void MessageBus::sendMessage(Message message)
{
    messages.push(message);
}

void MessageBus::update()
{
    for (; !messages.empty(); messages.pop()) // While messages is not empty, pop messages each loop
    {
        for (auto iter = receivers.begin(); iter != receivers.end(); ++iter)
        {
            if (iter->messageID == messages.front().getID())
            {
                iter->receiver(messages.front());
            }
        }
    }
}
void MessageBus::setup() {}
void MessageBus::draw() const {}

MessageBus *MessageBus::getMessageBus()
{
    return static_cast<MessageBus *>(EntityManager::getInstance()->getEntity(static_cast<std::string>(messageBusID)));
}