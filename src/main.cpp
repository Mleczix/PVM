#include "stdafx.h"
#include "SDLWindow.h"

int MIN, MAX;

int main(int argc, char *argv[])
{
    if(argc == 3) {
        MIN = stoi(argv[1]);
        MAX = stoi(argv[2]);
        printf("MIN: %d, MAX: %d\n", MIN, MAX);
    }

    try
    {
        SX::SDLWindow::SDLWindow mainWindow("PVM");
        mainWindow.start(MIN, MAX);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch( ... )
    {
        std::cout << "Unknow error!!\n";
    }

    SDL_Quit();
    pvm_exit();
    return 0;
}