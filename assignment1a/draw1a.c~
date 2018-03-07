#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void parseFile(FILE * fp, char * fname );
int fflush(FILE * stream);

int main(int argc, char * argv[]){
  int i;
  FILE * fp;
  for(i =1; i<argc; i++)
  {
    fp= fopen(argv[i], "r");
    if(fp ==NULL)
      {
	printf("Could not open file %s\n", argv[i]);
	exit(-1);
       }
    else
      { 
	//get the output for the first and second line
	printf("%s was started on ",argv[0]);
	fflush(NULL);
	system("date");
	printf("Input file: %s\n",argv[i]);
	parseFile(fp,argv[i]);
	fclose(fp);
	//close file
       }
    }
  return(0);
}/*main*/
void parseFile(FILE * fp, char * fname )
  {
    //All the parameters that will be used later
    char x[1000];
    int nImage = 0;
    int nLineTo =0;
    int nEnd = 0;
    int nprint =0;
    int ndraw =0;
    int ntranslate=0;
    int nchild =0;
    int ncomments =0;
    /*
     1.Run the wile loop only when the file is avilable to open
     2.and it will ignore all the stuffs except the first world.
     3.compare the first world to the key words
    */
    while (!feof(fp)) 
      {
        fscanf(fp,"%s%*[^\n]\n",x);

	if(strcmp(x,"Image")==0)
	  {
	    nImage++;
	  }
	else if(strcmp(x,"lineTo")==0)
	  {
	    nLineTo++;
	  }
	else if(strcmp(x,"End")==0)
	  {
	    nEnd++;
	  }	
	else if(strcmp(x,"print")==0)
	  {
	    nprint++;
	  }	
	else if(strcmp(x,"draw")==0)
	  {
	    ndraw++;
	  }
	else if(strcmp(x,"translate")==0)
	  {
	    ntranslate++;
	  }
	else if(strcmp(x,"child")==0)
	  {
	    nchild++;
	  }
	else if(strcmp(x,"#")==0)
	  {
	    ncomments++;
	  }
      }
    //get the output for the rest of line
    printf("%d Image definition(s)\n",nImage);
    printf("%d lineTo command(s)within Figures\n",nLineTo);
    printf("%d End command(s)\n",nEnd);
    printf("%d print command(s)\n",nprint);
    printf("%d draw command(s)\n",ndraw);
    printf("%d translate command(s)\n",ntranslate);
    printf("%d child command(s)\n",nchild);
    printf("%d comment(s)\n",ncomments);

  }

