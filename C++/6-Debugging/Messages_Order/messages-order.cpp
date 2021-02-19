#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

class Message {
private:
    std::string text;
    long message_index;
    static long num_messages;
public:
    explicit Message(std::string text) : text(std::move(text)), message_index(num_messages++) {
    }

    const std::string &get_text() {
        return text;
    }

    bool operator<(const Message &other) {
        return message_index < other.message_index;
    }
};
long Message::num_messages = 0;

class MessageFactory {
public:
    Message create_message(std::string text) {
        return Message(std::move(text));
    }
};

class Recipient {
private:
    std::vector<Message> messages_vec;

    void fix_order() {
        std::sort(messages_vec.begin(), messages_vec.end());
    }

public:
    void receive(const Message &msg) {
        messages_vec.push_back(msg);
    }

    void print_messages() {
        fix_order();
        for (auto &msg : messages_vec) {
            std::cout << msg.get_text() << "\n";
        }
        messages_vec.clear();
    }
};

class Network {
public:
    static void send_messages(std::vector<Message> messages, Recipient &recipient) {
        // simulates the unpredictable network, where sent messages might arrive in unspecified order
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(messages.begin(), messages.end(), g);
        for (const auto &msg : messages) {
            recipient.receive(msg);
        }
    }
};

int main() {
    MessageFactory message_factory;
    Recipient recipient;

    std::vector<Message> messages_vec;
    std::string text;
    while (getline(std::cin, text)) {
        messages_vec.push_back(message_factory.create_message(text));
    }

    Network::send_messages(messages_vec, recipient);
    recipient.print_messages();
}
