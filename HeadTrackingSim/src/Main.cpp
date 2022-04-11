#include "App.h"

int main()
{
    const auto app = App::create();
    app->loop();
    App::terminate();
    return 0;
}
