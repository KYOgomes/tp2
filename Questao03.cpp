#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 500
#define MAX_ATRIBUTO 50

typedef struct {
  int height;
  float wheight;
  char name[MAX_ATRIBUTO], hair_color[MAX_ATRIBUTO], skin_color[MAX_ATRIBUTO],
      eye_color[MAX_ATRIBUTO], birth_year[MAX_ATRIBUTO], gender[MAX_ATRIBUTO],
      homeworld[MAX_ATRIBUTO];
} 

Personagem;
int end(char *pal);
void new_Personagem(Personagem *per);
Personagem clonar(Personagem *per);
void Print(Personagem *per);
void Ler(Personagem *per, char *ender);
void DefinirAtributo(int j, char *atributo, Personagem *per);
void Substring(char *resp, char *str, int start, int length);
int Contem(char *str, char compared);
void RemoveVirgula(char *str);
int Iguala(char *str, char *compared);

int main() {
  char ender[MAX_STRING];
  Personagem per;
  scanf(" %s", ender);
  while (end(ender) == 0) {
    new_Personagem(&per);
    Ler(&per, ender);
    Print(&per);
    scanf(" %s", ender);
  }
  return 0;
}

int end(char *pal) {
  if (pal[0] == 'F' && pal[1] == 'I' && pal[2] == 'M') {
    return 1;
  } else {
    return 0;
  }
}

void new_Personagem(Personagem *per) {
  strcpy(per->name, "");
  strcpy(per->hair_color, "");
  strcpy(per->skin_color, "");
  strcpy(per->eye_color, "");
  strcpy(per->birth_year, "");
  strcpy(per->gender, "");
  strcpy(per->homeworld, "");
  per->height = -1;
  per->wheight = -1;
}

Personagem clonar(Personagem *per) {
  Personagem clone;
  strcpy(clone.name, per->name);
  strcpy(clone.hair_color, per->hair_color);
  strcpy(clone.skin_color, per->skin_color);
  strcpy(clone.eye_color, per->eye_color);
  strcpy(clone.birth_year, per->birth_year);
  strcpy(clone.gender, per->gender);
  strcpy(clone.homeworld, per->homeworld);
  clone.height = per->height;
  clone.wheight = per->wheight;
}

void Print(Personagem *per) {
  printf(" ## %s ## %d ## ", per->name, per->height);
  if ((per->wheight - (int)per->wheight) == 0) {
    printf("%.0f", per->wheight);
  } else {
    printf("%.1f", per->wheight);
  }
  printf(" ## %s ## %s ## %s ## %s ## %s ## %s ## \n", per->hair_color,
         per->skin_color, per->eye_color, per->birth_year, per->gender,
         per->homeworld);
}

void Ler(Personagem *per, char *ender) {
  FILE *arq = fopen(ender, "r");
  char texto[MAX_STRING];
  char atributo[MAX_ATRIBUTO][9];
  int aspas = 0;
  int j = 0;
  fgets(texto, MAX_STRING, arq);
  for (int i = 0; j < 9; i++) {
    int length, startIndex;
    if (aspas == 3) {
      startIndex = i;
      while (texto[i] != '\'') {
        i++;
      }
      length = i;
      Substring(atributo[j], texto, startIndex, length);
      DefinirAtributo(j, atributo[j], per);
      j++;
      i++;
      aspas = 0;
    }
    if (texto[i] == '\'')
      aspas++;
  }
  fclose(arq);
}

void DefinirAtributo(int j, char *atributo, Personagem *per) {
  switch (j) {
  case 0:
    strcpy(per->name, atributo);
    break;
  case 1: {
    if (Iguala(atributo, "unknown") == 1)
      per->height = 0;
    else
      per->height = atoi(atributo);
    break;
  }
  case 2: {
    if (Contem(atributo, ',') == 1)
      RemoveVirgula(atributo);
    if (Iguala(atributo, "unknown") == 1)
      per->wheight = 0;
    else
      per->wheight = atof(atributo);
    break;
  }
  case 3:
    strcpy(per->hair_color, atributo);
    break;
  case 4:
    strcpy(per->skin_color, atributo);
    break;
  case 5:
    strcpy(per->eye_color, atributo);
    break;
  case 6:
    strcpy(per->birth_year, atributo);
    break;
  case 7:
    strcpy(per->gender, atributo);
    break;
  case 8:
    strcpy(per->homeworld, atributo);
    break;
  default:
    break;
  }
}

void Substring(char *resp, char *str, int start, int length) {
  char sub[MAX_ATRIBUTO] = "";
  int j = 0;
  for (int i = start; i < length; i++) {
    sub[j] = str[i];
    j++;
  }
  strcpy(resp, sub);
}

int Contem(char *str, char compared) {
  int resp = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == compared) {
      i = strlen(str);
      resp = 1;
    }
  }
  return resp;
}

void RemoveVirgula(char *str) {
  int j = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] != ',') {
      str[j] = str[i];
      j++;
    }
  }
  str[strlen(str) - 1] = '\0';
}

int Iguala(char *str, char *compared) {
  int resp = 1;
  int i = 0;
  while (i < strlen(str) && resp == 1) {
    if (str[i] != compared[i]) {
      resp = 0;
    }
    i++;
  }
  return resp;
}