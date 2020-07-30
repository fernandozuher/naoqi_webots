#include "Image.hpp"

Image::Image(int width, int height, const unsigned char *data) :
    m_width {width}, m_height {height},    
    m_data {const_cast<unsigned char*>(data)},
    m_free_data {false}
{}

// RGB image data in bytes as an array of [width][height][3]
unsigned char* Image::data() const
{
    return m_data;
}

// Convert the image from BGRA to RGB and perform a basic 'pixel' enlarging resample.
// Note: it takes about 1ms to convert a 160x120 image in my environment
void Image::convert(int new_width, int new_height)
{
    // create new buffer to interpolate into
    unsigned char *new_data {new unsigned char [new_width * new_height * 3]};

    double scale_height {static_cast<double>(new_height) / static_cast<double>(m_height)};
    
    double one_over_scale_height {1.0 / scale_height};
    int three_new_width {3 * new_width};
    int four_width {4 * m_width};

    for (int cy {0}; cy < new_height; cy++) {

        int line_index {cy * three_new_width};
        int nearest_line {static_cast<int>((cy * one_over_scale_height) * four_width)};

        for (int cx {0}; cx < new_width; cx++) {

            int pixel_index {line_index + 3 * cx};
            int nearestMatch {nearest_line + 
                        static_cast<int>(cx * one_over_scale_height) * 4};

            for (int i {2}, j {0}; i >=0; i--, j++)
                new_data[pixel_index + j] = m_data[nearestMatch + i];
        }
    }

    if (m_free_data)
        delete [] m_data;

    m_data = new_data;
    m_free_data = true;
    m_width = new_width;
    m_height = new_height;
}

Image::~Image()
{
    if (m_free_data)
        delete [] m_data;
}