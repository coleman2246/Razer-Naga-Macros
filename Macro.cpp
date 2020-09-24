#include <linux/input.h> 
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include<iostream> 
int main(){

    const char* path = "/dev/input/by-id/usb-Razer_Razer_Naga_2014-if02-event-kbd";
    
    int fd;
    struct input_event ie;
    
 
    std::cout << "Program requires xdotool and dbus" << std::endl;

    if((fd = open(path, O_RDONLY)) == -1) {
        perror("Cannot access mouse device");
        return -1;
    }

    // taking io control of mouse
    ioctl(fd, EVIOCGRAB, 1) == 0;
     

    while(read(fd, &ie, sizeof(struct input_event))) {
        unsigned short number = ie.code;
        
        // EV_SYN is buffer event and EV_KEY means the event is a key press
        if( ie.value != EV_SYN & ie.value == EV_KEY){
            switch(ie.code){
                case KEY_1:
                    system("xdotool key 1");
                    break;
                case KEY_2:
                    system("xdotool key 2");
                    break;
                case KEY_3:
                    system("xdotool key 3");
                    break;
                case KEY_4:
                    system("xdotool key 4");
                    break;
                case KEY_5:
                    system("xdotool key 5");
                    break;
                case KEY_6:
                    system("xdotool key 6");
                    break;
                case KEY_7:
                    system("xdotool key 7");
                    break;
                case KEY_8:
                    system("xdotool key 8");
                    break;
                case KEY_9:
                    system("xdotool key 9");
                    break;
                case KEY_0:
                    system("dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Previous >/dev/null");
                    break;
                case KEY_MINUS:
                    system("dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.PlayPause >/dev/null");
                    break;
                case KEY_EQUAL:
                    system("dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Next >/dev/null");              
                    break;
            }
        }    
    }
}
