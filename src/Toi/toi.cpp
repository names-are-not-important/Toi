#include "Headers\toi.h"
#include "Headers\strink.h"
#include "SDL.h"
#include <cstdio>
#include "SDL_mixer.h"


#define musicpath "music/backroundmusic.wav"
#define torlet_flush_soundeffect "music/Sound Effects/torlet.wav"

void fullscreen(SDL_Window* window, bool value) {
    if (value) {
        SDL_SetWindowResizable(window, SDL_FALSE);
        SDL_SetWindowBordered(window, SDL_FALSE);
        SDL_SetWindowFullscreen(window, SDL_FALSE);
    }
    else {
        SDL_SetWindowResizable(window, SDL_TRUE);
        SDL_SetWindowBordered(window, SDL_TRUE);
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP); 
        SDL_UpdateWindowSurface(window);
    }
}


int main(int argc, char** argv)
{
    Mix_Music* music = NULL;
    Mix_Chunk* Flush_Sound = NULL;

bool waspooping = false;
    bool canpoop = false;
    bool fullscreener = false;
    bool pooping = false;
    bool flipx = false;
    bool clicked = false;
    double eplaspedtime = 0;
    int poopalpha = 200;
    bool flushing = false;

    float timerCurrent = 20.0f;
    float timerTotal = 5.0f;

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;
    SDL_Init(SDL_INIT_AUDIO);
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        //std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("T.totally O.riginal I.dea",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        680, 480,
        SDL_WINDOW_RESIZABLE);

    if (!window)
    {
        //std::cout << "Failed to create window\n";
        return -1;
    }


    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());

    }
    music = Mix_LoadMUS(musicpath);
    if (music == NULL)
    {
        printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
       
    }


    Flush_Sound = Mix_LoadWAV(torlet_flush_soundeffect);
    if (Flush_Sound == NULL)
    {
       printf("Failed to load Flush sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        
    }


    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface* window_surface = SDL_GetWindowSurface(window);

    SDL_Rect stinklinespos;
    stinklinespos.x = 90;
    stinklinespos.y = 250;
    stinklinespos.w = 100;
    stinklinespos.h = 100;
 
    SDL_Rect curserpos;
    curserpos.x = 0;
    curserpos.y = 10;
    curserpos.w = 50;
    curserpos.h = 50;

    SDL_Rect flusherpos;
    flusherpos.x = 25;
    flusherpos.y = 313;
    flusherpos.w = 40;
    flusherpos.h = 17;

    SDL_Rect bobpos;
    bobpos.x = 500;
    bobpos.y = 280;
    bobpos.w = 200;
    bobpos.h = 200;

    SDL_Rect bobposscalled;
    bobposscalled.x = 500;
    bobposscalled.y = 280;
    bobposscalled.w = 200;
    bobposscalled.h = 200;

    SDL_Rect torletpos;
    torletpos.x = 0;
    torletpos.y = 280;
    torletpos.w = 200;
    torletpos.h = 200;

    if (!window_surface)
    {
        // std::cout << "Failed to get the surface from the window\n";
        return -1;
    }
  SDL_RenderSetLogicalSize(renderer, 680, 480);
Uint32 iconrmask, icongmask, iconbmask, iconamask;
    if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
        int shift = (img_icon.bytes_per_pixel == 3) ? 8 : 0;
        iconrmask = 0xff000000 >> shift;
        icongmask = 0x00ff0000 >> shift;
        iconbmask = 0x0000ff00 >> shift;
        iconamask = 0x000000ff >> shift;
    }
    else {
        iconrmask = 0x000000ff;
        icongmask = 0x0000ff00;
        iconbmask = 0x00ff0000;
        iconamask = (img_icon.bytes_per_pixel == 3) ? 0 : 0xff000000;
    }



    Uint32 noclickrmask, noclickgmask, noclickbmask, noclickamask;
    if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
        int shift = (img_brucesfacenoclick.bytes_per_pixel == 3) ? 8 : 0;
        noclickrmask = 0xff000000 >> shift;
        noclickgmask = 0x00ff0000 >> shift;
        noclickbmask = 0x0000ff00 >> shift;
        noclickamask = 0x000000ff >> shift;
    }
    else {
        noclickrmask = 0x000000ff;
        noclickgmask = 0x0000ff00;
        noclickbmask = 0x00ff0000;
        noclickamask = (img_brucesfacenoclick.bytes_per_pixel == 3) ? 0 : 0xff000000;
    }




    Uint32 flusherrmask, flushergmask, flusherbmask, flusherkamask;
    if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
        int shift = (img_flusher.bytes_per_pixel == 3) ? 8 : 0;
        flusherkamask = 0xff000000 >> shift;
        flushergmask = 0x00ff0000 >> shift;
        flusherbmask = 0x0000ff00 >> shift;
        flusherkamask = 0x000000ff >> shift;
    }
    else {
        flusherrmask = 0x000000ff;
        flushergmask = 0x0000ff00;
        flusherbmask = 0x00ff0000;
        flusherkamask = (img_flusher.bytes_per_pixel == 3) ? 0 : 0xff000000;
    }

    Uint32 clickrmask, clickgmask, clickbmask, clickamask;
    if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
        int shift = (img_click.bytes_per_pixel == 3) ? 8 : 0;
        clickrmask = 0xff000000 >> shift;
        clickgmask = 0x00ff0000 >> shift;
        clickbmask = 0x0000ff00 >> shift;
        clickamask = 0x000000ff >> shift;
    }
    
    else {
        clickrmask = 0x000000ff;
        clickgmask = 0x0000ff00;
        clickbmask = 0x00ff0000;
        clickamask = (img_click.bytes_per_pixel == 3) ? 0 : 0xff000000;
    }

    Uint32 playerrmask, playergmask, playerbmask, playeramask;
    if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
        int shift = (img_BOBPOOPMAN.bytes_per_pixel == 3) ? 8 : 0;
        playerrmask = 0xff000000 >> shift;
        playergmask = 0x00ff0000 >> shift;
        playerbmask = 0x0000ff00 >> shift;
        playeramask = 0x000000ff >> shift;
    }

    else {
        playerrmask = 0x000000ff;
        playergmask = 0x0000ff00;
        playerbmask = 0x00ff0000;
        playeramask = (img_BOBPOOPMAN.bytes_per_pixel == 3) ? 0 : 0xff000000;
    }

        Uint32 toletrmask, toletgmask, toletbmask, toletamask;
    if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
        int shift = (img_funnitorlet.bytes_per_pixel == 3) ? 8 : 0;
        playerrmask = 0xff000000 >> shift;
        playergmask = 0x00ff0000 >> shift;
        playerbmask = 0x0000ff00 >> shift;
        playeramask = 0x000000ff >> shift;
    }

    else {
        toletrmask = 0x000000ff;
        toletgmask = 0x0000ff00;
        toletbmask = 0x00ff0000;
        toletamask = (img_funnitorlet.bytes_per_pixel == 3) ? 0 : 0xff000000;
    }

        Uint32 ermask, egmask, ebmask, eamask;
    if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
        int shift = (img_e.bytes_per_pixel == 3) ? 8 : 0;
        ermask = 0xff000000 >> shift;
        egmask = 0x00ff0000 >> shift;
        ebmask = 0x0000ff00 >> shift;
        eamask = 0x000000ff >> shift;
    }

    else {
        ermask = 0x000000ff;
        egmask = 0x0000ff00;
        ebmask = 0x00ff0000;
        eamask = (img_e.bytes_per_pixel == 3) ? 0 : 0xff000000;
    }


Uint32 stinkrmask, stinkgmask, stinkbmask, stinkamask;
if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
    int shift = (img_stinklines.bytes_per_pixel == 3) ? 8 : 0;
    stinkrmask = 0xff000000 >> shift;
    stinkgmask = 0x00ff0000 >> shift;
    stinkbmask = 0x0000ff00 >> shift;
    stinkamask = 0x000000ff >> shift;
}
else {
    stinkrmask = 0x000000ff;
    stinkgmask = 0x0000ff00;
    stinkbmask = 0x00ff0000;
    stinkamask = (img_stinklines.bytes_per_pixel == 3) ? 0 : 0xff000000;
}


SDL_Surface* tolet = SDL_CreateRGBSurfaceFrom((void*)img_funnitorlet.pixel_data,
        img_funnitorlet.width, img_funnitorlet.height, img_funnitorlet.bytes_per_pixel * 8,
        img_funnitorlet.bytes_per_pixel * img_funnitorlet.width, toletrmask, toletgmask, toletbmask, toletamask);

    SDL_Texture* tolet_texa = SDL_CreateTextureFromSurface(renderer, tolet);

SDL_Surface* stink = SDL_CreateRGBSurfaceFrom((void*)img_stinklines.pixel_data,
        img_stinklines.width, img_stinklines.height, img_stinklines.bytes_per_pixel * 8,
        img_stinklines.bytes_per_pixel * img_stinklines.width, stinkrmask, stinkgmask, stinkbmask, stinkamask);

    SDL_Texture* stink_tex = SDL_CreateTextureFromSurface(renderer, stink);

    SDL_Surface* eser = SDL_CreateRGBSurfaceFrom((void*)img_e.pixel_data,
        img_e.width, img_e.height, img_e.bytes_per_pixel * 8,
        img_e.bytes_per_pixel * img_e.width, ermask, egmask, ebmask, eamask);

    SDL_Texture* e_tex = SDL_CreateTextureFromSurface(renderer, eser);


    SDL_Surface* notclick = SDL_CreateRGBSurfaceFrom((void*)img_brucesfacenoclick.pixel_data,
        img_brucesfacenoclick.width, img_brucesfacenoclick.height, img_brucesfacenoclick.bytes_per_pixel * 8,
        img_brucesfacenoclick.bytes_per_pixel * img_brucesfacenoclick.width, noclickrmask, noclickgmask, noclickbmask, noclickamask);
    SDL_Texture* notclick_tex = SDL_CreateTextureFromSurface(renderer, notclick);

    SDL_Surface* bob = SDL_CreateRGBSurfaceFrom((void*)img_BOBPOOPMAN.pixel_data,
        img_BOBPOOPMAN.width, img_BOBPOOPMAN.height, img_BOBPOOPMAN.bytes_per_pixel * 8,
        img_BOBPOOPMAN.bytes_per_pixel * img_BOBPOOPMAN.width, playerrmask, playergmask, playerbmask, playeramask);
    SDL_Texture* bob_tex = SDL_CreateTextureFromSurface(renderer, bob);


    SDL_Surface* flusher = SDL_CreateRGBSurfaceFrom((void*)img_flusher.pixel_data,
        img_flusher.width, img_flusher.height, img_flusher.bytes_per_pixel * 8,
        img_flusher.bytes_per_pixel * img_flusher.width, flusherrmask, flushergmask, flusherbmask, flusherkamask);
    SDL_Texture* flusher_tex = SDL_CreateTextureFromSurface(renderer, flusher);
    





SDL_Surface* icon = SDL_CreateRGBSurfaceFrom((void*)img_icon.pixel_data,
        img_icon.width, img_icon.height, img_icon.bytes_per_pixel * 8,
        img_icon.bytes_per_pixel * img_icon.width, iconrmask, icongmask, iconbmask, iconamask);
  
    SDL_ShowCursor(false);


    SDL_Surface* click = SDL_CreateRGBSurfaceFrom((void*)img_click.pixel_data,
        img_click.width, img_click.height, img_click.bytes_per_pixel * 8,
        img_click.bytes_per_pixel * img_click.width, clickrmask, clickgmask, clickbmask, clickamask);
    SDL_Texture* click_tex = SDL_CreateTextureFromSurface(renderer, click);


    SDL_SetWindowIcon(window, icon);    

    int h = 1;
    int w = 1;
    
      SDL_Rect presse;
    presse.x = 106;
    presse.y = 277;
    presse.w = 50;
    presse.h = 50;

    const double delayTime = 500.0f;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    bool keep_window_open = true;
    while (keep_window_open) {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();

        deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());
        SDL_GetMouseState(&curserpos.x, &curserpos.y);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_GetWindowSize(window, &w, &h);

                if(waspooping){
                     if (poopalpha <= 0) {
                        waspooping = false;
                        poopalpha = 200;
                    }
                    else {
                        
                       
                        timerCurrent += deltaTime;
                        if (timerCurrent >= timerTotal) {
                            poopalpha--;
                            timerCurrent -= timerTotal;
                        }
                        SDL_SetTextureAlphaMod(stink_tex, poopalpha);
                        

                    }
                    SDL_RenderCopyEx(renderer, stink_tex, NULL, &stinklinespos, 0, NULL, SDL_FLIP_HORIZONTAL);

                }
                   
                
                   

        if (Mix_PlayingMusic() == 0)
        {
            //Play the music
            Mix_PlayMusic(music, -1);
        }
            if (bobpos.x < 190) {
                        if (bobpos.x > -30) {
                            canpoop = true;
                            }else{
                            canpoop = false;
                            }
                           
                           
                            
                        }else{
                        canpoop = false;
                    }
                
                  
            SDL_RenderCopy(renderer, tolet_texa, NULL, &torletpos);
            float scalew = w / 680;
            float scaleh = h / 480;
            SDL_RenderCopy(renderer, flusher_tex, NULL, &flusherpos);
           // SDL_RenderSetScale(renderer, scalew, scalew);
            if (flushing) {
                eplaspedtime += deltaTime;
         
                if (eplaspedtime > delayTime) {
                 //   std::cout << "f";
                    flushing = false;

                    eplaspedtime -= delayTime;
                }
            }
            if (flipx) {

             
                SDL_RenderCopyEx(renderer, bob_tex, NULL, &bobpos, 0, NULL, SDL_FLIP_HORIZONTAL);
            }
            else {
                if(canpoop){

               
                    if (!pooping) {
                    SDL_RenderCopyEx(renderer, e_tex, NULL, &presse, 0, NULL, SDL_FLIP_NONE);
               
                }
                }
                SDL_RenderCopyEx(renderer, bob_tex, NULL, &bobpos, 0, NULL, SDL_FLIP_NONE);
            }
                
                
                
                



        if (clicked) {
      SDL_RenderCopy(renderer, click_tex, NULL, &curserpos);
                  
        }
        else {
       SDL_RenderCopy(renderer, notclick_tex, NULL, &curserpos);
        }
        SDL_RenderPresent(renderer);
    
        SDL_Event e;
        while (SDL_PollEvent(&e) > 0)
            {

        
            switch (e.type)
            {
              
            case SDL_QUIT:
                keep_window_open = false;
      
                SDL_DestroyTexture(notclick_tex);
                SDL_DestroyTexture(bob_tex);
                SDL_DestroyTexture(click_tex);
                SDL_DestroyTexture(tolet_texa);
                SDL_DestroyTexture(flusher_tex);
                SDL_DestroyTexture(e_tex);
                SDL_CloseAudio();
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);

                Mix_FreeMusic(music);
                music = NULL;

                Mix_FreeChunk(Flush_Sound);
                Flush_Sound = NULL;

                SDL_FreeSurface(eser);
                SDL_FreeSurface(flusher);
                SDL_FreeSurface(icon);
                SDL_FreeSurface(click);
                SDL_FreeSurface(notclick);
                SDL_FreeSurface(bob);
                SDL_FreeSurface(tolet);

                SDL_FreeSurface(window_surface);
                Mix_FreeMusic(music);
                Mix_Quit();
                SDL_Quit();
                break;

            case SDL_MOUSEBUTTONUP:
                
            //    std::cout << " x: " << curserpos.x << std::endl;
            //    std::cout << " y: " << curserpos.y << std::endl;
                if (curserpos.y > 250) {
                    if (curserpos.x < 270) {
                        if (curserpos.x > -30) {
                            Mix_PlayChannel(-1, Flush_Sound, 0);

                            flushing = true; 
                            //play flush sound

                        }
                    }
                }
               
            case SDL_MOUSEBUTTONDOWN:


                clicked = !clicked;
                break;

            case SDL_KEYUP:
                switch (e.key.keysym.sym)
                {
                case SDLK_F11:
                
                    fullscreen(window, fullscreener);
                    if(fullscreener){
                         SDL_RenderSetScale(renderer, 1.0f, 1.0f);
                    }
                    else{
                         SDL_RenderSetScale(renderer, scaleh * 2.0f, scalew * 2.0f);
                    }
                    fullscreener = !fullscreener;
                    break;
                }
                break;
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym)
                {


                case SDLK_a:
                case SDLK_LEFT:
                    if(!pooping){
                        bobpos.x = bobpos.x - 10;
                        flipx = false;
                    }
                        
                    
                    break;
                case SDLK_g:
                          case SDLK_e:
                    if(canpoop){

                            if(pooping){
                             pooping = !pooping;
                             waspooping = true;
                           bobpos.y = 280;
                            }else{
                                waspooping = false;
                                bobpos.x = 30;
                            bobpos.y = 210;
                             pooping = !pooping;
                           
                            flipx = true;
                            }
                    }
                           
                           
                            
                 
                 
                      break;
                      break;
                    //bruce found good number thx bruce + 1!!!!!
                  
                case SDLK_RIGHT:
                case SDLK_d:
                   if(!pooping){
                      bobpos.x = bobpos.x + 10;
                        flipx = true;
                   }
                      
                    

                    break;




                        }

                   



                    break;



                }
        }
            SDL_Delay(10);
            }

}

        

        
        


