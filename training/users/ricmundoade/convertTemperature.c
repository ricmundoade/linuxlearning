 #include <stdio.h> 
/*#include <ncurses.h> */

int main()
{
   int grados = -100;
   int opcion = 0;
   float resultado = 0;
   system("clear");
   reinicio:
   
   printf("\n\n\n\nIntroduce opcion deseada: 1-Celsius a Farenheit 2-Farenheit a Celsius : ");
   scanf("%d", &opcion);
   if(opcion == 1)
   {
      printf("\n\n Introduce temperatura en grados celsius : ");
      scanf("%d", &grados);
      resultado = grados * 1.8 + 32;
      printf(" %d grados Celsius es ", grados);
      printf("  %f grados Farenheit", resultado);
   }
   else
      if(opcion == 2)      
      {
        printf("\n\n Introduce temperatura en grados Farenheit :  ");
        scanf("%d", &grados);
        resultado = (grados - 32) / 1.8;
        printf("\n %d grados Farenheit es %f ", grados, resultado);
/*        printf("  %f grados Celsius", resultado);*/
                
      
      }
      else      
      {
         printf("\n\n Opcion incorrecta...Intente de nuevo");
         goto reinicio;       
      } 

      printf("\n pulse enter tecla para salir \n");
      scanf("%d", &opcion);
      return 0; 
      

}