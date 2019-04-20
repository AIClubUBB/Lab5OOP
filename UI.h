#include "Controller.h"
#pragma once

class UI
{
///Here is the declaration of the methods and atributs of the UI class
public:
    Controller contr;
    UI();
    void printMenuAdmin();
    void printMenuUser();
    void printMenuMain();
    void userMenu();
    void adminMenu();
    void run();
};
