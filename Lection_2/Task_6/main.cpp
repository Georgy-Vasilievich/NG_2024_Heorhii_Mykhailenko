#include <iostream>

int main()
{
    int cards[10];

    for (unsigned int card = 0; card < 10; ++card)
        cards[card] = 0;

    while (true) {
        unsigned int cardNumber;
        unsigned int money;
        for (unsigned int card = 0; card < 10; ++card)
            std::cout << cards[card] << " ";
        std::cout << std::endl;

        std::cout << "Card: ";
        std::cin >> cardNumber;
        std::cout << "Money: ";
        std::cin >> money;

        cards[cardNumber - 1] += money;
    }

    return 0;
}
