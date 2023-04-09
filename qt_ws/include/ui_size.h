#ifndef __UI_SIZE_H__
#define __UI_SIZE_H__

namespace UI
{
struct UISize
{
    int width;
    int height;
    int margin_top;
    int margin_bottom;
    int margin_left;
    int margin_right;
    int x;
    int y;
};

UISize setUISize(int width, 
                 int height, 
                 int margin_top, 
                 int margin_bottom, 
                 int margin_left, 
                 int margin_right);
} // namespace UI

#endif // __UI_SIZE_H__