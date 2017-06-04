# Regular_Polygon_Area_Calculate
Regular Polygon Area Calculate

Programın amacı C dilinde OOP(object Orianted Programming) mantığına uygun nasıl kod yazılabilir için bir örnektir.

Düzenli Çokgen Alan Hesabı Formülü : (1/4)nk2 cot(π/n)
n : kenar sayısı
k : kenar uzunluğu

### Örnek:

$ make

cc		-c	src/polygon.c	-I./inc
cc		-I./inc	polygon.o	main.c	-lm	-o	polygon

```
$ ./polygon -l 3 -n 3
main.c:  27: edge_length = 3
main.c:  31: edge_number = 3
src/polygon.c:  87: self->edge_length = 3
src/polygon.c:  88: self->edge_number = 3
main.c:  60: result = 3.897114
```