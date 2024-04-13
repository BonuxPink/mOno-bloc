#include <fmt/format.h>

#include <ncpp/NotCurses.hh>

int main()
{
    std::setlocale (LC_ALL, "");
    notcurses_options opts { .termtype = nullptr,
                             .loglevel = ncpp::NCLogLevel::Silent,
                             .margin_t = 0, .margin_r = 0,
                             .margin_b = 0, .margin_l = 0,
                             .flags = NCOPTION_SUPPRESS_BANNERS,
    };

    ncpp::NotCurses nc{ opts };

    unsigned dimy = 0;
    unsigned dimx = 0;

    auto plane = nc.get_stdplane();

    plane->get_dim(dimy, dimx);
    plane->cursor_move(0, 0);
    plane->printf("Hello, %d %d", dimy, dimx);

    nc.render();

    ncinput ni;
    notcurses_get_blocking(plane->get_notcurses(), &ni);
}
