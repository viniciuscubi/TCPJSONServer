#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <zmq.hpp>

class Server{

    private:
        std::string ip;
        zmq::context_t context{1}; // initialize the zmq context with a single IO thread
        zmq::socket_t socket{context, zmq::socket_type::rep}; // construct a REP (reply) socket and connect to interface

    public:
        Server(const std::string addr);
        ~Server();

        int send(std::string message);
        std::string receive();
        int sendByte(bool message);
};

#endif
