#include<bits/stdc++.h>

class Person {
private:
    std::string firstName_;
    std::string lastName_;
    std::string title_;
    std::string email_;
    std::string phone_;
    double salary_;
    std::string department_;

public:
    virtual ~Person() = default;

    Person(const std::string& firstName,
           const std::string& lastName,
           const std::string& title,
           const std::string& email,
           const std::string& phone,
           double salary,
           const std::string& department)
    {
        setFirstName(firstName);
        setLastName(lastName);
        setTitle(title);
        setEmail(email);
        setPhone(phone);
        setSalary(salary);
        setDepartment(department);
    }

    Person& setFirstName(const std::string& firstName) {
        if (firstName.empty()) {
            throw std::invalid_argument("First name cannot be empty.");
        }
        firstName_ = firstName;
        return *this;
    }

    const std::string& getFirstName() const {
        return firstName_;
    }

    Person& setLastName(const std::string& lastName) {
        if (lastName.empty()) {
            throw std::invalid_argument("Last name cannot be empty.");
        }
        lastName_ = lastName;
        return *this;
    }

    const std::string& getLastName() const {
        return lastName_;
    }

    Person& setTitle(const std::string& title) {
        if (title.empty()) {
            throw std::invalid_argument("Title cannot be empty.");
        }
        title_ = title;
        return *this;
    }

    const std::string& getTitle() const {
        return title_;
    }

    Person& setEmail(const std::string& email) {
        const std::string suffix = "@gmail.com";

        if (email.size() <= suffix.size() ||
            email.substr(email.size() - suffix.size()) != suffix ||
            email.front() == '@') {
            throw std::invalid_argument("Invalid Gmail address.");
        }

        email_ = email;
        return *this;
    }

    const std::string& getEmail() const {
        return email_;
    }

    Person& setPhone(const std::string& phone) {
        if (phone.empty() || phone[0] != '+') {
            throw std::invalid_argument("Phone number must start with '+'.");
        }

        if (phone.size() < 8 || phone.size() > 16) {
            throw std::invalid_argument("Invalid phone number length.");
        }

        for (size_t i = 1; i < phone.size(); i++) {
            if (!std::isdigit(static_cast<unsigned char>(phone[i]))) {
                throw std::invalid_argument("Phone number must contain digits only.");
            }
        }

        phone_ = phone;
        return *this;
    }

    const std::string& getPhone() const {
        return phone_;
    }

    Person& setSalary(double salary) {
        if (salary < 0) {
            throw std::invalid_argument("Salary cannot be negative.");
        }

        salary_ = salary;
        return *this;
    }

    double getSalary() const {
        return salary_;
    }

    Person& setDepartment(const std::string& department) {
        if (department.empty()) {
            throw std::invalid_argument("Department cannot be empty.");
        }

        department_ = department;
        return *this;
    }

    const std::string& getDepartment() const {
        return department_;
    }

    std::string getFullName() const {
        return firstName_ + " " + lastName_;
    }

    void SendEmail(const std::string& subject,
                   const std::string& message) const {
        std::cout << "\n----- Email -----\n";
        std::cout << "To      : " << email_ << '\n';
        std::cout << "Subject : " << subject << '\n';
        std::cout << "Message : " << message << '\n';
        std::cout << "Email sent successfully.\n";
    }

    void SendSMS(const std::string& message) const {
        std::cout << "\n----- SMS -----\n";
        std::cout << "To      : " << phone_ << '\n';
        std::cout << "Message : " << message << '\n';
        std::cout << "SMS sent successfully.\n";
    }

    virtual void Print() const {
        std::cout << "\nFirst Name  : " << getFirstName();
        std::cout << "\nLast Name   : " << getLastName();
        std::cout << "\nTitle       : " << getTitle();
        std::cout << "\nFull Name   : " << getFullName();
        std::cout << "\nEmail       : " << getEmail();
        std::cout << "\nPhone       : " << getPhone();
        std::cout << "\nSalary      : " << getSalary();
        std::cout << "\nDepartment  : " << getDepartment();
        std::cout << '\n';
    }
};
class Developer : public Person {
private:
    std::string mainProgrammingLanguage_;

public:
    Developer(const std::string& firstName,
              const std::string& lastName,
              const std::string& title,
              const std::string& email,
              const std::string& phone,
              double salary,
              const std::string& department,
              const std::string& mainProgrammingLanguage)
        : Person(firstName,
                 lastName,
                 title,
                 email,
                 phone,
                 salary,
                 department)
    {
        setMainProgrammingLanguage(mainProgrammingLanguage);
    }

    Developer& setMainProgrammingLanguage(
        const std::string& mainProgrammingLanguage)
    {
        if (mainProgrammingLanguage.empty()) {
            throw std::invalid_argument(
                "Programming language cannot be empty.");
        }

        mainProgrammingLanguage_ = mainProgrammingLanguage;
        return *this;
    }

    const std::string& getMainProgrammingLanguage() const {
        return mainProgrammingLanguage_;
    }

    void Print() const override {
        Person::Print();
        std::cout << "Main Programming Language : "
                  << getMainProgrammingLanguage()
                  << '\n';
    }
};

int32_t main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    try {
        Developer dev(
            "Mahmoud",
            "H Hamdy",
            "Junior Developer",
            "Mahmoud@gmail.com",
            "+201234567890",
            5000,
            "IT",
            "C++"
        );
        std::cout << "Developer Information\n";
        dev.Print();
        std::cout << "\nAfter Updating\n";
        dev.setFirstName("Hamdy")
           .setLastName("Hamdy")
           .setTitle("Senior Developer")
           .setSalary(12000)
           .setDepartment("Software Engineering")
           .setEmail("Hamdy@gmail.com")
           .setPhone("+201112223334");
        dev.setMainProgrammingLanguage("C++");
        std::cout << "\nUpdated Information\n";
        dev.Print();
        dev.SendEmail(
            "Meeting",
            "Please attend the meeting at 10 AM."
        );
        dev.SendSMS(
            "Your salary has been transferred."
        );
    }
    catch (const std::exception& ex) {
        std::cout << "Error: " << ex.what() << '\n';
    }
    return 0;
}
