#include <iostream>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <conio.h>
#include <thread>
#include <time.h>
#define Max 99
#include <windows.h>
//#include <colordlg.h>
#include "mylibsnake.h"


using namespace std;
int lenghtsnake = 6 ;
int sl = 4;

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

//SV3- Sa
void XuLyRan(int toadox[], int toadoy[], int x, int y);
void them(int a[], int x);
void xoa(int a[], int vt);

//SV4- Ảnh
bool RanChamTuong (int toadox , int toadoy );
bool Ranchamduoi (int toadox[], int toadoy[] );
bool checkdieukienGameover (int toadox[] , int toadoy[] );

int main()
{

        bool GameOver = false ;
        int toadox [Max] ;
        int toadoy [Max] ;

// xay tuong

        VeTuong();

// Khởi tạo tọa độ rắn + vẽ
        Khoitaotoadoran(toadox , toadoy) ;
        VeRan(toadox, toadoy);
 //Sa
        int x = 50 , y = 14;
        int check = 2; // mac dinh ran di chuyen qua phai
        while(true)
        {
            Xoavitricu(toadox,toadoy);
            if(_kbhit())
            {
                char kitu = _getch();
                if(kitu == -32)
                {
                    kitu = _getch();
                    if(kitu == 72 && check != 0) //up
                    {
                        check =1;
                    }
                    else if(kitu == 80 && check != 1) //down
                    {
                        check = 0;
                    }
                    else if(kitu == 77 && check != 3) //right
                    {
                        check = 2;
                    }
                    else if(kitu == 75 && check != 2) //left
                    {
                        check = 3;
                    }
                }

            }

            if(check == 0)
            {
                y++;
            }
            else if(check == 1)
            {
                y--;
            }
            else if(check == 2)
            {
                x++;
            }
            else if(check == 3)
            {
                x--;
            }
            XuLyRan(toadox, toadoy, x, y);
            Sleep(300);
        }

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

// ham xu  ly di chuyen cua ran - SA
void XuLyRan(int toadox[], int toadoy[], int x, int y)
{
    //them toa do moi vao dau mang
    them(toadox,x);
    them(toadoy,y);

    //xoa toa do cuoi mang
    xoa(toadox, sl - 1);
    xoa(toadoy, sl - 1);

    //ve ran
    VeRan(toadox, toadoy);
}

void them(int a[], int x)
{
    for(int i = sl; i> 0; i--)
    {
        a[i] = a[i -1];
    }
    a[0] = x;
    sl++;
}

void xoa(int a[], int vt)
{
    for(int i = vt; i< sl; i++)
    {
        a[i] = a[i + 1];
    }
    sl--;
}

//xu ly ran di chuyen
//SV4-Ảnh
bool RanChamTuong (int toadox , int toadoy ) //xuat toa do ran hien tai
{
    if (toadoy == 1 &&(toadox >= 10 && toadox <=100))
    {
        return true ;
}
if (toadoy == 28 &&(toadox >= 10 && toadox <=100))
    {
        return true ;
}
if (toadox == 10 &&(toadoy >= 1 && toadoy <=28))
    {
        return true ;
}
if (toadox == 100 &&(toadoy >= 1 && toadoy <=28))
    {
        return true ;
}
return false ;
}
bool Ranchamduoi (int toadox[], int toadoy[] )
{
        for (int i = 1 ; i < lenghtsnake ; i++) {
            if (toadox[0] == toadox [i] && toadoy[0] == toadoy [i]){
               return true ;
            }

        }
        return false;
}
 bool checkdieukienGameover (int toadox[] , int toadoy[] )
     {
        bool check1 = RanChamTuong (toadox[0] ,toadoy[0] );
        bool check2 = Ranchamduoi (toadox,toadoy );
        if (check1 == true || check2 == true)
        {
            return true ;
        }
        return false ;
     }


