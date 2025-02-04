#include <iostream>
#include <cstdlib>

void packageProject(const std::string& uprojectPath, const std::string& outputPath) {
    //std::string uatPath = "D:/Epic/UnrealEngine/Engine/Build/BatchFiles/RunUAT.bat";
    std::string uatPath = "./Engine/Build/BatchFiles/RunUAT.bat";

    std::string command = "call " + uatPath + 
        " -ScriptsForProject=" + uprojectPath +
        " BuildCookRun -project=" + uprojectPath +
        " -noP4 -clientconfig=Development -serverconfig=Development -nocompileeditor" +
        " -unrealexe=D:/Epic/UnrealEngine/Engine/Binaries/Win64/UnrealEditor-Cmd.exe -utf8output" +
        " -platform=Win64 -build -cook -map=ThirdPersonMap+ThirdPersonMap -CookCultures=en -unversionedcookedcontent -stage -package" +
        " -cmdline=\" -Messaging\" -addcmdline=\"-SessionId=537725F84F11907CB15DC6BF977AB053 -SessionOwner='Rock' -SessionName='ProfileTest'\"" + " -stagingdirectory=" + outputPath;


    std::cout << command;
    
    int result = std::system(command.c_str());
    
    if (result != 0) {
        std::cerr << "Error: Packaging failed." << std::endl;
    } else {
        std::cout << "Packaging successful. Output in: " << outputPath << std::endl;
    }
}