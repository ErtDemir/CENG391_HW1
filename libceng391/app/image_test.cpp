// @author Name: Ertuğrul Demir - ID: 260201059
#include <cstdlib>
#include <iostream>

#include "ceng391/image.hpp"

using namespace std;
using ceng391::Image;

void exercise_1(int channels, int width, int height, int x_tl, int y_tl, int rect_width, int rect_height) ;

void exercise_2(const std::string &path){
    Image img(0, 0, 1);
    img.read_pnm(path);
    std::string write_direc = "/tmp/test_img_read";
    img.write_pnm(write_direc);
    cout << "Read "<<img.type()<<" image at "<<path<<" and write to "<<write_direc<< endl;
}
void exercise_3(int channels);

int main(int /*argc*/, char** /*argv*/)
{
    exercise_1(4 , 320 , 240 , 0 , 0 , 100 ,150);
    exercise_2("/tmp/test_img_rgba.ppm");
    exercise_3(1);

    return EXIT_SUCCESS;
}
    /*  README
     *  TEST-1
     *  line 22 executes exercise 1 then create a rgba img object and write a file that /tmp/test_img_rgba
     *
     *  TEST-2
     *  line 23 executes exercise 2 then read a file as parameter (/tmp/test_img_rgba.ppm) and write a file that /tmp/test_img_read
     *
     *  TEST-3
     *  line 24 executes exercise 3 then read a file inside itself and convert to another channel format
     *  and write a file that /tmp/test_img_rgba_to_grayscale
     *
     *  Some explanation
     *  Channels value in exercise_1 and 3 represents :  1 -> grayscale
     *                                                   3 -> rgb
     *                                                   4 -> rgba
     *
     *  exercise_1 executes between lines from 58 to  87 and then
     *  these lines execute some of those lines between from 50 to 184 in image.cpp
     *
     *  exercise_2 executes between lines from 12 to 17 and then
     *  these lines execute some of those lines between from 128 to 249 in image.cpp
     *
     *  exercise_3 executes between lines from 89 to 118 and then
     *  these lines execute some of those lines between from 128 to 390 in image.cpp
     */




void exercise_1(int channels, int width, int height, int x_tl, int y_tl, int rect_width, int rect_height){
    Image img(width, height, channels);
    cout << "Created image of size (" << img.w()
         << "x" << img.h() << ")!" << endl;
    std::string write_direc;
    switch(img.n_channels()) {
        case 1:
            img.set(255);
            img.set_rect(x_tl, y_tl, rect_width, rect_height, 0);
            write_direc=  "/tmp/test_img_gray" ;
            break;
        case 3:
            img.set_rgb(255, 0, 0);
            img.set_rect_rgb(x_tl, y_tl, rect_width, rect_height, 255, 255, 0);
            write_direc=  "/tmp/test_img_rgb" ;
            break;
        case 4:
            img.set_rgba(255, 0, 0);
            img.set_rect_rgba(x_tl, y_tl, rect_width, rect_height, 255, 255, 0);
            write_direc=  "/tmp/test_img_rgba" ;

            break;
        default:
            cerr << "Invalid value of m_n_channels! Please check that number."<< endl;
            return;

    }
    img.write_pnm(write_direc);
    cout << "Saved the created image to "<< write_direc << endl;
}

void exercise_3(int channels){
    Image img(0,0,1);
    std::string write_direc;
    img.read_pnm("/tmp/test_img_rgba.ppm");
    //we can give these value to parameters , we can also give the image as file name or object.
    std::string name ;
    std::string convert_name;
    name = img.type();
    switch (channels) {
        case 1:
            img.to_grayscale();
            convert_name = "grayscale";
            break;
        case 3:
            img.to_rgb();
            convert_name = "rgb";
            break;
        case 4:
            img.to_rgba();
            convert_name = "rgba";
            break;
        default:
            convert_name = "";
            cerr << "Invalid value of channels! Please check that number." << endl;
            return;
    }
    write_direc = "/tmp/test_img_"+name+"_to_" + convert_name;
    img.write_pnm(write_direc);
    cout << "Converted image "<< name <<" to "+convert_name <<". And saved the image to"<<write_direc<< endl;
}




/// Local Variables:
/// mode: c++
/// compile-command: "make -C ../build image-test"
/// End:
