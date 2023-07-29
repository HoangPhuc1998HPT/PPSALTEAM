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
//int sl = 4;
int tocdochay = 400 ;
int DiemsoHT = 0 ;

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
void XuLyRan(int toadox[],int toadoy[], int x , int y,int &toadothucanx,int &toadothucany);
void them(int a[], int x);
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
// vẽ ô ghi điểm
// Ghi diem so
void DiemSo (int &Sodiemoday);


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

// hởi tạo tọa độ va kiem tra
        srand(time(NULL)) ; // lấy giá trị theo thời gian thực
        int toadothucanx = 0, toadothucany = 0  ;
        KhoiTaoToaDoThucAn(toadox, toadoy , toadothucanx, toadothucany ); // tọa độ được khởi tạo ngẫu nhiên

 //Sa
        int x = 50 , y = 14;
        int check = 2; // mac dinh ran di chuyen qua phai
        while(GameOver == false)
        {
            Xoavitricu(toadox,toadoy);
                if (kbhit()){
            char kitu = getch();

            if ((kitu == 'a'|| kitu ==75 )&& check!= 2) { //qua trai
                    check = 3;
            } else if ((kitu == 'w' || kitu == 72)&& check!= 1) {//di len
                check = 0;
            } else if ((kitu == 'd'|| kitu == 77) && check!= 3) {//qua phai
                check = 2;
           } else if ((kitu == 's' || kitu == 80)&& check!= 0) {//di xuong
               check = 1;
           }
}

            if(check == 0)
            {
                y--;
            }
            else if(check == 1)
            {
                y++;
            }
            else if(check == 2)
            {
                x++;
            }
            else if(check == 3)
            {
                x--;
            }

         //   XuLyRan(toadox, toadoy, x, y);

            //xử lý cho ran chay
        XuLyRan (toadox, toadoy, x , y,toadothucanx,toadothucany) ;


// Xoa(toadox,toadoy)
        GameOver = checkdieukienGameover ( toadox , toadoy );
        this_thread::sleep_for(chrono::milliseconds(tocdochay)) ;

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
void XuLyRan(int toadox[],int toadoy[], int x , int y,int &toadothucanx,int &toadothucany)
{
    // them toa do vao dau mang

        them(toadox, x);
        them(toadoy, y);
    if ((XuLyRanAnThucAn(toadox[0], toadoy[0], toadothucanx,toadothucany)) == false )
    {
    // xoa toa do cuoi mang
        Xoa(toadox , lenghtsnake - 1);
        Xoa(toadoy, lenghtsnake - 1);

    //KhoiTaoToaDoThucAn(toadox, toadoy,toadothucanx, toadothucany);

    } else {
     //bo qua xoa toa do cuoi mang
        lenghtsnake-- ;
         KhoiTaoToaDoThucAn(toadox, toadoy,toadothucanx, toadothucany);

        // dieu chinh toc do ran chay sau khi rắn ăn quả

          tocdochay = tocdochay - 10 ; //giới hạn khi tocdochay = 0
          // sau mỗi lần ăn thức ăn rắn sẽ tăng tốc độ lên 10đ



    }
    // ve ran
     VeRan(toadox, toadoy);
}


void them(int a[] , int x )
{
    for (int i = lenghtsnake ; i > 0 ; i-- )
    {
        a[i] = a[i - 1] ;
    }
    a[0] = x ;
    lenghtsnake++;

}
void Xoa (int a[] , int vt)
{
    for (int i = vt ; i < lenghtsnake ; i++ )
    {
        a[i] = a[i+1] ;

    }
    lenghtsnake-- ;
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

bool checkRanDeLenThucAn(int toadoranx[], int toadorany[],int toadothucanx, int toadothucany)
{
        for (int i = 0 ; i < lenghtsnake ; i++ )
        {
            if ((toadothucanx == toadoranx[i] )&&( toadothucany == toadorany[i]))
            {
                return true ;// ran de len thuc an
            }
        }
    return false ;// ran khong de len qua
   // KhoiTaoToaDoThucAn(toadothucanx,toadothucany)
}


void KhoiTaoToaDoThucAn(int toadoranx[], int toadorany[],int &toadothucanx, int &toadothucany)
{
    do
    {
    toadothucanx = rand ()% (99 - 11 + 1 ) + 11 ; //x >10 - x =11
    toadothucany = rand ()%( 27 - 2 + 1) + 2 ; // y > 1 -y = 2
    } while (checkRanDeLenThucAn(toadoranx,toadorany,toadothucanx,toadothucany)== true) ;

    gotoXY(toadothucanx,toadothucany) ;

    cout<< "@" ;
    }

// neu toa do ran = toa do thuc an ran ++
bool XuLyRanAnThucAn (int toadoranx, int toadorany,int toadothucanx, int toadothucany) // khi ran an qua
{
        if ((toadoranx == toadothucanx) && (toadorany == toadothucany ))
        {
            return true ;

        }
    return false ;
}

