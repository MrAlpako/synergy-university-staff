#ifndef UNIVERSITY_STAFF_H
#define UNIVERSITY_STAFF_H

#include <string>
#include <iostream>

class UNIVERSITY_STAFF {
private:
    std::string last_name_and_initials;
    std::string position;
    double salary;
    int year_of_employment;

public:
    // Конструкторы
    UNIVERSITY_STAFF();  // По умолчанию
    UNIVERSITY_STAFF(const std::string& name, const std::string& pos, 
                    double sal, int year);  // С параметрами
    
    // Деструктор
    ~UNIVERSITY_STAFF();

    // Методы изменения полей (сеттеры)
    void setLastName(const std::string& name);
    void setPosition(const std::string& pos);
    void setSalary(double sal);
    void setYearOfEmployment(int year);

    // Методы получения значений (геттеры)
    std::string getLastName() const;
    std::string getPosition() const;
    double getSalary() const;
    int getYearOfEmployment() const;

    // Метод расчета стажа
    int calculate_experience(int current_year) const;

    // Метод отображения информации
    void display_info() const;

    // Метод для вывода только фамилии и должности (для задания)
    void display_name_and_position() const;
};

#endif // UNIVERSITY_STAFF_H
