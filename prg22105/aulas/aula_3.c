#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Obs.: haverá mais comentários neste doc., atualizações serão feitas com o tempo. */

int main() {
    /*
     *  Parte 1 – Arrays:
     */

    /* int notas[3] = {8, 7, 9}; */
    /* printf("Nota 1: %d\n", notas[0]); */


    
    /*
     *  Parte 2 – Struct: agrupando dados diferentes
     */

    /* struct Aluno { */
    /*     char nome[50]; */
    /*     int matricula; */
    /*     float nota; */
    /* }; */

    /* struct Aluno g = {"Gabrielle", 12345, 9.5}; */
    /* printf("Nome: %s\nNota: %.2f\n", g.nome, g.nota); */


    
    /*
     *  Parte 3 – Array de structs
     */

    /* struct Aluno { */
    /*     char nome[50]; */
    /*     int matricula; */
    /*     float nota; */
    /* }; */

    /* struct Aluno turma[2] = { */
    /*     {"Gabrielle", 12345, 9.5}, */
    /*     {"João", 67890, 7.8} */
    /* }; */

    /* printf("Nota do João: %.1f\n", turma[1].nota); */


    
    /*
     *  Parte 4 – Struct com array interno
     */

    /* struct Aluno { */
    /*     char nome[50]; */
    /*     float notas[3]; */
    /* }; */

    /* struct Aluno a = {"Gabrielle", {8.0, 9.0, 7.5}}; */
    /* printf("Nota 2: %.1f\n", a.notas[1]); */


    
    /*
     *  Parte 5 – Typedef: simplificando
     */

    /* typedef struct { */
    /*     char nome[50]; */
    /*     int idade; */
    /* } Pessoa; */

    /* Pessoa p = {"Gabrielle", 26}; */
    /* printf("Nome: %s\n", p.nome); */
    /* printf("Idade: %d\n", p.idade); */


    
    /*
     *  Parte 6 – Enum: valores simbólicos
     */

    /* enum DiaDaSemana { DOM, SEG, TER, QUA, QUI, SEX, SAB }; */

    /* enum DiaDaSemana hoje = QUA; */
    /* printf("Hoje é dia %d\n", hoje); */


    
    /*
     *  Parte 7 – Ponteiro para struct (só plantar ideia)
     */

    /* typedef struct { */
    /*     char nome[50]; */
    /*     float nota; */
    /* } Aluno; */

    /* Aluno *p = malloc(sizeof(Aluno)); */
    /* strcpy(p->nome, "Gabrielle"); */
    /* p->nota = 9.8; */
    /* printf("Nota: %.1f\n", p->nota); */
    /* free(p); */

    
    return 0;
}

