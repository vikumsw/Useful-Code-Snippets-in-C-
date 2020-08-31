// Example program
#include <iostream>
#include <string>
#include <list>

using namespace std;

#define PRE_STAGE_1 1
#define POST_STAGE_1 2
#define POST_STAGE_2 3


class observer
{
    
public:
    virtual void on_event(int event) = 0;
    
};


class logger: public observer
{
    void on_event(int event)
    {
        switch (event)
        {
            case PRE_STAGE_1:
                cout<< "PRE_STAGE_1" << endl;
                break;
            case POST_STAGE_1:
                cout<< "POST_STAGE_1" << endl;
                break;
            case POST_STAGE_2:
                cout<< "POST_STAGE_2" << endl;
                break;
            default:
                break;
            
        }
        
    };
};


class stringProcessor
{
    std::list<observer*> observer_list;
    
    void fireObservers(int event)
    {
        for (auto observer : observer_list)
            observer->on_event(event);
    }
    
    string processStage1(string str)
    {
        return str;
    }
    
    string processStage2(string str)
    {
        return str;
    }
    
public:
    string processString(string str)
    {
        
        
        fireObservers(PRE_STAGE_1);
        string str1 = processStage1(str);
        fireObservers(POST_STAGE_1);
        string str2 = processStage2(str1);
        fireObservers(POST_STAGE_2);
        return str2;
    }
    
    void addObserver(observer* ob)
    {
        observer_list.push_back(ob);
    }
    
    
    
};

int main()
{
  stringProcessor strP;
  logger log;
  strP.addObserver(&log);
  strP.processString("Hello_");
}
