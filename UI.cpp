#include "UI.h"

///The default constructor of the UI class
UI::UI()
{

}
void UI::printMenuUser()
{
    string s;
    s+="1 - Show movies from watch list\n";
    s+="2 - Add movie to watch list from genre\n";
    s+="3 - Delete movie from watch list\n";
    s+="0 - Back to main menu\n";
    cout<<s<<endl;
}
void UI::printMenuMain()
{
    string s;
    s+="1 - Administrator menu\n";
    s+="2 - User menu\n";
    s+="0 - Exit\n";
    cout<<s<<endl;
}
void UI::userMenu()
{
    bool ok=true;
    string s;
    while(ok==true)
    {
        this->printMenuUser();
        cout<<"Please insert the value of the option you want!"<<endl;
        cin>>s;
        if(contr.isInt(s)==true && contr.stringToInt(s)>=0 && contr.stringToInt(s)<=3)
        {
            if(contr.stringToInt(s)==0)
                ok=false;
            else if(contr.stringToInt(s)==1)
            {
                if(contr.WL.movieList.size()==0)
                    cout<<"The watch list is empty"<<endl;
                else
                    this->contr.showAllMovies(contr.WL.movieList);
            }
            else if(contr.stringToInt(s)==2)
            {
                cout<<"Please insert the genre you would like: ";
                string gen;
                cin>>gen;
                contr.runSlide(contr.showByGenre(gen));
            }
            else if(contr.stringToInt(s)==3)
            {
                this->contr.deleteFromWL();
            }
        }
        else
            cout<<"The value you inserted is not valid, please try again!"<<endl;
    }
}
void UI::adminMenu()
{

}
void UI::run()
{
    bool ok=true;
    string s;
    while(ok==true)
    {
        this->printMenuMain();
        cout<<"Please insert the value of the option you want!"<<endl;
        cin>>s;
        if(contr.isInt(s)==true && contr.stringToInt(s)>=0 && contr.stringToInt(s)<=2)
        {
            if(contr.stringToInt(s)==0)
                ok=false;
            else if(contr.stringToInt(s)==1)
            {
                this->adminMenu();
            }
            else if(contr.stringToInt(s)==2)
            {
                this->userMenu();
            }
        }
        else
            cout<<"The value you inserted is not valid, please try again!"<<endl;
    }
}
