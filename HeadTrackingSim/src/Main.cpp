#include "App.h"

int main()
{
    const auto app = App::create();
    app->loop();
    app->terminate();
    return 0;
}
