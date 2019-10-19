int getIn (char mensaje[]);
float getFloat (char mensaje[]);
char getChar(char mensaje[]);
void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico (char str []);
int esLetras (char str[]);
int esAlfaNumerico(char str[]);
int esTelefono(char str []);

int checkLenght(char str[], int i);
int checkLenghtTelefono(char str[], int i);
int limitadorInt(float valor, int lowLimit, int highLimit);
int validarOpcion(int opcion, int a, int b);

char getCharSexo(void);
int getIntLimitado(char mensaje[], char eMensaje[], int lowLimit, int highLimit);

int checkMail(char aux[]);

int menuInicio();
int menuSecond();
int menuArchivos();

