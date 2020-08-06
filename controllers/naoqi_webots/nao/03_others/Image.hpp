// Description: Class for storing and resampling pixmap images

#ifndef IMAGE_HPP
#define IMAGE_HPP

class Image
{
    private:
        int m_width, m_height;
        unsigned char *m_data;
        bool m_free_data;

    public:
        // data is a pointer to a BGRA image buffer
        Image(int width, int height, const unsigned char *data);
        virtual ~Image();

        // RGB image data in bytes as an array of [width][height][3]
        unsigned char *data() const;

        // Change image format from BGRA to RGB and dimensions to the ones
        // specified
        void convert(int new_width, int new_height);
};

#endif
