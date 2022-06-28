#include <spdlog/spdlog.h>
#include "RenderHelp/RenderHelp.h"

int main(){
    spdlog::set_level(spdlog::level::debug);
    SPDLOG_DEBUG("begin");
    Bitmap img(200, 100);
    img.DrawLine(0, 0, 100, 50, 1);
    img.SaveFile("test2.bmp", true);
    SPDLOG_DEBUG("done");
    return 0;
}