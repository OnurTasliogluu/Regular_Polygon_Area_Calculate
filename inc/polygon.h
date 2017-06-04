#ifndef POLYGON_H
#define POLYGON_H

static void polygon_init(void* self, unsigned int v_edge_length, unsigned int v_edge_number);
void* polygon_create(unsigned int v_edge_length, unsigned int v_edge_number);
static double cotan(double v_edge_number);
static void polygon_calculate_area(void* self);
void polygon_destroy(void* self);
double getter_polygon_area();

#endif