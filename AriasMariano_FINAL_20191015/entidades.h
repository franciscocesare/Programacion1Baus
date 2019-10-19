typedef struct
{
    int id;
    char titulo [50];
    char autor[50];
    int precio;
    int editorialId;
}eLibro;

int parser_FromText(FILE* pFile , LinkedList* lista);

eLibro* libro_new();

int entidad_setCampo1(eLibro* pLibro, char *aux);
int entidad_setCampo2(eLibro* pLibro, char *aux);
int entidad_setCampo3(eLibro* pLibro, char *aux);
int entidad_setCampo4(eLibro* pLibro, char *aux);
int entidad_setCampo5(eLibro* pLibro, char *aux);

int eEntidad_getCampo1(eLibro* thisIs);
char* eEntidad_getCampo2(eLibro* thisIs);
char* eEntidad_getCampo3(eLibro* thisIs);
int eEntidad_getCampo4(eLibro* thisIs);
int eEntidad_getCampo5(eLibro* thisIs);

int parser_SaveToText(LinkedList* lista, char* archivo);

void printerList (LinkedList* lista);

void setDescuento(void* element);

int ordenar(void* element, void* elementB);
