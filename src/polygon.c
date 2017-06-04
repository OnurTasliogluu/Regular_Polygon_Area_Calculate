#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "polygon.h"
#include "debug.h"

/*
    Sabit PI sayisi
*/
#define PI 3.14159265358979323846


/*
    Polygon struct'i;
    Kenar uzunlugu
    Kenar sayisi
    Cokgen alani
*/
struct
{
    int edge_length;
    int edge_number;
    double polygon_area;
}typedef Polygon;

/**
 * @brief Constructor : ilk verilen degiskenleri set eder.
 *
 * @param Polygon* self : Cokgen'in, kenar uzunlugu ve kenar sayisini tutan degerleri barindirir.
 *
 * @param unsigned int v_edge_length : Cokgen kenar uzunlugunudur.
 *
 * @param unsigned int v_edge_number : Cokgen kenar sayisidir.
 *
*/
static void polygon_init(void* self, unsigned int v_edge_length, unsigned int v_edge_number)
{
    Polygon *polygon = (Polygon*)self;
    polygon->edge_length = v_edge_length;
    polygon->edge_number = v_edge_number;
    polygon->polygon_area = 0;
}

/**
 * @brief Polygon(Cokgen) verilen parametrelerle olusturur.
 *
 * @param unsigned int v_edge_length : Cokgen kenar uzunlugunudur.
 *
 * @param unsigned int v_edge_number : Cokgen kenar sayisidir.
 *
 * @return Polygon pointer degiskeni dondurur.
 *
*/
void* polygon_create(unsigned int v_edge_length, unsigned int v_edge_number)
{
    Polygon* polygon = malloc(sizeof(Polygon));
    if(polygon == NULL)
    {
        return NULL;
    }
    polygon_init(polygon, v_edge_length, v_edge_number);
    polygon_calculate_area(polygon);
    return polygon;
}

/**
 * @brief Cotanjant degerini dondurur. Kenar sayisina gore cotanjant hesabi yapar.
 *
 * @param double v_edge_number : Cokgen kenar sayisidir.
 *
 * @return Cotanjant degerini dondurur.
*/
static double cotan(double v_edge_number)
{
    return(1 / tan(v_edge_number));
}

/**
 * @brief Regular Polygon Alan hesabini yapar.
 *
 * @param Polygon* self : Polygon pointer degerini alir.
*/
static void polygon_calculate_area(void* self)
{
	Polygon *polygon = (Polygon*)self;
	DEBUG_INFO("self->edge_length = %d", polygon->edge_length);
	DEBUG_INFO("self->edge_number = %d", polygon->edge_number);
    polygon->polygon_area = ((double)1/4)*polygon->edge_number*pow(polygon->edge_length,2)*cotan(PI/polygon->edge_number);
}

/**
 * @brief Olusturulan Polygon* pointer'ini free eder.
 *
 * @param Polygon* self : Polygon* pointer degeridir.
*/
void polygon_destroy(void* self)
{
	Polygon *polygon = (Polygon*)self;
    if(polygon != NULL)
    {
        free(polygon);
    }
}

/**
 * @brief Hesaplanan alan degerini getirir.
 *
 * @return Hesaplanan Alan degerini dondurur.
*/
double getter_polygon_area(void* self)
{
	Polygon *polygon = (Polygon*)self;
    if (polygon != NULL)
    {
        return polygon->polygon_area;
    }
}