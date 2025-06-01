#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;    // Нижняя диагональ
    std::vector<double> m_upper;   // Верхняя диагональ
    std::vector<double> m_middle;  // Главная диагональ

    // Конструктор класса
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down },
        m_upper{ upper },
        m_middle{ middle }
    {
    };

    // Деструктор класса
    ~tridiagonal_matrix()
    {
        std::cout << "destructor called\n";
    }

    // Метод для создания копии объекта
    std::unique_ptr<tridiagonal_matrix> clone()
    {
        // Создаем новый unique_ptr с копией текущего объекта
        return std::make_unique<tridiagonal_matrix>(
            this->m_down,    // Копируем нижнюю диагональ
            this->m_upper,   // Копируем верхнюю диагональ
            this->m_middle  // Копируем главную диагональ
        );
    }
};

int main()
{
    // Исходные данные для матрицы
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };

    // Создаем исходную матрицу
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    // Создаем копию матрицы
    auto matrix_clone = matrix->clone();

    return 0;
}