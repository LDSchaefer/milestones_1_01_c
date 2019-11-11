#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Field {
public:
    int a;
    int b;
    int *arr;
    int size;
    int *old_arr;


    int *val(int rows, int cols)
    {
        int *new_arr;
        std::cout << "Anzahl Zeilen:" << std::endl;
        std::cin >> rows;
        a = rows;
        std::cout << "Anzahl Spalten:" << std::endl;
        std::cin >> cols;
        b = cols;
        new_arr = size_arr(rows, cols);
        return arr = new_arr;
    }


    int print(int a,int b, int *arr)
    {
        std::cout << "Aktueller Zustand der Matrix:" << std::endl;
        for(int i=0; i<a; i++)
           {
               for(int j=0; j<b; j++)
               {
                   std::cout << arr[i * size + j];
               }
               std::cout << "" << std::endl;
           }
        return 0;
    }


    int *size_arr(int arg1,int arg2)
    {
        size = arg1;
        int r;
        int *tem_arr = new int[arg1 * arg2];
        for(int i=0; i<a; i++)
           {
               for(int j=0; j<b; j++)
               {
                   r = 0;
                   tem_arr[i * size + j] = r;
               }
           }
        tem_arr[0 * size + 0] = 1;
        tem_arr[1 * size + 0] = 1;
        tem_arr[2 * size + 0] = 1;
        tem_arr[0 * size + 2] = 1;
        tem_arr[0 * size + 3] = 1;
        tem_arr[1 * size + 3] = 1;
        tem_arr[2 * size + 3] = 1;
        tem_arr[2 * size + 2] = 1;
        tem_arr[3 * size + 3] = 1;
        tem_arr[3 * size + 2] = 1;
        tem_arr[3 * size + 4] = 1;
        tem_arr[9 * size + 9] = 1;
        return tem_arr;
    }


    int *copy_array()
    {
        int *temp_arr = arr;
        arr = old_arr;
        old_arr = temp_arr;
        return arr;
    }


    int *change(int *arr)
            {
                int rows, cols, stat;
                std::cout << "Geben sie an welches Feld sie Ansteuern moechten." << std::endl;
                std::cout << "Zeile:" << std::endl;
                std::cin >> rows;
                std::cout << "Spalte:" << std::endl;
                std::cin >> cols;
                std::cout << "Zustand der Zelle? (0 = Tod, 1 = Lebened)" << std::endl;
                std::cin >> stat;
                arr[(rows-1) * size + (cols-1)] = stat;
                return old_arr=arr;
            }


    int *evo()
    {
        int k_temp;
        int l_temp;
        int count = 0;
        for(int i=0; i<a; i++)
        {
            for(int j = 0; j<b; j++)
            {
                for(int k=i-1; k<=i+1; k++)
                {
                    for(int l=j-1; l<=j+1; l++)
                    {
                     if(k==l)
                     {
                         continue;
                     }
                     else
                     {
                         k_temp = k;
                         l_temp = l;
                      if(k<0)
                     {
                         k_temp = k + a;

                     }
                      if(l<0)
                     {
                         l_temp = l + b;

                     }
                      if(k>a)
                     {
                         k_temp = k - a;

                     }
                      if(l>b)
                     {
                         l_temp = l - b;

                     }
                      if(arr[k_temp * size + l_temp] == 1)
                      {
                          count++;
                      }
                     }
                    }
                }

                if(arr[i * size + j] == 1 and count<=1)
                {
                    old_arr[i * size + j] = 0;
                }
                if(arr[i * size + j] == 1 and (count== 2 or count==3))
                {
                    old_arr[i * size + j] = 1;
                }
                if(arr[i * size + j] == 1 and count>=4)
                {
                    old_arr[i * size + j] = 0;
                }
                if(arr[i * size + j] == 0 and count==3)
                {
                    old_arr[i * size + j] = 1;
                }
                count = 0;
            }
        }
        return arr;
    }
    int u_control()
    {
        int frage;
        print(a, b, arr);
        std::cout << "Moechten sie die Zeilen-/Spaltenanzahl des Feldes aendern? ( [1] = ja, [2] = nein)" << std::endl;
        std::cin >> frage;
        if(frage == 1)
        {
        val(a, b);
        print(a, b, arr);
        }

        std::cout << "Moechten sie den Zustand einer Zelle aendern? ( [1] = ja, [2] = nein)" << std::endl;
        std::cin >> frage;
        while(frage == 1)
        {
        change(arr);
        print(a, b, arr);
        std::cout << "Moechten sie den Zustand einer Zelle aendern? ( [1] = ja, [2] = nein)" << std::endl;
        std::cin >> frage;
        }
        std::cout << "Moechten sie einen evolutions Schritt vollziehen? ( [1] = ja, [2] = nein)" << std::endl;
        std::cin >> frage;
        while(frage == 1)
        {
            evo();
            print(a, b, old_arr);
            std::cout << "Moechten sie einen evolutions Schritt vollziehen? ( [1] = ja, [2] = nein)" << std::endl;
            std::cin >> frage;
        }
        return 0;
    }






    Field(int arg1,int arg2)
    {
        a=arg1;
        b=arg2;
        arr = size_arr(arg1, arg2);
        old_arr = size_arr(arg1, arg2);
        //u_control();
    }
};

int to_int(std::string str)
{
    std::stringstream val(str);
    int x = 0;
    val>>x;
    return x;
}

int main()
{
    Field f(10,10);
    std::ifstream data("beispieldatei_cellularautomaton.txt");
    std::string colum;
    int count=0;
    while(std::getline(data, colum))
    {
        int col = to_int(colum);
        count++;
        if(colum.size()==2 and count == 1)
        {
            f.a = to_int(colum);
            continue;
        }
        if(colum.size()==2 and count == 2)
        {
            f.b = to_int(colum);
            continue;
        }
        f.size_arr(f.a,f.b);
        for(int i=0; i<col; i++)
        {
            if(colum[i] == 'o')
            {
                f.arr[col * f.size + i] = 0;
            }
            else if(colum[i] == '*')
            {
                f.arr[col * f.size + i] = 1;
            }
        }
    }


//    f.copy_array();
//    f.evo();
//    std::cout<<"Evolutionsschritt"<<std::endl;
//    f.print(f.a, f.b, f.arr);
//    f.print(f.a, f.b, f.old_arr);

    f.print(f.a,f.b,f.arr);
    return 0;
}




//  std::cout << f.old_arr << "\t" << f.arr << std::endl;
