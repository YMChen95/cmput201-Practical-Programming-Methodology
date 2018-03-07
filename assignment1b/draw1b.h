/* assignment 1b
   Mengyang Chen
   1412408
   lecture section A2
   lab section D05
   Juehui Fan Ta's name */


//declaration for all function, global variables
int i=0,j=0;
char X[256];
char print_name[16],draw_name[16],translate_name[16];
//image's struct, which contains the x and y point of image, name of image and image size. 
struct image
{
	double x_initial[100],y_initial[100];
	char name;
	int size;
};
struct image i_name[16];
int image_num=0;
double delta_x, delta_y;
double image_Ax,image_Ay,image_Bx,image_By;
double translate_x,translate_y;

void parseFile( FILE * fp, char * fname, FILE * executable);
//praseFile function's prototypes, which contains the majority of this program's code.
void trans(char * X);
//tranlate function's prototypes. will add all the x and y point to translate value.
void pri(char * X);
//print function's prototypes. will print the image infomation that asked to.
void dr(char * X, FILE * executable);
//draw function's prototypes. will send the command to sketchpad and draw all the images that have already been stored.
FILE *popen(char *command, const char *type);

int pclose(FILE *stream);
//closefile prototypes.
