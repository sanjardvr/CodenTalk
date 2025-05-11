#include "../../Core/Source/Core/Core.h"

#include "../Client/client.h"
#include "../Admin/admin.h"

//!temp
#include "../../Core/Utils/utils.h"

#include <iostream>
using namespace std;

int main()
{   
    Registration reg("Core/Source/Files/clients.txt");
    reg.signup();
    // CodenTalk app;
    // app.registerModule(new Client());
    // app.registerModule(new Admin());
    // app.run();


    return 0;
    // end of main
}