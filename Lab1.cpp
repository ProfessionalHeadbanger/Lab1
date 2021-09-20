#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;

const double eps = 1.0e-10;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    double A_x, A_y, B_x, B_y, C_x, C_y;
    cout << "Введите координаты трех точек на плоскости: " << endl;

    cout << "A_x: ";
    cin >> A_x;
    cout << "A_y: ";
    cin >> A_y;

    cout << "B_x: ";
    cin >> B_x;
    cout << "B_y: ";
    cin >> B_y;

    cout << "C_x: ";
    cin >> C_x;
    cout << "C_y: ";
    cin >> C_y;

    if (((C_x - A_x) / (B_x - A_x) == (C_y - A_y) / (B_y - A_y)) || ((A_x == B_x) && (B_x == C_x) && (C_x == A_x)) || ((A_y == B_y) && (B_y == C_y) && (C_y == A_y)))
    {
        cout << "Все три точки лежат на одной прямой" << endl;
        return 0;
    }

    double sideAB, sideBC, sideCA;
    sideAB = sqrt(pow(B_x - A_x, 2) + pow(B_y - A_y, 2));
    sideBC = sqrt(pow(C_x - B_x, 2) + pow(C_y - B_y, 2));
    sideCA = sqrt(pow(A_x - C_x, 2) + pow(A_y - C_y, 2));

    //cout << sideAB << " " << sideBC << " " << sideCA << endl;

    double cosA, cosB, cosC;
    cosA = (pow(sideAB, 2) + pow(sideCA, 2) - pow(sideBC, 2)) / (2 * sideAB * sideCA);
    cosB = (pow(sideBC, 2) + pow(sideAB, 2) - pow(sideCA, 2)) / (2 * sideBC * sideAB);
    cosC = (pow(sideCA, 2) + pow(sideBC, 2) - pow(sideAB, 2)) / (2 * sideCA * sideBC);

    //cout << cosA << " " << cosB << " " << cosC << endl;

    if ((((cosA - eps) <= 0) || ((cosB - eps) <= 0) || ((cosC - eps) <= 0)))
    {
        cout << "Треугольник не остроугольный" << endl;
        return 0;
    }

    if ((sideAB == sideBC) || (sideBC == sideCA) || (sideCA == sideAB))
    {
        cout << "Треугольник не разносторонний" << endl;
        return 0;
    }

    double half_p, heightAB, heightBC, heightCA;
    half_p = (sideAB + sideBC + sideCA) / 2;
    heightAB = (2 / sideAB) * sqrt(half_p * (half_p - sideAB) * (half_p - sideBC) * (half_p - sideCA));
    heightBC = (2 / sideBC) * sqrt(half_p * (half_p - sideAB) * (half_p - sideBC) * (half_p - sideCA));
    heightCA = (2 / sideCA) * sqrt(half_p * (half_p - sideAB) * (half_p - sideBC) * (half_p - sideCA));

    cout << "Высоты полученного треугольника: " << max(max(heightAB, heightBC), heightCA) << " ";
    if ((heightAB > heightBC) && (heightAB > heightCA))
    {
        cout << max(heightBC, heightCA) << " ";
    }
    if ((heightBC > heightAB) && (heightBC > heightCA))
    {
        cout << max(heightAB, heightCA) << " ";
    }
    if ((heightCA > heightBC) && (heightCA > heightAB))
    {
        cout << max(heightBC, heightAB) << " ";
    }
    cout << min(min(heightAB, heightBC), heightCA);
}
