#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// the max points
#define MAX_PT 10000


struct node
{
    int index;
    int x;
    int y;
    int parent;
    int num_children;
    int child[8];
    int overlap_hv;
    int overlap_vh;
};


// all the possible nodes
struct node nodes[MAX_PT];
// the number of nodes
int num_pts;

// keep the order of the dfs
int dfs_order[MAX_PT];

// init all the nodes
void init_nodes();
void load_data(FILE *inFile);
int spacelen(char *line);

void print_second_point(FILE *outFile);

void dfs(FILE *outFile, int index);

void calc_overlap();



int main(int argc, char *argv[])
{
    if (argc != 3 && argc != 5)
    {
        printf("Arguments error\n");
        return 1;
    }

    FILE *inFile = NULL;
    FILE *outFILE = NULL;

    // open the input file
    inFile = fopen(argv[2], "r");

    if (inFile == NULL)
    {
        printf("File %s doesn't exist\n", argv[2]);
    }

    if (argc == 5)
    {
        outFILE = fopen(argv[4], "w");
    }
    else
    {
        outFILE = stdout;
    }

    init_nodes();
    load_data(inFile);



    if(num_pts > 1)
    {

        print_second_point(outFILE);
        printf("\n");

    }

    dfs(outFILE, 0);
    printf("\n");






    fclose(inFile);

    if (outFILE != stdout)
    {
        fclose(outFILE);
    }

    return 0;
}


void init_nodes()
{
    int i, j;
    for (i = 0; i < MAX_PT; i++)
    {
        nodes[i].index = -1;
        nodes[i].x = -1;
        nodes[i].y = -1;
        nodes[i].parent = -1;
        nodes[i].num_children = 0;

        for (j = 0; j < 8; j++)
        {
            nodes[i].child[j] = -1;

        }
        nodes[i].overlap_hv = -1;
        nodes[i].overlap_vh = -1;

    }

}

void load_data(FILE *inFile)
{
    int i = 0, Max_x = 0, Max_y = 0, num_pt = 0, t = 0, c = 0;
    char line[100];
    int len_space;
    while(fgets(line, 100, inFile) != NULL)
    {
        //puts(line);
        int x = -1, y = -1;

        len_space = spacelen(line);
        if (strncmp(&line[len_space], "\n" , 1) == 0)
        {
            continue;
        }
        else if (i == 0 && strncmp(line,"#",1) !=0)
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
        else if(i>1 && i <=1+num_pt && strncmp(line,"#",1)!=0)
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
            nodes[num_pts].index = num_pts;
            nodes[num_pts].x = x;
            nodes[num_pts].y = y;
            num_pts++;
        }
        else if(i>1+num_pt && strncmp(line,"#",1)!=0)
        {
            i++;
            int p_index, c_index, dist;
            sscanf(&line[0],"%d %d %d",&p_index, &c_index, &dist);
            nodes[c_index].parent = p_index;
            nodes[p_index].child[nodes[p_index].num_children++] = c_index;

        }
    }


}


int spacelen(char *line)
{
    int spaces = 0;
    int i;
    for(i = 0; line[i] != '\0'; i++)
    {
        if(line[i] == ' ')
        {
            spaces++;
        }
    }
    return spaces;
}

void print_second_point(FILE *outFile)
{

    int i;
    fprintf(outFile, "%d\n", nodes[1].index);
    fprintf(outFile, "%d\n", nodes[1].x);
    fprintf(outFile, "%d\n", nodes[1].y);
    fprintf(outFile, "%d\n", nodes[1].parent);
    fprintf(outFile, "%d\n", nodes[1].num_children);


    if (nodes[1].num_children == 0)
    {
        fprintf(outFile, " \n");
    }
    else
    {
        for (i = 0; i < nodes[1].num_children; i++)
        {
            if (i != nodes[1].num_children-1)
            {
                fprintf(outFile, "%d, ", nodes[1].child[i]);
            }
            else
            {
                fprintf(outFile, "%d\n", nodes[1].child[i]);
            }

        }
    }

    fprintf(outFile, "%d\n", nodes[1].overlap_hv);
    fprintf(outFile, "%d\n", nodes[1].overlap_vh);

}


void dfs(FILE *outFile, int index)
{
    static int cnt = 0;
    dfs_order[cnt++] = index;
    int i;
    fprintf(outFile, "%d, ", nodes[index].index);
    fprintf(outFile, "%d", nodes[index].num_children);
    if (nodes[index].num_children != 0)
    {

        for(i = 0; i < nodes[index].num_children; i++)
        {

            fprintf(outFile, ", %d", nodes[index].child[i]);

        }
        fprintf(outFile, "\n");

        for(i = 0; i < nodes[index].num_children; i++)
        {
            dfs(outFile, nodes[index].child[i]);
        }

    }
    else
    {
        fprintf(outFile, "\n");
    }

}

//void calc_overlap()
//{
//    int idx;
//    int i, j, k, p;
//    for(idx = num_pts-1; i >= 0; i--)
//    {
//        i = dfs_order[idx];
//
//        if (nodes[i].num children == 0)
//        {
//            nodes[i].overlap_hv = 0;
//            nodes[i].overlap_vh = 0;
//        }
//        else
//        {
//            int max
//            p = nodes[i].parent;
////
////            for (k = 0; k < nodes[i].num children; k++)
////            {
////                j = nodes[i].child[k];
////
////                // combine two
////
////            }
//
//
//        }
//
//    }
//
//}

