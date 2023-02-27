#include <iostream>
#include <cmath>
#include <vector>

int divisorCount(int num){
    int count = 2;

    for(int i = 2; i <= int(num / 2); ++i){
        if(num % i == 0){
            count++;
        }
    }
    
    return count;
}

int primeFactorisation(int num){
	std::vector<int> ret;
	for (int i = 2; i * i <= num; i++) {
		while (num % i == 0) {
			ret.push_back(i);
			num /= i;
		}
	}
	if (num > 1) ret.push_back(num);
	return ret.size();
}


int main(){
    for(int i = 0; i < std::pow(10, 8); ++i){
        divisorCount(i);
    }
}
