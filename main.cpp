#include <iostream>
#include "university_staff.h"

int main() {
    // Русская локаль для корректного отображения
    setlocale(LC_ALL, "Russian");
    
    std::cout << "=== УЧЕТ СОТРУДНИКОВ УНИВЕРСИТЕТА 'СИНЕРГИЯ' ===" << std::endl;
    std::cout << "================================================" << std::endl;
    
    // Ввод текущего года
    int current_year;
    std::cout << "\nВведите текущий год: ";
    std::cin >> current_year;
    std::cin.ignore();  // Очистка буфера
    
    // Ввод количества сотрудников
    int num_staff;
    std::cout << "Введите количество сотрудников для добавления: ";
    std::cin >> num_staff;
    std::cin.ignore();
    
    // Проверка корректности ввода
    if (num_staff <= 0) {
        std::cout << "Ошибка: количество сотрудников должно быть больше 0!" << std::endl;
        return 1;
    }
    
    // Создание динамического массива объектов
    UNIVERSITY_STAFF* staff_array = new UNIVERSITY_STAFF[num_staff];
    
    // Ввод данных о сотрудниках
    std::cout << "\n=== ВВОД ДАННЫХ О СОТРУДНИКАХ ===" << std::endl;
    
    for (int i = 0; i < num_staff; i++) {
        std::string name, position;
        double salary;
        int year;
        
        std::cout << "\n--- Сотрудник " << (i + 1) << " ---" << std::endl;
        
        // Фамилия и инициалы
        std::cout << "Фамилия и инициалы: ";
        std::getline(std::cin, name);
        
        // Должность
        std::cout << "Должность: ";
        std::getline(std::cin, position);
        
        // Зарплата
        std::cout << "Зарплата (руб.): ";
        std::cin >> salary;
        
        // Год приема
        std::cout << "Год приема на работу: ";
        std::cin >> year;
        std::cin.ignore();  // Очистка буфера после числа
        
        // Установка значений через сеттеры
        staff_array[i].setLastName(name);
        staff_array[i].setPosition(position);
        staff_array[i].setSalary(salary);
        staff_array[i].setYearOfEmployment(year);
    }
    
    // Ввод минимального требуемого стажа
    int min_experience;
    std::cout << "\n=== ФИЛЬТРАЦИЯ ПО СТАЖУ ===" << std::endl;
    std::cout << "Введите минимальный требуемый стаж (лет): ";
    std::cin >> min_experience;
    
    // Поиск сотрудников с заданным стажем
    std::cout << "\n=== РЕЗУЛЬТАТЫ ПОИСКА ===" << std::endl;
    
    bool found = false;
    int count = 0;
    
    for (int i = 0; i < num_staff; i++) {
        int experience = staff_array[i].calculate_experience(current_year);
        
        if (experience > min_experience) {
            if (!found) {
                std::cout << "Сотрудники со стажем более " << min_experience 
                         << " лет в Университете 'Синергия':" << std::endl;
                found = true;
            }
            
            std::cout << ++count << ". ";
            staff_array[i].display_name_and_position();
            std::cout << "   (Стаж: " << experience << " лет)" << std::endl;
        }
    }
    
    // Если сотрудников не найдено
    if (!found) {
        std::cout << "Сотрудников со стажем более " << min_experience 
                 << " лет не найдено." << std::endl;
    } else {
        std::cout << "\nВсего найдено: " << count << " сотрудник(ов/а)." << std::endl;
    }
    
    // Дополнительно: вывод всей информации о всех сотрудниках
    std::cout << "\n=== ПОЛНАЯ ИНФОРМАЦИЯ О ВСЕХ СОТРУДНИКАХ ===" << std::endl;
    for (int i = 0; i < num_staff; i++) {
        std::cout << "\n--- Сотрудник " << (i + 1) << " ---" << std::endl;
        std::cout << "ФИО: " << staff_array[i].getLastName() << std::endl;
        std::cout << "Должность: " << staff_array[i].getPosition() << std::endl;
        std::cout << "Зарплата: " << staff_array[i].getSalary() << " руб." << std::endl;
        std::cout << "Год приема: " << staff_array[i].getYearOfEmployment() << std::endl;
        std::cout << "Стаж (на " << current_year << " год): " 
                 << staff_array[i].calculate_experience(current_year) << " лет" << std::endl;
    }
    
    // Освобождение памяти
    delete[] staff_array;
    
    std::cout << "\n================================================" << std::endl;
    std::cout << "Программа завершена. Спасибо!" << std::endl;
    
    return 0;
}
