#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H

#include<iostream>


class LoaderParams {
    private:
        int _x;
        int _y;
        int _width;
        int _height;
        std::string _texture_id;

    public:
        LoaderParams(int x, int y, int width, int height,
                     std::string texture_id): _x(x), _y(y), _width(width),
                     _height(height), _texture_id(texture_id) {}

        int get_x() const {return _x;}
        int get_y() const {return _y;}
        int get_width() const {return _width;}
        int get_height() const {return _height;}
        std::string get_texture_id() const {return _texture_id;}
};

#endif
