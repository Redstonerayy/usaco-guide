#include <iostream>
#include <cmath>
#include <vector>

int divisor_count(int num){
    int count = 2;

    for(int i = 2; i <= int(num / 2); ++i){
        if(num % i == 0){
            count++;
        }
    }
    
    return count;
}

std::vector<int> prime_factorisation(int num){
	std::vector<int> ret;
	for (int i = 2; i * i <= num; i++) {
		while (num % i == 0) {
			ret.push_back(i);
			num /= i;
		}
	}
	if (num > 1) ret.push_back(num);
	return ret;
}

int main(){
    for(int i = 0; i < std::pow(10, 2); ++i){
        std::cout << "Number:" << i << "\n";
        std::cout << divisor_count(i) << "\n";
        std::vector<int> factors = prime_factorisation(i);
        for(auto factor : factors){
            std::cout << factor << " ";
        }
        std::cout << "\n";
    }
}
