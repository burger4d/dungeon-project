#include "game.hh"

Game::Game()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    window_ = SDL_CreateWindow("dungeon", 400, 400, SDL_WINDOW_RESIZABLE);
    renderer_ = SDL_CreateRenderer(window_, NULL);

    texture_ = IMG_LoadTexture(renderer_, "images/catacombes.jpeg");

    MIX_Init();
    mixer_ = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);
    if (!mixer_)
    {
        SDL_Log("MIX_CreateMixerDevice failed: %s", SDL_GetError());
    }

    audio_ =
        MIX_LoadAudio(mixer_, "soundtracks/taira-komori__hell_bell.mp3", false);
    if (!audio_)
    {
        SDL_Log("MIX_LoadAudio failed: %s", SDL_GetError());
    }

    track_ = MIX_CreateTrack(mixer_);
    MIX_SetTrackAudio(track_, audio_);

    SDL_PropertiesID props = SDL_CreateProperties();
    SDL_SetNumberProperty(props, MIX_PROP_PLAY_LOOPS_NUMBER, -1);
    MIX_PlayTrack(track_, props);
    SDL_DestroyProperties(props);

    running_ = true;
}

Game::~Game()
{
    MIX_DestroyAudio(audio_);
    MIX_DestroyMixer(mixer_);
    MIX_Quit();
    SDL_DestroyTexture(texture_);
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}

void Game::run()
{
    SDL_Event event;
    while (running_)
    {
        while (SDL_PollEvent(&event))
            if (event.type == SDL_EVENT_QUIT)
                running_ = false;

        SDL_RenderClear(renderer_);
        SDL_RenderTexture(renderer_, texture_, NULL, NULL);
        SDL_RenderPresent(renderer_);
        SDL_Delay(16);
    }
};