#include "Domain.h"

int main() {
    string baseUrl;
    baseUrl="https://www.youtube.com/channel/UC54cfMkmXqLjxgdqd00CY-g";
    string completeUrl=baseUrl;
    system(std::string("start " + completeUrl).c_str());
	return 0;
}
