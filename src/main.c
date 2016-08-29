/*
 * main.c
 *
 *  Created on: 06.08.2016
 *      Author: vp
 */

#include <stdio.h>

#include "hour_glass_worker.h"

int main() {
	int i;
	sorter_t s;

	printf("Hi C\n");

	s = sorter_new();

	sorter_put(s, 23);
	sorter_put(s, 13);
	sorter_put(s, 6);
	sorter_put(s, 12);
	sorter_put(s, 42);

	/* Iterate over all values and exhaust the container by 2 */
	for (i = 0; i < 5 + 2; ++i) {
		printf("%i: %i\n", i, sorter_get(s));
	}

	sorter_cleanup(s);

	printf("Bye C\n");

	return 0;
}

