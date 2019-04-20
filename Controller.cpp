#include "Controller.h"

bool Controller::isInt(string val)
{
    for(int i=0;i<val.length();i++)
    {
        if(val[i]<48 || val[i]>57)
            return false;
    }
    return true;
}
int Controller::stringToInt(string val)
{
    int ret=0;
    for(int i=0;i<val.length();i++)
    {
        ret=ret*10+(val[i]-48);
    }
    this->repo.fillRepo();
    return ret;
}
Controller::Controller()
{

}
