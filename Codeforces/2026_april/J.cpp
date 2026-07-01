#include <iostream>
int main() {
    std::string joe; getline(std::cin,joe);
    if (joe=="Are you a verified human?") {
        std::cout << "Yes, I can attest to my status as a thoroughly validated, carbon-based biological entity.\n";
    }
    else {
        std::cout << "Joe\n";
    }
}