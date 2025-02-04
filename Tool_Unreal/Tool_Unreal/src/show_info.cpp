#include <iostream>
#include <fstream>
#include "../include/nlohmann/json.hpp"
#include "commands/show_info.h"
#include <string>

std::string getFileNameWithoutExtension(const std::string& path) {
    size_t lastSlash = path.find_last_of("/\\");
    size_t lastDot = path.find_last_of(".");
    if (lastDot != std::string::npos && lastDot > lastSlash) {
        return path.substr(lastSlash + 1, lastDot - lastSlash - 1);
    }
    return path.substr(lastSlash + 1);
}

void showInfo(const std::string& uprojectPath) {
    std::string projectName = getFileNameWithoutExtension(uprojectPath);
    std::cout << "Project Name: " << projectName << std::endl;

    std::ifstream file(uprojectPath);
    if (!file) {
        std::cerr << "Error: Could not open file " << uprojectPath << std::endl;
        return;
    }

    nlohmann::json jsonFile;
    try {
        file >> jsonFile;
    } catch (const nlohmann::json::parse_error& e) {
        std::cerr << "Error: Failed to parse JSON: " << e.what() << std::endl;
        return;
    }

    std::string engineAssociation = jsonFile.value("EngineAssociation", "");
    if (engineAssociation.empty()) {
        std::cout << "Unreal Engine Version: " << jsonFile["EngineVersion"] << std::endl;
    } else {
        std::cout << "Unreal Engine Version: Unknown" << std::endl;
    }

    if (!engineAssociation.empty() && engineAssociation[0] == '{') {
        std::cout << "Built From Source: Yes" << std::endl;
    } else {
        std::cout << "Built From Source: No" << std::endl;
    }
    
    if (jsonFile.contains("Plugins")) {
        std::cout << "Plugins:" << std::endl;
        for (const auto& plugin : jsonFile["Plugins"]) {
            std::cout << " - " << plugin["Name"] << std::endl;
        }
    }
}
