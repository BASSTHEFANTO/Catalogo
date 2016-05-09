#include<stdio.h>
#include<string.h>
void logo()
{
    printf("________________________________________________________________________________\n\n\n");
    printf("______________________________ANALIZADOR DE TEXTO PLANO_________________________\n\n\n");
    printf("______________________________GENERADOR DE PAGINAS WEB__________________________\n\n\n");
    printf("__________________________________VERSION BETA 1.0______________________________\n\n\n");
    printf("____________________________________MAYO_05_2016________________________________\n\n\n");
    printf("________________________________PROGRAMA CREADO POR_____________________________\n\n\n");
    printf("_______________________________FABIAN TOBAR NUMESQUI____________________________\n\n\n");
    printf("______________________________ INGENIERIA MECATRONICA___________________________\n\n\n");
    printf("__________________________UNIVERSIDAD NACIONAL DE COLOMBIA______________________\n\n\n");
    printf("________________________________________________________________________________\n\n\n");
    return;
}
void analizar_archivo(char path[])
{
    FILE *archivo;//Puntero_archivo de obtencion de datos
    FILE *archivo_salida;//Punteros_archivos generados

    archivo = fopen(path,"r");//protocolo_lectura archivo de datos
    if (archivo != NULL)
    {
        /*lector de caracteres*/    char caracter;
        /*Caracteres por item*/     int tam_cadena = 2000;
        /*Buffer*/                  char cadena[tam_cadena];
        /*Buffer de nombre archivo*/ char path[9];
        /*Contador de archivos*/    int cant_arch_gen = 0;

        int tam_dvd, tam_titulo, tam_director, tam_genero, tam_ano, tam_idioma, tam_subtitulo, tam_duracion, tam_trailer, tam_descripcion;

        /*1*/tam_dvd = 5;
        /*2*/tam_titulo = 35;
        /*3*/tam_director = 30;
        /*4*/tam_genero = 15;
        /*5*/tam_ano = 5;
        /*6*/tam_idioma = 15;
        /*7*/tam_subtitulo = 15;
        /*8*/tam_duracion = 10;
        /*9*/tam_trailer = 50;
        /*10*/tam_descripcion = 1500;


        /*1*/char dvd[tam_dvd];
        /*2*/char titulo[tam_titulo];
        /*3*/char director[tam_director];
        /*4*/char genero[tam_genero];
        /*5*/char ano[tam_ano];
        /*6*/char idioma[tam_idioma];
        /*7*/char subtitulo[tam_subtitulo];
        /*8*/char duracion[tam_duracion];
        /*9*/char trailer[tam_trailer];
        /*10*/char descripcion[tam_descripcion];

        while(feof(archivo) == 0)
        {
            memset(cadena,   0, tam_cadena);
            memset(dvd,      0, tam_dvd);
            memset(titulo,   0, tam_titulo);
            memset(director, 0, tam_director);
            memset(genero,   0, tam_genero);
            memset(ano,      0, tam_ano);
            memset(idioma,   0, tam_idioma);
            memset(subtitulo,0, tam_subtitulo);
            memset(duracion, 0, tam_duracion);
            memset(trailer,  0, tam_trailer);
            memset(descripcion, 0, tam_descripcion);
            memset(path,     0, 9);

            int pos_leEs = 0;
            int tab = 0;
            int enter = 0;

            int tdvd_pos = 0;
            int ttitulo_pos = 0;
            int tdirector_pos = 0;
            int tgenero_pos = 0;
            int tano_pos = 0;
            int tidioma_pos = 0;
            int tsubtitulo_pos = 0;
            int tduracion_pos = 0;
            int ttrailer_pos = 0;
            int tdescripcion_pos = 0;

            bool fin_info_dvd = false;//indica cuando termina la informacion de un mismo dvd y el fin de cadena
            int cero = 0;

            printf("________________________________________________________________________________\n\n");
            while (feof(archivo) == false && fin_info_dvd== false)//Guardar la cadena en buffer si no es el final del archivo o fila .
            {
                caracter = fgetc(archivo);
                if(caracter == '\n')
                {
                    fin_info_dvd = true;
                }
                cadena[pos_leEs] = caracter;
                pos_leEs++;
            }

            for(int i = 0; i < tam_cadena; i++)//Lectura de arreglo para estructurar
            {
                if(cadena[i] == '\t')
                {
                    tab++;
                    int reseteo = 0;

                    switch(tab) //Asignar valores a los campos a partir de las cadenas
                        {
                        case 1 :
                            {
                                tdvd_pos = i;
                                for(int i = 0; i < tdvd_pos; i++)
                                {
                                    dvd[i] = cadena[i];
                                };
                            }
                            break;
                        case 2 :
                            {
                                ttitulo_pos = i;
                                for(int i = tdvd_pos + 1; i < ttitulo_pos; i++)
                                {
                                    titulo[reseteo] = cadena[i];
                                    reseteo++;
                                };
                            }
                            break;
                        case 3 :
                            {
                                tdirector_pos = i;
                                for(int i = ttitulo_pos + 1; i < tdirector_pos; i++)
                                {
                                    director[reseteo] = cadena[i];
                                    reseteo++;
                                };
                            }
                            break;
                        case 4 :
                            {
                                tgenero_pos = i;
                                for(int i = tdirector_pos + 1; i < tgenero_pos; i++)
                                {
                                    genero[reseteo] = cadena[i];
                                    reseteo++;
                                };
                            }
                            break;
                        case 5 :
                            {
                                tano_pos = i;
                                for(int i = tgenero_pos + 1; i < tano_pos; i++)
                                {
                                    ano[reseteo] = cadena[i];
                                    reseteo++;
                                };
                            }
                            break;
                        case 6 :
                            {
                                tidioma_pos = i;
                                for(int i = tano_pos + 1; i < tidioma_pos; i++)
                                {
                                    idioma[reseteo] = cadena[i];
                                    reseteo++;
                                };
                            }
                            break;
                        case 7 :
                            {
                                tsubtitulo_pos = i;
                                for(int i = tidioma_pos + 1; i < tsubtitulo_pos; i++)
                                {
                                    subtitulo[reseteo] = cadena[i];
                                    reseteo++;
                                };
                            }
                            break;
                        case 8 :
                            {
                                tduracion_pos = i;
                                for(int i = tsubtitulo_pos + 1; i < tduracion_pos; i++)
                                {
                                    duracion[reseteo] = cadena[i];
                                    reseteo++;
                                };
                            }
                            break;
                        case 9 :
                            {
                                ttrailer_pos = i;
                                for(int i = tduracion_pos + 1; i < ttrailer_pos; i++)
                                {
                                    trailer[reseteo] = cadena[i];
                                    reseteo++;
                                };
                            }
                        break;
                }
                }
                else if(cadena[i] == '\n')
                {
                    enter++;
                    tdescripcion_pos = i;
                    for(int i2 = ttrailer_pos + 1; i2 < tdescripcion_pos; i2++)
                    {
                        descripcion[cero] = cadena[i2];
                        cero++;
                    };
                }
            }
            for(int i = 0; i < 16; i++)
            {
                if(i == 0){path[i] = 'd';}
                if(i == 1){path[i] = 'v';}
                if(i == 2){path[i] = 'd';}
                if(i == 3){path[i] = dvd[0];}
                if(i == 4){path[i] = dvd[1];}
                if(i == 5){path[i] = dvd[2];}
                if(i == 6){path[i] = dvd[3];}
                if(i == 7){path[i] = '.';}
                if(i == 8){path[i] = 'h';}
                if(i == 9){path[i] = 't';}
                if(i == 10){path[i] = 'm';}
                if(i == 11){path[i] = 'l';}
                if(i == 12){path[i] = '\0';}

            };
            printf("Analizando cadena... = %s\n", cadena);
            printf("La cadena tiene: %d Tabs y %d Enter\n\n", tab, enter);
            printf("Dvd no\t\t=\t%s\n", dvd);
            printf("Titulo\t\t=\t%s\n", titulo);
            printf("Director\t=\t%s\n", director);
            printf("Genero\t\t=\t%s\n", genero);
            printf("Año\t\t=\t%s\n", ano);
            printf("Idioma\t\t=\t%s\n",idioma);
            printf("Subtitulo\t=\t%s\n",subtitulo);
            printf("Duracion\t=\t%s\n",duracion);
            printf("Trailer\t\t=\t%s\n",trailer);
            printf("Descripcion\t=\t%s\n\n",descripcion);
            printf("Esta informacion se guardara en el fichero = %s\n\n",path);

                archivo_salida = fopen(path, "w");
                fprintf(archivo_salida,
                        "<!DOCTYPE html>\n"
                        "<html>\n"

                        "<head>\n"
                            "\t<title>DVD %s</title>\n"//1
                            "\t<link rel=\"stylesheet\" href=\"css/estilos.css\" TYPE=\"text/css\">\n"
                        "</head>\n"

                        "<body>\n"
                            "\t<h1 align=\"center\">%s<h1>\n"//2
                            "\t<h2 align=\"center\">DVD %s</h2>\n"//3
                            "\t<hr>\n"
                            "\t<center>\n"
                                "\t\t<img alt=\"DVD %s\" title=\"%s\" src=\"portadas/dvd%s.png\" align=\"left\" width=\"500\" height=\"620\">\n"//4,5,6
                                "\t\t<center>\n"
                                    "\t\t\t<h2>Director</h2>\n"
                                        "\t\t\t\t<p><a href=\"%s.html\" title=\"Pulsa aquí para ver mas DVD's de este director\">%s</a></p>\n"//7,8
                                    "\t\t\t<h2>Género</h2>\n"
                                        "\t\t\t\t<p><a href=\"%s.html\" title=\"Pulsa aquí para ver mas DVD's de este género\">%s</a></p>\n"//9,10
                                    "\t\t\t<h2>Año</h2>\n"
                                        "\t\t\t\t<p>%s</p>\n"//11
                                    "\t\t\t<h2>Lenguajes</h2>\n"
                                        "\t\t\t\t<p>%s</p>\n"//12
                                        "\t\t\t\t<p>%s(Subtítulos)</p>\n"//13
                                    "\t\t\t<hr>\n"
                                    "\t\t\t<center>\n"
                                        "\t\t\t\t<a href=\"%s\">\n"//14
                                        "\t\t\t\t<img alt=\"QRCode.dvd%s\" src=\"QR/dvd %s.png\"\n"//15,16
                                            "\t\t\t\t\t title=\"Ház Clíck o escanéa este código para ver el trailer en youtube.com\" align \"right\">\n"
                                        "\t\t\t\t</a>\n"
                                        "\t\t\t\t<h2>Descripción</h2>\n"
                                            "\t\t\t\t\t<p align=\"center\" >\n\t\t\t\t\t\t %s \n\t\t\t\t\t<p>\n"//17
                                        "\t\t\t\t<h3>Duración</h3>\n"
                                        "\t\t\t\t\t<p>%s minutos</p>\n"//18
                                    "\t\t\t</center>\n"
                                "\t\t</center>\n"
                            "\t</center>\n"
                        "</body>\n"
                        "</html>"
                           ,/*1*/dvd, /*2*/titulo, /*3*/dvd, /*4*/dvd, /*5*/titulo,
                            /*6*/dvd, /*7*/director, /*8*/director, /*9*/genero, /*10*/genero,
                            /*11*/ano, /*12*/idioma, /*13*/subtitulo, /*14*/trailer, /*15*/dvd,
                            /*16*/dvd, /*17*/descripcion, /*18*/duracion);

                fclose(archivo_salida);
            cant_arch_gen++;
        }
        fclose(archivo);
        printf("________________________________________________________________________________\n\n\n");
        printf("-El analisis se ha llevado a cabo con exito!\n");
        printf("-Se han generado todos los archivos!\n");
        printf("Total de archivos generados: %d\n", cant_arch_gen - 1);
    }
    else
    {
        printf("Archivo no encontrado");
    }
}

int main()
{
    logo();
    analizar_archivo((char*)"entrada.txt");
    logo();
    return 0;
}
