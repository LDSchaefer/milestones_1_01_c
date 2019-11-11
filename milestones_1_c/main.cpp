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
        //tem_arr[0 * size + 0] = 1;
        //tem_arr[1 * size + 0] = 1;
        //tem_arr[2 * size + 0] = 1;
        //tem_arr[0 * size + 2] = 1;
        //tem_arr[0 * size + 3] = 1;
        //tem_arr[1 * size + 3] = 1;
        //tem_arr[2 * size + 3] = 1;
        //tem_arr[2 * size + 2] = 1;
        //tem_arr[3 * size + 3] = 1;
        //tem_arr[3 * size + 2] = 1;
        //tem_arr[3 * size + 4] = 1;
        //tem_arr[9 * size + 9] = 1;
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
        std::cout << "Moechten sie einen Datei importieren? ( [1] = ja, [2] = nein)" << std::endl;
        std::cin >> frage;
        if(frage == 1)
        {
            std::string path;
            std::cout <<"Geben sie den Datei pfad ein: " <<std::endl;
            std::cin >> path;
            import(path);
            std::cout << "Moechten sie einen evolutions Schritt vollziehen? ( [1] = ja, [2] = nein)" << std::endl;
            std::cin >> frage;
        }
        std::cout <<"Möchten sie das Programm verlassen?( [1] = ja, [2] = nein)"<<std::endl;
        std::cin >> frage;
        if(frage == 1)
        {
        exit(0);
        }
        u_control();
        return 0;
    }
    int to_int(std::string str)
    {
        std::stringstream val(str);
        int x = 0;
        val>>x;
        return x;
    }
    int import(std::string i_path){
        std::ifstream data(i_path);
        std::string colum;
        int count=0;
        std::getline(data, colum);
        int col = to_int(colum);
        a = col;
        std::getline(data, colum);
        int row = to_int(colum);
        b = row;
        arr = size_arr(a,b);
        count = 2;
        for(size_t zeile = 0; std::getline(data, colum); ++zeile){
            for(size_t columnindex = 0; columnindex < col; ++columnindex)
            {
                const char & x = colum[columnindex];

                if(x == 'o')
                {
                    arr[zeile*size + columnindex] = 0;
                }
                if(x == '*')
                {
                    arr[zeile*size + columnindex] = 1;
                }
            }
        }
        print(a,b,arr);
        return 0;
    }





    Field(int arg1,int arg2)
    {
        a=arg1;
        b=arg2;
        arr = size_arr(arg1, arg2);
        old_arr = size_arr(arg1, arg2);
        u_control();
    }
};



int main()
{
    Field f(10,10);

//    std::ofstream outp;
//    outp.open("output.txt");
//    outp<< f.a;
//    outp<< f.b;

    return 0;
}
