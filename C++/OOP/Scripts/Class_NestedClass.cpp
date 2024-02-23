#include <iostream>
#include <string>

using namespace std;

class My_IMG{
private:
    static const int SIZE = 6;

    class Pixel{
        public:
            Pixel(int red, int green, int blue){
                this->red = red;
                this->green = green;
                this->blue = blue;
            }

            string Get_PixelInfo(){
                return "\tred = " + to_string(red) + "\tgreen = " + to_string(green) + "\tblue = " + to_string(blue);
            }
        private:
            int red;
            int green;
            int blue;

    };

    Pixel pixels[SIZE]{
        Pixel((rand()%256), (rand()%256), (rand()%256)),
        Pixel((rand()%256), (rand()%256), (rand()%256)),
        Pixel((rand()%256), (rand()%256), (rand()%256)),
        Pixel((rand()%256), (rand()%256), (rand()%256)),
        Pixel((rand()%256), (rand()%256), (rand()%256)),
        Pixel((rand()%256), (rand()%256), (rand()%256))
    };

public:

    void GetImgInfo(){
        for (int i = 0; i < SIZE; i++){
            cout << "Pixel №" << i + 1 << pixels[i].Get_PixelInfo() << endl;
        }
    }

};


int main(){

    My_IMG img;
    img.GetImgInfo();
}