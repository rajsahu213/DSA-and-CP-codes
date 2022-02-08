#include<stdio.h>
#include<string.h>

void main(int argc , char *argv[])
{
        FILE *file1,*file2;
        char byte1,byte2;
        int line=1,byte_count=0;
   
        file1 = fopen(argv[1],"r");
        file2 = fopen(argv[2],"r");

        while((byte1=fgetc(file1))!=EOF && (byte2=fgetc(file2))!=EOF)
        {
              if(byte1=='\n' || byte2 == '\n')
              ++line;
           
             if(byte1 == byte2)
            {
                  ++byte_count;
                  continue;
             }
            else
           {
                  break;
            }
    }
    printf("\nchar %d  line %d\n",byte_count,line);   //first different byte and line no
    fclose(file1);
    fclose(file2);
}