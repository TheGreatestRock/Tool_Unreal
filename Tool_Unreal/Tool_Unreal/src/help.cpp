#include <iostream>
#include "commands/help.h"

void showHelp() {
    std::cout << "Usage: MyTool [UPROJECT_PATH] [COMMAND] [OPTIONS]\n";
    std::cout << "\nAvailable Commands:\n";
    std::cout << "  show-infos   - Displays information about the Unreal project (name, version, plugins)\n";
    std::cout << "  build        - Builds the Unreal project using UBT\n";
    std::cout << "  package      - Packages the Unreal project using UAT\n";
    std::cout << "\nOptions:\n";
    std::cout << "  For 'package':\n";
    std::cout << "    MyTool [UPROJECT_PATH] package [OUTPUT_PATH]\n";
    std::cout << "    OUTPUT_PATH - The directory where the packaged build will be stored\n";
    std::cout << "\nExample Usage:\n";
    std::cout << "  MyTool MyGame.uproject show-infos\n";
    std::cout << "  MyTool MyGame.uproject build\n";
    std::cout << "  MyTool MyGame.uproject package ./PackagedBuild\n";
    std::cout << "\n";
}