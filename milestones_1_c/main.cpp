#include <iostream>

    class Field {
    public:
        int a;
        int b;
        int r;
        int *arr;
        int size;
        int *old_arr;


        int *val(int rows,int cols)
        {
            int *new_arr;
            std::cout << "Anzahl Zeilen:" << std::endl;
            std::cin >> rows;
            a = rows;
            std::cout << "Anzahl Spalten:" << std::endl;
            std::cin >> cols;
            b = cols;
            new_arr = size_arr(rows,cols);
            init_arr(rows,cols,new_arr);
            return arr = new_arr;
        }


        int init_arr(int a,int b, int *arr)
        {
            for(int i=0; i<a; i++)
               {
                   for(int j=0; j<b; j++)
                   {
                       r = 0;
                       arr[i * size + j] = r;
                   }
               }
            return 0;
        }
        int print(int a,int b, int *arr)
        {
            std::cout<< "Aktueller Zustand der Matrix:"<<std::endl;
            for(int i=0; i<a; i++)
               {
                   for(int j=0; j<b; j++)
                   {
                       std::cout << arr[i * size + j];
                   }
                   std::cout<< "" <<std::endl;
               }
            return 0;
        }


        int *size_arr(int arg1,int arg2){
            size = arg1;
            arr = new int[arg1 * arg2];
            return arr;
        }

        int *copy_array(int *arr)
        {
            return old_arr=arr;
        }
        int *change(int *arr)
                {
                    int rows,cols,stat;
                    std::cout << "Geben sie an welches Feld sie Ansteuern möchten."<< std::endl;
                    std::cout << "Zeile"<< std::endl;
                    std::cin >> rows;
                    std::cout << "Spalte"<< std::endl;
                    std::cin >> cols;
                    std::cout << "Zustand der Zelle?(0=Tod, 1= Lebened)" << std::endl;
                    std::cin >> stat;
                    arr[rows * size + cols] = stat;
                    return old_arr=arr;
                }
        int *evo(int *arr)
        {
            int k_temp;
            int l_temp;
            int count = 0;

            for(int i=0; i<a;i++)
            {
                for(int j = 0; j<b;j++)
                {
                    for(int k=i-1;k<=i+1; k++)
                    {
                        for(int l=j-1;l<=j+1; l++)
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
                        arr[i * size + j] = 0;
                    }
                    if(arr[i * size + j] == 1 and(count== 2 or count==3))
                    {
                        arr[i * size + j] = 1;
                    }
                    if(arr[i * size + j] == 1 and count>=4)
                    {
                        arr[i * size + j] = 0;
                    }
                    if(arr[i * size + j] == 0 and count==3)
                    {
                        arr[i * size + j] = 1;
                    }
                    count = 0;
                }
            }
            copy_array(arr);
            return arr;
        }


        Field(int arg1=10,int arg2=10){
            a=arg1;
            b=arg2;
            arr = size_arr(arg1, arg2);
            init_arr(a,b,arr);
        }
    };


    int main()
    {
        Field f(30,30);
        f.print(f.a, f.b, f.arr);
        f.val(f.a, f.b);
        f.print(f.a, f.b, f.arr);
        f.copy_array(f.arr);
        f.print(f.a,f.b,f.old_arr);
        f.change(f.arr);
        f.print(f.a,f.b,f.old_arr);
      return 0;
    }





