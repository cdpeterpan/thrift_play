#include "Serv.h"
#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

int main(int argc, char **argv)
{
    std::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
    std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    std::shared_ptr<TProtocol> protocal(new TBinaryProtocol(transport));
    transport->open();

    Student s;
    s.sno = 123456;
    s.sname = "testuser";
    s.ssex = 1;
    s.sage = 30;
    ServClient client(protocal);
    client.put(s);
    sleep(3);

    Student getInfo;
    client.get(getInfo);
    printf("get from server sno=%d sname=%s ssex=%d sage=%d\n", getInfo.sno, getInfo.sname.c_str(), getInfo.ssex, getInfo.sage);

    transport->close();
    return 0;
}