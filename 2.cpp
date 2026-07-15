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
    bool Contains(const std::string& word) const {
        return description.find(word) != std::string::npos;
    }
    Product& ReplaceDescription(const std::string& oldWord, const std::string& newWord) {
        size_t pos = description.find(oldWord);
        while(pos != std::string::npos){
            description.replace(pos, oldWord.length(), newWord);
            pos = description.find(oldWord, pos + newWord.length());
        }
        return *this;
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
        if (amount <= 0) {
            throw std::invalid_argument("Invalid amount.");
        }
        this->quantity -= amount;
        return *this;
    }

    Product& IncrementQuantity() {
        ++quantity;
        return *this;
    }

    Product& DecrementQuantity() {
        if(quantity == 0)
            throw std::invalid_argument("Out of stock.");
        --quantity;
        return *this;
    }

    double GetStockValue() const {
        return getPrice() * getQuantity();
    } 

    Product& MergeProduct(const Product& other) {
        if (brand != other.brand) {
            throw std::invalid_argument("Brands are different.");
        }
        if (category != other.category) {
            throw std::invalid_argument("Categories are different.");
        }
        quantity += other.quantity;
        price = (price * quantity + other.price * other.quantity) / (quantity + other.quantity);
        description += "\nMerged With : " + other.name;
        return *this;
    }

    std::string GenerateProductCode() const {
        std::string code;
        code += brand.substr(0, std::min((size_t)2, brand.size()));
        code += category.substr(0, std::min((size_t)2, category.size()));
        return code;
    }

    virtual void Print() const {
        std::cout << "\nName       : " << getName();
        std::cout << "\nCategory   : " << getCategory();
        std::cout << "\nBrand      : " << getBrand();
        std::cout << "\nPrice      : " << getPrice();
        std::cout << "\nQuantity   : " << getQuantity();
        std::cout << "\nDescription: " << getDescription();
    }

    Product& Reset() {
        name.clear();
        category.clear();
        brand.clear();
        price = 1;
        quantity = 0;
        description = "No Description";
        return *this;
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

    int PerformanceScore() const {
        return RAM * 10 + Storage / 100;
    }

    double CalculateDepreciation(int years) const {
        if (years < 0) {
            throw std::invalid_argument("Invalid years.");
        }
        double currentPrice = getPrice();
        for (int i = 0; i < years; ++i) {
            currentPrice *= 0.9; 
        }
        return currentPrice;
    }

    void CalculateInstallment(int months, double interest) const {
        if (months <= 0) {
            throw std::invalid_argument("Invalid months.");
        }
        if (interest < 0) {
            throw std::invalid_argument("Invalid interest.");
        }
        double total = getPrice() + (getPrice() * interest / 100.0);
        double monthly = total / months;
        std::cout << "\n" << std::string(5, '-') << " Installment Plan " << std::string(5, '-') << "\n";
        std::cout << "Product        : " << getName() << '\n';
        std::cout << "Original Price : " << getPrice() << '\n';
        std::cout << "Interest       : " << interest << "%\n";
        std::cout << "Total Price    : " << total << '\n';
        std::cout << "Months         : " << months << '\n';
        std::cout << "Monthly Payment: " << monthly << '\n';
    }

    void RecommendUsage() const {
        std::cout << "\nRecommended Usage:\n";
        if (RAM >= 32 && Storage >= 1024) {
            std::cout << "- Gaming\n- AI Development\n- Video Editing\n";
        } else if (RAM >= 16) {
            std::cout << "- Programming\n- Gaming\n- Graphic Design\n";
        } else if (RAM >= 8) {
            std::cout << "- Office Work\n- Programming Basics\n";
        } else {
            std::cout << "- Browsing\n- Watching Videos\n- Study\n";
        }
    }

    void RecommendUpgrade() const {
        std::cout << "\n" << std::string(5, '-') << " Upgrade Recommendation " << std::string(5, '-') << "\n";
        bool upgraded = false;
        if (RAM < 16) {
            std::cout << "- Upgrade RAM to at least 16 GB.\n";
            upgraded = true;
        }
        if (Storage < 512) {
            std::cout << "- Upgrade Storage to at least 512 GB SSD.\n";
            upgraded = true;
        }
        if (CPU.find("i3") != std::string::npos ||
            CPU.find("Ryzen 3") != std::string::npos) {
            std::cout << "- Upgrade CPU for better performance.\n";
            upgraded = true;
        }
        if (!upgraded) {
            std::cout << "This laptop does not need any upgrades.\n";
        }
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
            "Nitro v 16",
            "Gaming",
            "HP",
            60000,
            10,
            "High performance gaming laptop",
            "Intel Core i7-13700H",
            16,
            512
        );

        laptop.Print();

        std::cout << "\n\nStock Value - " << laptop.GetStockValue() << '\n';

        std::cout << "Product Code - " << laptop.GenerateProductCode() << '\n';

        std::cout << "Contains Gaming ? " << (laptop.Contains("gaming") ? "Yes" : "No") << '\n';

        laptop.ReplaceDescription("gaming", "professional");
        laptop.ApplyDiscount(10);
        laptop.IncreasePrice(5);
        laptop.Restock(5);
        laptop.Sell(3);

        std::cout << "\nAfter Updates:\n";
        laptop.Print();

        std::cout << "\nPerformance Score - " << laptop.PerformanceScore();

        std::cout << "\nPrice after 3 years - " << laptop.CalculateDepreciation(3);

        laptop.CalculateInstallment(12, 8);

        laptop.RecommendUsage();

        laptop.RecommendUpgrade();

    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what();
    }
    return 0;
}
