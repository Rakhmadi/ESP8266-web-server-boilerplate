#include <ESP8266WebServer.h>
#include <WiFiClient.h>
class Servs
{
private:
    /* data */
public:
    ESP8266WebServer httpx;
    Servs(int port);
    route(char path,std::function<void()> callback);
    ~Servs();
};

Servs::Servs(int port)
{
   httpx(port)
}
Servs::route(char path,std::function<void()> callback){
        httpx.on(path,callback);
}
Servs::~Servs()
{
}
