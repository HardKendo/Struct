#include <iostream>

struct car
{
    float len;         //длина
    float klirens;     //высота посадки
    float V;           //объем двигателя
    float W;           //мощность двигателя
    float D;           //диаметр
    std::string color; //цвет
    bool type_c;       // тип коробки передач
};

car *arr;

int size = -1;

void input_arr()
{
    std::cout << "input size array...";

    std::cin >> size;

    if (size < 1)
        size = 1;

    arr = new car[size];

    for (int i = 0; i < size; i++)
    {
        std::cout << "Nomber " << i + 1 << ": " << std::endl;
        std::cout << "input length car..." << std::endl;
        std::cin >> arr[i].len;
        std::cout << "input klirens..." << std::endl;
        std::cin >> arr[i].klirens;
        std::cout << "input V ..." << std::endl;
        std::cin >> arr[i].V;
        std::cout << "input W..." << std::endl;
        std::cin >> arr[i].W;
        std::cout << "input Diamter..." << std::endl;
        std::cin >> arr[i].D;
        std::cout << "input color..." << std::endl;
        std::cin >> arr[i].color;
        std::cout << "input type_corob, 0 - autom, 1 - mexanika..." << std::endl;

        int type = 0;
        std::cin >> type;
        (type > 0) ? arr[i].type_c = true : arr[i].type_c = false;
    }
}

void prosmotr_record(int i)
{
    std::cout << "Nomber " << i + 1 << ": " << std::endl;
    std::cout << "length car..." << arr[i].len << std::endl;
    std::cout << "klirens..." << arr[i].klirens << std::endl;
    std::cout << "V ..." << arr[i].V << std::endl;
    std::cout << "W..." << arr[i].W << std::endl;
    std::cout << "Diamter..." << arr[i].D << std::endl;
    std::cout << "color..." << arr[i].color << std::endl;
    std::cout << "korobka - ";
    (arr[i].type_c) ? std::cout << "mexanika" : std::cout << "automatika" << std::endl;
    std::cout << std::endl
              << std::endl;
}

void output_arr()
{
    if (size < 0)
        std::cout << "Array is not input!" << std::endl;
    else
        for (int i = 0; i < size; i++)
            prosmotr_record(i);
}

int search() // поиск и вывод всех машин по объему двигателя
{

    if (size <= 0)
        std::cout << "Array is not input!" << std::endl;
    else
    {

        int menu_s;
        std::cout << "Input param to search..." << std::endl;
        std::cout << "1 - length..." << std::endl;
        std::cout << "2 - klirens..." << std::endl;
        std::cout << "3 - V dvigatel..." << std::endl;
        std::cout << "4 - W..." << std::endl;
        std::cout << "5 - Diametr..." << std::endl;
        std::cout << "6 - types corobka ..." << std::endl;
        std::cout << "7 - color..." << std::endl;

        std::cin >> menu_s;

        if (menu_s != 6)

            std::cout << "Input obrazec dlya poiska..." << std::endl;
        else

            std::cout << "<= 0 - automat, >=1 - mehanika ..." << std::endl;

        float obr;
        std::string obr_color;

        if (menu_s <= 6)
            std::cin >> obr;

        else
            std::cin >> obr_color;

        int count_s = 0;

        for (int i = 0; i < size; i++)
        {

            float temp;
            std::string temp_color;

            switch (menu_s)
            {

            case 1:
            {
                temp = arr[i].len;
                break;
            }
            case 2:
            {
                temp = arr[i].klirens;
                break;
            }
            case 3:
            {
                temp = arr[i].V;
                break;
            }
            case 4:
            {
                temp = arr[i].W;
                break;
            }
            case 5:
            {
                temp = arr[i].D;
                break;
            }
            case 6:
            {
                temp = arr[i].type_c;
                break;
            }
            case 7:
            {
                temp_color = arr[i].color;
                break;
            }
            }

            if (menu_s <= 6)
            {
                if (temp == obr)
                {
                    prosmotr_record(i);
                    count_s++;
                }
            }
            else
            {

                if (temp_color == obr_color)
                {
                    prosmotr_record(i);
                    count_s++;
                }
            }
        }

        return count_s;
    }
    return 0;
}

int main()
{

    bool ok = true;
    short menu = -1;

    do
    {

        std::cout << "MENU" << std::endl;
        std::cout << "1 - input array;" << std::endl;
        std::cout << "2 - output array;" << std::endl;
        std::cout << "3 - search array;" << std::endl;
        std::cout << "any key - exit." << std::endl;
        std::cout << "Press menu key...";
        std::cin >> menu;

        switch (menu)
        {
        case 1:
            input_arr();

            break;

        case 2:
            output_arr();

            break;

        case 3:
        {

            int count = search();
            (count == -1) ? std::cout << "record is not search!" << std::endl : (size < 0) ? std::cout << "Error search!" << std::endl : std::cout << "record search count: " << count << std::endl;
            break;
        }

        default:
            ok = false;
            break;
        }

        if (menu <= 3 && menu >= 1)
        {
            std::string ext;
            std::cout << "OK! Press any key!";
            std::cin >> ext;
        }

    } while (ok);

    std::cout << "DONE!";

    return 0;
}