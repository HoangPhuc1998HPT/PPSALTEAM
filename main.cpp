#include <iostream>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <conio.h>
#include <thread>



using namespace std;

int main()
{

        bool GameOver = false ;
        int toadox [Max] ;
        int toadoy [Max] ;

// xay tuong
    void VeTuong()
{
        SetColor(1);
    VeTuongTren();
    VeTuongDuoi();
    VeTuongtrai();
    VeTuongphai() ;
        SetColor(9) ;

}


void VeTuongTren()
{
     int x = 10 , y = 1 ;
    while (x <= 100)
    {
    gotoXY(x,y) ;
    cout << "*" ;
    x++;
}
}
void VeTuongDuoi()
{
     int x = 10 , y = 28 ;
    while (x < 100)
    {
    gotoXY(x,y) ;
    cout << "*" ;
    x++;
}
}
void VeTuongtrai()
{
     int x = 10 , y = 1 ;
    while (y <= 28)
    {
    gotoXY(x,y) ;
    cout << "*" ;
    y++;
}
}
void VeTuongphai()
{
     int x = 100 , y = 1 ;
    while (y <= 28)
    {
    gotoXY(x,y) ;
    cout << "*" ;
    y++;
}
}



    return 0;
}
