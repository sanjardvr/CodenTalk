#include "Core/Core.h"
#include "../Client/client.h"
#include "../Admin/admin.h"
#include <iostream>
using namespace std;

int main()
{
    CodenTalk app;
    app.registerModule(new Client());
    app.registerModule(new Admin());
    app.run();
    return 0;
    // end of main
}