#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_ogrenciEntity
{
    int id;
    char *name;
    char *surname;

} t_ogrenciEntity;

typedef struct s_ogrenci
{
    t_ogrenciEntity *ogrenci;
} t_ogrenci;


// int main()
// {
//     t_ogrenciEntity ogrenciEntity;
//     t_ogrenci ogrenci;

//     t_ogrenciEntity.id = 1;
//     t_ogrenciEntity->name = "Ali";

//     ogrenciEntity = malloc(type of t_ogrenciEntity);
//     ogrenci = malloc(type of t_ogrenci);

//     ogrenciEntity.id = t_ogrenciEntity.id;
//     ogrenciEntity->name = t_ogrenciEntity->name;
    
//     printf("%d\n", ogrenci.id);
//     printf("%s", ogrenci->name);

// }

int main()
{
    t_ogrenciEntity *ogrenciEntity;
    t_ogrenci *ogrenci;

    ogrenciEntity = (t_ogrenciEntity *)malloc(sizeof(t_ogrenciEntity));
    ogrenci = (t_ogrenci *)malloc(sizeof(t_ogrenci));

    ogrenciEntity->id = 1;
    ogrenciEntity->name = (char *)malloc(sizeof(char) * (strlen("Ali") + 1));
    strcpy(ogrenciEntity->name, "Ali");

    ogrenci->ogrenci = ogrenciEntity;
    
    printf("%d\n", ogrenci->ogrenci->id);
    printf("%s", ogrenci->ogrenci->name);

    free(ogrenciEntity->name);
    free(ogrenciEntity);
    free(ogrenci);

    return 0;
}