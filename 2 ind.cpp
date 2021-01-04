///2 индивидуальное, 11 вариант

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Staff
{
    char name[20];
    char surname[20];
    char patronymic[20];
    int personnel_number;
    int hours;
    int rate;
    float wage;
};

void filling_the_arr (Staff* array_of_struct, int n);
void array_padding(Staff *&array_of_struct,int &size1);
void delete_srtuct (Staff *&array_of_struct, int &size1);
void change_struct (Staff* array_of_struct, int size1);
void output(string str);

int main()
{
    int N;
    cout << "Enter the number of employees: ";
    cin >> N;

    Staff* array_of_struct = new Staff[N];

    string str = "File8lab.txt";
    string str2 = "Fileend8lab.txt";
    ofstream infile;

    filling_the_arr (array_of_struct, N);
    //array_padding(array_of_struct, N);
    //delete_srtuct (array_of_struct, N);
    //change_struct (array_of_struct, N);

    infile.open(str);

    if (!infile.is_open())
    {
        cout << "Error";
    } else
    {
        for (int i = 0; i < N; i++)
        {
            if (i == N - 1)
            {
                infile << array_of_struct[i].hours << "\n";
                infile << array_of_struct[i].rate;
            } else
            {   infile << array_of_struct[i].hours << "\n";
                infile << array_of_struct[i].rate << "\n";
            }
        }
    }
    infile.close();

    cout << endl;

    ifstream fromfile;
    fromfile.open(str);

    if(!fromfile.is_open())
    {
        cout << "Error";
    } else
    {
        int a;
        int b;
        int k = 0;
        int i = 1;
        while (!fromfile.eof())
        {
            if (i % 2 != 0)
            {
                fromfile >> a; //если строка нечётная, значит в ней хранятся данные о часах за месяц
            } else             //если четная, то о тарифе
            {
                fromfile >> b;
                if (a > 144)
                {
                   array_of_struct[k].wage = 144 * b + (a - 144) * 2 * b;
                   array_of_struct[k].wage = array_of_struct[k].wage - array_of_struct[k].wage * 0.12;
                   k++;
                } else
                {
                   array_of_struct[k].wage = a * b;
                   array_of_struct[i].wage = array_of_struct[k].wage - array_of_struct[k].wage * 0.12;
                   k++;
                }

            }
            i++;
        }
    }
    fromfile.close();

    infile.open(str2);

    if (!infile.is_open())
    {
        cout << "Error";
    } else
    {
        for (int i = 0; i < N; i++)
        {
            infile << "Name: " << array_of_struct[i].name << "\n";
            infile << "Surname: " << array_of_struct[i].surname << "\n";
            infile << "Patronymic: " << array_of_struct[i].patronymic << "\n";
            infile << "Personnel number: " << array_of_struct[i].personnel_number << "\n";
            infile << "Hours per month: " << array_of_struct[i].hours << "\n";
            infile << "Rate: " << array_of_struct[i].rate << "\n";
            infile << "Wage: " << array_of_struct[i].wage << "\n";
            infile << "\n";
        }
    }
    infile.close();

    output(str2);



    delete [] array_of_struct;
    array_of_struct = nullptr;
    return 0;
}


void filling_the_arr (Staff* array_of_struct, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Name: ";
        cin >> array_of_struct[i].name;

        cout << "Surname: ";
        cin >> array_of_struct[i].surname;

        cout << "Patronymic: ";
        cin >> array_of_struct[i].patronymic;

        cout << "Personnel number: ";
        cin >> array_of_struct[i].personnel_number;

        cout << "Hours per month: ";
        cin >> array_of_struct[i].hours;

        cout << "Rate: ";
        cin >> array_of_struct[i].rate;

        cout << endl;
    }
}

void array_padding(Staff *&array_of_struct,int &size1)
{
    int k;
    cout << "How many new employees? ";
    cin >> k;

    Staff* arrdop_or_struct = new Staff[k];
    cout << "\n";
    filling_the_arr(arrdop_or_struct, k);

    Staff* newarr_or_struct = new Staff[size1 + k];

    int i;
    for (i = 0; i < size1; i++)
    {
        newarr_or_struct[i] = array_of_struct[i];
    }


    int m;
    for(i = size1, m = 0; i < size1+k, m < k; i++, m++)
    {
        newarr_or_struct[i] = arrdop_or_struct[m];
    }
    size1 += k;
    delete [] array_of_struct;
    array_of_struct = newarr_or_struct;
    delete [] arrdop_or_struct;
    arrdop_or_struct = nullptr;

}

void delete_srtuct (Staff *&array_of_struct, int &size1)
{
    cout << "How many employees have quit? ";
    int del;
    cin >> del;
    int* array_numb = new int [del];
    cout << "\n";
    cout << "Their numbers on the list: ";
    cout << "\n";
    for(int i = 0; i < del; i++)
    {
        cin >> array_numb[i];
    }

    Staff* newarr_or_struct = new Staff[size1 - del];

    int k = 0;
    int s = 0;
    int l = 0;
    while (s < size1)
    {
        if (s == array_numb[l]-1)
        {
            s++;
            l++;
        } else
        {
            newarr_or_struct[k] = array_of_struct[s];
            k++;
            s++;
        }
    }

    size1 = size1 - del;

    delete [] array_of_struct;
    array_of_struct = newarr_or_struct;
    delete [] array_numb;
    array_numb = nullptr;
}

void change_struct (Staff* array_of_struct, int size1)
{
    cout << "How many statements do you want to change? ";
    int change;
    cin >> change;
    int* array_numb = new int [change];
    cout << "\n";
    cout << "Their numbers on the list: ";
    cout << "\n";
    for(int i = 0; i < change; i++)
    {
        cin >> array_numb[i];
    }

    Staff* newarr_or_struct = new Staff[change];

    cout << "Make changes: ";
    cout << "\n";
    filling_the_arr (newarr_or_struct, change);

    int l = 0;
    int k = 0;
    for(int i = 0; i < size1; i++)
    {
        if (i == array_numb[l]-1)
        {
            array_of_struct[i] = newarr_or_struct[k];
            l++;
            k++;
        }
    }

    delete [] newarr_or_struct;
    newarr_or_struct = nullptr;
    delete [] array_numb;
    array_numb = nullptr;
}

void output(string str)
{
    ifstream fromfile;

    fromfile.open(str);

    cout << "Result:" << endl;
    if(!fromfile.is_open())
    {
        cout << "Error";
    } else
    {
        string s;
        while(!fromfile.eof())
        {
            s = "";
            getline(fromfile, s);
            cout << s << endl;
        }
    }
    fromfile.close();
}
