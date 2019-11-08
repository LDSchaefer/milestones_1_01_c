#include <iostream>

    class Field {
    public:
        int a;
        int b;
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
            return arr = new_arr;
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
        int *evo()
        {
            int k_temp;
            int l_temp;
            int count = 0;
            arr[5 * size + 5] = 1;
            arr[6 * size + 5] = 1;
            arr[5 * size + 6] = 1;
            arr[6 * size + 6] = 1;
            arr[7 * size + 6] = 1;
            arr[7 * size + 5] = 1;

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
                        old_arr[i * size + j] = 0;
                    }
                    if(arr[i * size + j] == 1 and(count== 2 or count==3))
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
            std::cout<<old_arr<<"\t"<<arr<<std::endl;
            return arr;
        }


        Field(int arg1=10,int arg2=10){
            a=arg1;
            b=arg2;
            arr = size_arr(arg1, arg2);
            old_arr = size_arr(arg1, arg2);

        }
    };


    int main()
    {
        Field f(10,10);
        f.print(f.a, f.b, f.arr);
        //f.copy_array();
                        std::cout<<f.old_arr<<"\t"<<f.arr<<std::endl;
        f.evo();
        std::cout<<"Evolutionsschritt"<<std::endl;
        f.print(f.a, f.b, f.arr);
        f.print(f.a, f.b, f.old_arr);
      return 0;
    }





