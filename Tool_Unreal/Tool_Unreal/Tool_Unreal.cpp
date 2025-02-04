#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "src/commands/build.h"
#include "src/commands/help.h"
#include "src/commands/package.h"
#include "src/commands/show_info.h"
 
int main(int argc, char* argv[]) {
    if (argc == 2 && std::string(argv[1]) == "help") { 
        showHelp(); 
        return 0; 
    } 
    
    if (argc < 3) { 
        std::cerr << "Usage: Tool_Unreal [UPROJECT_PATH] [COMMAND] [ARGS]\n";
        std::cerr << "Use 'Tool_Unreal help' for more details.\n";
        return 1;
    } 

    std::string uprojectPath = argv[1];
    std::string command = argv[2];

    std::ostringstream oss;
    for (int i = 3; i < argc; ++i) {
        oss << argv[i];
        if (i < argc - 1) oss << " ";
    }
    std::string otherArgs = oss.str();

    std::cout << "Project Path: " << uprojectPath << std::endl;
    std::cout << "Command: " << command << std::endl;
    std::cout << "Other Args: " << otherArgs << std::endl;
 
    if (command == "show-infos") {
        showInfo(uprojectPath);
    } 
    else if (command == "build") {
        buildProject(uprojectPath, otherArgs);
    } 
    else if (command == "package") {
        if (argc < 4) {
            std::cerr << "Error: Package command requires an output path." << std::endl;
            return 1; 
        }
        packageProject(uprojectPath, argv[3]);
    } 
    else {
        std::cerr << "Unknown command: " << command << std::endl;
        return 1; 
    }
    
    return 0;   
}
