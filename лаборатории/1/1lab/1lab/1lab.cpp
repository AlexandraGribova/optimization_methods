#include <iostream>
using namespace std;
double a = -2;
double b = 20;

double eps = 0.0001;

double f(double x) {
    return (x - 8) * (x - 8);
}

void dichotomy(double a, double b) {
    double x1, x2, f1, f2;
    double delta = eps / 10;
    for (int i = 0; abs(b - a) > eps; i++)
    {
        x1 = (b + a - delta) / 2;
        x2 = (b + a + delta) / 2;
        f1 = f(x1);
        f2 = f(x2);
        if (f1 > f2)
            a = x1;
        else 
            b = x2;
        cout << "Iteration: " << i << "  a:" << a << "  b:" << b << "  X_min:"<<(a+b)/2<<endl;
    }

    cout << a << " " << b << endl;


}
void golden_ratio(double a, double b) {
    double x1, x2, f1, f2;

    for (int i = 0; abs(b - a) > eps; i++)
    {
        x1 = a + 0.381966011 * (b - a);
        x2 = a + 0.618003399 * (b - a);
        f1 = f(x1);
        f2 = f(x2);
       /* if (abs(f1 - f2) < 0.000000001)
        {
            a = x1;
            b = x2;
        }
        else*/ if (f1 > f2)//то что закомментировано прописано в методичке но не влияет на результат решения. Оставить или удалить?
            a = x1;
        else
            b = x2;
        cout << "Iteration: " << i << "  a:" << a << "  b:" << b << "  X_min:" << (a + b) / 2 << endl;
    }
}
void interval_search(double &a, double &b, double x0) 
{
    double delta = eps / 10;
    double f0 = f(x0);
    double f1 = f(x0 + delta);
    double x1, h;
    int k = 0;
        if (f0 > f1)//Если ф-я на участке убывает
        {
            x1 = x0 + delta;
            h = delta;
            k = 1;
        }
        else//Если ф-я на участке возрастает
        {
            x1 = x0 - delta;
            h = -delta;
        }
        while (true)
        {
            h *= 2;
            x1= x0 + h;
            f1 = f(x1);
            if (f0 > f1)
            {
                k++;
                x0 = x1;
                f0 = f1;
            }
            else
            {                
                x0 -= h/2;//Тут точно h/2 или я не так поняла??
                break;
            }
        }
        a = x0;
        b = x1;
        cout << x0 << " " << x1 << endl;

}
void fibonacci() {

}
int main()
{
    float x0;   
    cout << "Enter the initial value: " << endl<<"x0 = ";
    cin >> x0;
    interval_search(a, b, x0);
    dichotomy(a, b);
    golden_ratio(a, b);
}
