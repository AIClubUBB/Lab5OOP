#include "Controller.h"

int main() {
    Controller contr=Controller();
    cout<<contr.isInt("56")<<endl;
    cout<<contr.isInt("5hx6")<<endl;
    cout<<contr.stringToInt("56")<<endl;
    /*string baseUrl;
    baseUrl="https://www.google.com/";
    string completeUrl=baseUrl;
    system(std::string("start " + completeUrl).c_str());*/
	return 0;
}
