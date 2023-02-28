#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(){
    std::ifstream input_file("input.txt");
    if(!input_file.is_open()) return 1;
    
    // get number of inputs
    std::string line;
    std::getline(input_file, line, '\n');
    int input_count = std::stoi(line);

    std::vector<std::string> inputs;
    inputs.reserve(input_count);

    // get the wood string if the length matches
    for(int i = 0; i < input_count; ++i){
        if(std::getline(input_file, line, '\n')){
            int wood_length = std::stoi(line);
            std::getline(input_file, line, '\n');
            std::string wood = line;
            if(line.length() != wood_length) return 1;
            inputs.emplace_back(wood);
        }
    }

    for(auto wo : inputs){
        std::cout << wo << "\n";
    }
}