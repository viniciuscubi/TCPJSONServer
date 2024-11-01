#include "../include/server.hpp"


Server::Server(const std::string addr){
    ip = addr;
    this->socket.bind(ip);
}

Server::~Server(){
    this->socket.unbind(ip);
}


int Server::send(std::string message){
    this->socket.send(zmq::buffer(message), zmq::send_flags::none);
    return 0;
}

int Server::sendByte(bool message){
    std::string msg;

    if(message){
        msg = "1";
    }else{
        msg = "0";
    }

    this->socket.send(zmq::buffer(msg), zmq::send_flags::none);
    return 0;
}

std::string Server::receive(){
    zmq::message_t request;
    this->socket.recv(request, zmq::recv_flags::none);
    return request.to_string();
}