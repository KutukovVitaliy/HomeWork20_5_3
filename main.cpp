#include <iostream>
#include <fstream>
#include <string>

int main() {
    bool EndTheGame = false;
    std::string FishName, ContinueGame, TmpString;
    std::ifstream RiverFile;
    std::ofstream BasketFile;
    do{
        std::cout << "Enter the fish: ";
        std::cin >> FishName;
        RiverFile.open("../river.txt");
        while(!RiverFile.eof()){
            RiverFile >> TmpString;
            if(TmpString == FishName){
                std::cout << " You have caught a fish! " << std::endl;
                BasketFile.open("../basket.txt",std::ios::app);
                BasketFile << FishName << std::endl;
                BasketFile.close();
            }
        }
        RiverFile.close();
        std::cout << "Continue the game? (Yes/No): ";
        std::cin >> ContinueGame;
        if(ContinueGame == "Yes") EndTheGame = false;
        else EndTheGame = true;
    }while(!EndTheGame);
    std::cout << "Your basket: " << std::endl;
    std::ifstream FileToPrint("../basket.txt");
    while (!FileToPrint.eof()){
        FileToPrint >> TmpString;
        std::cout << TmpString << std::endl;
    }
    FileToPrint.close();
    return 0;
}
