#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 8192
#define fileOrigen  "programwithcomments.c"
#define fileDestino "programsincomments.c"

/* prototype */
void removeComment(int archivoOrigen, int archivodestino);


int main()
{
  int j = 0;
  int archivoOrigen, archivoDestino;
  ssize_t origSize, destSize; /* ssize_t is a data type repreenting sizes of blocks for single operations */
  char buffer[BUF_SIZE];
  archivoOrigen = open(fileOrigen, O_RDONLY);
  if(archivoOrigen == -1)
  {
    perror("open");
    return 2;
  }
  else
  {
    printf("archivo origen abierto con exito \n\n\n\n");
    
  } 
  
  archivoDestino = open(fileDestino, O_WRONLY | O_CREAT, 0644); 
  if(archivoDestino == -1)
  {
    perror("open");
    return 3;
  }
  else
  {
    printf("archivo odestino creado con exito \n\n\n\n");
    
  } 
  
  /* copia archivo completo */
     removeComment(archivoOrigen, archivoDestino);
  
  
/*     while((origSize = read(archivoOrigen,&buffer, BUF_SIZE)) > 0)
     {
       destSize = write(archivoDestino, &buffer, (ssize_t) origSize);
       if(destSize != origSize)
       {
           perror("write");
           return 4;
       }
     
     } 
  */   
     close(archivoOrigen);
     close(archivoDestino);
     return(EXIT_SUCCESS);          
  /**************************/
    
}


/*******************************/
/* function to remove comments */
/*******************************/
void removeComment(int archivoOrigen, int archivoDestino)
{
     char buffer, secBuffer;
     ssize_t origSize, destSize, auxSize; /* ssize_t is a data type repreenting sizes of blocks for single operations */
     int isComment = 0;
     while((origSize = read(archivoOrigen,&buffer, 1)) > 0)
     { 
         printf("Leido-> %c \n", buffer); 
         if(isComment == 0) 
         {
           if(buffer =='/') 
           {
             auxSize = read(archivoOrigen,&secBuffer, 1);
             if(secBuffer == '*')
             {
               printf("encontre un comentario \n");          
               isComment = 1;             
             }
             else
             {
               destSize = write(archivoDestino, &buffer, (ssize_t) origSize);
               if(destSize != origSize)
               {
                 perror("write");
                 /*return 4;*/
               }
               destSize = write(archivoDestino, &secBuffer, (ssize_t) auxSize);
               if(destSize != auxSize)
                {
                  perror("write");
                  /*return 4;*/
                }                    
             }       
           }
           else
           {
             destSize = write(archivoDestino, &buffer, (ssize_t) origSize);
             if(destSize != origSize)
             {
               perror("write");
               /*return 4;*/
             }
           }
         } /* if buffer  = 0 */
         else
         {
            if(buffer == '*')
            {
               auxSize = read(archivoOrigen,&secBuffer, 1);
               if(secBuffer == '/')
               {
                 printf("encontre fin de comentario \n");          
                 isComment = 0;             
               }                
            }                  
         }     
     }/* while end */ 
}





























