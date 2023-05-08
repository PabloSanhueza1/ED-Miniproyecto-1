#include "Array.h"
#include "List.h"
#include "ListArr.h"

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int bArr[4] = {128, 256, 1024, 2048};

    // Experimento Array:
    for (int j = 0; j < 4; j++)
    {
        int b = bArr[j];
        n = 10000;

        cout << "--------- Experimento Array ---------" << endl << endl;
        Array array(b);
        while (n <= 80000)
        {
            cout << "n: " << n << endl;
            cout << "b: " << b << endl << endl;

            // insert_left
            auto start_time = chrono::high_resolution_clock::now();
            for (int i = 0; i < n; i++)
            {
                array.insert_left(i);
            }
            auto end_time = chrono::high_resolution_clock::now();
            auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
            cout << "Tiempo total: Array - insert_left: " << elapsed_time << " ms" << endl;

            double tiempo_promedio = static_cast<double>(elapsed_time) / n;
            cout << "Tiempo promedio: Array - insert_left: " << fixed << setprecision(6) << tiempo_promedio << " ms"
                 << endl
                 << endl;

            // insert_right
            start_time = chrono::high_resolution_clock::now();
            for (int i = 0; i < n; i++)
            {
                array.insert_right(i);
            }
            end_time = chrono::high_resolution_clock::now();
            elapsed_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
            cout << "Tiempo total: Array - insert_right: " << elapsed_time << " ms" << endl;

            tiempo_promedio = static_cast<double>(elapsed_time) / n;
            cout << "Tiempo promedio: Array - insert_right: " << fixed << setprecision(6) << tiempo_promedio << " ms"
                 << endl
                 << endl;

            // find
            start_time = chrono::high_resolution_clock::now();
            for (int i = 0; i < n; i++)
            {
                array.find(i);
            }
            end_time = chrono::high_resolution_clock::now();
            elapsed_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
            cout << "Tiempo total: Array - find: " << elapsed_time << " ms" << endl;

            tiempo_promedio = static_cast<double>(elapsed_time) / n;
            cout << "Tiempo promedio: Array - find: " << fixed << setprecision(6) << tiempo_promedio << " ms" << endl
                 << endl;
            n = n * 2;
        }
        array.~Array();
    }
    cout << endl << endl;

    // Experimento List:
    for (int j = 0; j < 4; j++)
    {
        int b = bArr[j];
        n = 10000;

        cout << "--------- Experimento List ---------" << endl << endl;
        List list;
        n = 10000;
        while (n <= 80000)
        {
            cout << "b: " << b << endl;
            cout << "n: " << n << endl << endl;

            // insert_left
            auto start_time = chrono::high_resolution_clock::now();
            for (int i = 0; i < n; i++)
            {
                list.insert_left(i);
            }
            auto end_time = chrono::high_resolution_clock::now();
            auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
            cout << "Tiempo total: List - insert_left: " << elapsed_time << " ms" << endl;
            cout << "Tiempo promedio: List - insert_left: " << elapsed_time / n << " ms" << endl << endl;

            // insert_right
            start_time = chrono::high_resolution_clock::now();
            for (int i = 0; i < n; i++)
            {
                list.insert_right(i);
            }
            end_time = chrono::high_resolution_clock::now();
            elapsed_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
            cout << "Tiempo total: List - insert_right: " << elapsed_time << " ms" << endl;
            cout << "Tiempo promedio: List - insert_left: " << elapsed_time / n << " ms" << endl << endl;

            start_time = chrono::high_resolution_clock::now();
            for (int i = 0; i < n; i++)
            {
                list.find(i);
            }
            end_time = chrono::high_resolution_clock::now();
            elapsed_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
            cout << "Tiempo total: List - find: " << elapsed_time << " ms" << endl;
            cout << "Tiempo promedio: List - insert_left: " << elapsed_time / n << " ms" << endl << endl;
            n = n * 2;
        }
        list.~List();
    }
    cout << endl;

    // Experimento ListArr:
    for (int j = 0; j < 4; j++)
    {
        int b = bArr[j];
        n = 10000;

        cout << "--------- Experimento ListArr ---------" << endl << endl;
        ListArr listArr(b);
        n = 10000;
        while (n <= 80000)
        {
            cout << "b: " << b << endl;
            cout << "n: " << n << endl << endl;
            // insert_left
            auto start_time = chrono::high_resolution_clock::now();
            for (int i = 0; i < n; i++)
            {
                listArr.insert_left(i);
            }
            auto end_time = chrono::high_resolution_clock::now();
            auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
            cout << "Tiempo total: ListArr - insert_left: " << elapsed_time << " ms" << endl;
            cout << "Tiempo promedio: ListArr - insert_left: " << elapsed_time / n << " ms" << endl << endl;

            // insert_right
            start_time = chrono::high_resolution_clock::now();
            for (int i = 0; i < n; i++)
            {
                listArr.insert_right(i);
            }
            end_time = chrono::high_resolution_clock::now();
            elapsed_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
            cout << "Tiempo total: ListArr - insert_right: " << elapsed_time << " ms" << endl;
            cout << "Tiempo promedio: ListArr - insert_left: " << elapsed_time / n << " ms" << endl << endl;

            start_time = chrono::high_resolution_clock::now();
            for (int i = 0; i < n; i++)
            {
                listArr.find(i);
            }
            end_time = chrono::high_resolution_clock::now();
            elapsed_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
            cout << "Tiempo total: ListArr - find: " << elapsed_time << " ms" << endl;
            cout << "Tiempo promedio: ListArr - insert_left: " << elapsed_time / n << " ms" << endl << endl;
            n = n * 2;
        }
        ListArr.~ListArr();
    }
    cout << endl;

    return 0;
}