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

//SV3 Sa
void Dichuyeran(int toadox[],int toadoy[], int x , int y,int &toadothucanx,int &toadothucany);
void them(int a[] , int x );
void Xoa (int a[] , int vt);

//SV4- Ảnh
bool RanChamTuong (int toadox , int toadoy );
bool Ranchamduoi (int toadox[], int toadoy[] );
bool checkdieukienGameover (int toadox[] , int toadoy[] );

//SV5 - Phúc
void KhoiTaoToaDoThucAn(int toadoranx[], int toadorany[],int &toadothucanx, int &toadothucany);// tao thuc an
bool checkRanDeLenThucAn (int toadoranx[], int toadorany[],int toadothucanx, int toadothucany);
bool XuLyRanAnThucAn (int toadoranx, int toadorany,int toadothucanx, int toadothucany);
// cải tiến phía sau
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



    return 0;
}
