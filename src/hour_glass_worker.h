/*
 * hour_glass_worker.h
 *
 *  Created on: 06.08.2016
 *      Author: vp
 */

#ifndef HOUR_GLASS_WORKER_H_
#define HOUR_GLASS_WORKER_H_

#define EXPORT_TO_SO __attribute__ ((visibility ("default")))

#ifdef __cplusplus
extern "C" {
#endif

typedef struct IntSorter * sorter_t;

EXPORT_TO_SO
sorter_t sorter_new();
EXPORT_TO_SO
void sorter_cleanup(sorter_t sorter);


EXPORT_TO_SO
void sorter_put(sorter_t sorter, int e);
EXPORT_TO_SO
int sorter_get(sorter_t sorter);

#ifdef __cplusplus
}
#endif

#endif /* HOUR_GLASS_WORKER_H_ */
