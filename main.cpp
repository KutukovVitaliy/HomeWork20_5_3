#include <iostream>
#include <fstream>
#include <string>

int main() {
    bool endTheGame = false;
    std::string fishName, continueGame, tmpString;
    std::ifstream riverFile;
    std::ofstream basketFile;
    do{
        std::cout << "Enter the fish: ";
        std::cin >> fishName;
        riverFile.open("../river.txt");
        if(!riverFile.is_open()){
            std::cout << "Can't open file river.txt" << std::endl;
            return -1;
        }
        while(!riverFile.eof()){
            std::getline(riverFile, tmpString);
            if(tmpString == fishName){
                std::cout << " You have caught a fish! " << std::endl;
                basketFile.open("../basket.txt", std::ios::app);
                if(!basketFile.is_open()){
                    std::cout << "Can't open file basket.txt!" << std::endl;
                    return -1;
                }
                basketFile << fishName << std::endl;
                basketFile.close();
            }
        }
        riverFile.close();
        std::cout << "Continue the game? (Yes/No): ";
        std::cin >> continueGame;
        if(continueGame == "Yes") endTheGame = false;
        else endTheGame = true;
    }while(!endTheGame);
    std::cout << "Your basket: " << std::endl;
    std::ifstream fileToPrint("../basket.txt");
    if(!fileToPrint.is_open()){
        std::cout << "Can't open file basket.txt!" << std::endl;
        return -1;
    }
    while (!fileToPrint.eof()){
        std::getline(fileToPrint, tmpString);
        std::cout << tmpString << std::endl;
    }
    fileToPrint.close();
    return 0;
}
