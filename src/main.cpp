#include <string>
#include <iostream>
#include <pigpio.h>
#include <unistd.h>
#include "../include/server.hpp"
#include "../include/parser.hpp"
#include "../include/pinsys.hpp"

#define test_pin 14

int main() 
{  

    bool var = true;
	
	PinSys ps(test_pin);

    Server sv("tcp://192.168.1.102:5555");


    while(1) 
    {
        std::string msg = sv.receive();

        //std::cout << "Received: " << msg << std::endl;
        Parser parser(msg);

		
        if(parser.parse()){
			
            rapidjson::Value &data = parser.getData();
            rapidjson::Value &ahi = data["AHi"];

            if(ahi.GetInt()){
				
                var = false;
                ahi.SetInt(0);
            }else{
				
                var = true;
                ahi.SetInt(1);
            }

			
            rapidjson::StringBuffer buffer;
            rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

            data.Accept(writer);
            
			
            sv.send(buffer.GetString());
			
			ps.updatePin(var);

        }else{
            std::cerr << "error" << std::endl;

        }

    }

    return 0;
}