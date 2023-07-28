#include <iostream>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <conio.h>
#include <thread>
#include <time.h>
#define Max 99
#include <windows.h>
#include <colordlg.h>
#include "mylibsnake.h"


using namespace std;
int lenghtsnake = 6 ;

//SV1 vẽ tường + khai báo main - Lâm
void VeTuongTren();
void VeTuongDuoi();
void VeTuongtrai();
void VeTuongphai();
void VeTuong();

//SV2 Phát
void Khoitaotoadoran(int toadox[], int toadoy[]);
void VeRan (int toadox[] , int toadoy[]);
void Xoavitricu (int toadox[] , int toadoy[]);

int main()
{

        bool GameOver = false ;
        int toadox [Max] ;
        int toadoy [Max] ;

// xay tuong

        VeTuong();

// Khởi tạo tọa độ rắn + vẽ
        Khoitaotoadoran(toadox , toadoy) ;
        VeRan(toadox, toadoy) ;

    return 0;
}

 void VeTuong()
{
       // SetColor(1);
    VeTuongTren();
    VeTuongDuoi();
    VeTuongtrai();
    VeTuongphai() ;
      //  SetColor(9) ;

}


void VeTuongTren()
{
     int x = 10 , y = 1 ;
    while (x <= 100)
    {
    gotoXY(x,y) ;
    cout << "*" ;
    x=x+2;
}
}
void VeTuongDuoi()
{
     int x = 10 , y = 28 ;
    while (x < 100)
    {
    gotoXY(x,y) ;
    cout << "*" ;
    x=x+2;
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
void Khoitaotoadoran(int toadox[], int toadoy[])
{
    int x = 50 , y = 14 ;
    for (int i = 0; i <lenghtsnake  ; i ++ ){
        toadox[i] = x ;
        toadoy[i] = y ;
        x-- ;

    }
}
void VeRan (int toadox[] , int toadoy[]) {

        for (int i = 0 ; i < lenghtsnake ;i++ ){
            gotoXY(toadox[i], toadoy[i])  ;
            if (i == 0) {
                cout <<"0" ;
            } else {
            cout <<"o" ;
            }

        }
    /*
        gotoXY(toadox[0] ,toadoy[0]) ;
        cout << "o" ;
        gotoXY(toadox[1] ,toadoy[1]) ;
        cout << "o" ;
        gotoXY(toadox[2] ,toadoy[2]) ;
        cout << "o" ;
        gotoXY(toadox[3] ,toadoy[3]) ;
        cout << "o" ;
        */

}
void Xoavitricu (int toadox[] , int toadoy[]) {

        for (int i = 0 ; i < lenghtsnake ; i++ ){
            gotoXY(toadox[i], toadoy[i])  ;

                cout <<" " ;
           // lenghtsnake++ ;

        }
    }

// ham xu  ly di chuyen cua ran
//xu ly ran di chuyen



