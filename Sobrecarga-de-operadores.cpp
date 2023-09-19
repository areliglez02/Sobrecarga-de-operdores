#include <iostream>
#include <string>

class Empleado {
private:
    int ClaveEmpleado;
    std::string nombre;
    std::string domicilio;
    float sueldo;
    std::string reportas;

public:
    Empleado() {
        ClaveEmpleado = 0;
        nombre = "";
        domicilio = "";
        sueldo = 0;
        reportas = "";
    }

    Empleado(int C, std::string n, std::string d, float s, std::string r) {
        ClaveEmpleado = C;
        nombre = n;
        domicilio = d;
        sueldo = s;
        reportas = r;
    }

    void Imprime() {
        std::cout << "Clave: " << ClaveEmpleado << "\nNombre: " << nombre << "\nDomicilio: " << domicilio << "\nSueldo: " << sueldo << "\nReporta a: " << reportas << std::endl;
    }

    void CambiarDomic(std::string d) {
        domicilio = d;
    }

    void ReportaA(std::string r) {
        reportas = r;
    }

    void ActualSueldo(float s) {
        sueldo = s;
    }
    // Sobrecarga de operadores
    bool operator==(const Empleado& otro) const {
        return ClaveEmpleado == otro.ClaveEmpleado;
    }

    bool operator!=(const Empleado& otro) const {
        return ClaveEmpleado != otro.ClaveEmpleado;
    }

    bool operator<(const Empleado& otro) const {
        return ClaveEmpleado < otro.ClaveEmpleado;
    }

    bool operator>(const Empleado& otro) const {
        return ClaveEmpleado > otro.ClaveEmpleado;
    }

    Empleado operator+(const Empleado& otro) const {
        // Suma de sueldos y concatenación de nombres en el nuevo objeto
        Empleado resultado;
        resultado.ClaveEmpleado = ClaveEmpleado;
        resultado.nombre = nombre + " y " + otro.nombre;
        resultado.domicilio = domicilio;
        resultado.sueldo = sueldo + otro.sueldo;
        resultado.reportas = reportas;
        return resultado;
    }

    friend std::istream& operator>>(std::istream& input, Empleado& empleado) {
        // Sobrecarga del operador de entrada (>>)
        input >> empleado.ClaveEmpleado >>empleado.nombre >>empleado.domicilio>> empleado.sueldo >> empleado.reportas;
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, const Empleado& empleado) {
        // Sobrecarga del operador de salida (<<)
        output << "Clave: " << empleado.ClaveEmpleado << "\nNombre: " << empleado.nombre << "\nDomicilio: " << empleado.domicilio << "\nSueldo: " << empleado.sueldo << "\nReporta a: " << empleado.reportas << std::endl;
        return output;
    }
};

int main() {
    // Declaración de objetos
    Empleado JefePlanta(1, "Alberto Plaza", "Morelos #50", 5000.0, "Jefe de planta");
    Empleado JefePersonal(2, "Fernando Gracia", "16 de septiembre #67B", 6000.0, "Jefe personal");

    char repite = 1;
    int opc;
    do {
        std::cout << "\n\t\tMENU PRINCIPAL" << std::endl;
        std::cout << "\n\n1. Cambio de domicilio\n2. Actualizacion de sueldo\n3. Imprimir datos de empleado\n4. Cambiar persona que reporta\n5. Salir" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opc;
        switch (opc) {
            case 1: {
                std::string nuevoDomicilio;
                std::cout << "Nuevo domicilio: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoDomicilio);
                JefePlanta.CambiarDomic(nuevoDomicilio);
                JefePersonal.CambiarDomic(nuevoDomicilio);
                break;
            }
            case 2: {
                float nuevoSueldo;
                std::cout << "Nuevo sueldo: ";
                std::cin >> nuevoSueldo;
                JefePlanta.ActualSueldo(nuevoSueldo);
                JefePersonal.ActualSueldo(nuevoSueldo);
                break;
            }
            case 3:
                JefePlanta.Imprime();
                JefePersonal.Imprime();
                break;
            case 4: {
                std::string nuevaPersona;
                std::cout << "Nueva persona que reporta: ";
                std::cin.ignore();
                std::getline(std::cin, nuevaPersona);
                JefePlanta.ReportaA(nuevaPersona);
                JefePersonal.ReportaA(nuevaPersona);
                break;
            }
            case 5:
                repite = 0;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    } while (repite);

    return 0;
}
