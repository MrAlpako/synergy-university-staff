#include "university_staff.h"
#include <iostream>

// Конструктор по умолчанию
UNIVERSITY_STAFF::UNIVERSITY_STAFF() 
    : last_name_and_initials("Неизвестно"), 
      position("Не указана"), 
      salary(0.0), 
      year_of_employment(2024) {
    std::cout << "Создан объект UNIVERSITY_STAFF (по умолчанию)" << std::endl;
}

// Конструктор с параметрами
UNIVERSITY_STAFF::UNIVERSITY_STAFF(const std::string& name, const std::string& pos, 
                                 double sal, int year)
    : last_name_and_initials(name), 
      position(pos), 
      salary(sal), 
      year_of_employment(year) {
    std::cout << "Создан объект для " << name << std::endl;
}

// Деструктор
UNIVERSITY_STAFF::~UNIVERSITY_STAFF() {
    std::cout << "Удален объект для " << last_name_and_initials << std::endl;
}

// Методы изменения полей
void UNIVERSITY_STAFF::setLastName(const std::string& name) {
    last_name_and_initials = name;
}

void UNIVERSITY_STAFF::setPosition(const std::string& pos) {
    position = pos;
}

void UNIVERSITY_STAFF::setSalary(double sal) {
    salary = sal;
}

void UNIVERSITY_STAFF::setYearOfEmployment(int year) {
    year_of_employment = year;
}

// Методы получения значений
std::string UNIVERSITY_STAFF::getLastName() const {
    return last_name_and_initials;
}

std::string UNIVERSITY_STAFF::getPosition() const {
    return position;
}

double UNIVERSITY_STAFF::getSalary() const {
    return salary;
}

int UNIVERSITY_STAFF::getYearOfEmployment() const {
    return year_of_employment;
}

// Метод расчета стажа
int UNIVERSITY_STAFF::calculate_experience(int current_year) const {
    if (year_of_employment <= current_year) {
        return current_year - year_of_employment;
    } else {
        return 0;  // Если год приема больше текущего
    }
}

// Метод отображения полной информации
void UNIVERSITY_STAFF::display_info() const {
    std::cout << "\n=== Информация о сотруднике ===" << std::endl;
    std::cout << "ФИО: " << last_name_and_initials << std::endl;
    std::cout << "Должность: " << position << std::endl;
    std::cout << "Зарплата: " << salary << " руб." << std::endl;
    std::cout << "Год приема: " << year_of_employment << std::endl;
}

// Метод для вывода только фамилии и должности
void UNIVERSITY_STAFF::display_name_and_position() const {
    std::cout << "- " << last_name_and_initials << " (" << position << ")" << std::endl;
}
