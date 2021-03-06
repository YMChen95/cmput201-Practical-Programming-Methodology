/* assignment1
Mengyang Chen 1412408
References: stack overflow
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printout(FILE *inputfile);
void generatefile(FILE *gen_file,int max_x, int max_y, int innum_p);
void writefile(FILE *inputfile, FILE*outputfile);
char* inputfile_name(int leghth, char** array);
char* outputfile_name(int length, char** array);
int spacelen(char *line);

int main(int argc, char** argv){

  FILE * fpin;
  FILE * fpout;
  FILE * fpgen;

  char* inputfile;
  char* outputfile;  
  char gen_file[30];

  int inmax_x,inmax_y,innum_pt,innum_inst;
  if (argc ==3 || argc==5){
    if (strncmp(argv[1],"-i",2)==0||strncmp(argv[1],"-o",2)==0){
      inputfile=inputfile_name(argc,argv);
      outputfile=outputfile_name(argc,argv);    
      if(inputfile!=NULL && outputfile==NULL){
	fpin = fopen(inputfile,"r");
	if (fpin == NULL){
	  printf("File %s doesn't exist\n", inputfile);
	  exit(-1);
	}
	else{
	  printout(fpin);
	}
	fclose(fpin);
      }
      else if(inputfile!=NULL && outputfile!=NULL){
	fpin=fopen(inputfile,"r");
	fpout=fopen(outputfile,"w");
	if(fpin == NULL){
	  printf("File %s doesn't exist\n",inputfile);
	  exit(-1);
	}
	else{
	  writefile(fpin,fpout);
	}
	fclose(fpin);
	fclose(fpout);
      }
      else{
	 printf(">%s [-i inputfile[-o outputfile]]\n",argv[0]);
	 exit(-1);
      }
    }
    else{
      printf(">%s [-i inputfile[-o outputfile]]\n",argv[0]);
      exit(-1);
    }
  }

  else if(argc==1){
    printf("Generating random instances ...\n");
    printf("Enter the circuit board size MAX_X MAX_Y: ");
    scanf("%d %d",&inmax_x,&inmax_y);
    if(inmax_x>1000 || inmax_x<0||inmax_y<0||inmax_y>1000){
      printf("The range of Max_x and Max_y should be [0-1000]\n");
      exit(-1);
    }
    printf("Enter the number of points NUM_PT: ");
    scanf("%d",&innum_pt);

    if(innum_pt>10000||innum_pt<1){
      printf("The range of number point should be [1-10000]\n");
      exit(-1);
    }
    else if((inmax_x+1)*(inmax_y+1)<innum_pt){
      printf("File structure error.\n");
      exit(-1);
    }

    printf("Enter the number of random instances to be generated:");
    scanf("%d",&innum_inst);
    if(innum_inst<1){
      printf("The number of instances should be a number and greater or equal than 1\n");
      exit(-1);
    }

    for(int i=1;i<=innum_inst;i++){
      sprintf(gen_file,"instance%d_%d.txt",innum_pt,i);
      fpgen=fopen(gen_file,"w");
      generatefile(fpgen,inmax_x,inmax_y,innum_pt);
      printf("\ninstance%d_%d.txt generated",innum_pt,i);
    }
    printf("...done!\n");
    // printf("%d %d %d %d\n",inmax_x,inmax_y,innum_pt,innum_inst);    
}

  else{
    printf(">%s [-i inputfile[-o outputfile]]\n",argv[0]);
    exit(-1);
  }
}
void generatefile(FILE* gen_file,int max_x, int max_y, int innum_pt){
 int x,y,prev_x,prev_y;
 fprintf(gen_file,"%d %d\n%d\n",max_x,max_y,innum_pt);

 for(int i=1;i<=innum_pt;i++){
   prev_x=x;
   prev_y=y;
   x=rand()%(max_x+1);
   y=rand()%(max_y+1);
   if(x==prev_x && y==prev_y){
     printf("  File structure error\n");
     printf("There are duplicated points\n");
     exit(-1);
   }
   else{
     fprintf(gen_file,"%d %d\n",x,y);
   }
 }
}

void writefile(FILE *inputfile, FILE *outputfile){
  int i=0,Max_x=0,Max_y=0,num_pt=0,t=0,c=0;
  char line[100];
  int len_space;
  while(fgets(line,100,inputfile)!=NULL){
    int x=-1,y=-1;
    len_space=spacelen(line);
    if (strncmp(&line[len_space],"\n",1)==0){
      continue;
    }
    else if (i==0 && strncmp(line,"#",1)!=0 ){
      i++;
      sscanf(&line[0],"%d %d",&Max_x,&Max_y);
      for(c=0;c<=strlen(line);c++){
	if (line[c]==32&&line[c+1]!=10&&line[c+1]!=32){
	    t++;
	}
      }
      if(Max_x>1000 || Max_x<0||Max_y<0||Max_y>1000){
	printf("The range of Max_x and Max_y should be [0-1000]\n");
	exit(-1);
      }
      else if(t!=1){
	printf("File structure error.\n");
	exit(-1);
      }

      fprintf(outputfile,"%d %d\n",Max_x,Max_y);
     }
    else if(i==1 && strncmp(line,"#",1)!=0){
      i++;
      t=0;
      sscanf(&line[0],"%d",&num_pt);
      for(c=0;c<=strlen(line);c++){
	if (line[c]==32&&line[c+1]!=10&&line[c+1]!=32){
	    t++;
	}
      }

      if(num_pt>10000||num_pt<1){
	printf("The range of number point should be [1-10000]\n");
	exit(-1);
      }
      else if(t!=0){
	printf("File structure error.\n");
	exit(-1);
      }
      fprintf(outputfile,"%d\n",num_pt);
      }
    else if(i>1 && strncmp(line,"#",1)!=0){
      i++;
      t=0;
      for(c=0;c<=strlen(line);c++){
	if (line[c]==32&&line[c+1]!=10&&line[c+1]!=32){
	    t++;
	}
      }
      sscanf(&line[0],"%d %d",&x,&y);

      if(x>Max_x || y>Max_y||x<0||y<0){
	printf("The input x or y is incorrect.\n");
	exit(-1);
      }
      else if(i-2>num_pt){
	printf("File structure error.\n");
	printf("coordinate is out of the specified rectangular area\n");
	exit(-1);
      }
      else if(t!=1){
	printf("File structure error.\n");
	exit(-1);
      }
      fprintf(outputfile,"%d %d\n",x,y);
     
    }   
  }
 if(i-2<num_pt){
   printf("File structure error.\n");
    printf("Not engough input coordinate in inputfile.\n");
  }
}


void printout(FILE *inputfile){
   int i=0,Max_x=0,Max_y=0,num_pt=0,t=0,c=0;
  char line[100];
  int len_space;
  while(fgets(line,100,inputfile)!=NULL){
    int x=-1,y=-1;
    len_space=spacelen(line);
    if (strncmp(&line[len_space],"\n",1)==0){
      continue;
    }
    else if (i==0 && strncmp(line,"#",1)!=0 ){
      i++;
      sscanf(&line[0],"%d %d",&Max_x,&Max_y);

      for(c=0;c<=strlen(line);c++){
	if (line[c]==32&&line[c+1]!=10&&line[c+1]!=32){
	    t++;
	}
      }
      if(Max_x>1000 || Max_x<0||Max_y<0||Max_y>1000){
	printf("The range of Max_x and Max_y should be [0-1000]\n");
	exit(-1);
      }
      else if(t!=1){
	printf("File structure error.\n");
	exit(-1);
      }

      printf("%d %d\n",Max_x,Max_y);
     }
    else if(i==1 && strncmp(line,"#",1)!=0){
      i++;
      t=0;
      sscanf(&line[0],"%d",&num_pt);
      for(c=0;c<=strlen(line);c++){
	if (line[c]==32&&line[c+1]!=10&&line[c+1]!=32){
	    t++;
	}
      }

      if(num_pt>10000||num_pt<1){
	printf("The range of number point should be [1-10000]\n");
	exit(-1);
      }
      else if(t!=0){
	printf("File structure error.\n");
	exit(-1);
      }
      printf("%d\n",num_pt);
      }
    else if(i>1 && strncmp(line,"#",1)!=0){
      i++;
      t=0;
      for(c=0;c<=strlen(line);c++){
	if (line[c]==32&&line[c+1]!=10&&line[c+1]!=32){
	    t++;
	}
      }
      sscanf(&line[0],"%d %d",&x,&y);

      if(x>Max_x || y>Max_y||x<0||y<0){
	printf("The input x or y is incorrect.\n");
	exit(-1);
      }
      else if(i-2>num_pt){
	printf("File structure error.\ncoordinate is out of the specified rectangular area\n");
	exit(-1);
      }
      else if(t!=1){
	printf("File structure error.\n");

	exit(-1);
      }
      printf("%d %d\n",x,y);
     
    }   
  }
 if(i-2<num_pt){
    printf("File structure error.\n");
    printf("Missing point line x/y value.\n");
  }

}

int spacelen(char *line){
  int spaces=0;
  for(int i = 0; line[i] != '\0'; i++)
 {
     if(line[i]==' ')
     {
          spaces++;
     }
  }
  return spaces;
}


char* inputfile_name(int length, char** array){

    char* filename;
    filename = NULL;

    for(int i=0; i < length; i++){
      if(strcmp(array[i], "-i") == 0){
	filename = array[i+1];
	break;
      }
    }
	return filename;
}
char* outputfile_name(int length, char** array){

    char* filename;
    filename = NULL;
        for(int i=0; i < length; i++){
            if(strcmp(array[i], "-o") == 0){
                filename = array[i+1];
                break;
            }
        }
    return filename;
}
