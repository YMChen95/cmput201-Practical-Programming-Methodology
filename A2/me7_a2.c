/* assignment2
Mengyang Chen 1412408
References: stack overflow
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// the max points
#define MAX_PT 10000

void loaddata(FILE *inputfile);
void savaPrime(FILE *outputfile);
char* inputfile_name(int leghth, char** array);
char* outputfile_name(int length, char** array);
int spacelen(char *line);

void prime();

int num_pts;
int pt_x[MAX_PT];
int pt_y[MAX_PT];

// distance to root
int dist[MAX_PT];

int in_tree[MAX_PT];

int num_edge;
int edge_pt1[MAX_PT];
int edge_pt2[MAX_PT];


int main(int argc, char** argv)
{

    FILE * fpin;
    FILE * fpout;


    char* inputfile;
    char* outputfile;

    if (argc ==3 || argc==5)
    {
        if (strncmp(argv[1],"-i",2)==0||strncmp(argv[1],"-o",2)==0)
        {
            inputfile=inputfile_name(argc,argv);
            outputfile=outputfile_name(argc,argv);

            if(inputfile == NULL && outputfile == NULL)
            {
                printf(">%s [-i inputfile[-o outputfile]]\n",argv[0]);
                exit(-1);
            }

            if(inputfile!=NULL)
            {
                fpin = fopen(inputfile,"r");
                if (fpin == NULL)
                {
                    printf("File %s doesn't exist\n", inputfile);
                    exit(-1);
                }
                else
                {

                    loaddata(fpin);
                }
                fclose(fpin);

            }

            if (outputfile!=NULL)
            {
              fpout=fopen(outputfile,"w");
            }
            else
            {
              fpout=stdout;
            }

            savaPrime(fpout);

            if (fpout!=stdout)
            {
              fclose(fpout);
            }

        }
        else
        {
            printf(">%s [-i inputfile[-o outputfile]]\n",argv[0]);
            exit(-1);
        }
    }

    else
    {
        printf(">%s [-i inputfile[-o outputfile]]\n",argv[0]);
        exit(-1);
    }



    return 0;
}


int max(int a, int b)
{

  return a > b ? a : b;
}


void prime()
{

  int i, j, k;
  int min_dist, d;
  int pt1, pt2;

  for (i = 0; i < num_pts; i++)
    in_tree[i] = -2;

  in_tree[0] = -1;

  for (i = 1; i < num_pts; i++)
  {
    min_dist = -1;
    for (j = 1; j < num_pts; j++)
    {
      // find a white point
      if (in_tree[j] == -2)
      {

        
        for (k = 0; k < num_pts; k++)
        {
          if (in_tree[k] != -2)
          {
            d = abs(pt_x[j]-pt_x[k]) + abs(pt_y[j]-pt_y[k]);

            if (min_dist == -1)
            {

              min_dist = d;
              pt1 = k;
              pt2 = j;
              
            }
            else if (min_dist > d)
            {
              min_dist = d;
              pt1 = k;
              pt2 = j;

            }
            else if (min_dist == d)
            {

              if (abs(pt_y[k]-pt_y[j]) > abs(pt_y[pt1]-pt_y[pt2]))
              {
                pt1 = k;
                pt2 = j;
              }
              else if (abs(pt_y[k]-pt_y[j]) == abs(pt_y[pt1]-pt_y[pt2]))
              {
                if (max(pt_x[k], pt_x[j]) >= max(pt_x[pt1], pt_x[pt2]))
                {
                  pt1 = k;
                  pt2 = j;
                }

              }
            }

          }

        }
      }

    }
    in_tree[pt2] = pt1;
    edge_pt1[num_edge] = pt1;
    edge_pt2[num_edge] = pt2;
    num_edge++;
  }

}



int calc_dist(int pt)
{


  return abs(pt_x[pt]-pt_x[0])+abs(pt_y[pt]-pt_y[0]);

}

void savaPrime(FILE *outputfile)
{

  prime();
  int i;
  int d;
  int total_length = 0;
  fprintf(outputfile, "Choosing point 0 as the root ...\n");


  for (i = 1; i < num_pts; i++)
  {

    fprintf(outputfile, "Point %d has a distance %d to the tree, parent 0;\n", i, calc_dist(i));
  }

   fprintf(outputfile, "#Edges of the MST by Prim’s algorithm:\n");

  for (i = 0; i < num_edge; i++)
  {
    d = abs(pt_x[edge_pt1[i]]-pt_x[edge_pt2[i]])+abs(pt_y[edge_pt1[i]]-pt_y[edge_pt2[i]]);
    total_length += d;
    fprintf(outputfile, "%d %d %d\n", edge_pt1[i], edge_pt2[i], d);
  }

  fprintf(outputfile, "The total length of the MST is %d.\n", total_length);

}

void loaddata(FILE *inputfile)
{
    int i=0,Max_x=0,Max_y=0,num_pt=0,t=0,c=0;
    char line[100];
    int len_space;
    while(fgets(line,100,inputfile)!=NULL)
    {
        int x=-1,y=-1;
        len_space=spacelen(line);
        if (strncmp(&line[len_space],"\n",1)==0)
        {
            continue;
        }
        else if (i==0 && strncmp(line,"#",1)!=0 )
        {
            i++;
            sscanf(&line[0],"%d %d",&Max_x,&Max_y);

            for(c=0; c<=strlen(line); c++)
            {
                if (line[c]==32&&line[c+1]!=10&&line[c+1]!=32)
                {
                    t++;
                }
            }
            if(Max_x>1000 || Max_x<0||Max_y<0||Max_y>1000)
            {
                printf("The range of Max_x and Max_y should be [0-1000]\n");
                exit(-1);
            }
            else if(t!=1)
            {
                printf("File structure error.\n");
                exit(-1);
            }

            // printf("%d %d\n",Max_x,Max_y);
        }
        else if(i==1 && strncmp(line,"#",1)!=0)
        {
            i++;
            t=0;
            sscanf(&line[0],"%d",&num_pt);
            for(c=0; c<=strlen(line); c++)
            {
                if (line[c]==32&&line[c+1]!=10&&line[c+1]!=32)
                {
                    t++;
                }
            }

            if(num_pt>10000||num_pt<1)
            {
                printf("The range of number point should be [1-10000]\n");
                exit(-1);
            }
            else if(t!=0)
            {
                printf("File structure error.\n");
                exit(-1);
            }
            // printf("%d\n",num_pt);
        }
        else if(i>1 && strncmp(line,"#",1)!=0)
        {
            i++;
            t=0;
            for(c=0; c<=strlen(line); c++)
            {
                if (line[c]==32&&line[c+1]!=10&&line[c+1]!=32)
                {
                    t++;
                }
            }
            sscanf(&line[0],"%d %d",&x,&y);

            if(x>Max_x || y>Max_y||x<0||y<0)
            {
                printf("The input x or y is incorrect.\n");
                exit(-1);
            }
            else if(i-2>num_pt)
            {
                printf("File structure error.\ncoordinate is out of the specified rectangular area\n");
                exit(-1);
            }
            else if(t!=1)
            {
                printf("File structure error.\n");

                exit(-1);
            }
            // printf("%d %d\n",x,y);
            pt_x[num_pts] = x;
            pt_y[num_pts] = y;
            num_pts++;

        }
    }
    if(i-2<num_pt)
    {
        printf("File structure error.\n");
        printf("Missing point line x/y value.\n");
    }

}

int spacelen(char *line)
{
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


char* inputfile_name(int length, char** array)
{

    char* filename;
    filename = NULL;

    for(int i=0; i < length; i++)
    {
        if(strcmp(array[i], "-i") == 0)
        {
            filename = array[i+1];
            break;
        }
    }
    return filename;
}
char* outputfile_name(int length, char** array)
{

    char* filename;
    filename = NULL;
    for(int i=0; i < length; i++)
    {
        if(strcmp(array[i], "-o") == 0)
        {
            filename = array[i+1];
            break;
        }
    }
    return filename;
}
