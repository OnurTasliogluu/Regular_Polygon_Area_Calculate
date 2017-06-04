#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "polygon.h"
#include "debug.h"

int main(int argc, char *argv[])
{
    int option = 0;
    unsigned int length = -1;
    unsigned int number = -1;
    double result;

    void *polygon = NULL;

    /*
        Dis degerler parse edilir.
    */
    while ((option = getopt(argc, argv,"l:n:")) != -1)
    {
        switch (option)
        {
            case 'l' : 
                DEBUG_INFO("edge_length = %s",optarg);
                length = (unsigned int)strtol(optarg,NULL,10);
                break;
            case 'n' :
                DEBUG_INFO("edge_number = %s",optarg);
                number = (unsigned int)strtol(optarg,NULL,10);
                break;
            default:
                DEBUG_ERROR("Usage: polygon -l edge_length -b edge_number");
                DEBUG_INFO("Usage: polygon -l 3 -b 3");
            exit(EXIT_FAILURE);
        }
    }

    if (number < 2 || length < 0)
    {
        DEBUG_ERROR("Usage: polygon -l edge_length -b edge_number");
        DEBUG_INFO("Usage: polygon -l 3 -b 3");
        exit(EXIT_FAILURE);
    }

    /*
        Nesne olusturmak;
        Alan hesabi yapildiktan sonra, sonuc alinir.
        Nesne free edilir.
    */
    polygon = polygon_create(length,number);
    result = getter_polygon_area(polygon);
    polygon_destroy(polygon);

    /*
        Sonucu ekrana basar.
    */
    DEBUG_INFO("result = %lf",result);

    return 0;
}