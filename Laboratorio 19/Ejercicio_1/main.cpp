#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template<typename Type>
class Summation{
    public:
       std::pair<double, double> operator() (vector<Type> &vec)
       {
            double rpt_x{}, rpt_y{};
            for (auto i{0}; i < vec.size(); ++i)
            {
                rpt_x += vec.at(i).first;
                rpt_y += vec.at(i).second;
           }
           return(std::make_pair(rpt_x, rpt_y));
       }
};

template<typename Type>
class Power{
    public:
       std::vector<std::pair<double, double>> operator() (vector<Type> &vec)
       {
            std::vector<std::pair<double, double>> rpt{};
            for (auto i{0}; i < vec.size(); ++i)
            {
                rpt.push_back(std::make_pair(vec.at(i).first * vec.at(i).first, vec.at(i).second * vec.at(i).second));
           }
           return rpt;
       }
};

template<typename Type>
class Multiplication{
    public:
       double operator() (vector<Type> &vec)
       {
            auto rpt{0};
            for (auto i{0}; i < vec.size(); ++i)
            {
                rpt += (vec.at(i).first * vec.at(i).second);
            }
            return rpt;
       }
};

template<typename Type>
class Mean{
    public:
       std::pair<double, double> operator() (vector<Type> &vec)
       {
            double rpt_x{}, rpt_y{};
            auto n {vec.size()};
            for (auto i{0}; i < n; ++i)
            {
                rpt_x += vec.at(i).first;
                rpt_y += vec.at(i).second;
            }
            return(std::make_pair(rpt_x / n, rpt_y / n));
       }
};

template<typename Type>
class Deviation{
    public:
       std::pair<double, double> operator() (vector<Type> &vec)
       {
            Power<std::pair<double,double>> obj;
            std::vector<std::pair<double, double>> power = obj(vec);
            Summation<std::pair<double,double>> obj1;
            std::pair<double, double> summation = obj1(power);
            Mean<std::pair<double,double>> obj2;
            std::pair<double, double> mean = obj2(vec);
            auto n{vec.size()};
            double rpt_x{}, rpt_y{};
            rpt_x = sqrt((summation.first / n) - (mean.first * mean.first));
            rpt_y = sqrt((summation.second / n) - (mean.second * mean.second));
            return(std::make_pair(rpt_x, rpt_y));
       }
};

template<typename Type>
class Covariance{
    public:
       double operator() (vector<Type> &vec)
       {
            Multiplication<std::pair<double,double>> obj;
            auto multiplication = obj(vec);
            Mean<std::pair<double,double>> obj1;
            std::pair<double, double> mean = obj1(vec);
            double rpt{0};
            auto n{vec.size()};
            rpt = (multiplication / n) - (mean.first * mean.second);
            return rpt;
       }
};

template<typename Type>
class Pearson{
    public:
       double operator() (vector<Type> &vec)
       {
            Covariance<std::pair<double,double>> obj;
            double covariance = obj(vec);
            Deviation<std::pair<double,double>> obj1;
            std::pair<double, double> deviation = obj1(vec);
            double rpt{0};
            rpt = (covariance / (deviation.first * deviation.second));
            return rpt;
       }
};

template<typename Type>
class Covariance_a{
    public:
       double operator() (vector<Type> &vec)
       {
            Covariance<std::pair<double,double>> obj;
            double covariance = obj(vec);
            Deviation<std::pair<double,double>> obj1;
            std::pair<double, double> deviation = obj1(vec);
            double rpt{0};
            rpt = (covariance / (deviation.first * deviation.first));
            return rpt;
       }
};

template<typename Type>
class Covariance_b{
    public:
       double operator() (vector<Type> &vec)
       {
            Mean<std::pair<double,double>> obj;
            auto mean = obj(vec);
            Covariance_a<std::pair<double,double>> obj1;
            double covariance_a = obj1(vec);
            double rpt{0};
            rpt = (mean.second - (covariance_a * mean.first));
            return rpt;
       }
};

template<typename Type>
class LeastSquares_a{
    public:
       double operator() (vector<Type> &vec)
       {
            Multiplication<std::pair<double,double>> obj;
            auto multiplication = obj(vec);
            Summation<std::pair<double,double>> obj1;
            std::pair<double, double> summation = obj1(vec);
            Power<std::pair<double,double>> obj2;
            std::vector<std::pair<double, double>> power = obj2(vec);
            Summation<std::pair<double,double>> obj3;
            std::pair<double, double> summation1 = obj3(power);
            auto n{vec.size()};
            double rpt{0};
            double aux1 {(n * multiplication) - (summation.first * summation.second)};
            double aux2 {(n * summation1.first) - (summation.first * summation.first)};
            rpt = aux1 / aux2;
            return rpt;
       }
};

template<typename Type>
class LeastSquares_b{
    public:
       double operator() (vector<Type> &vec)
       {
            Summation<std::pair<double,double>> obj;
            std::pair<double, double> summation = obj(vec);
            LeastSquares_a<std::pair<double,double>> obj1;
            auto leastSquares_a = obj1(vec);
            auto n{vec.size()};
            double rpt{0};
            rpt = ((summation.second - (leastSquares_a * summation.first)) / n);
            return rpt;
       }
};

template<typename Type>
void mostrar(vector<Type> &vec)
{
    for (auto i = 0; i < vec.size(); ++i) {
        cout << "(" << vec.at(i).first << ","
            << vec.at(i).second << ")" << "; ";
    }
    cout << endl;
}

int main() {
    vector<pair<double, double>> vec1 = {{2, 14},
                                      {3, 20},
                                      {5, 32},
                                      {7, 42},
                                      {8, 44}};

    std::cout << "Elementos:\n";
    mostrar(vec1);
    Pearson<std::pair<double,double>> pe;
    Covariance_a<std::pair<double,double>> ca;
    Covariance_b<std::pair<double,double>> cb;
    LeastSquares_a<std::pair<double,double>> la;
    LeastSquares_b<std::pair<double,double>> lb;
    std::cout << "Coeficiente de Pearson:\n";
    std::cout << pe(vec1) << std::endl;
    std::cout << "Valores por el metodo de covarianza.\n";
    std::cout << "a = " << ca(vec1) << "\nb = " << cb(vec1) << std::endl;
    std::cout << "Ecuacion de regresion lineal simple por el metodo de covarianza:\n";
    std::cout << ca(vec1) << "x + " << cb(vec1) << std::endl;
    std::cout << "Ecuacion de regresion lineal simple por el metodo de minimos cuadrados:\n";
    std::cout << la(vec1) << "x + " << lb(vec1) << std::endl;
    std::cout << "Valores por el metodo de minimos cuadrados.\n";
    std::cout << "a = " << la(vec1) << "\nb = " << lb(vec1) << std::endl;
    return 0;
}
