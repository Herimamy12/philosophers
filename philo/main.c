/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:32:24 by nherimam          #+#    #+#             */
/*   Updated: 2024/07/22 12:32:27 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	if (check_arg(ac, av))
		return (1);
	printf("ok\n");
	return (0);
}

/*###################################*/
/*###################################*/
/*###################################*/

// /* CELEBP27 */
// #define _OPEN_THREADS
// #include <pthread.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdio.h>
// void *thread(void *arg) {
//   char *ret;
//   printf("thread() entered with argument '%s'\n", (char *)arg);
//   if ((ret = (char*) malloc(20)) == NULL) {
//     perror("malloc() error");
//     exit(2);
//   }
//   strcpy(ret, "This is a test");
//   pthread_exit(ret);
// }

// int	main() {
//   pthread_t thid;
//   void *ret;

//   if (pthread_create(&thid, NULL, thread, "thread 1") != 0) {
//     perror("pthread_create() error");
//     exit(1);
//   }

//   if (pthread_join(thid, &ret) != 0) {
//     perror("pthread_create() error");
//     exit(3);
//   }

//   printf("thread exited with '%s'\n", (char *)ret);
// }
