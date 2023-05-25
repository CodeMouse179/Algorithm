#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <filesystem>

std::vector<std::string> get_directories(const std::string& path)
{
    std::vector<std::string> paths;
    for (const auto& item : std::filesystem::directory_iterator(path))
    {
        if (item.is_directory())
            paths.push_back(item.path().string());
    }
    return paths;
}

std::vector<std::string> get_project_names(const std::vector<std::string>& paths)
{
    std::vector<std::string> projects;
    for (const auto& item : paths)
    {
        std::string name = item.substr(item.find("/") + 1);
        if (
            name == ".git" ||
            name == "CMakeFiles" ||
            name == ".vs" ||
            name == "a.dir" ||
            name == "x64" ||
            name == "Debug" ||
            name == "Release" ||
            name == "MinSizeRel" ||
            name == "RelWithDebInfo"
        ) continue;
        projects.push_back(name);
    }
    return projects;
}

std::string input_project_name()
{
    std::cout << "input project name: ";
    std::string project_name;
    std::getline(std::cin, project_name);
    return project_name;
}

bool create_project(std::string project_name)
{
    bool success = std::filesystem::create_directory(project_name);
    if (!success) return false;
    std::ofstream cmake_file;
    std::ofstream main_file;
    cmake_file.open(project_name + "/CMakeLists.txt");
    if (!cmake_file.is_open()) return false;
    main_file.open(project_name + "/main.cpp");
    if (!main_file.is_open()) return false;
    cmake_file << "cmake_minimum_required(VERSION 3.26)\n\n";
    cmake_file << "project(" << project_name << "_project)\n\n";
    cmake_file << "add_executable(a main.cpp)";
    main_file << "int main()\n";
    main_file << "{\n";
    main_file << "    return 0;\n";
    main_file << "}\n";
    cmake_file.close();
    main_file.close();
    return success;
}

int main()
{
    auto paths = get_directories("./");
    auto projects = get_project_names(paths);
    int index = 1;
    for (const auto& item : projects)
    {
        std::cout << index << "." << item << "\n";
        index++;
    }
    while (true)
    {
        std::string project_name = input_project_name();
        if (project_name.empty())
        {
            std::cout << "empty project name!\n";
            continue;
        }
        if (project_name.find(".") != -1)
        {
            std::cout << "project name contains '.'!\n";
            continue;
        }
        if (std::count(projects.begin(), projects.end(), project_name))
        {
            std::cout << "duplicated project name!\n";
            continue;
        }
        bool success = create_project(project_name);
        if (!success)
        {
            std::cout << "create project failed!\n";
            continue;
        }
        std::cout << project_name << " created.\n";
        break;
    }
    return 0;
}