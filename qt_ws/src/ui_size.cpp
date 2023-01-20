#include "ui_size.h"

namespace UI
{
UI::UISize setUISize(int width, 
                     int height, 
                     int margin_top, 
                     int margin_bottom, 
                     int margin_left, 
                     int margin_right)
{
    UI::UISize ui_size{
        width,
        height,
        margin_top,
        margin_bottom,
        margin_left,
        margin_right
    };

    return ui_size;
}
}