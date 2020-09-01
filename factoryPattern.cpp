// Example program
#include <iostream>
#include <string>

using namespace std;

class stringProcessor
{
    public:
    virtual string process(string str)
    {
        return str;
    }
    
};


class stringProcessor_ : public stringProcessor
{
    public:
    string process(string str) override
    {
        return str + "_";
    }
    
};

class factory
{
    public:
    static stringProcessor* getProcessor();
};

stringProcessor* factory::getProcessor()
{
    //return new stringProcessor;
    return new stringProcessor_;
}


int main()
{
    string input = "aaa";
    stringProcessor* str_p = factory::getProcessor();
    cout<< str_p->process(input) << endl;
}
