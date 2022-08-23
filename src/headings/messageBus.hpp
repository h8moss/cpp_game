#pragma once
#include <functional>
#include <vector>
#include <queue>
#include <string>

#include "entity.hpp"
#include "message.hpp"
#include "messageReciever.hpp"

class MessageBus : public Entity
{
protected:
    std::vector<MessageReceiver> receivers;
    std::queue<Message> messages;

public:
    static std::string messageBusID;

    MessageBus();
    ~MessageBus();

    void addReceiver(MessageReceiver messageReceiver);
    void sendMessage(Message message);

    virtual void update() override;
    virtual void setup() override;
    virtual void draw() const override;

    static MessageBus *getMessageBus();
};