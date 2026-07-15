#include <bits/stdc++.h>

class Product {
private:
    std::string name;
    std::string category;
    std::string brand;
    double price;
    int quantity;
    std::string description;

public:
    virtual ~Product() = default;
    Product(
        const std::string &name,
        const std::string &category,
        const std::string &brand,
        double price,
        int quantity,
        const std::string &description)
    {
        setName(name);
        setCategory(category);
        setBrand(brand);
        setPrice(price);
        setQuantity(quantity);
        setDescription(description);
    }
    Product &setName(const std::string &name) {
        if (name.empty()) {
            throw std::invalid_argument("Product name cannot be empty.");
        }
        this->name = name;
        return *this;
    }
    const std::string& getName() const {
        return this->name;
    }

    Product &setCategory(const std::string &category) {
        if (category.empty()) {
            throw std::invalid_argument("Category cannot be empty.");
        }
        this->category = category;
        return *this;
    }
    const std::string& getCategory() const {
        return this->category;
    }

    Product &setBrand(const std::string &brand) {
        if (brand.empty()) {
            throw std::invalid_argument("Brand cannot be empty.");
        }
        this->brand = brand;
        return *this;
    }
    const std::string& getBrand() const {
        return this->brand;
    }

    Product &setPrice(double price) {
        if (price <= 0) {
            throw std::invalid_argument("Price must be greater than zero.");
        }
        this->price = price;
        return *this;
    }
    double getPrice() const {
        return this->price;
    }

    Product &setQuantity(int quantity) {
        if (quantity < 0) {
            throw std::invalid_argument("Quantity cannot be negative.");
        }
        this->quantity = quantity;
        return *this;
    }
    int getQuantity() const {
        return this->quantity;
    }

    Product &setDescription(const std::string &description) {
        if (description.empty()) {
            throw std::invalid_argument("Description cannot be empty.");
        }
        this->description = description;
        return *this;
    }
    const std::string& getDescription() const {
        return this->description;
    }

    Product& ApplyDiscount(double percentage) {
        if (percentage < 0 || percentage > 100) {
            throw std::invalid_argument("Discount must be between 0 and 100.");
        }
        price -= (price * percentage) / 100;
        return *this;
    }

    Product& IncreasePrice(double percentage) {
        if (percentage < 0 || percentage > 100) {
            throw std::invalid_argument("Percentage must be between 0 and 100.");
        }
        price += (price * percentage) / 100;
        return *this;
    }

    Product &Restock(int amount) {
        if(amount <= 0) {
            throw std::invalid_argument("Restock amount must be greater than zero.");
        }
        this->quantity += amount;
        return *this;
    }

    Product &Sell(int amount) {
        if (amount > this->quantity) {
            throw std::invalid_argument("Not enough quantity in stock.");
        }
        this->quantity -= amount;
        return *this;
    }
    virtual void Print() const {
        std::cout << "\nName       : " << getName();
        std::cout << "\nCategory   : " << getCategory();
        std::cout << "\nBrand      : " << getBrand();
        std::cout << "\nPrice      : " << getPrice();
        std::cout << "\nQuantity   : " << getQuantity();
        std::cout << "\nDescription: " << getDescription();
    }
};

class Laptop : public Product {
private:
    std::string CPU;
    int RAM;
    int Storage;

public:
    Laptop(const std::string &name,
           const std::string &category,
           const std::string &brand,
           double price,
           int quantity,
           const std::string &description,
           const std::string &CPU,
           int RAM,
           int Storage)
        : Product(name, category, brand, price, quantity, description)
    {
        setCPU(CPU);
        setRAM(RAM);
        setStorage(Storage);
    }

    Laptop &setCPU(const std::string &CPU) {
        if (CPU.empty()) {
            throw std::invalid_argument("CPU cannot be empty.");
        }
        this->CPU = CPU;
        return *this;
    }
    const std::string& getCPU() const {
        return CPU;
    }

    Laptop &setRAM(int RAM) {
        if (!std::set<int>{4, 8, 16, 32, 48, 64, 96, 128}.count(RAM)) {
            throw std::invalid_argument("Invalid RAM size.");
        }
        this->RAM = RAM;
        return *this;
    }
    const int getRAM() const {
        return RAM;
    }

    Laptop &setStorage(int Storage) {
        if (!std::set<int>{128, 256, 512, 1024, 2048, 4096, 8192}.count(Storage)) {
            throw std::invalid_argument("Invalid storage size.");
        }
        this->Storage = Storage;
        return *this;
    }
    const int getStorage() const {
        return Storage;
    }

    bool IsGamingLaptop() const {
        return (RAM >= 16 && Storage >= 512);
    }
    Laptop& UpgradeStorage(int storage) {
        setStorage(storage);
        return *this;
    }
    void Print() const override {
        Product::Print();
        std::cout << "\nCPU        : " << getCPU();
        std::cout << "\nRAM        : " << getRAM();
        std::cout << "\nStorage    : " << getStorage();
    }
};

int32_t main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    try {
        Laptop laptop(
            "Victus 15",
            "Gaming",
            "HP",
            35000,
            10,
            "High performance gaming laptop",
            "Intel Core i7-13700H",
            16,
            512
        );

        std::cout << std::string(10, '-') << " Laptop Information " << std::string(10, '-') << "\n";
        laptop.Print();

        std::cout << "\n\n" << std::string(10, '-') << " After Update " << std::string(10, '-') << "\n";

        laptop.setName("ROG Strix G16")
              .setCategory("Gaming Laptop")
              .setBrand("ASUS")
              .setPrice(42000)
              .setQuantity(15)
              .setDescription("Powerful gaming laptop")
              .ApplyDiscount(10)
              .IncreasePrice(5)
              .Sell(3)
              .Restock(8);

        laptop.setCPU("Intel Core i9-14900HX")
              .setRAM(32)
              .setStorage(1024);

        laptop.Print();

        std::cout << "\n\nTotal Stock Value : "
                  << laptop.getPrice() * laptop.getQuantity()
                  << '\n';

        std::cout << "Gaming Laptop : "
                  << (laptop.IsGamingLaptop() ? "Yes" : "No")
                  << '\n';
    }
    catch (const std::exception& ex) {
        std::cout << "Error: " << ex.what() << '\n';
    }

    return 0;
}
