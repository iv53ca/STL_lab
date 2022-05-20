#include <iostream>
#include "subvector_class.h"
#include "forward_list"
#include "subforwardlist_class.h"
#include <random>
#include <chrono>
#include <algorithm>
#include <vector>
#include <fstream>
#include <list>
#include <map>
#include <set>
using namespace std;

double get_time()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()/1e6;
}

int rand_uns(int min, int max)
{
        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        static std::default_random_engine e(seed);
        std::uniform_int_distribution<int> d(min, max);
        return d(e);
}
//int 7 задания
int main() {
    subvector_class<int> sv;
    vector<int> vect;
    subforwardlist<int> sfl;
    forward_list<int> fl;
    list<int> m;
    map<int, int> q;
    set<int> l;
    int n = 100, ind, val, tmp;
    unsigned sz;
    double start = 0, finish = 0, total = 0;
    ofstream fll("fl.txt");
    ofstream vecc("vec.txt");
    ofstream mapp("mapp.txt");
    ofstream sett("sett.txt");
    double s = 0;
    while (n < 100000) {
        for (int i = 0; i < 100; i++) { // На каждую итерацию добавляем по 100 элементов
            val = rand_uns(0, 10000);
            fl.push_front(val);
        }
        for (int i = 0; i < 100; i++) { // На каждую итерацию добавляем по 100 элементов
            val = rand_uns(0, 10000);
            m.push_back(val);
        }
        for (int i = 0; i < 100; i++) { // На каждую итерацию добавляем по 100 элементов
            val = rand_uns(0, 10000);
            l.insert(n+i);
        }
        for (int i = 0; i < 100; i++) { // На каждую итерацию добавляем по 100 элементов
            val = rand_uns(0, 10000);
            vect.push_back(val);
        }
        double s1 = 0, s2 = 0, c1 = 0, c2 = 0, s3=0, s4=0, c3=0, c4=0;
        sz = n;
        for (int i = 0; i < 2; i++) { // Для каждого размера будем проводить несколько измерений и потом усредним
            //ind = rand_uns(0, sz - 1); // Генерируем случайный индекс
            //val = rand_uns(0, 10000);
            start = get_time();
            for (auto &el : fl)
                el++;
            finish = get_time();
            total = finish - start;
            c1++; // количество раз
            s1 += total; // суммарное время

            start = get_time();
            for(int i = 0; i<n; i++){
                vect[i]++;
            }
            finish = get_time();
            total = finish - start;
            c2++; // количество раз
            s2 += total; // суммарное время

            start = get_time();
            for (auto &el : m)
                el++;
            finish = get_time();
            total = finish - start;
            c3++; // количество раз
            s3 += total; // суммарное время

            unsigned long long sum =0;
            set <int> :: iterator it = l.begin();
            start = get_time();
            while(it!=l.end()){
                sum+=*it;
                it++;
            }
            finish = get_time();
            total = finish - start;
            c4++; // количество раз
            s4 += total; // суммарное время

        }
        fll << n << ' ' << s1 / c1 << endl;
        vecc << n << ' ' << s2 / c2 << endl;
        mapp << n << ' ' << s3 / c3 << endl;
        sett << n << ' ' << s4 / c4 << endl;
        n += 100; // Увеличиваем размер на 500
    }

    return 0;
}


/*
 int для 1 задания
 int main() {
    subvector_class<int> sv;
    vector<int> vect;
    subforwardlist<int> sfl;
    forward_list<int> fl;
    list<int> m;
    map<int, int> q;
    set<int> l;
    int n = 1, ind, val, tmp;
    unsigned sz;
    double start = 0, finish = 0, total = 0;
    ofstream f("data_vect.txt");
    ofstream h("data_my.txt");
    double s = 0;
    while (n <= 100000) {
        val = rand_uns(0, 100000);
        vect.push_back(val);
        sv.push_back(val);
        sz = vect.size();
        f << vect.capacity()<<' '<<vect.size() << endl; // в файл f записываем cap & size  STL
        h << sv.capacity<<' '<< n << endl; // в файл р записываем cap & size  subvector
        n++;
    }
return 0;
}
 */




/* int для 2 задания
 int main() {
    subvector_class<int> sv;
    vector<int> vect;
    subforwardlist<int> sfl;
    forward_list<int> fl;
    list<int> m;
    map<int, int> q;
    set<int> l;
    int n = 100, ind, val, tmp;
    unsigned sz;
    double start = 0, finish = 0, total = 0;
    ofstream f("data_my.txt");
    ofstream h("data_vect.txt");
    double s = 0;
    while (n <= 100000) {
        for (int i = 0; i < 100; i++) { // На каждую итерацию добавляем по 100 элементов
            val = rand_uns(0, 10000);
            vect.push_back(val); //
            sv.push_back(val);
        }
        double s1 = 0, s2 = 0, c1 = 0, c2 = 0;
        sz = vect.size();
        for (int i = 0; i < 10000; i++) { // Для каждого размера будем проводить несколько измерений и потом усредним
            ind = rand_uns(0, sz - 1); // Генерируем случайный индекс
            val = rand_uns(0, 100000);
            auto it1 = vect.begin() + ind; // Итератор на сгенерированный индекс
            auto it = vect.begin(); // Итератор на добавляющий индекс
            start = get_time();
            vect.insert(it1,val); // добавление
            finish = get_time();
            total = finish - start;
            c1++; // количество раз
            s1 += total; // суммарное время

            start = get_time();
            sv.insert(val,ind); // добавление
            finish = get_time();
            total = finish - start;
            c2++; // количество раз
            s2 += total; // суммарное время

            vect.erase(it); // 1 элемент добавили, удаляем случайный, чтобы размер не изменился
            sv.erase(1);

        }
        f << n << ' ' << s1 / c1 << endl; // в файл f записываем среднее время удаления для данного размера  STL
        h << n << ' ' << s2 / c2 << endl; // в файл р записываем среднее время удаления для данного размера  subvector
        n += 100; // Увеличиваем размер на 500
    }

return 0;
}*/




/*int для 3 задания
 * int main() {
    subvector_class<int> sv;
    vector<int> vect;
    subforwardlist<int> sfl;
    forward_list<int> fl;
    list<int> m;
    map<int, int> q;
    set<int> l;
    int n = 100, ind, val, tmp;
    unsigned sz;
    double start = 0, finish = 0, total = 0;
    ofstream f("data_my.txt");
    ofstream h("data_vect.txt");
    double s = 0;
    while (n <= 200000) {
        for (int i = 0; i < 100; i++) { // На каждую итерацию добавляем по 500 элементов
            val = rand_uns(0, 10000);
            vect.push_back(val); //
            sv.push_back(val);
        }
        double s1 = 0, s2 = 0, c1 = 0, c2 = 0;
        sz = vect.size();
        for (int i = 0; i < 10000; i++) { // Для каждого размера будем проводить несколько измерений и потом усредним
            ind = rand_uns(0, sz - 1); // Генерируем случайный индекс
            val = rand_uns(0, 100000);
            auto it1 = vect.begin() + ind; // Итератор на сгенерированный индекс
            start = get_time();
            vect.erase(it1); // Удаление из вектора
            finish = get_time();
            total = finish - start;
            c1++; // количество раз
            s1 += total; // суммарное время

            start = get_time();
            sv.erase(ind); // Удаление из рукописаного вектора
            finish = get_time();
            total = finish - start;
            c2++; // количество раз
            s2 += total; // суммарное время

            vect.push_back(val); // 1 элемент удалили, добавляем случайный, чтобы размер не изменился
            sv.push_back(val);

        }
        f << n << ' ' << s1 / c1 << endl; // в файл f записываем среднее время удаления для данного размера  STL
        h << n << ' ' << s2 / c2 << endl; // в файл р записываем среднее время удаления для данного размера  subvector
        n += 100; // Увеличиваем размер на 500
    }

return 0;
}*/




/*int для 4 задания
 int main() {
    subvector_class<int> sv;
    vector<int> vect;
    subforwardlist<int> sfl;
    forward_list<int> fl;
    list<int> m;
    map<int, int> q;
    set<int> l;
    int n = 100, ind, val, tmp;
    unsigned sz;
    double start = 0, finish = 0, total = 0;
    ofstream f("data_my.txt");
    ofstream h("data_vect.txt");
    double s = 0;
    while (n <= 100000) {
        for (int i = 0; i < 100; i++) { // На каждую итерацию добавляем по 500 элементов
            val = rand_uns(0, 10000);
            vect.push_back(val); //
            sv.push_back(val);
        }
        double s1 = 0, s2 = 0, c1 = 0, c2 = 0;
        sz = vect.size();
        for (int i = 0; i < 10000; i++) { // Для каждого размера будем проводить несколько измерений и потом усредним
            ind = rand_uns(0, sz - 1); // Генерируем случайный индекс
            start = get_time();
            vect[ind]++;
            finish = get_time();
            total = finish - start;
            c1++; // количество раз
            s1 += total; // суммарное время

            start = get_time();
            sv[ind]++;
            finish = get_time();
            total = finish - start;
            c2++; // количество раз
            s2 += total; // суммарное время


        }
        f << n << ' ' << s1 / c1 << endl; // в файл f записываем среднее время удаления для данного размера  STL
        h << n << ' ' << s2 / c2 << endl; // в файл р записываем среднее время удаления для данного размера  subvector
        n += 100; // Увеличиваем размер на 500
    }

    return 0;
}*/



/* int на 5 задание
 int main() {
    subvector_class<int> sv;
    vector<int> vect;
    subforwardlist<int> sfl;
    forward_list<int> fl;
    list<int> m;
    map<int, int> q;
    set<int> l;
    int n = 100, ind, val, tmp;
    unsigned sz;
    double start = 0, finish = 0, total = 0;
    ofstream f("data_my.txt");
    ofstream h("data_vect.txt");
    double s = 0;
    while (n <= 100000) {
        for (int i = 0; i < 100; i++) { // На каждую итерацию добавляем по 100 элементов
            val = rand_uns(0, 10000);
            vect.push_back(val); //
            sv.push_back(val);
        }
        double s1 = 0, s2 = 0, c1 = 0, c2 = 0;
        sz = n;
        for (int i = 0; i < 10000; i++) { // Для каждого размера будем проводить несколько измерений и потом усредним
            ind = rand_uns(0, sz - 1); // Генерируем случайный индекс
            val = rand_uns(0, 10000);
            start = get_time();
            fl.push_front(val);
            finish = get_time();
            total = finish - start;
            c1++; // количество раз
            s1 += total; // суммарное время

            start = get_time();
            sfl.push_forward(val);
            finish = get_time();
            total = finish - start;
            c2++; // количество раз
            s2 += total; // суммарное время


        }
        f << n << ' ' << s1 / c1 << endl; // в файл f записываем среднее время удаления для данного размера  STL
        h << n << ' ' << s2 / c2 << endl; // в файл р записываем среднее время удаления для данного размера  subvector
        fl.pop_front();
        sfl.pop_forward();//удаляем чтоб n не увеличивалось
        n += 100; // Увеличиваем размер на 500
    }

    return 0;
}*/



/* int к 6 заданию
 int main() {
    subvector_class<int> sv;
    vector<int> vect;
    subforwardlist<int> sfl;
    forward_list<int> fl;
    list<int> m;
    map<int, int> q;
    set<int> l;
    int n = 100, ind, val, tmp;
    unsigned sz;
    double start = 0, finish = 0, total = 0;
    ofstream f("data_my.txt");
    ofstream h("data_vect.txt");
    double s = 0;
    while (n <= 100000) {
        for (int i = 0; i < 100; i++) { // На каждую итерацию добавляем по 100 элементов
            val = rand_uns(0, 10000);
            fl.push_front(val); //
            sfl.push_forward(val);
        }
        double s1 = 0, s2 = 0, c1 = 0, c2 = 0;
        sz = n;
        for (int i = 0; i < 10000; i++) { // Для каждого размера будем проводить несколько измерений и потом усредним
            //ind = rand_uns(0, sz - 1); // Генерируем случайный индекс
            //val = rand_uns(0, 10000);
            start = get_time();
            fl.pop_front();
            finish = get_time();
            total = finish - start;
            c1++; // количество раз
            s1 += total; // суммарное время

            start = get_time();
            sfl.pop_forward();
            finish = get_time();
            total = finish - start;
            c2++; // количество раз
            s2 += total; // суммарное время

            fl.push_front(1);
            sfl.push_forward(1);//добавляем чтоб n не уменьшилось

        }
        f << n << ' ' << s1 / c1 << endl; // в файл f записываем среднее время удаления для данного размера  STL
        h << n << ' ' << s2 / c2 << endl; // в файл р записываем среднее время удаления для данного размера  subvector
        n += 100; // Увеличиваем размер на 500
    }

    return 0;
}
*/
