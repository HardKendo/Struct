#include <iostream>

 
struct ComplexNumber {
public:
    ComplexNumber();
    ComplexNumber(double a, double b);
    ComplexNumber plus(ComplexNumber&);
    ComplexNumber minus(ComplexNumber&);
    ComplexNumber multiply(ComplexNumber&);
    ComplexNumber divide(ComplexNumber&);
    void print();
    void setA(double a);
    void setB(double b);
    void read();
    private:
    double a, b;
};
 
ComplexNumber::ComplexNumber() {
    a = 0;
    b = 0;
}
 
ComplexNumber::ComplexNumber(double a, double b) {
    this->a = a;
    this->b = b;
}
 
void ComplexNumber::setA(double a) {
    this->a = a;
}
 
void ComplexNumber::setB(double b) {
    this->b = b;
}
 
void ComplexNumber::read() {
    std::cout << "Введите вещественную часть: ";
    std::cin >> a;
    std::cout << "Введите мнимую часть: ";
    std::cin >> b;
}
 
void ComplexNumber::print() {
    std::cout << a << (b > 0? "+" : "") << b << "*i\n";
}
 
ComplexNumber ComplexNumber::plus(ComplexNumber &right) {
    return ComplexNumber(this->a + right.a, this->b + right.b);
}
 
ComplexNumber ComplexNumber::minus(ComplexNumber &right) {
    return ComplexNumber(this->a - right.a, this->b - right.b);
}
 
ComplexNumber ComplexNumber::multiply(ComplexNumber &right) {
    double a = this->a,
        b = this->b,
        c = right.a,
        d = right.b;
    return ComplexNumber(a*c - b*d, b*c + a*d);
}
 
ComplexNumber ComplexNumber::divide(ComplexNumber &right) {
    double a = this->a,
        b = this->b,
        c = right.a,
        d = right.b;
    double resultA = (a*c + b*d)/(c*c + d*d),
        resultB = (b*c - a*d)/(c*c + d*d);
    return ComplexNumber(resultA, resultB);
}
 
int menu() {
    int answer;
    std::cout << "\n1 - Сложить\n"
        << "2 - Вычесть\n"
        << "3 - Умножить\n"
        << "4 - Разделить\n"
        << "0 - Выход из программы\n"
        << "> ";
    std::cin >> answer;
    std::cout << std::endl;
    return answer;
}
 
int main() {
    ComplexNumber a, b, result;
    int answer;
    do {
        answer = menu();
        if (answer != 0) {
            std::cout << "Число А\n";
            a.read();
            std::cout << "Число B\n";
            b.read();
        }
        switch (answer) {
        case 0:
            break;
        case 1:
            result = a.plus(b);
            break;
        case 2:
            result = a.minus(b);
            break;
        case 3:
            result = a.multiply(b);
            break;
        case 4:
            result = a.divide(b);
            break;
        }
        if (answer != 0) {
            std::cout << "Результат: ";
            result.print();
        }
    } while (answer != 0);
}