//
// Created by kurch on 22.04.2026.
//
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

class Product{
private:
    std::string nameProd = "Unnamed";
    int countProd = 0;

public:
    Product() {}
    Product(std::string name, int count) {
        if (!(name == "" || name == " ")) {
            nameProd = name;
        }

        if (count <= 0) {
            throw std::invalid_argument("\nCount for add dont be lower at 0");
        }

        if (count > 10) {
            throw std::invalid_argument("\nCount for add dont be more 10 in one hand");
        }

        countProd = count;
    }

    void addCount (int count) {
        if (countProd + count > 100) {
            throw std::overflow_error ("\nNo more 100 items in cart");
        }
        countProd+=count;
    }
    void delCount (int count) {
        if (countProd - count < 0) {
            throw std::invalid_argument ("\nThe count of deleted items must not be greater than the number in the cart.");

            //дописать конструкцию в мейн
        }
    }

    std::string getNameProd () const { return nameProd; }
    int getCountProd () const { return countProd; }
};

void commandList () {
    std::cout << "\nEnter next command for:"
                 "\n~Show - for show car items;"
                 "\n~Add - for add item in cart;"
                 "\n~Del - for del item." << std::endl;
}
void showAllItemsInCart (const std::map<std::string, Product>& cart) {
    if (cart.empty()) {
        std::invalid_argument ("\nCart is empty");
    } else {
        int i = 1;
        for (const auto& item : cart) {
            std::cout << "#" << i << " Articles: " << item.first <<
                         "\nName product: " << item.second.getNameProd() <<
                         "\nCount pruduct: " << item.second.getCountProd() << std::endl;
        }
    }

}

int main () {
    std::map<std::string, Product> cart;
    std::string nameProduct,
        command = "list",
        article = "";

    int countForAdd = 0,
        countForDel = 0;


    do {

        if (command == "list") {
            commandList();
        }

        std::cout << "\nEnter command: "; std::cin >> command;

        if (command == "Add") {

            std::cout << "Enter Article product:"; std::cin >> article;
            std::cout << "Enter Name product:"; std::cin >> nameProduct;
            std::cout << "Enter count product for add in cart:"; std::cin >> countForAdd;

            try {
                auto item = cart.find(article);
                if (item != cart.end()) {
                    item->second.addCount(countForAdd);
                } else {
                    Product ItemProd(nameProduct, countForAdd);
                    cart[article] = ItemProd;
                }

            } catch (const std::invalid_argument &error){
                std::cout << "\nError: " << error.what() << std::endl;
                std::cout << "Try again." << std::endl;
            } catch (const std::overflow_error &error) {
                std::cout << "\nError: " << error.what() << std::endl;
                std::cout << "Try again." << std::endl;
            }
        } else if (command == "Del") {
            std::cout << "\nEnter article for del count"; std::cin >> article;

            auto item = cart.find(article);
            if (item != cart.end()) {
                std::cout << "\nEnter count product be deleted:"; std::cin >> countForDel;

            } else {
                std::cout << "\nProduct with article " << article << " is not in the basket" << std::endl;
            }



        } else if (command == "Show") {
            try {
                showAllItemsInCart(cart);
            } catch (std::invalid_argument &error) {
                std::cout << "\nError: " << error.what() << std::endl;
                std::cout << "Try again." << std::endl;
            }
        } else if (command != "exit") {
            std::cout << "\nInvalid command" << std::endl;
        }
    } while (command != "exit");






    return 0;
}