#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>

int main()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    SDL_Window *window =
        SDL_CreateWindow("dungeon", 400, 400, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    SDL_Texture *texture = IMG_LoadTexture(renderer, "images/catacombes.jpeg");

    // Modern SDL3_mixer API — Mix_OpenAudio/Mix_LoadMUS are gone
    MIX_Init();
    MIX_Mixer *mixer =
        MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);
    if (!mixer)
    {
        SDL_Log("MIX_CreateMixerDevice failed: %s", SDL_GetError());
    }

    MIX_Audio *audio =
        MIX_LoadAudio(mixer, "soundtracks/taira-komori__hell_bell.mp3", false);
    if (!audio)
    {
        SDL_Log("MIX_LoadAudio failed: %s", SDL_GetError());
    }

    MIX_Track *track = MIX_CreateTrack(mixer);
    MIX_SetTrackAudio(track, audio);

    SDL_PropertiesID props = SDL_CreateProperties();
    SDL_SetNumberProperty(props, MIX_PROP_PLAY_LOOPS_NUMBER, -1);
    MIX_PlayTrack(track, props);
    SDL_DestroyProperties(props);

    bool running = true;
    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
            if (event.type == SDL_EVENT_QUIT)
                running = false;

        SDL_RenderClear(renderer);
        SDL_RenderTexture(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    MIX_DestroyAudio(audio);
    MIX_DestroyMixer(mixer);
    MIX_Quit();
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
