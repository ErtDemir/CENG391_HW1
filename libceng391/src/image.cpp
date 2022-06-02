// @author Name: Ertuğrul Demir - ID: 260201059
#include "ceng391/image.hpp"

#include<fstream>
#include<cstring>
#include <iostream>
#include <sstream>

using namespace std;

namespace ceng391 {

Image::Image(int width, int height,int n_channels, int step)
{
        m_width = width;
        m_height = height;
        m_n_channels = n_channels;

        if (step < width * n_channels)
            step = width * n_channels;
        m_step = step;

        m_data = new uchar[m_step * m_height];
}

std::string Image::type() { // 1 -> grayscale , 3 -> rgb , 4 -> rgba
    string name;
    switch (n_channels()) {
        case 1:
            name = "grayscale";
            break;
        case 3:
            name = "rgb";
            break;
        case 4:
            name = "rgba";
            break;
    }
    return name;
}

Image::~Image()
{
    delete [] m_data;
}




void Image::set_rect(int x_tl, int y_tl, int width, int height, uchar value)
{
        if (x_tl < 0) {
                width += x_tl;
                x_tl = 0;
        }

        if (y_tl < 0) {
                height += y_tl;
                y_tl = 0;
        }

        size_t length = min(width, m_width - x_tl);
        int y_max = min(y_tl + height, m_height);
        for (int y = y_tl; y < y_max; ++y) {
                uchar *row_y = data(y) + x_tl;
                memset(row_y, value, length);
        }
}

void Image::set_rect_rgb(int x_tl, int y_tl, int width, int height, uchar red_value , uchar green_value , uchar blue_value )
    {
        uchar* value_list = new uchar[3];
        if (x_tl < 0) {
            width += x_tl;
            x_tl = 0;
        }

        if (y_tl < 0) {
            height += y_tl;
            y_tl = 0;
        }
        value_list[0] = red_value;
        value_list[1] = green_value;
        value_list[2] = blue_value;
        for (int y = y_tl; y < y_tl+height; ++y) {
            if (y >= m_height)
                break;
            uchar* row_data = data(y) + x_tl;
            for (int x = x_tl; x < x_tl+width; ++x) {
                if (x >= m_width)
                    break;
                for (int ch = 0; ch < m_n_channels; ++ch)
                    row_data[x*m_n_channels + ch] = value_list[ch];
            }
        }
    }

void Image::set_rect_rgba(int x_tl, int y_tl, int width, int height, uchar red_value , uchar green_value , uchar blue_value )
    {
        uchar* value_list = new uchar[3];
        if (x_tl < 0) {
            width += x_tl;
            x_tl = 0;
        }

        if (y_tl < 0) {
            height += y_tl;
            y_tl = 0;
        }
        value_list[0] = red_value;
        value_list[1] = green_value;
        value_list[2] = blue_value;
        value_list[3] = 255; // Default alpha value
        for (int y = y_tl; y < y_tl+height; ++y) {
            if (y >= m_height)
                break;
            uchar* row_data = data(y) + x_tl;
            for (int x = x_tl; x < x_tl+width; ++x) {
                if (x >= m_width)
                    break;
                for (int ch = 0; ch < m_n_channels; ++ch)
                    row_data[x*m_n_channels + ch] = value_list[ch];
            }
        }
    }


void Image::write_pnm(const  std::string& filename) const
    {
        if (n_channels() == 1 )
        {
            const string magic_head = "P5";
            ofstream fout;
            string extended_name = filename + ".pgm";
            fout.open(extended_name.c_str(), ios::out | ios::binary);
            fout << magic_head << "\n";
            fout << m_width << " " << m_height << " 255\n";
            for (int y = 0; y < m_height; ++y) {
                const uchar *row_data = this->data(y);
                fout.write(reinterpret_cast<const char*>(row_data),
                           m_width*sizeof(uchar));
            }
            fout.close();}
        else if (n_channels() == 3 || n_channels() == 4)
        {
            const string magic_head = "P6";
            ofstream fout;
            string extended_name = filename + ".ppm";
            fout.open(extended_name.c_str(), ios::out | ios::binary);
            fout << magic_head << "\n";
            fout << m_width << " " << m_height << " 255\n";
            if (n_channels() == 3)
            {

                for (int y = 0; y < m_height; ++y) {
                    const uchar *row_data = this->data(y);
                    fout.write(reinterpret_cast<const char*>(row_data),
                               m_width*sizeof(uchar)*3);
                }
                fout.close();
            }
            else{
                for (int y = 0; y < m_height; ++y) {
                    const uchar *row_data = this->data(y);
                    uchar *new_row_data = new uchar[m_width * 3];
                    int keeper = 0;
                    for (int x = 0; x < m_step; x++) {
                        if ((x+1) % 4 != 0) {
                            new_row_data[keeper] = row_data[x];
                            keeper++;
                        }
                    }
                    fout.write(reinterpret_cast<const char*>(new_row_data),
                               m_width*sizeof(uchar)*3);

                }

            }

        }
        else{
            cerr << "n_channels are invalid value" << endl;
        }
    }


void Image::read_pnm(const std::string &filename){

    int width = 0 , height = 0 , max_value = 0;
    ifstream  fileRead(filename, ios::binary);
    stringstream sString;
    string line = "";
    getline(fileRead, line);

    sString << fileRead.rdbuf();
    sString >> width >> height >> max_value;

    if (line.compare("P5") == 0){
        Image *img_read = new Image(width,height,1);
        uchar value ;
        for (int y = 0; y < img_read->h(); ++y){
            uchar *new_row = img_read->m_data + y * img_read->m_step;
            for(int x = 0; x < img_read->w(); x++){
                sString >> value;
                new_row[x] = value;
            }
    }
        fileRead.close();

        this->m_n_channels  = img_read->m_n_channels;
        this->m_step        = img_read->m_step;
        this->m_data        = img_read->m_data;
        this->m_height      = img_read->m_height;
        this->m_width       = img_read->m_width;
    }
    else if (line.compare("P6") == 0) {
        Image *img_read = new Image(width, height, 4);
        uchar red_value, green_value, blue_value;
        for (int y = 0; y < img_read->h(); ++y) {
            uchar *new_row = img_read->m_data + y * img_read->m_step;

            for (int x = 0; x < img_read->w() * img_read->m_n_channels; x += img_read->m_n_channels) {
                sString >> red_value >> green_value >> blue_value;
                new_row[x ]     = red_value;
                new_row[x + 1] = green_value;
                new_row[x + 2] = blue_value;
                new_row[x + 3] = max_value;
            }

        }
        fileRead.close();

        this->m_n_channels  = img_read->m_n_channels;
        this->m_step        = img_read->m_step;
        this->m_data        = img_read->m_data;
        this->m_height      = img_read->m_height;
        this->m_width       = img_read->m_width;

    }
    else {
        Image *img_read = new Image(0, 0, 0);
        this->m_n_channels  = img_read->m_n_channels;
        this->m_step        = img_read->m_step;
        this->m_data        = img_read->m_data;
        this->m_height      = img_read->m_height;
        this->m_width       = img_read->m_width;
    }

}


void Image::to_rgb() {

    int ch = 3;
    int width = m_width;
    int height = m_height;
    Image *imgRGB = new Image(width, height, ch);
    imgRGB->set_rect_rgb(0, 0, width, height, 0, 0, 0);

    if (m_n_channels == 1) {
        for (int y = 0; y < imgRGB->h(); ++y) {

            uchar *rowImgGray = m_data + y * m_step;
            uchar *rowImgRGB = imgRGB->m_data + y * imgRGB->m_step;
            for (int x = 0; x < imgRGB->w(); ++x) {

                rowImgRGB[x * ch] = rowImgGray[x];
                rowImgRGB[x * ch + 1] = rowImgGray[x];
                rowImgRGB[x * ch + 2] = rowImgGray[x];
            }
        }
    } else if (m_n_channels == 4) {
        for (int y = 0; y < imgRGB->h(); ++y) {

            uchar *rowImgRGBA = m_data + y * m_step;
            uchar *rowImgRGB = imgRGB->m_data + y * imgRGB->m_step;
            for (int x = 0; x < imgRGB->w(); ++x) {

                rowImgRGB[x * ch]     = rowImgRGBA[x * m_n_channels];
                rowImgRGB[x * ch + 1] = rowImgRGBA[x * m_n_channels + 1];
                rowImgRGB[x * ch + 2] = rowImgRGBA[x * m_n_channels + 2];
            }
        }
    } else if (m_n_channels == 3) {return;}
    this->m_n_channels  = imgRGB->m_n_channels;
    this->m_step        = imgRGB->m_step;
    this->m_data        = imgRGB->m_data;
    this->m_height      = imgRGB->m_height;
    this->m_width       = imgRGB->m_width;
}

void Image::to_rgba() {

        int ch = 4;
        int width = m_width;
        int height = m_height;
        Image *imgRGBA = new Image(width, height, ch);
        imgRGBA->set_rect_rgba(0, 0, width, height, 0, 0, 0);

        if (m_n_channels == 1) {
            for (int y = 0; y < imgRGBA->h(); ++y) {

                uchar *rowImgGray = m_data + y * m_step;
                uchar *rowImgRGBA = imgRGBA->m_data + y * imgRGBA->m_step;
                for (int x = 0; x < imgRGBA->w(); ++x) {

                    rowImgRGBA[x * ch]     = rowImgGray[x];
                    rowImgRGBA[x * ch + 1] = rowImgGray[x];
                    rowImgRGBA[x * ch + 2] = rowImgGray[x];
                    rowImgRGBA[x * ch + 3] = 255;
                }
            }
        } else if (m_n_channels == 3) {
            for (int y = 0; y < imgRGBA->h(); ++y) {

                uchar *rowImgRGB = m_data + y * m_step;
                uchar *rowImgRGBA = imgRGBA->m_data + y * imgRGBA->m_step;
                for (int x = 0; x < imgRGBA->w(); ++x) {

                    rowImgRGBA[x * ch]     = rowImgRGB[x * m_n_channels];
                    rowImgRGBA[x * ch + 1] = rowImgRGB[x * m_n_channels + 1];
                    rowImgRGBA[x * ch + 2] = rowImgRGB[x * m_n_channels + 2];
                    rowImgRGBA[x * ch + 3] = 255;
                }
            }
        }else if (m_n_channels == 4){return;}

    this->m_n_channels  = imgRGBA->m_n_channels;
    this->m_step        = imgRGBA->m_step;
    this->m_data        = imgRGBA->m_data;
    this->m_height      = imgRGBA->m_height;
    this->m_width       = imgRGBA->m_width;
    }


void Image::to_grayscale() {

        int ch = 1;
        int width = m_width;
        int height = m_height;
        Image *imgGray = new Image(width, height, ch);
        imgGray->set_rect(0, 0, width, height, 0);
        unsigned char red_value, green_value, blue_value;

        if (m_n_channels == 3) {
            for (int y = 0; y < imgGray->h(); ++y) {

                uchar *rowImgGray = imgGray->m_data + y * imgGray->m_step;
                uchar *rowImgRGB = m_data + y * m_step;
                for (int x = 0; x < imgGray->w(); ++x) {
                    red_value   = rowImgRGB[x * m_n_channels];
                    green_value = rowImgRGB[x * m_n_channels + 1];
                    blue_value  = rowImgRGB[x * m_n_channels + 2];
                    int gray_value = red_value * 0.3 + green_value * 0.59 + blue_value * 0.11;
                    if (gray_value > 255){
                        gray_value = 255;
                        cerr << "Gray Value Overflow ! Set to max !" << endl;
                    }
                    else if (gray_value < 0 ){
                        gray_value = 0;
                        cerr << "Gray Value Underflow ! Set to min !" << endl;
                    }
                    else {
                        rowImgGray[x] = gray_value;
                    }
                }
            }
        } else if (m_n_channels == 4) {
            for (int y = 0; y < imgGray->h(); ++y) {

                uchar *rowImgRGBA = m_data + y * m_step;
                uchar *rowImgGray = imgGray->m_data + y * imgGray->m_step;
                for (int x = 0; x < imgGray->w(); ++x) {
                    red_value   = rowImgRGBA[x * m_n_channels];
                    green_value = rowImgRGBA[x * m_n_channels + 1];
                    blue_value  = rowImgRGBA[x * m_n_channels + 2];
                    int gray_value = red_value * 0.3 + green_value * 0.59 + blue_value * 0.11;
                    rowImgGray[x] = gray_value;
                }
            }
        }else if (m_n_channels == 1){return;}

        this->m_n_channels  = imgGray->m_n_channels;
        this->m_step        = imgGray->m_step;
        this->m_data        = imgGray->m_data;
        this->m_height      = imgGray->m_height;
        this->m_width       = imgGray->m_width;
    }

}