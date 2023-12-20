#ifndef BASECLASS_H
#define BASECLASS_H
class BaseClass
{
public:
    struct DataStruct
    {
        int ch_num;
        double* data;
        char marker;
    };
    virtual void ReceiveData(const DataStruct& data) = 0;
    virtual void SendData(const DataStruct& data) = 0;
};
#endif // BASECLASS_H
