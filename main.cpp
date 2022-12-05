#ifdef USING_CLION
#include "Include/SDL.h"
#include "Include/SDL_image.h"
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
#include <cstdlib>
#include <fstream>
//#include <WinUser.h>
#include "Hero.h"
#include "Mouvement.h"
#include "Logger.h"
#include "Terrain_Exception.h"

bool arrowPressed();
void showFormattedDialog(char *format,...);

int main(int argumentCount, char* arguments[])
{
    SDL_Renderer* renderer;
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window;
    SDL_CreateWindowAndRenderer(504, 558, SDL_WINDOW_ALWAYS_ON_TOP, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Texture* texture;
    SDL_Surface* imagePerso = SDL_LoadBMP(Perso::sprite_fileName);
    //SDL_Surface* imagePerso = IMG_Load(Perso::sprite_fileName);
    texture = SDL_CreateTextureFromSurface(renderer, imagePerso);
    SDL_Surface *backgroundSurface = SDL_LoadBMP("field_empty.bmp");
    SDL_Texture *background = SDL_CreateTextureFromSurface(renderer, backgroundSurface);


    Hero hero;
    try {
        Terrain terrain("terrain.txt", 56, 62);
        //Terrain terrain;
        //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message",msg,window);


        int continuer = 1;
        int compteurDePas = 1;
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,background,NULL,NULL);
        SDL_RenderCopy(renderer, texture, &(hero.getImage().getBaseRect(LEFT)), &(hero.getPosition()));
        SDL_RenderPresent(renderer);
        SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
        //SystemParametersInfo(SPI_SETKEYBOARDDELAY, 0, 0, 0);

        SDL_FreeSurface(imagePerso);

        SDL_Event event;
        Side oldSide;

        bool timing = false;

//        Logger::getInstance()->newLogSection();
        bool leftPressed = false, upPressed = false, rightPressed = false,downPressed = false;
        while (continuer)
        {

            SDL_PollEvent(&event);

            switch (event.type)
            {

                case SDL_QUIT:
                    //fprintf(fichier, "%s quit event", ctime(&crtTime));
                    continuer = 0;
                    break;

                case SDL_KEYDOWN:
                    //fprintf(fichier, "%s mouvements.c : \nkeydown event", ctime(&crtTime));
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            //fprintf(fichier, "%s mouvements.c : \nescape event", ctime(&crtTime));
                            continuer = 0;
                            break;


                        case SDLK_UP:
                            Logger::getInstance()->addInfoLog("up pressed");
                            upPressed = true;
                            Mouvement::move(UP,hero,terrain, window);

                            break;
                        case SDLK_DOWN:
                            Logger::getInstance()->addInfoLog("down pressed");
                            downPressed = true;
                            Mouvement::move(DOWN,hero,terrain, window);
                            break;
                        case SDLK_LEFT:
                            Logger::getInstance()->addInfoLog("left pressed");
                            leftPressed = true;
                            Mouvement::move(LEFT,hero,terrain, window);
                            break;
                        case SDLK_RIGHT:
                            Logger::getInstance()->addInfoLog("right pressed");
                            rightPressed = true;
                            Mouvement::move(RIGHT,hero,terrain, window);
                            break;

                            /*vidage du buffer

                                    default:
                                        cleanBuffer();
                                    break;*/
                    }

                case SDL_KEYUP:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_UP:
                            upPressed = false;
                            if (!arrowPressed()) {
                                hero.setCurrentSprite(&(hero.getImage().getUp1()));
                                hero.setStepCount(1);
                            }
                            break;
                        case SDLK_DOWN:
                            downPressed = false;
                            if (!arrowPressed()){
                                hero.setCurrentSprite(&(hero.getImage().getDown1()));
                                hero.setStepCount(1);
                            }

                            break;
                        case SDLK_LEFT:
                            leftPressed = false;
                            if (!arrowPressed()){
                                hero.setCurrentSprite(&(hero.getImage().getLeft1()));
                                hero.setStepCount(1);
                            }

                            break;
                        case SDLK_RIGHT:
                            rightPressed = false;
                            if (!arrowPressed()){
                                hero.setCurrentSprite(&(hero.getImage().getRight1()));
                                hero.setStepCount(1);
                            }

                            break;

                    }

                    break;

            }

            //envoyer le sdl_rect a mouvement pour changer partie sprite affichée

            //SDL_UpdateTexture(texture, NULL, imageZabeth->pixels, imageZabeth->pitch);

            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer,background,NULL,NULL);


            SDL_RenderCopy(renderer, texture, hero.getCurrentSprite(), &(hero.getPosition()));

            SDL_RenderPresent(renderer);

        }
    } catch (Terrain_Exception const &e) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "message", e.what(), window);
    }
    return EXIT_SUCCESS;
}
bool arrowPressed(){
    return (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_UP] ||
            SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_DOWN] ||
            SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_LEFT] ||
            SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RIGHT]);



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