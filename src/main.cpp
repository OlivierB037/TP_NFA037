
#include <SDL.h>
//#include <SDL_image.h>

#include <cstdlib>

#include "UI/Game.h"

/*
 * Je n'ai pas réussi à dessiner un Pacman convaincant, et les fantomes allaient me prendre bien trop de temps, donc je suis revenu à la version utilisant des sprites
 */
void showFormattedDialog(char *format,...);

int main(int argumentCount, char* arguments[])
{
    //TODO créer classe Window
//    std::shared_ptr<Window> window = std::make_shared<Window>();
    Window window;
    window.init();
    Game game("terrain.txt");
    game.start(&window);

    return EXIT_SUCCESS;
}


void showFormattedDialog(SDL_Window * window, char *format,...) {
    va_list list;
    va_start(list, format);
    char* msg = new char[90];
    int i = 0, j=0;
    while(format[i] != '\0' && j < 90){
        if (format[i] == '%') {
            i++;

            if (format[i] == 'c'){

                char c = va_arg(list,int);
                msg[j] = c;
                //printf("getting char = %c\n",c);
                //printf("%c", (char)c);
                i++;
                j++;
            }
            else if(format[i] == 's'){
                char *s = va_arg(list,char*);
                int k = 0;
                while(s[k] != '\n'){
                    msg[j] = s[k];
                    k++;
                    j++;
                }
                //printf("getting string = %s\n",s);

                i++;
            }
            else if(format[i] == 'd'){
                int k = 0;
                int l = va_arg(list,int );
                char chars[9]{'\n'};
                sprintf(chars,"%d",l);
                while(chars[k] != '\n'&& k < 9){
                    msg[j] = chars[k];
                    k++;
                    j++;
                }
                //printf("getting int = %d\n",j);

                i++;
            }

            else if(format[i] == 'f'){
                double f = va_arg(list,double );
                char chars[9]{'\n'};
                int k = 0;
                //printf("getting float = %f\n",f);
                sprintf(chars,"%.3f",f);
                while(chars[k] != '\n' && k < 9){
                    msg[j] = chars[k];
                    k++;
                    j++;
                }
                i++;

            }
            else if(format[i] == 'p'){
                void* ptr = va_arg(list,void*);
                char chars[10]{'\n'};
                int k = 0;
                //printf("getting float = %f\n",f);
                sprintf(chars,"%p",ptr);
                while(chars[k] != '\n' && k < 10){
                    msg[j] = chars[k];
                    k++;
                    j++;
                }
                i++;
            }


//            else if(format[i] == '.'&& isdigit(format[i+1])&& format[i+2] == 'f'){
//                i++;
//                int k = 0;
//                char str[5]={'%','.',format[i],'f','\0'};
//
//                double f = va_arg(list,double );
//                printf(str,f);
//                i+=2;
//
//            }
            else{
                msg[j] = format[i-1];
                j++;
//                i++;
            }
        } else{
            msg[j] = format[i];
            i++;
            j++;
        }

    }

    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message",msg,window);
}