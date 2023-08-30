
#include <SDL.h>
//#include <SDL_image.h>

#include <cstdlib>

#include "Core/Game.h"
#include "Labyrinth_Exception.h"
#include "Logger.h"

/*
* J'ai commencé par coder le jeu sans me soucier des TP à rendre, j'effectue ensuite des modifications pour essayer de coller aux énoncés,
* cela coute du temps, mais cela permet également de beaucoup pratiquer, et faire comme ça m'a permis de bien progresser en java
*
* La classe Labyrinthe diffère un peu de celle de l'énoncé:
*
* ** par chance j'ai utilisé les mêmes symboles que ceux demandés dans l'énoncé pour les murs, j'ai également ajouté un type Door (symbole '_'
*       correspondant à la porte du respawn des fantomes.
*
* ** au lieu d'un char* correspondant au terrain, les données du labyrinthe sont dans un fichier et sont extraites vers une matrice de pointeurs de Bloc (map***)
*      Le polymorphisme est ensuite utilisé pour distinguer la nature de chaque Bloc (Food, Fruit, Wall, Door ou Bloc représentant le chemin)
*
* ** j'ai surchargé l'opérateur = de Labyrinthe pour suivre la consigne et respecter la forme canonique de Coplien, mais ça ne colle pas vraiment
*      avec la classe Labyrinthe qui est prévue pour être une classe unique (1 jeu, 1 labyrinthe)
*
* la fonction getElement est essentiellement remplacée par les fonctions :
*
* ** getBlocCoordinates(int x, int y) qui renvoie les coordonnées d'un bloc à partir de ses indexes dans la matrice
*
* ** getBloc(Position position) qui renvoie le Bloc contenant la position passée en paramètre
*
* l'enum Direction est dans le fichier UI/Sprites.h (ça avait du sens au début du projet) il serait vraiment fastidieux de la déplacer maintenant
*/
void showFormattedDialog(char *format,...);

int main(int argumentCount, char* arguments[])
{
    Window window;
    window.init();


    // début Bloc de test
    /*
     * le bloc suivant teste le bon fonctionnement des méthodes de Coplien
     */
//    try {
//
//        Labyrinthe *labyrinthe = new Labyrinthe("resources/terrain.txt", 56, 62, window.getWindow());
//        Labyrinthe copy(*labyrinthe);
//
//        labyrinthe->setDoor(true);
//        Logger::getInstance()->newLogSection();
//        if (copy.getDoor()[0]->isCrossable()) {
//            Logger::getInstance()->addInfoLog("copy door has been open too"); // la "copie" a été modifiée en même temps que labyrinthe
//        }
//        else{
//            Logger::getInstance()->addInfoLog("copy door stayed close"); // copy est bien une copie
//        }
//        delete labyrinthe;
////        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "message", "test", window.getWindow());
//
//        if (copy.getDoor() == nullptr || copy.getDoor()[0] == nullptr || copy.getBloc({0,0}) == nullptr){ // vérifie si les pointeurs ont été supprimés dans copy
//            Logger::getInstance()->addInfoLog("copy elements were deleted");
//
//        }
//        else{
//            Logger::getInstance()->addInfoLog("copy is really a copy");
//
//        }
//        // le dernier log sert a vérifier si il n'y a pas eu d'erreurs en accèdant à copy dans le if précédent
//        Logger::getInstance()->addInfoLog("if this Line is in the log, there were no errors accessing copy after original was deleted");
//
//
//        //Labyrinthe labyrinthe;
//
//    } catch (std::exception const &e) {
//        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "message", e.what(), window.getWindow());
//    }

    //fin bloc de test

    Game game("resources/terrain.txt");
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