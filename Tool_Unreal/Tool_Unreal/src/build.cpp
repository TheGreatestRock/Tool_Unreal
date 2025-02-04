#include <iostream>
#include <sstream>
#include <vector>

void buildProject(const std::string& uprojectPath, const std::string& otherArgs) {
    //std::string ubtPath = "D:/Epic/UnrealEngine/Engine/Build/BatchFiles/Build.bat";
    std::string ubtPath = "./Engine/Build/BatchFiles/Build.bat";
    
    std::istringstream iss(otherArgs);
    std::vector<std::string> args;
    std::string arg;

    while (iss >> arg) {
        args.push_back(arg);
    }

    std::string command;
    
    if (args.size() < 3) {
        std::string projectName = uprojectPath.substr(uprojectPath.find_last_of("/\\") + 1);
        projectName = projectName.substr(0, projectName.find_last_of("."));
        command = "call " + ubtPath + " " + projectName + "Editor Win64 Development -Project=\"" + uprojectPath + "\" -waitmutex";
    }
    else
    {
        std::string projectName = args[0]; 
        std::string targetName = args[1];
        std::string platform = args[2];
        std::string configuration = args[3];

        command = "call " + ubtPath + " " + projectName + targetName + " " + platform + " " + configuration +
                              " -Project=\"" + uprojectPath + "\"";

        for (size_t i = 3; i < args.size(); ++i) {
            command += " " + args[i];
        } 
    }



    std::cout << "Executing: " << command << std::endl;
    int result = std::system(command.c_str());

    if (result != 0) {
        std::cerr << "Error: Build failed." << std::endl;
    } else {
        std::cout << "Build successful." << std::endl;
    }
}
