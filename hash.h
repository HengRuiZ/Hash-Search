#define KEY_NUM 32
#define HASH_LENGTH 43
typedef struct{
	char key[10];
	int frqc1;
	int frqc2;
}KeyInfo;
int h(char x[9]);
void FormHash(KeyInfo*a,char key[KEY_NUM][9]);
int Hash(char key[9],KeyInfo *a,int &i);
void SearchKey_F(KeyInfo *a,FILE*fp,int*frqc);
float Cos(int *x1,int *x2);
float L(int *x1,int *x2);

