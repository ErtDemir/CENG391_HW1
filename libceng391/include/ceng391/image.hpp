// @author Name: Ertuğrul Demir - ID: 260201059
#include <string>

namespace ceng391 {
typedef unsigned char uchar;

class Image
{
public:
        Image(int width, int height,int n_channels , int step=-1);
        ~Image();

        int w() const { return m_width; }
        int h() const { return m_height; }
        int step() const { return m_step; }
        int n_channels() const {return m_n_channels;}
        const uchar *data() const { return m_data; }
        uchar *      data()       { return m_data; }
        const uchar *data(int y) const { return m_data + y*m_step; }
        uchar *      data(int y)       { return m_data + y*m_step; }
        std::string type();

        void set(uchar value) { set_rect(0, 0, m_width, m_height, value); }
        void set_rect(int x_tl, int y_tl, int width, int height, uchar value);

        void set_rgb(uchar red ,uchar green ,uchar blue) { set_rect_rgb(0 , 0 ,m_width , m_height , red, green, blue);}
        void set_rect_rgb(int x_tl, int y_tl, int width, int height, uchar red_value, uchar green_value, uchar blue_value);

        void set_rgba(uchar red ,uchar green ,uchar blue) { set_rect_rgb(0 , 0 ,m_width , m_height , red, green, blue);}
        void set_rect_rgba(int x_tl, int y_tl, int width, int height, uchar red_value, uchar green_value, uchar blue_value);

        void write_pnm(const std::string& filename) const;
        void read_pnm(const std::string &filename);

        void to_rgb();
        void to_rgba();
        void to_grayscale();
private:
    int m_width;
    int m_height;
    int m_n_channels;
    int m_step;
    uchar *m_data;
};

}
