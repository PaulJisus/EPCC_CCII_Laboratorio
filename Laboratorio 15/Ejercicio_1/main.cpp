#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Producto1 {
public:
	vector<std::string> componentes;
	void ListaComp()const {
        std::cout << "Componentes:\n";
        for (size_t i = 0; i < componentes.size(); i++) {
            if (componentes[i] == componentes.back()) {
                std::cout << componentes[i];
            }
            else {
                std::cout << componentes[i] << '\n';
            }
        }
        std::cout << "\n\n";
    }
};

class IBuilder {
public:
	virtual ~IBuilder() {}
	virtual void ProducirMotor() const = 0;
	virtual void ProducirTimon() const = 0;
	virtual void ProducirCarroceria() const  = 0;
	virtual void ProducirPuertas() const  = 0;
	virtual void ProducirLlantas() const = 0;
	virtual void ProducirAsientos() const  = 0;
	virtual void ProducirVidrios() const = 0;
	virtual void ProducirLuces() const = 0;
	virtual void ProducirEspejos() const = 0;
	virtual void ProducirTransmision() const = 0;
};

class BuilderEspecifico : public IBuilder {
private:
	Producto1* producto;
public:

	BuilderEspecifico() {
		this->Reset();
	}
	~BuilderEspecifico() {
		delete producto;
	}
	void Reset() {
		this->producto = new Producto1();
	}
    void ProducirMotor() const override {
        std::string aux;
        std::cout<<"Elegir color del Motor: ";
        std::cin >> aux;
        this->producto->componentes.push_back("Motor " + aux);
    }
    void ProducirTimon() const override {
        std::string aux{};
        std::cout<<"Elegir color del Timon: ";
        std::cin >> aux;
        this->producto->componentes.push_back("Timon " + aux);
    }
    void ProducirCarroceria() const override {
        std::string aux{};
        std::cout<<"Elegir color de la Carroceria: ";
        std::cin >> aux;
        this->producto->componentes.push_back("Carroceria " + aux);
    }
    void ProducirPuertas() const override {
        std::string aux{};
        std::cout<<"Elegir color de las Puertas: ";
        std::cin >> aux;
        this->producto->componentes.push_back("Puertas " + aux);
    }
    void ProducirLlantas() const override {
        std::string aux{};
        int tam{};
        std::cout << "Elegir color de los Aros: ";
        std::cin >> aux;
        std::cout << "Elegir el tamanio de las Llantas: ";
        std::cin >> tam;
        this->producto->componentes.push_back("Aros de " + std::to_string(tam) + " pulgadas color " + aux);
    }
    void ProducirAsientos() const override {
        std::string aux{}, aux1{};
        std::cout<<"Elegir color de los Asientos: ";
        std::cin >> aux;
        std::cout<<"Elegir el material de los Asientos: ";
        std::cin >> aux1;
        this->producto->componentes.push_back("Asientos " + aux + " de " + aux1);
    }
    void ProducirVidrios() const override {
        std::string aux;
        std::cout<<"Elegir color de los Vidrios: ";
        std::cin >> aux;
        this->producto->componentes.push_back("Vidrios " + aux);
    }
    void ProducirLuces() const override {
        std::string aux;
        std::cout<<"Elegir color de las Luces: ";
        std::cin >> aux;
        this->producto->componentes.push_back("Luces " + aux);
    }
    void ProducirEspejos() const override {
        std::string aux;
        std::cout << "Elegir color de los Espejos: ";
        std::cin >> aux;
        this->producto->componentes.push_back("Espejos " + aux);
    }
    void ProducirTransmision() const override {
        int op{};
        do{
            std::cout << "Elegir el tipo transmision:\n";
            std::cout << "\n\t-------------------------\n";
            std::cout << "\t|Numero\t|    Opcion\t|\n";
            std::cout << "\t-------------------------\n";
            std::cout << "\t|1\t|Manual\t\t|\n";
            std::cout << "\t|2\t|Automatica\t|\n";
            std::cout << "\t-------------------------\n";
            std::cin >> op;
        }while(op < 1 || op > 2);
        if(op == 1)
        {
            this->producto->componentes.push_back("Transmision Manual");
        }
        else if(op == 2)
        {
            this->producto->componentes.push_back("Transmision Automatica");
        }
    }
    Producto1* GetProducto() {
        Producto1* resultado = this->producto;
        this->Reset();
        return resultado;
    }
};

class Director {
private:
	IBuilder* builder;
public:
	void set_builder(IBuilder* builder) {
		this->builder = builder;
	}
	void BuildProductoBasico() {
		this->builder->ProducirTimon();
		this->builder->ProducirCarroceria();
		this->builder->ProducirLlantas();
		this->builder->ProducirAsientos();
		this->builder->ProducirMotor();
		this->builder->ProducirTransmision();
	}
	void BuildProductoCompleto() {

		this->builder->ProducirTimon();
		this->builder->ProducirCarroceria();
		this->builder->ProducirPuertas();
		this->builder->ProducirLlantas();
		this->builder->ProducirAsientos();
		this->builder->ProducirMotor();
		this->builder->ProducirLuces();
		this->builder->ProducirVidrios();
		this->builder->ProducirEspejos();
		this->builder->ProducirTransmision();
	}
};

void menuPrincipal()
{
    std::cout << "\n\t---------------------------------\n";
    std::cout << "\t|Numero\t|\tOpcion\t\t|\n";
    std::cout << "\t---------------------------------\n";
    std::cout << "\t|1\t|Automovil Basico\t|\n";
    std::cout << "\t|2\t|Automovil Completo\t|\n";
    std::cout << "\t|3\t|Personalizar Automovil\t|\n";
    std::cout << "\t|4\t|Salir\t\t\t|\n";
    std::cout << "\t---------------------------------\n";
}

void Submenu()
{
    std::cout << "\n\t-------------------------\n";
    std::cout << "\t|Numero\t|    Opcion\t|\n";
    std::cout << "\t-------------------------\n";
    std::cout << "\t|1\t|Motor\t\t|\n";
    std::cout << "\t|2\t|Timon\t\t|\n";
    std::cout << "\t|3\t|Carroceria\t|\n";
    std::cout << "\t|4\t|Puertas\t|\n";
    std::cout << "\t|5\t|Llantas\t|\n";
    std::cout << "\t|6\t|Asientos\t|\n";
    std::cout << "\t|7\t|Vidrios\t|\n";
    std::cout << "\t|8\t|Luces\t\t|\n";
    std::cout << "\t|9\t|Espejos\t|\n";
    std::cout << "\t|10\t|Transimsion\t|\n";
    std::cout << "\t|11\t|Salir\t\t|\n";
    std::cout << "\t-------------------------\n";
}

void ClienteCode(Director& director)
{
	int op{};
	BuilderEspecifico* builder = new BuilderEspecifico();
	director.set_builder(builder);
	Producto1* p = builder->GetProducto();
	do{
		menuPrincipal();
		std::cout << "\nIngrese una opcion valida:\n";
		std::cin >> op;

		if(op == 1){
			director.BuildProductoBasico();
			p = builder->GetProducto();
			std::cout << "Automovil Basico:\n";
			p->ListaComp();
			delete p;
		}
		else if(op == 2){
			director.BuildProductoCompleto();
			p = builder->GetProducto();
			std::cout << "Automovil Completo:\n";
			p->ListaComp();
			delete p;
		}
		else if(op == 3){
			int opc{};
			do{
				Submenu();
				std::cout << "Ingrese una opcion valida:\n";
				std::cin >> opc;

				if(opc == 1){
					builder->ProducirMotor();
				}
				else if(opc == 2) {
					builder->ProducirTimon();
				}
				else if(opc == 3) {
					builder->ProducirCarroceria();
				}
				else if(opc == 4) {
					builder->ProducirPuertas();
				}
				else if(opc == 5) {
					builder->ProducirLlantas();
				}
				else if(opc == 6) {
					builder->ProducirAsientos();
				}
				else if(opc == 7) {
					builder->ProducirVidrios();
				}
				else if(opc == 8) {
					builder->ProducirLuces();
				}
				else if(opc == 9) {
					builder->ProducirEspejos();
				}
				else if(opc == 10) {
                    builder->ProducirTransmision();
				}
				else if(opc == 11) {
					cout<<"\nAutomovil Finalizado."<<endl;
				}
				else {
					cout<<"\nError"<<endl;
				}

			}while(opc != 11);
			p = builder->GetProducto();
			std::cout << "Automovil Personalizado:\n";
			p->ListaComp();
			delete p;

		}else if(op == 4){

			cout<<"\nGracias por usar el programa."<<endl;

		}else{

			cout<<"\nOpcion invalida."<<endl;
		}

	}while(op != 4);
	delete builder;
}

int main() {

	Director* director = new Director();
	ClienteCode(*director);
	delete director;
	return 0;

}
