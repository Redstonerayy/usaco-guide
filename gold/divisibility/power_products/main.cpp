#include <bits/stdc++.h>

int main(){
    // open file
    std::ifstream input_file("input.txt");
    if(!input_file.is_open()) return 1;
    
    // get number of integers and k
    std::string line;
    std::getline(input_file, line, '\n');

    std::stringstream ss(line);
    std::string number;

    std::getline(ss, number,' ');
    int integer_count = std::stoi(number);
    std::getline(ss, number,' ');
    int k = std::stoi(number);

    // parse integers
    std::vector<int> inputs;
    inputs.reserve(integer_count);

    std::getline(input_file, line, '\n');
    std::stringstream ints(line);

    for(int i = 0; i < integer_count; ++i){
        std::getline(ints, number, ' ');
        inputs.emplace_back(std::stoi(number));
    }

    int pairs = 0;
    // calculate for all numbers
    for(int i = 0; i < inputs.size(); ++i){
        for(int j = i + 1; j < inputs.size(); ++j){
            int multiple = inputs.at(i) * inputs.at(j);
            int x = 0;
            while(multiple > std::pow(x, k)){
                x++;
                if(multiple == std::pow(x, k)){
                    // std::cout << i + 1 << ":" << j + 1 << ":" << x << "\n";
                    pairs++;
                }
            }
        }
    }

    std::cout << pairs << "\n";
}