/*
課題名：flood_fill
期待されるファイル*.c, *.h
許可された関数-
--------------------------------------------------------------------------------

char **をcharの2次元配列、t_pointをこの配列の次元、t_pointを始点とする関数を作成する。

この関数は、与えられた'begin't_pointを起点として、ゾーン内の文字を'F'に置き換えて、ゾーン全体を塗りつぶします。
ゾーンとは、水平方向と垂直方向に他の文字や配列の境界で区切られた、同じ文字の集まりのことである。

flood_fill関数では、斜めに塗りつぶすことはできない。

flood_fill関数は、次のようにプロトタイプ化されます。
	void flood_fill(char **tab, t_point size, t_point begin);

t_point構造体は、このようにプロトタイプ化されています。

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

例:

$> cat test.c
#include <stdlib.h>
#include <stdio.h>
#include "flood_fill.h"

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

$> gcc flood_fill.c test.c -o test; ./test
11111111
10001001
10010001
10110001
11100001

FFFFFFFF
F000F00F
F00F000F
F0FF000F
FFF0000F
$> 
*/
