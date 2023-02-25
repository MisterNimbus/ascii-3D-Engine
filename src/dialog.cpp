#include "./include/dialog.h"

const std::string title = horizontalSpace(50) + "                          _ _       ___________        _____            _            \n" + horizontalSpace(50) + "                         (_|_)     |____ |  _  \\      |  ___|          (_)           \n" + horizontalSpace(50) + "            __ _ ___  ___ _ _ ______   / / | | |______| |__ _ __   __ _ _ _ __   ___ \n" + horizontalSpace(50) + "           / _` / __|/ __| | |______|  \\ \\ | | |______|  __| '_ \\ / _` | | '_ \\ / _ \\\n" + horizontalSpace(50) + "          | (_| \\__ \\ (__| | |     .___/ / |/ /       | |__| | | | (_| | | | | |  __/\n" + horizontalSpace(50) + "           \\__,_|___/\\___|_|_|     \\____/|___/        \\____/_| |_|\\__, |_|_| |_|\\___|\n" + horizontalSpace(50) + "                                                                   __/ |             \n" + horizontalSpace(50) + "                                                                  |___/              \n";
std::string link = horizontalSpace(73)+"https://github.com/MisterNimbus/ascii-3D-Engine\n";
std::string warning = horizontalSpace(55) +"Please make sure your terminal is 190 by 35. There should be a \"+\" on all corners.";
std::string menu = horizontalSpace(85) + "(1) Rotating Cube\n" + horizontalSpace(85) + "(2) Rotating Tetrahedron\n" + horizontalSpace(85) + "(3) Rotating Triangle\n";
std::string cornerMarkers = "+" + horizontalSpace(188) + "+";
//Terminal Size 190*35
std::string creditASCII = horizontalSpace(70) +"  _           __  __        _  _ _       _            \n" + horizontalSpace(70) + " | |__ _  _  |  \\/  |_ _   | \\| (_)_ __ | |__ _  _ ___\n" + horizontalSpace(70) + " | '_ \\ || | | |\\/| | '_|  | .` | | '  \\| '_ \\ || (_-<\n" + horizontalSpace(70) + " |_.__/\\_, | |_|  |_|_|(_) |_|\\_|_|_|_|_|_.__/\\_,_/__/\n" + horizontalSpace(70) + "       |__/                                           \n";
std::string choice = horizontalSpace(75) + "Please type your choice and press Enter...\n";

int OpeningDialog(){
char input = '0';
while(input != '1' && input != '2' && input != '3' ){
std::cout << "\x1b[2J"; // ANSI clearScreen
std::cout << cornerMarkers;
std::cout << verticalSpace(2);
std::cout << title ;
std::cout << verticalSpace(1);
std::cout << creditASCII;
std::cout << verticalSpace(2);
std::cout << link;
std::cout << verticalSpace(2);
std::cout << warning;
std::cout << verticalSpace(4);
std::cout << menu;
std::cout << verticalSpace(2);
std::cout << choice;
std::cout << verticalSpace(3);
std::cout << cornerMarkers;
std::cin >> input;
}
return ((int)input - 48);
}

std::string verticalSpace(int space){
    std::string output = "";
    for (int i = 0; i < space; i++)
    {
        output += "\n";
    }
    return output;
}

std::string horizontalSpace(int space){
    std::string output = "";
    for (int i = 0; i < space; i++)
    {
        output += " ";
    }
    return output;
}